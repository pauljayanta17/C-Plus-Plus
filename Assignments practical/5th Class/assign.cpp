// 1. Write a class to represent an integer array. Include member functions to perform the
// following tasks:
//     1. Initialize the array.
//     2. Display the values of array.
//     3. Find the minimum element of the array.
//     4. Find the maximum element of the array.

// Write a main program to test your class. Use switch case in main so that user can select his
// desired function.

//#include<iostream>
//using namespace std;
//#define SIZE 20
//class array_elements
//{
//    int array[SIZE],no=0;
//    public:
//        void initializing();
//        void display();
//        void minimum();
//        void maximum();
//};
//
//void array_elements :: initializing(){
//    cout << "How many elements do you want to enter ?"<<endl;
//    cin >> no;
//    cout << "Enter the numbers one by one "<<endl;
//    for (int i=0;i<no;i++)
//    {   
//        cin >> array[i];
//    }
//}
//
//void array_elements :: display(){
//    if(no==0){
//        cout << "Sorry data not found"<<endl;
//        exit(0);
//    }
//    cout << "The numbers are "<<endl;
//    for (int i=0;i<no;i++)
//    {   
//        cout << array[i] << endl;
//    }
//}
//
//void array_elements :: minimum(){
//    if(no==0){
//        cout << "Sorry data not found"<<endl;
//        exit(0);
//    }
//    int MIN=32767;
//    for(int i=0;i<no;i++)
//    {
//        if(array[i]<MIN)
//        {
//            MIN=array[i];
//        }
//    }
//    cout << "Minimum value is " <<MIN<<endl;
//}
//
//void array_elements :: maximum(){
//    if(no==0){
//        cout << "Sorry data not found"<<endl;
//        exit(0);
//    }
//    int MAX=-32768;
//    for(int i=0;i<no;i++)
//    {
//        if(array[i]>MAX)
//        {
//            MAX=array[i];
//        }
//    }
//    cout << "Maximum value is " <<MAX<<endl;
//}
//
//int main()
//{
//    array_elements a1;
//    int ch;
//    char choice;
//    do{
//    cout << "1. Initializing array \n2. Display Values\n3.Minimum Value\n4.Maximum Value "<<endl;
//    cout << "Enter Your choice "<<endl;
//    cin >> ch;
//    switch (ch)
//    {
//    case 1 : a1.initializing();
//           break;
//    case 2 : a1.display();
//            break;
//    case 3: a1.minimum();
//            break;
//    case 4: a1.maximum();
//            break;
//    default:
//        cout << "Wrong Input\n Enter a correct input "<<endl;
//        cout << "1. Initializing array \n2. Display Values\n3.Minimum Value\n4.Maximum Value "<<endl;
//        cout << "Enter Your choice "<<endl;
//        cin >> ch;
//        break;
//    }
//    cout << "Do you perform this again ?\n Type y/n"<<endl;
//    cin >> choice;
//    }
//    while(choice=='y' || choice =='Y');
//    cout << "Bye";
//    return 0;
//}









// // 2. Write a c++ program to create a class for employee to get and print details(Name, Age) of N
// // employees.

// #include<iostream>
// using namespace std;
 
// class employee{
//     string name;
//     int age;

//     public:
//         void get_data();
//         void put_data();
// };

// void employee :: get_data()
// {	
// 	cin.ignore(20,'\n');
//     cout << "Employee name ";
//     getline(cin,name);
//     //This method get two arguments First one is total numbers of numericals and second one is new line
//     // used to ignore or clear one or more characters from the input buffer
//     cout << "Employee age ";
//     cin >> age;
// }

// void employee :: put_data()
// {
//     cout << "Employee name  " << name <<endl;
//     cout << "Employee age  " <<age <<endl;
// }

// int main()
// {
//     int e_no;
//     cout << "How many employee do you want to create ";
//     cin >> e_no;
//     employee emp[e_no];
//     for (int i=0;i<e_no;i++)
//     {
//         cout << "Details for employee "<<i+1<<endl;
//         emp[i].get_data();
//     }
//     cout << "The given details of employees are " <<endl;
//     for (int i=0;i<e_no;i++)
//     {
//         emp[i].put_data();
//     }
//     return 0;
// }













