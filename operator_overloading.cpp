#include<iostream>
using namespace std;

class complex
{
    private:
        int real,img;
    public:
        complex (int r=0,int i=0)
        {
            real=r;
            img=i;
        }
        friend complex operator +(complex const &,complex const &);
        void print()
        {
            cout <<real<<" + "<<img<<"i";
        }
};
complex operator +(complex const &obj1,complex const &obj2)
        {
            complex res;
            res.real = obj1.real + obj2.real;
            res.img = obj1.img + obj2.img;
            return res; 
        }

int main()
{
    complex c1(10,5),c2(20,10);
    complex c3=c1+c2;
    c3.print();
    return 0;
}