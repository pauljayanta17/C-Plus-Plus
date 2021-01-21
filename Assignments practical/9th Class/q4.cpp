#include <iostream>
#include <string>

using namespace std;

class Student
{
    string name,branch;
    int roll;

public:
    void get_name()
    {
        cout << "Enter name of the student ";
        cin.ignore(20,'\n');
        getline(cin, name);
    };
    void get_roll()
    {
        cout << "Enter Roll of the student ";
        cin >> roll;
    };
    void get_branch()
    {
        cout << "Stream of the student ";
        getline(cin,branch);
    };
    void display()
    {
        cout << "Name  - " << name << endl;
        cout << "Stream - " << branch << endl;
        cout << "Roll  - " << roll << endl;
    };
};

class InternamExam : public Student
{
    double imarks;

public:
    void get_imarks()
    {
        cout << "Enter internal marks of the student ";
        cin >> imarks;
    };
    void display_imarks()
    {
        cout << "Internal marks is " << imarks;
    }
};

class ExternalExam : public Student
{
    double emarks;

public:
    void get_emarks()
    {
        cout << "Enter external marks of the student ";
        cin >> emarks;
    };
    void display_emarks()
    {
        cout << "External marks is " << emarks;
    }
};

int main()
{
    InternamExam i;
    ExternalExam e;
    int ch;
    cout << "1. Internal exam \n2. External Exam "<<endl<<"Choose your option ";
    cin >>ch;
    if(ch==1){
        i.get_name();
        i.get_branch();
        i.get_roll();
        i.get_imarks();
        cout << "Student details -------------- "<<endl;
        i.display();
        i.display_imarks();
    }
    else if(ch==2){
        e.get_name();
        e.get_branch();
        e.get_roll();
        e.get_emarks();
        cout << "Student details -------------- "<<endl;
        e.display();
        e.display_emarks();
    }
    return 0;
}