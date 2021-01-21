//Concatenation without + Operator///////////////////////////////////
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string name1,name2,str;
    int length;
    cout << "Write a string " <<endl;
    getline(cin,name1);
    cout << "Write another string "<< endl;
    getline(cin,name2);
    str=name1.append(name2);
    length=str.length();
    cout << "The given string is ------"<<endl << str << endl;
    cout << "Length of the string is " << length <<endl;
    return 0;
}