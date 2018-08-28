#include <iostream>
#include "src/SimpleLife.hpp"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    SimpleLife life(1024, 768);
    life.sim(100);

    return 0;
}
