#include "PointSet.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

PointSet::PointSet()
{
	_set.clear();
}

std::set<Point>::iterator PointSet::begin()
{
	return _set.begin();
}

std::set<Point>::iterator PointSet::end()
{
	return _set.end();
}

PointSet::uint PointSet::size() const
{
	return _set.size();
}

void PointSet::getRanges(int &x_min, int &x_max, int &y_min, int &y_max, PointSet::uint &v_min, PointSet::uint &v_max) const
{
	x_min = 0;
	x_max = 0;
	y_min = 0;
	y_max = 0;
	v_min = 0;
	v_max = 0;
	if(_set.empty())
		return;
	auto it=_set.begin();
	x_min = (*it).XPos();
	x_max = x_min;
	y_min = (*it).YPos();
	y_max = y_max;
	v_min = (*it).value;
	v_max = v_min;
	for(auto it=_set.begin();it!=_set.end();++it)
	{
		if((*it).XPos()<x_min)
			x_min = (*it).XPos();
		if((*it).YPos()<y_min)
			y_min = (*it).YPos();
		if((*it).value<v_min)
			v_min = (*it).value;
		if((*it).XPos()>x_max)
			x_max = (*it).XPos();
		if((*it).YPos()>y_max)
			y_max = (*it).YPos();
		if((*it).value>v_max)
			v_max = (*it).value;
	}
	return;
}

/**
 * Funcja dodaje obiekt Point do zestawu, jeżeli obiekt o identycznych współrzędnych już istniał to 
 * dodaje pole Point::value do obiektu już istniejącego.
 */
void PointSet::addPoint(const Point added)
{
	auto res = _set.insert(added);
	if(!res.second)
		(*res.first).value += added.value;
}

/**
 * Metoda dodaje wszystkie pozycje zawarte w wskazanym obiekcie PointSet.
 */
void PointSet::merge(PointSet &other)
{
	for(auto it=other.begin();it!=other.end();++it)
		this->addPoint((*it));
}

/**
 * Funkcja zwraca obiekt przekształcony według zasad:
 * - od wszystkich współrzędnych X odejmowana jest najmniejsza wartość X oryginalnego zbioru,
 * - od wszystkich współrzędnych Y odejmowana jest najmniejsza wartość Y oryginalnego zbioru,
 * - wartości value są przeskalowane w taki sposób, aby ich zakres zawierał się w przedziale od 0 
 * do maxValue.
 */
PointSet PointSet::normalized(PointSet::uint maxValue) const
{
	PointSet temp;
	if(_set.empty())
		return temp;
	uint v_min, v_max;
	int x_min, x_max, y_min, y_max;
	getRanges(x_min, x_max, y_min, y_max, v_min, v_max);
	float k;
	
	if((v_max-v_min)!=0)
		k = (float)maxValue/((float)v_max-(float)v_min);
	else
	{
		k = (float)maxValue/(float)v_max;
		v_min = 0;
	}
	
	std::cout << "min: " << v_min << ", max: " << v_max << ", K: " << k << std::endl;
 	for(auto it=_set.begin();it!=_set.end();++it)
	{
		Point tpoint((*it).XPos()-x_min, (*it).YPos()-y_min, (float)((*it).value-v_min)*k);
		temp.addPoint(tpoint);
	}
	return temp;
}

/**
 * Funkcja zapisuje znormalizowany zbiór punktów jako monochromatyczną bitmape w pliku wskazanym w
 * argumencie.
 */
bool PointSet::toBitmap(std::string fileAdr) const
{
	std::ofstream file;
	file.open(fileAdr, std::ios::out | std::ios::trunc | std::ios::binary);
	if(!file.is_open())
		throw "ERROR!";
	
	for(auto it=_set.begin();it!=_set.end();++it)
		(*it).value = sqrt(10*(*it).value);
	for(auto it=_set.begin();it!=_set.end();++it)
		(*it).value = sqrt(10*(*it).value);
	
	PointSet norm = normalized();
	const uint buflength = 64;
	unsigned int v_min, v_max;
	int x_min, x_max, y_min, y_max;
	norm.getRanges(x_min, x_max, y_min, y_max, v_min, v_max);
	unsigned int szerokosc = x_max+1;
	while(szerokosc%4)
		szerokosc++;
	unsigned int wysokosc = y_max+1, rozmiar=szerokosc*wysokosc;
	unsigned int rozmiarPliku = rozmiar+buflength;
	rozmiarPliku *= 3;
	rozmiar *= 3;
	char header[buflength];
	for(int i=0;i<buflength;++i)
		header[i] = 0x00;
	header[0] = 0x42; // B
	header[1] = 0x4d; // M
	header[2] = (rozmiarPliku>>0)&0xFF; // rozmiar pliku
	header[3] = (rozmiarPliku>>8)&0xFF;
	header[4] = (rozmiarPliku>>16)&0xFF;
	header[5] = (rozmiarPliku>>24)&0xFF;
	header[10] = buflength&0xFF; // offset do danych
	header[14] = 0x28; // dlugosc kolejnego naglowka
	header[18] = (szerokosc>>0)&0xFF; // szerokosc
	header[19] = (szerokosc>>8)&0xFF;
	header[20] = (szerokosc>>16)&0xFF;
	header[21] = (szerokosc>>24)&0xFF;
	header[22] = (wysokosc>>0)&0xFF; // wysokosc
	header[23] = (wysokosc>>8)&0xFF;
	header[24] = (wysokosc>>16)&0xFF;
	header[25] = (wysokosc>>24)&0xFF;
	header[26] = 0x01; // liczba warstw
	header[28] = 0x18; // bitow na piksel
	header[34] = (rozmiar>>0)&0xFF; // rozmiar obrazu
	header[35] = (rozmiar>>8)&0xFF;
	header[36] = (rozmiar>>16)&0xFF;
	header[37] = (rozmiar>>24)&0xFF;
	
	std::vector<char> vec(rozmiar);
	for(int i=0;i<vec.size();i++)
		vec[i] = 0x00;
	
	for(auto it=norm.begin();it!=norm.end();++it)
	{
		vec[(*it).XPos()*wysokosc+(*it).YPos()] = (*it).value;
	}

	file.write(header, buflength);
	char tt[2];
	for(int i=0;i<vec.size();i++)
	{
		tt[0] = vec.at(i);
		file.write(tt, 1);
		file.write(tt, 1);
		file.write(tt, 1);
	}
	
	file.close();
}


