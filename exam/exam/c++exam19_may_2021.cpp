#include<iostream>
using namespace std;

template <class T1,class T2>

class sumTwoNumbers{
    private : T1 num1;T2 num2;
    public: sumTwoNumbers(T1 n1,T2 n2){
        num1=n1;
        num2=n2;
    }
    void display_numbers(){
        cout << "Your numbers are "<<num1<< " and "<<num2<<endl;
    }

};

int main(){
    int su = 100;
    float s = 100.09;
    double s1= 200.99882;
    char cha = 'J';
    sumTwoNumbers<int,int>sum(10,10);
    sum.display_numbers();
    const type_info& t1 = typeid(su);
    cout << "Type is ";
    return 0;
}