#include <iostream>
using namespace std;

class matrix
{
    public:
 
    void print_summed_matrices(int first_array[3][3],int second_array[3][3])
    {
        int var_m, var_n, array_matrix[3][3];

        for(var_m=0; var_m<3; var_m++)
        {
            for(var_n=0; var_n<3; var_n++)
            {
                array_matrix[var_m][var_n] = first_array[var_m][var_n]+second_array[var_m][var_n];
            }
        }

        cout<<"The new matrix will be :\n";
        for(var_m=0; var_m<3; var_m++)
        {
            for(var_n=0; var_n<3; var_n++)
            {
                cout<<array_matrix[var_m][var_n]<<" ";
            }
            cout<<"\n";
        }
    }

};
