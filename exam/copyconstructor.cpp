#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class copyConstructor{
    int num1,num2,result;
    public:
    copyConstructor(int a,int b){
        num1=a;
        num2=b;
    }
    copyConstructor(copyConstructor & copy){
        num1=copy.num1;
        num2=copy.num2;
    }
    void calculateSum(){
        result = num1+num2;
    };
    void printData(){
        cout << "The sum of "<<num1 << "  and "<<num2 <<" is "<<result;
    };
};

int main()
{
    copyConstructor C(100,200);
    copyConstructor A(C);
    C.calculateSum();
    C.printData();
    return 0;
}