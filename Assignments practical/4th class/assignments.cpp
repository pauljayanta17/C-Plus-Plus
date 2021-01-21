// //1. Write a C++ Program to display the following output using a single cout statement
// #include<iostream>
// using namespace std;
// int main()
// {
//     cout << "Subject        " << "Marks" <<endl<<"Mathematics   "<<"90"<<endl<<"Computer      "<<"77"<<endl<<"Chemistry     "<<"69"<<endl;
//     return 0;
// }


// // 2.Write a C++ program to check whether the given number is even or odd(using ?: ternary operator)
// #include<iostream>
// using namespace std;
// int main()
// {
//     int num;
//     cout << "Enter a number to check it's Even or Odd ? "<<endl;
//     cin >> num;
//     cout << num <<" is " << (num%2==0?"Even":"Odd")<< endl;
//     return 0;
// }


// // 3.Write a C++ program to swap value of two variables without using third variable.
// #include<iostream>
// using namespace std;
// int main()
// {
//     int num1,num2,temp;
//     cout << "Enter first number ";
//     cin >>num1;
//     cout << "Enter second number ";
//     cin >> num2;
//     num1=num1*num2;
//     num2=num1/num2;
//     num1=num1/num2;
//     cout << "After swap the values are \nFirst number " << num1 << "\nSecond number " << num2;
//     return 0;
// }


// // 4.Write a C++ program which accepts days as integer and display total number of years, months and days in it.
// // for example : If user input as 856 days the output should be 2 years 4 months 6 days.
// #include<iostream>
// using namespace std;
// int main()
// {   
//     int number,year=0,month=0,day=0;
//     cout <<"Enter a whole number "<<endl;
//     cin >> number;
//     if(number>=365)
//     {
//         year=number/365;
//         number=number%365;
//         if(number>30)
//         {
//             month=number/30;
//             day=number%30;
//         }
//         else{
//             day=number;
//         }
//         cout << year <<" Year "<<month<< " Month "<< day <<" Day "<<endl;

//     }
//     else if(number<365 && number>=30)
//     {
//         month=number/30;
//         day=number%30;
//         cout << month << " Month "<< day << " Day "<<endl;
//     }
//     else
//     {
//         day=number;
//         cout <<" Day is " <<day<<endl;
//     }
    
//     return 0;
// }


// // 5.Write a C++ program to calculate the total expenses. Quantity and price per
// // item are input by the user and discount of 10% is offered if the expense is
// // more than 5000

// #include<iostream>
// using namespace std;
// int main()
// {
//     double price,net_amount;
//     int quantity;
//     cout << "How much expense of the item?"<<endl;
//     cin >> price;
//     cout << "What is the quantity of the item ?"<<endl;
//     cin >> quantity;
//     net_amount = (price>5000)? price - ((price*10*quantity)/100):(price*quantity);
//     cout << "Total Expense is  "<<net_amount;
//     return 0;
// }


// 6. In a company an employee is paid as under:
// If his basic salary is less than Rs. 1500, then HRA = 10% of basic
// salary and DA = 90% of basic salary.
// If his salary is either equal to or above Rs. 1500, then HRA = Rs.
// 500 and DA = 98% of basic salary.
// If the employee's salary is input by the user write a C++ program to find his
// gross salary.

// #include<iostream>
// using namespace std;
// int main()
// {
//     double basic,HRA,DA,gross;
//     cout << "Give basic salary of employee " <<endl;
//     cin >> basic;
//     if(basic>=1500)
//     {
//         HRA = 500;
//         DA = basic * 98/100;
//         gross = basic + DA + HRA;
//     }
//     else if(basic<1500)
//     {
//         HRA = basic * 10/100;
//         DA = basic * 90/100;
//         gross = basic + DA + HRA;
//     }
//     cout << "Gross salary of the employee is "<< gross;
//  return 0;
// }   



// 7.Write a C++ program to find the roots of and quadratic equation of type
// ax2+bx+c where a is not equal to zero.
// #include<iostream>
// #include<math.h>
// using namespace std;
// int main()
// {
//     int a,b,xpos,xneg,c;
//     cout << "Please give the value of the cofficients of x"<< endl<<"Like a,b,c "<<endl<<"For this equation ax2+bx+c to find its roots"<<endl;
//     cout << "a is "<<endl;
//     cin >>a ;
//     cout << "b is "<<endl;
//     cin >> b;
//     cout << "c is "<< endl;
//     cin >> c;
//     if(((b*b)-(4*a*c))<0)
//     {
//         cout << "Roots are imaginary"<<endl;
//     }
//     else
//     {
//     xpos=(-b+sqrt(((b*b)-(4*a*c))))/2*a;
//     cout << "Positive root is "<<xpos<<endl;
//     xneg=(-b-sqrt(b*b-4*a*c))/2*a;
//     cout << "Negative root is "<<xneg;
//     }
    
//     return 0;
// }   





// 8.Any character is entered by the user; write a C++ program to determine
// whether the character entered is a capital letter, a small case letter, a digit or
// a special symbol. The following table shows the range of ASCII values for
// various characters.

// #include<iostream>
// using namespace std;
// int main()
// {
//     char a;
//     cout << "Enter a charcter " << endl;
//     cin >> a;
//     if(a>=65 && a<=90)
//     {
//         cout << "This is From A to Z " << endl<<"ASCII value is from 65 to 90"<<endl;
//          cout << "You enter capital letters"; 
//     }
//     else if(a>=97 && a<=122)
//     {
//         cout << "This is From a to z " << endl<<"ASCII value is from 97 to 122"<< endl;
//          cout << "You enter small case letters";
//     }
//     else if(a>=48 && a<=57)
//     {
//         cout << "This is From 0 to 9 " << endl<<"ASCII value is from 48 to 57"<<endl;
//          cout << "You enter digits ";
//     }
//     else
//     {
//         cout << "You enter Special simbols";
//     }
//  return 0;
// }



// 9.Write a C++ program to compute the cosine of x. The user should supply x
// and a positive integer n. We compute the cosine of x using the series and the
// computation should use all terms in the series up through the term involving
// x^n.

// #include<iostream>
// using namespace std;
// int fact(int a)
// {
//     if(a>1)
//     {
//        return a * fact(a - 1);
//     }
//     return 1;
// }
// double power(double a,double b)
// {
//     double k=1;
//     while(b>0)
//     {
//         k=k*a;
//         b--;
//     }
//     return k;
// }
// int main()
// {
//     int n;
//     double x,value;
//     cout << "To find the cos series input the values of n and x "<< endl;
//     cout << "X  is " <<endl;
//     cin >> x;
//     cout << "n is (should be positive integer) " << endl;
//     cin >>n;
//     if(n > 0)
//     {
//         value = (power(-1,n) * power(x,2*n))/fact(2*n);
//     }
//     cout << "The seris value of COSx is "<< value <<endl;
//     return 0;
// }


