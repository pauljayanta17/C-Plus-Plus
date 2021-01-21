// Grading system//////////////////////////////////////
#include<iostream>
using namespace std;
int main()
{
    int marks;
    char grade;
    cout << "Enter the student's marks to show Grade " << endl;
    cin >> marks;
    cout << "Grade is ";
    if(marks > 80)
    {
        cout << "A";
    }
    else if(marks>=60)
    {
         cout << "B";    
    }
    else if(marks>=50)
    {
         cout << "C";    
    }
    else if(marks>=45)
    {
         cout << "D";    
    }
    else if(marks>=25)
    {
         cout << "E";    
    }
    else
    {
        cout << "F";
    }
    return 0;
    
}