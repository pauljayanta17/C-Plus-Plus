
#include<iostream>
using namespace std;
int main()
{
    char a;
    cout << "Enter a charcter " << endl;
    cin >> a;
    if(a>=65 && a<=90)
    {
        cout << "This is From A to Z " << endl<<"ASCII value is from 65 to 90"<<endl;
         cout << "You enter capital letters"; 
    }
    else if(a>=97 && a<=122)
    {
        cout << "This is From a to z " << endl<<"ASCII value is from 97 to 122"<< endl;
         cout << "You enter small case letters";
    }
    else if(a>=48 && a<=57)
    {
        cout << "This is From 0 to 9 " << endl<<"ASCII value is from 48 to 57"<<endl;
         cout << "You enter digits ";
    }
    else
    {
        cout << "You enter Special simbols";
    }
 return 0;
}
