#include<iostream>
using namespace std;

int fibbonaicciseries(int n)
{
    if(n<=1)
    {
        return 1;
    }
    return fibbonaicciseries(n-1) + fibbonaicciseries(n-2);
}

int main()
{
    int number;
    cout << "Give a position to find Fibbonicci series " << endl;
    cin >> number ;
    cout << "The nth term is " << fibbonaicciseries(number) << endl;

}


