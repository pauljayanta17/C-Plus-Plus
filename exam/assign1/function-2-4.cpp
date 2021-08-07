#include<iostream>
using namespace std;


int sum_min_and_max(int array_of_integers[], int array_length);
int max_integer(int array_of_integers[], int array_length);
int min_integer(int array_of_integers[], int array_length);

int sum_min_and_max(int array_of_integers[], int array_length)
{
   int x = max_integer(array_of_integers, array_length);
   int y = min_integer(array_of_integers, array_length); 
   return x+y;
  
}
//max finding function
int max_integer(int array_of_integers[], int array_length) {
   int high = array_of_integers[0], i=0;
   while (i < array_length) {
       if (array_of_integers[i] > high) {
           high = array_of_integers[i];
       }
       i++;
   }
   return high;
}
//min finding function
int min_integer(int array_of_integers[], int array_length) {
   int high = array_of_integers[0], i=0;
   while (i < array_length ) {
       if (array_of_integers[i] < high) {
           high = array_of_integers[i];
       }
       i++;
   }
   return high;
}
