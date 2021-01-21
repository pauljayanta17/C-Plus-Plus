// print two number ,one is constant
#include<iostream>
using namespace std;
int main()
{
    int num1,num2;
    cout << "Enter first constant number ";
    cin >>num1;
    int const num3=num1;
    cout << "Enter second number ";
    cin >> num2;
    cout << "The two numbers are " << num3 << " and " << num2;
    return 0;
}