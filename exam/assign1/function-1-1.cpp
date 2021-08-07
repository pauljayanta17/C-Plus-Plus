#include <iostream>
using namespace std;

int diagonal(int array[4][4])
{
    int addition=0, x=0;

    while(x<4)
    {
        addition += array[x][x];
        x++;
    }

    return addition;
}

