#ifndef SIMPLELIFE_HPP
#define SIMPLELIFE_HPP

#include "Life.hpp"

class SimpleLife : public Life
{
public:
    SimpleLife(unsigned int rows, unsigned int cols);

protected:
    virtual void siml(dat& current, const dat& old, unsigned int column, unsigned int row);
};

#endif
