#include<iostream>
#include<math.h>
using namespace std;
class shape
{
    public:
        void volume(double a, double b);
        void volume(double a);
        void volume(double a,double b, double c);
       
};
void shape :: volume(double a, double b)
{
    cout << "Area of the rectangle is " << a*b<<endl;
}
void shape :: volume(double a)
{
    cout << "Area of the square is " << a*a<<endl;
}
void shape :: volume(double a,double b, double c)
{
    cout << "Area of the Box is " << a*b*c<<endl;
}
int main()
{
    shape s;
    double l,h,w;
    int ch;
    cout << "Volume for\n1.Rectangel\n2.Square\n3.Box\n";
    cout<<"Enter Your choice "<<endl;
    cin >> ch;
    switch (ch)
    {
    case 1:
        cout << "Enter Length "<<endl;
        cin >> l;
        cout << "Enter Breadth "<<endl;
        cin >> w;
        s. volume(l,w);
        break;
     case 2:
        cout << "Enter Length "<<endl;
        cin >> l;
        s.volume(l);
        break;
     case 3:
        cout << "Enter Length "<<endl;
        cin >> l;
        cout << "Enter breadth "<<endl;
        cin >> w;
        cout << "Enter height "<<endl;
        cin >> h;
        s.volume(l,w,h);
        break;
    default:
        break;
    }

    return 0;
}