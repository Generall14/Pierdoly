#include "PointSet.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

PointSet::PointSet(std::string name):
	_name(name)
{
	_set.clear();
}

std::string PointSet::name() const
{
	return _name;
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

/**
 * Funkcja wysyłą na std::cout opis zbioru (zakresy, długości itp.).
 */
void PointSet::about() const
{
	unsigned int v_min, v_max;
	int x_min, x_max, y_min, y_max;
	getRanges(x_min, x_max, y_min, y_max, v_min, v_max);
	std::cout << "########################## about " << _name << std::endl;
	std::cout << "# Elementów: " << size() << ", szerokosc: " << y_max-y_min << ", wysokosc: " << x_max-x_min << std::endl;
	std::cout << "# Zakresy: x[ " << x_min << " ; " << x_max << " ], y[ " << y_min << " ; " << y_max << " ], v[ " << v_min << " ; " << v_max << " ]" << std::endl;
	std::cout << "##########################" << std::endl;
}

/**
 * Funkcja oblicza zakresy współrzędnych i wartości.
 */
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
	auto t1 = std::chrono::high_resolution_clock::now();
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
	
 	for(auto it=_set.begin();it!=_set.end();++it)
	{
		Point tpoint((*it).XPos()-x_min, (*it).YPos()-y_min, (float)((*it).value-v_min)*k);
		temp.addPoint(tpoint);
	}
	
	auto t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> ms = t2 - t1;
	std::cout << "Normalized in " << ms.count() << " ms" << std::endl;
	return temp;
}

/**
 * Funkcja logarytmuje (logarytm natralny) wszystkie elementy zbioru.
 */
void PointSet::logarithm()
{
	auto t1 = std::chrono::high_resolution_clock::now();
	for(auto it=_set.begin();it!=_set.end();++it)
		(*it).value = log((*it).value);
	auto t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> ms = t2 - t1;
	std::cout << "Logarithmed in " << ms.count() << " ms" << std::endl;
}

/**
 * Funkcja mnoży wszystkie elementy zbioru przez wskazaną wartość.
 */
void PointSet::multiply(float mul)
{
	auto t1 = std::chrono::high_resolution_clock::now();
	for(auto it=_set.begin();it!=_set.end();++it)
		(*it).value = mul*(*it).value;
	auto t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> ms = t2 - t1;
	std::cout << "Multiplied in " << ms.count() << " ms" << std::endl;
}

/**
 * Funkcja pierwiastkuje (pierwiastek kwadratowy) wszystkie elementy zbioru.
 */
void PointSet::sqrt()
{
	auto t1 = std::chrono::high_resolution_clock::now();
	for(auto it=_set.begin();it!=_set.end();++it)
		(*it).value = std::sqrt((*it).value);
	auto t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> ms = t2 - t1;
	std::cout << "Sqrted in " << ms.count() << " ms" << std::endl;
}

/**
 * Funkcja zapisuje znormalizowany zbiór punktów jako monochromatyczną bitmape w pliku wskazanym w
 * argumencie.
 */
void PointSet::toBitmap(std::string fileAdr) const
{
	std::function<char(char)>lambda = [=](char arg)->char{return arg&0xFF;};
	toBitmap(fileAdr, lambda, lambda, lambda);
}

/**
 * Funkcja zapisuje znormalizowany zbiór punktów jako dziwnie pokolorowaną bitmape w pliku wskazanym w
 * argumencie.
 */
void PointSet::toBitmapc(std::string fileAdr) const
{
	std::function<char(char)>r = [=](char arg)->char
	{
		unsigned int x = (unsigned int)arg;
		if(x<128)
			return x;
		else
			return (x-128)*2;
	};
	std::function<char(char)>g = [=](char arg)->char
	{
		unsigned int x = (unsigned int)arg;
		if(x<64)
			return 0;
		else if(x>192)
			return 0xFF;
		else
			return (x-65)*2;
	};
	std::function<char(char)>b = [=](char arg)->char
	{
		unsigned int x = (unsigned int)arg;
		if(x>128)
			return 0xFF;
		else
			return (x)*2;
	};
	toBitmap(fileAdr, g, b, r);
}

/**
 * Funkcja zapisuje znormalizowany zbiór punktów jako bitmape w pliku wskazanym w
 * argumencie. Funkcja all przetwarza dane z zakresu 0x00 - 0xFF na bajty 
 * wszystkich kanałów.
 * @param fileAdr - nazwa pliku docelowego
 * @param all - funkcja [=](char arg)->char{} przekształcająca wartość na wszystkie kanały
 */
void PointSet::toBitmap(std::string fileAdr, fun all) const
{
	toBitmap(fileAdr, all, all, all);
}

/**
 * Funkcja zapisuje znormalizowany zbiór punktów jako bitmape w pliku wskazanym w
 * argumencie. Funkcje r, g, b przetwarzają dane z zakresu 0x00 - 0xFF na bajty 
 * poszczególnych kolorów.
 * @param fileAdr - nazwa pliku docelowego
 * @param r - funkcja [=](char arg)->char{} przekształcająca wartość na kanał czerwony 
 * @param g - funkcja [=](char arg)->char{} przekształcająca wartość na kanał zielony
 * @param b - funkcja [=](char arg)->char{} przekształcająca wartość na kanał niebieski 
 */
void PointSet::toBitmap(std::string fileAdr, fun r, fun g, fun b) const
{
	std::ofstream file;
	file.open(fileAdr, std::ios::out | std::ios::trunc | std::ios::binary);
	if(!file.is_open())
		throw "ERROR!";
	
	PointSet norm = normalized(0xFF);
	
	auto t1 = std::chrono::high_resolution_clock::now();
	
	const uint buflength = 64; // zbieraniena obliczania rozmiarow itp.
	unsigned int v_min, v_max;
	int x_min, x_max, y_min, y_max;
	norm.getRanges(x_min, x_max, y_min, y_max, v_min, v_max);
	unsigned int szerokosc = y_max+1;
	while(szerokosc%4)
		szerokosc++; // wymagane wyrównanie wierszy do 4 bajtów?
	unsigned int wysokosc = x_max+1, rozmiar=szerokosc*wysokosc;
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
	
	std::vector<char> vec(rozmiar); // bufor danych do zapisu
	for(int i=0;i<vec.size();i++)
		vec[i] = 0x00;
	
	for(auto it=norm.begin();it!=norm.end();++it)
		vec[(*it).XPos()*szerokosc+(*it).YPos()] = (*it).value; // dodawanie do bufora danych obliczonego zestawu punktow

	file.write(header, buflength); // zapis bufora naglowka
	char tt[3];
	for(int i=0;i<vec.size();i++)
	{
		tt[0] = b(vec.at(i));
		tt[1] = g(vec.at(i));
		tt[2] = r(vec.at(i));
		file.write(tt, 3);
	}
	
	file.close();
	
	auto t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> ms = t2 - t1;
	std::cout << "Saved as bitmap in " << ms.count() << " ms" << std::endl;
}


