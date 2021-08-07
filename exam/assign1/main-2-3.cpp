#include <iostream>
#include "function-2-3.cpp"
using namespace std;

int main()
{
    int array_length;
    cout<<"Enter length : ";
    cin>>array_length;

    int array_1[array_length];
    if(array_length>1)
    {
        cout<<"Enter "<<array_length<<" elements : ";
        int x=0;
        while(x<array_length)
        {
            cin>>array_1[x];
             x++;
        }
    }
    cout<<sum_if_a_palindrome(array_1, array_length);
    return 0;
}