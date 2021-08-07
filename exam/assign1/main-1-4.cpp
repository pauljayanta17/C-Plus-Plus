#include <iostream>
#include "function-1-4.cpp"
using namespace std;

int main()
{
    matrix one_object;
    int scale = 3;
    int matrix_3_3[3][3] = {
        {0,1,2},
        {3,4,5},
        {6,7,8}
        };

    one_object.print_scaled_matrix(matrix_3_3, scale);
    
    return 0;
}