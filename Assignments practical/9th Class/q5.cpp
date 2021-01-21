#include <iostream>
#include <string>
using namespace std;

class Student
{
    string name,address;
    int roll, phone_no;

public:
    void get_details()
    {
        cout << "Enter name of the student ";
        getline(cin,name);
        cout << "Enter Roll of the student ";
        cin >> roll;
        cout <<"Enter the phone number of the student ";
        cin >>phone_no;
        cout << "Enter the address of the student "<<endl;
        cin.ignore(20,'\n');
        getline(cin,address);
    };
    void display()
    {
        cout << "Name          - " << name << endl;
        cout << "Roll          - " << roll << endl;
        cout << "Phone Number  - " << phone_no << endl;
        cout << "Address -" << endl<<address<<endl;
    };
};

class First_Semester : public Student
{

public:
    double fmarks;
    void get_f_marks()
    {
        cout << "Enter 1st Semester marks of the student ";
        cin >> fmarks;
    };
    void display_f_marks()
    {
        cout << "1st Semester marks is " << fmarks<<endl;
    }
};

class Second_Semester : public Student
{

public:
    double smarks;
    void get_s_marks()
    {
        cout << "Enter 2nd Semester marks of the student ";
        cin >> smarks;
    };
    void display_s_marks()
    {
        cout << "2nd Semester marks is " << smarks<<endl;
    }
};

int main()
{
    First_Semester fs;
    Second_Semester ss;
    cout << "Enter the details of the student "<<endl;
    fs.get_details();
    fs.get_f_marks();
    ss.get_s_marks();
    cout << "Total details of the student is "<<endl;
    fs.display();
    fs.display_f_marks();
    ss.display_s_marks();
    cout << "Total marks is "<<fs.fmarks+ss.smarks<<endl;
    return 0;
}