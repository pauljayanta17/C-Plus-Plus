//Design a calculator where the operators are +, -, *, /, squire root, round, log, max and min.

#include<iostream>
#include<cmath>
using namespace std;

double addition(double ,double);
double subtraction(double, double );
double multipication(double, double);
double division(double ,double );
double sqareroot(double );
double roundnumber(double);
double lognum(double);
void  maxnum(double,double);
void minnum(double,double);

int main()
{
    int num1,num2;
    int ch;
    char ch1;
    cout << "--------Calculator---------------------- " << endl;
    cout <<"1. Addition " <<endl;
    cout <<"2. Subtraction " <<endl;
    cout <<"3. Multipication " <<endl;
    cout <<"4. Division " <<endl;
    cout <<"5. Suare Root " <<endl;
    cout <<"6. Round of a number " <<endl;
    cout <<"7. Logx " <<endl;
    cout <<"8. Max " <<endl;
    cout <<"9. Min " <<endl;
    do
    {
         cout << "Choose Your Operation  ";
        cin >> ch;
        if(ch==5 || ch==6 || ch==7)
    {
        cout << "Enter value " << endl;
        cin >> num1;
    }
    else
    {
        cout << "Enter First Number " << endl;
        cin >> num1;
        cout << "Enter Second Number " << endl;
        cin >> num2;
    }
    switch(ch)
    {
        case 1:
            cout << num1 <<" + " << num2 << " = " << addition(num1,num2)<<endl;
            break;
        case 2:
            cout << num1 <<" - " << num2 << " = " << subtraction(num1,num2)<<endl;
            break;
        case 3:
            cout << num1 <<" x " << num2 << " = " << multipication(num1,num2)<<endl;
            break;
        case 4:
            cout << num1 <<" / " << num2 << " = " << division(num1,num2)<<endl;
            break;
        case 5:
            cout << "The sqare root of " << num1 << " is " << sqareroot(num1) << endl;
            break;
        case 6:
            cout << "The Round of " << num1 << " is " << roundnumber(num1)<<endl;
            break;
        case 7:
            cout << "log(" << num1 <<")" <<" = " << lognum(num1)<<endl;
            break;
        case 8:
            maxnum(num1,num2);
            break;
        case 9:
            minnum(num1,num2);
            break;
    }
    cout << "Again Operate (y/n) ? "<< endl;
    cin >> ch1;
    }while(ch1=='y' || ch1=='Y');
    cout << "Thank You for using this calculator"<<endl;
}

double addition(double a,double b){
    return a+b;
}
double subtraction(double a, double b){
    return a-b;
}
double multipication(double a, double b){
    return a*b;
}
double division(double a,double b){
    return a/b;
}
double sqareroot(double a){
  return sqrt(a);
}
double roundnumber(double a){
    return round(a);
}
double lognum(double a){
    return log(a);
}
void maxnum(double a,double b){
    bool dis;
    dis=(a==b)?1:0;
    if(dis==1)
    {
      cout << "Both Numbers are same" <<endl;
    }
    else
    {
        cout << "Maximum(" << a << ", "<< b <<") = " << max(a,b) <<endl;
    }
    
}
void minnum(double a,double b){
    bool dis;
    dis=(a==b)?1:0;
    if(dis==1)
    {
      cout << "Both Numbers are same" <<endl;
    }
    else
    {
        cout << "Minumum(" << a << ", "<< b <<") = " << min(a,b) <<endl;
    }
}