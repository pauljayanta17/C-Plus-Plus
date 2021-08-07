//print string 
#include<iostream>
#include<string>
using namespace std;
int main()
{

    string name;
    int l,i;
    cout << "Enter a string ";
    getline(cin,name);
    cout << "The given string is " << name<<endl;
    cout << "The reverse string is ";
    l = name.length();
    for(i=l-1;i>=0;i--){
        cout << name[i];
    }
    cout <<endl;
    cout << "The pattern is "<<endl;
    for(i=0;i<l;i++){
        for(int j=0;j<=i;j++){
            cout << name[j];
        }
        cout << endl;
    }
    return 0;
}