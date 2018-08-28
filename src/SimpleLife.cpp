#include "SimpleLife.hpp"

SimpleLife::SimpleLife(unsigned int rows, unsigned int cols):
    Life(rows, cols)
{
    _name = "SimpleLife";
}

void SimpleLife::siml(dat& current, const dat& old, unsigned int column, unsigned int row)
{
    uint count = 0;
    uint left = column-1, right = column+1, up = row+1, down = row-1;

    if(left>old.cols)
        left = old.cols-1;
    if(right>old.cols)
        right = 0;
    if(up>old.rows)
        up = old.rows-1;
    if(down>old.rows)
        down = 0;

    count += old.ptr[up*old.cols+left]&0x01;
    count += old.ptr[up*old.cols+column]&0x01;
    count += old.ptr[up*old.cols+right]&0x01;
    count += old.ptr[row*old.cols+left]&0x01;
    count += old.ptr[row*old.cols+right]&0x01;
    count += old.ptr[down*old.cols+left]&0x01;
    count += old.ptr[down*old.cols+column]&0x01;
    count += old.ptr[down*old.cols+right]&0x01;

    current.ptr[row*old.cols+column] = 0x00;
    if(old.ptr[row*old.cols+column]&0x01)
    {
        if((count==3)||(count==2))
            current.ptr[row*old.cols+column] = 0x01;
    }
    else
    {
        if(count==3)
            current.ptr[row*old.cols+column] = 0x01;
    }
}
