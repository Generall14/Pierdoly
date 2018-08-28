#ifndef LIFE_HPP
#define LIFE_HPP

#include <string>

class Life
{
public:
    struct dat
    {
        char* ptr;
        unsigned int rows;
        unsigned int cols;
    };

    Life(unsigned int rows, unsigned int cols);
    ~Life();

    void sim(unsigned int steps=1);
    const dat* get();

protected:
    std::string _name="base";
    dat buff[2];
    unsigned int _currentBuff = 0;

    virtual void sim(dat& current, const dat& old, unsigned int column, unsigned int row) = 0;

private:
    Life(const Life&){}
    const Life& operator=(const Life&){return *this;}
};

#endif
