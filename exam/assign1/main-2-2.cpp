#include<iostream>
#include <string>
#include<cstring>
#include <cstdio>
#include<cmath>
#include"function-2-2.cpp"
using namespace std;


// main function

int main()
{

int n;
int i=0;
// array declaration
int binary_number[31],digit=-1;

cout<<"enter Binary number to convert into decimal : ";

// char string declaration
char str[31];
cin>>str;

// finding string length
n=strlen(str);

cout<<"\nnumber of digit: "<<n<<endl;

// converting to int digit by substracting 48 from ascii value
while(i<n)
{
binary_number[i]=str[i]-48;
cout<<binary_number[i]<<" ";
i++;
}
cout<<endl;

// function calling

binary_to_number(binary_number,n);

// returning from main function
return 0;

}
