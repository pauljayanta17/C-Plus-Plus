#include <iostream>
#include "function-1-5.cpp"
using namespace std;


int main()
{
    matrix new_object;

    int first_matrix[3][3] = {
        {0,1,2},
        {3,4,5},
        {6,7,8}
        };

    int second_matrix[3][3] = {
        {0,0,0},
        {2,2,2},
        {-5,-4,8}
        };

    new_object.print_summed_matrices(first_matrix, second_matrix);
    return 0;

}