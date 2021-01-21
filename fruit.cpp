#include <iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class items
{
    double price,total;
    char name[20];
    int quantity;
    public:
        void get_price_of_fruits();
        void display_price_of_fruits();
        void get_fruit_name();
        void display_fruit_name();
        void get_quantity();
        void display_per_price();
        void display_quantity();
};

void items :: get_fruit_name()
{
    cout << "Fruit name " << endl;
    cin >> name;

}

void items :: get_price_of_fruits()
{
    cout << "Fruit price " << endl;
    cin >> price;
}

void items :: get_quantity()
{
    cout << "Quantity  " << endl;
    cin >> quantity;
    total= price*quantity;
}

void items :: display_price_of_fruits()
{
    cout << "Total Price---- "<<endl << total <<endl;
}

void items :: display_fruit_name()
{
    cout << "\nName------   "<<name << endl;
}

void items :: display_quantity()
{
    cout << "Quantity-----  "<<quantity<<endl;
}

void items :: display_per_price()
{
    cout << "Price-----  "<<price<<endl;
}

int main() {
    items bucket[10];
    char ch;
    int n;
    cout << "------------------------Counting Buckets----------------------------- " << endl;
    cout << "No of Bucket ? " << endl;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cout << "Details for bucket  " << i+1 << endl;
        bucket[i].get_fruit_name();
        bucket[i].get_price_of_fruits();
        bucket[i].get_quantity();
    }

    // Display Bucket///////////////////////
    cout << "Want to show ? "<<endl;
    cin >> ch;
    if(ch=='y')
    {
        cout << "------------------------Display Buckets----------------------------- " << endl;
    //cout << "----Name---- ----Price(One)---- ----Quantity---- ----Total----" << endl;
    for(int i=0;i<n;i++)
    {
        bucket[i].display_fruit_name();
        bucket[i].display_per_price();
        bucket[i].display_quantity();
        bucket[i].display_price_of_fruits();
       
    }
    }

    else
    {
        cout <<"Thank You , Visit Again" << endl;
    }
    

    

}