#include <iostream>
#include<string>
using namespace std;

class Person{
    string name;
    char gender;
    int age;
    public:
        void read(){
            cout << "Name ";
            getline(cin,name);
            //cin.ignore(20,'\n');
            cout << "Gender ";
            cin >> gender;
            cout << "Age ";
            cin >> age;
        };
        void display(){
            cout << "Name is "<<name<<endl;
            if(gender=='M' || gender=='m'){
                cout << "Gender is Male"<<endl;
            }
            else if (gender=='f' || gender== 'F'){
                cout << "Gender is Female"<<endl;
            }
            cout << "Age "<<age<<endl;
        };

};


class Student : public Person{
    int roll_no;
    public:
        void get_roll(){
            cout << "Student roll no ";
            cin >> roll_no;
        };
        void display_roll(){
            cout << "Roll of the student is "<<roll_no<<endl;
        };
};

class Exam : public Person{
    double branch_marks;
    public:
        void get_marks(){
            cout << "Enter the marks of the student ";
            cin >>branch_marks;
        };
        void display_marks(){
            cout << "Marks of the student is "<<branch_marks;
        }
};

int main()
{
    Student student;
    Exam exam;
    cout << "Enter the all information about student "<<endl;
    student.read();
    student.get_roll();
    cout << "Give the exam details "<<endl;
    exam.get_marks();
    cout << "The details of the student is "<<endl;
    student.display();
    student.display_roll();
    exam.display_marks();
    return 0;
}