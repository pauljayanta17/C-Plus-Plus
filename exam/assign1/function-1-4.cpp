#include <iostream>
using namespace std;

class matrix
{
    public:

    void print_scaled_matrix(int arr_x[3][3], int scale)
    {
        int var_a=0, var_b=0;

        while(var_a<3)
        {
            while(var_b<3)
            {
                arr_x[var_a][var_b] *= 3;
                var_b++;
            }
            var_b=0;
            var_a++;
        }

        cout<<"The resultant matrix is"<<endl;
        int x=0, y=0;

        var_a=0;var_b=0;
        while(var_a<3)
        {
            while(var_b<3)
            {
                cout<<arr_x[var_a][var_b]<<" ";
                var_b++;
            }

            cout<<"\n";
            var_b=0;
             var_a++;
        }
        var_a=0;var_b=0;
    }

};


