#include <iostream>
#include "function-1-1.cpp"
using namespace std;
int main()
{
    //creating sample arrays for testing  
    int sample_count[4][4] = {
        {1,0,0,0},
        {2,1,0,0},
        {0,0,1,0},
        {0,0,0,1}
        };
    //printing the sampkle run outputs

    cout<<"Output of diagonal(sample_count):: "<<diagonal(sample_count)<<endl;
    return 0;

    //end of function

}