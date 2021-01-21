#include<iostream>
#include<string>
using namespace std;


class Person{
    string name;
    char gender;
    public:
        void get_data(){
            cout << "Enter Name ";
            getline(cin,name);
            cout << "Gender (M/F) ";
            cin>>gender;
        };
        void display(){
            cout << "Name is "<<name<<endl;
             if(gender=='M' || gender=='m'){
                cout << "Gender is Male"<<endl;
            }
            else if (gender=='f' || gender== 'F'){
                cout << "Gender is Female"<<endl;
            }
        };

};

class Teacher:public Person{
    int id;
    string department;
    public:
        void get_data_teacher(){
            cout << "Enter id no of teacher ";
            cin >> id;
            cout << "Which department of the teacher ?"<<endl;
            cin.ignore(20,'\n');
            getline(cin,department);
        };
        void display_teacher(){
            cout << "Id no of the teacher is "<<id<<endl;
            cout << "Department is "<<department<<endl;
        };
};

class Student : public Person{
    double marks;
    string stream;
    public:
        void get_data_student(){
            cout << "Enter the stream of the student ";
            cin.ignore(20,'\n');
            getline(cin,stream);
            cout << "Enter the marks of the student ";
            cin >> marks;
        };  
        void display_student(){
            cout << "Stream of the student is "<<stream<<endl;
            cout << "Marks of the student is "<<marks<<endl;
        };
};

int main(){
    Person p;
    Teacher t;
    Student s;
    cout << "Enter details of the student "<<endl;
    s.get_data();
    s.get_data_student();
    cout << "Enter the details of the teacher "<<endl;
    cin.ignore(20,'\n');
    t.get_data();
    t.get_data_teacher();
    cout << "All informations are -------------- "<<endl;
    cout << "For the student ----------"<<endl;
    s.display();
    s.display_student();
    cout << "For the teacher ----------"<<endl;
    t.display();
    t.display_teacher();
    return 0;
}