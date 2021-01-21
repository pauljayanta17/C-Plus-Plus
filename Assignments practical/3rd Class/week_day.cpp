// Take integer number from 1 to 7 and print day according the number.
// Exp: enter number: 6
// Today is friday


#include<iostream>
#include<string>
using namespace std;
int main()
{
    int num;
    cout << "Give a number from 1 to 7 "<<endl;
    cin >> num;
    switch(num)
    {
        case 1:
            cout << "Today is Sunday " << endl;
            break;
        case 2:
            cout << "Today is Monday " << endl;
            break;
        case 3:
            cout << "Today is Tuesday " << endl;
            break;
        case 4:
            cout << "Today is Wednesday " << endl;
            break;
        case 5:
            cout << "Today is Thursday " << endl;
            break;
        case 6:
            cout << "Today is Friday " << endl;
            break;
        case 7:
            cout << "Today is Saturday " << endl;
            break;
        default:
            cout << "Wrong Input"<<endl;
            break;
    }
    return 0;
}