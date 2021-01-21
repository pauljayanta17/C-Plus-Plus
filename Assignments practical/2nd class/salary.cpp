//Salary ////////////////////////////////////////////////////
#include<iostream>
using namespace std;
int main()
{
    double salary,bonus,total_salary;
    int years;
    const int bonus_rate=5;
    cout << "Employee salary amount " << endl;
    cin >> salary;
    cout << "Employee experiences in years " << endl;
    cin >> years;
    if(years>5)
    {
        bonus=salary*bonus_rate/100;
        total_salary=salary+bonus;
        cout << "Employee salary is " << total_salary << endl;
        cout << "Employee Bonus is " << bonus;
    }
    else
    {
        cout << "Employee salary is " << salary <<endl;
        cout << "Can not give you Bonus";
    }
}