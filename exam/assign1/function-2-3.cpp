#include <iostream>
using namespace std;

int sum_elements(int int_array[], int length_of_array);
bool is_a_palindrome(int int_array[], int length_of_array);
int sum_if_a_palindrome(int int_array[], int length_of_array);


int sum_if_a_palindrome(int int_array[], int length_of_array)
{
    if(length_of_array<=0)
    {
        return -1;
    }
    if(is_a_palindrome(int_array,length_of_array))
    {
        return sum_elements(int_array,length_of_array);
    }
    else
    {
        return -2;
    }
}


int sum_elements(int int_array[], int length_of_array)
{
    int addition = 0;
    if(length_of_array <= 0)
    {
        return -1;
    }
    else
    {
        int x=0; 
        while(x<length_of_array)
        {
            addition += int_array[x];
            x++;
        }
    }
    return addition;
}


bool is_a_palindrome(int int_array[], int length_of_array)
{
    if(length_of_array<=0)
    {
        return false;
    }
    int x=0;
    while( x<length_of_array/2)
    {
        if(int_array[x] != int_array[length_of_array-x-1])
        {
            return false;
        }
        else
        {
            return true;
        }
         x++;
    }
}