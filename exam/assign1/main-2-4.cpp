#include<iostream>
#include "function-2-4.cpp"
using namespace std;
int main()
{
    int array1[] = { 5,6,10,1,2 };
    cout << "Sum of maximum and minimum value of the integerarray is = " << sum_min_and_max(array1, 5)<<endl;
    return 0;
}