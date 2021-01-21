#include<iostream>
#include<string>
using namespace std;

class Publication{
    string title;
    double price;
    public:
        void get_data(string a,double b){
            title=a;
            price=b;
        };
        void display(){
            cout << "Title of the publication is "<<title<<endl;
            cout << "Price of the book is "<<price<<endl;
        };

};


class Sales{
    int id_no;
    public:
      void get_id(){
           cout << "Enter the ID no of the book  ";
           cin >> id_no;
      };
      void display_id(){
          cout << "ID no - "<<id_no<<endl;
      };
};


class Book : public Publication,public Sales{
    string name;
    int no_of_pages;
    public:
        void get_name(){
            cout << "Name of the book ";
            cin.ignore(20,'\n');
            getline(cin,name);
            cout << "Total Pages ";
            cin >> no_of_pages;
        };
        void display_name(){
            cout <<"Name of the book is "<<name<<endl;
            cout << "Total pages "<<no_of_pages<<endl;
        };
};

int main(){
    Book book;
    string pub;
    double pri;
    cout << "Enter Title of the publication ";
    getline(cin,pub);
    cout << "Enter Price ";
    cin >> pri;
    book.Publication::get_data(pub,pri);
    book.Sales::get_id();
    book.get_name();
    cout << "Details of the book is "<<endl;
    book.Publication::display();
    book.Sales::display_id();
    book.display_name();
    return 0;
}