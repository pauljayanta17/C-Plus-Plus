// Shopping Discount /////////////////////////////////////////////////
#include<iostream>
using namespace std;
int main()
{
    double amount,discount,net_value;
    const int discount_rate=10;
    cout << "Total amount of shopping " << endl;
    cin >> amount;
    if(amount>=1000)
    {
        discount=amount*discount_rate/100;
        net_value=amount-discount;
        cout << "Your net amount is " << net_value << endl;
        cout << "Your discount is " << discount;
    }
    else
    {
        cout << "Your payable amount is " << amount <<endl;
        cout << "Can not give you discount";
    }
}