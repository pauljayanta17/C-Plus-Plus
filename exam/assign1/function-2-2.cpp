#include<iostream>
#include <string>
#include<cstring>
#include <cstdio>
#include<cmath>

using namespace std;
// function to convert binary to dcimal

int binary_to_number(int binary_digits[],int number_of_digits)
{
// variables declaration

long long int decimal=0;
int n=number_of_digits,i=0;

int temp=n;

// finding equivalent decimal number
while(i<n)
{
   decimal+=binary_digits[i]*pow(2,--temp);
   i++;

}
i=0;
cout<<"Decimal equivalent of given binary number: "<<decimal<<endl;

}