// Create a class Integer which contains a data member integer value and use suitable
// constructor, destructor and member functions and overload operators =, ++, -- operator.
#include <iostream>
using namespace std;

class integer
{
    int data;

public:
    integer(int a){
     data=a;  
    };
    ~integer(){}; 
    void operator ++ (){
        data++;
    };
    void operator -- (){
        data--;
    };
    void operator = (integer &i){
       
    };
    void printData(){
        cout << "Data is "<<data<<endl;
    };
};

int main()
{

    integer _interger(10);
    _interger.printData();
    --_interger;
    _interger.printData();
    ++_interger;
    _interger.printData();
    return 0;
}