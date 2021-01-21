// Create a class Complex which stores a complex number(a pair of real numbers) as data
// members and use suitable constructor, destructor and member functions and overload
// operators: + (using operator/friend) , - (using operator/friend), +=,=,*=.
#include <iostream>
using namespace std;

class complex
{

    int real, img;

public:
    complex(int a = 0, int b = 0)
    {
        real = a;
        img = b;
    };
    ~complex(){};
    complex operator+(complex &obj)
    {
        complex temp;
        temp.real = real + obj.real;
        temp.img = img + obj.img;
        return temp;
    };
    complex operator-(complex &obj)
    {
        complex temp;
        temp.real = real - obj.real;
        temp.img = img - obj.img;
        return temp;
    };

    void printdata()
    {
        cout << "The actual result is " << endl;
        cout << real << " + " << img << "i" << endl;
    }
};

int main()
{
    int r1, r2, i1, i2;
    cout << "For first complex number " << endl;
    cout << "Real is " << endl;
    cin >> r1;
    cout << "Imagenary is " << endl;
    cin >> i1;

    cout << "For Second complex number " << endl;
    cout << "Real is " << endl;
    cin >> r2;
    cout << "Imagenary is " << endl;
    cin >> i2;

    complex c1(r1, i1), c2(r2, i2), res;

    res = c1 + c2;
    cout << "Sum of complex numbers " << endl;
    res.printdata();
    res = c1 - c2;
    cout << "Subtract of complex numbers " << endl;
    res.printdata();
    return 0;
}