//#include <iostream>
//#include <string> 
//using namespace std;
//class employee
//{
//  private :
//    int age;
//    char name[30];
//    
//  public :
//    void get_Data()
//    {
//      cout << "\nEnter Employee Name:\n";
//      cin >> name;
//      cin.ignore (20, '\n');
//      cout << "\nEnter Employee Age:\n";
//      cin >> age;
//    }
//    
//    void show_Data()
//    {
//      cout << "\n***********************_*\n\n ";
//      cout << "\nEmployee Name Is :\t"<<name<<"\n\n ";
//      cout << "\nEmployee Age Is :\t"<< age <<"\n";
//      cout << "\n***********************_*\n ";
//    }
//};
//
//
//    
//int main()
//{
//  employee e[40];
//  
//  int i, n;
//  
//  cout << "\nEnter Number Of Employees:\n";
//  
//  cin >> n;
//  
//  for( i=0; i<n; i++ )
//  {
//    e[i].get_Data();
//  }
//  
//  for ( i=0; i<n; i++ )
//  {
//    e[i].show_Data();
//  }
//  
//}

// New assignment attach this assignments to the previous one/////////////




// Write a c++ program for addition of two private members of two different classes.

// #include<iostream>
// using namespace std;
// class B;
// class A
// {
//     double num1;
//     public:
//         void getnum1()
//         {
//             cout << "Enter a number ";
//             cin >> num1;
//         };
//         friend void Friend(A,B);
// };

// class B
// {
//     double num2;
//     public:
//         void getnum2()
//         {
//             cout << "Enter another number ";
//             cin >> num2;
//         };
//         friend void Friend(A,B);
// };

// void Friend(A a1,B b1)
// {
//     cout << "The sum of " <<a1.num1 <<" and " << b1.num2 <<" is ";
//     cout << a1.num1 + b1.num2 <<endl;
// }


// int main()
// {
//     A aa;
//     aa.getnum1();
//     B bb;
//     bb.getnum2();
//     Friend(aa,bb);
// }



    // Design a class Time containing two members hours and minutes and the following
    // member functions:a) To read time b) To display time
    // c) To get the sum of two times passed as argument

#include<iostream>
using namespace std;

class TimeContaining
{
    int minute,hours;
    public:
        int h(){return hours;};
        int m(){return minute;};
        void getminute();
        void gethour();
        void display();
        void sumTime(int h1,int m1,int h2,int m2);
};

void TimeContaining :: getminute()
{
    cout << "Enter minute ";
    cin >> minute;
}

void TimeContaining :: gethour()
{
    cout << "Enter Hour ";
    cin >> hours;
}

void TimeContaining :: display()
{
    cout << "The Given time is " << hours << " : " <<minute<<endl;
}

void TimeContaining :: sumTime(int h1,int m1,int h2,int m2)
{
    int temp=0;
    cout << "Total time is "<<endl;
    m1=m1+m2;
    h1=h1+h2;
    temp=m1/60;
    m1 = m1%60;
    h1=h1+temp;
    cout << h1 << " : " << m1<<endl;
}


int main()
{
    TimeContaining t1,t2,t3;
    int m1,m2,h1,h2;
    int c; 
    char ch;
    do 
    {
        cout << "1. Input Time\n2. Display Time\n3. Sum of two times"<<endl;
        cout << "Enter Your choice "<<endl;
        cin >> c;
         switch(c)
    {
        case 1:
            cout << "For Time 1" <<endl;
            t1.gethour();
            t1.getminute();
            cout << "For Time 2"<<endl;
            t2.gethour();
            t2.getminute();
            m1=t1.m();
            m2=t2.m();
            h1=t1.h();
            h2=t2.h();
            break;
        case 2:
            t1.display();
            t2.display();
            break;
        case 3:
            t1.sumTime(h1,m1,h2,m2);
            break;
    }
    cout << "Perform this again y/n   ";
    cin >>ch;
    }while(ch=='y' || ch=='Y');
    

}   