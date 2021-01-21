// 1) Create a class Box and initialized its object using Constructor. Calculate area,
// volume of the box using suitable member function.
// #include<iostream>
// using namespace std;
// class Box
// {
//     double L,H,W;
//     public:
//         Box(double ,double,double);
//         void area();
//         void volume();
// };

// Box :: Box(double a, double b, double c)
// {
//     L=a;
//     H=b;
//     W=c;
// }

// void Box :: area()
// {
//     cout << "The Area of the Box is  " << L*H*W <<endl;
// }

// void Box :: volume()
// {
//     cout << "The volume of the Box is  " << (2*(H * W) + 2*(H * L) + 2*(W * L)) <<endl;
// }
// int main()
// {
//     double l,h,w;
//     cout << "For the Box " <<endl;
//     cout << "Enter Length "<<endl;
//     cin >> l;
//     cout << "Enter height "<<endl;
//     cin >> h;
//     cout << "Enter width "<<endl;
//     cin >> w;
//     Box b1 = Box(l,h,w);
//     b1.area();
//     b1.volume();
//     return 0;
// }



// 2) Create a class person with data members as name, address and phone number. Initialize
// them dynamically using appropriate constructors. Use member function show_name,
// show_address, and show_phone_no to display the content. Also use destructor to clean
// up the memory.

// #include<iostream>
// using namespace std;

// class Person
// {
//     private:
//         string name,address,phone;
//     public:
//         Person(){};
//         ~Person(){};
//         Person(string n,string a, string p);
//         void showName();
//         void showAddress();
//         void showPhone();
// };

// Person :: Person(string n,string a, string p)
// {
//     name = n;
//     address = a;
//     phone = p;
// }


// void Person :: showName()
// {
//     cout << "Person Name is " << name<<endl;
// }
// void Person :: showAddress()
// {
//     cout << "Person Address is " << address<<endl;
// }
// void Person :: showPhone()
// {
//     cout << "Person Phone no is " << phone <<endl;
// }

// int main()
// {
//     string name,add,phone,n;
//     int no;
//     cout << "How many person do you want to enter ?"<<endl;
//     cin >> no;
//     Person p[no];
//     getline(cin,n);
//     for(int i=0;i<no;i++)
//     {
//         cout << "For Person " <<i+1<<endl;
//         cout << "Person Name "<<endl;
//         getline(cin,name);
//         cout << "Person Address "<<endl;
//         getline(cin,add);
//         cout << "Person Phone Number "<<endl;
//         getline(cin,phone);
//         p[i] = Person(name,add,phone);
//     }
//     cout << "The Given Persons are "<<endl;
//     for(int i=0;i<no;i++)
//     {
//         cout << "For Person " <<i+1<<endl;
//         p[i].showName();
//         p[i].showAddress();
//         p[i].showPhone();
//         p[i] = Person();
//     }


//     return 0;
// }



// 3) Create a Triangle class consisting of 3 pairs of (x,y) coordinates.Use appropriate
// constructors &amp; destructor. Write a function to check whether a triangle is equilateral/
// isosceles/ scalene.

#include<iostream>
#include<math.h>
using namespace std;

class Triangle
{
    double x1,y1,x2,y2,x3,y3;
    public:
        Triangle(){};
        ~Triangle(){};
        Triangle(double a1, double b1,double a2, double b2,double a3, double b3);
        void checkTriangle();
};

Triangle :: Triangle(double a1, double b1,double a2, double b2,double a3, double b3)
{
    x1=a1;
    y1=b1;
    x2=a2;
    y2=b2;
    x3=a3;
    y3=b3;
}

void Triangle :: checkTriangle()
{
    int l1,l2,l3;
    l1 = sqrt(  pow( (x1-x2) ,2) +  pow( (y1-y2) ,2));
    l2 = sqrt(  pow( (x1-x3) ,2) +  pow( (y1-y3) ,2));
    l3 = sqrt(  pow( (x2-x3) ,2) +  pow( (y2-y3) ,2));
    if(l1==l2==l3)
    {
        cout << "This is equilateral triangle "<<endl; 
    }
    else if(l1==l2 || l2==l3 || l1==l3)
    {
        cout << "This is isosceles triangle "<<endl; 
    }
    else
    {
       cout << "This is scalene triangle "<<endl;  
    }
    
}

int main()
{
    Triangle t;
    double x1,y1,x2,y2,x3,y3;
    cout << "Enter the value of the Triangle points(x,y)" <<endl;
    cout << "For P1(X,Y) \n x is ";
    cin >> x1;
    cout << "y is ";
    cin >> y1;
    cout << "For P2(X,Y) \n x is ";
    cin >> x2;
    cout << "y is ";
    cin >> y2;
    cout << "For P3(X,Y) \n x is ";
    cin >> x3;
    cout << "y is ";
    cin >> y3;
    t=Triangle(x1,y1,x2,y2,x3,y3);
    t.checkTriangle();
    t.~Triangle();

    return 0;
}