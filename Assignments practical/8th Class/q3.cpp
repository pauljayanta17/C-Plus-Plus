// Create a class date with data members as day month and year. Initialized them using
// constructor. Overload ++ operator to increment the date by one day (Condition of end of
// month, end of year and leap year should be preserved).
#include<iostream>
using namespace std;

class date{
    int day,month,year;
    int day_check;
    public:
        date(int a,int b,int c){
            day=a;
            month=b;
            year=c;
        }
        void operator ++(){
            day++;
        };
        void checkdate(){
            if(month==2){
                day_check = (year%4==0 || year%400==0 || year %100==0)?29:28;
            }
            else
            {
                day_check = (month%2==0) ? 30: 31;
            }
            
        }
        void showdate(){
            if(day>day_check){
                month = month+1;
                day=1;
            }
            if(month>12){
                year=year+1;
                month=1;
            }
        };
        void printdate(){
            cout << "Day is "<<day<<endl;
            cout <<"Month is "<<month<<endl;
            cout << "Year is "<<year<<endl;
        };
};

int main()
{
    int d,m,y;
    cout << "Enter day "<<endl;
    cin>>d;
    cout << "Enter month "<<endl;
    cin >>m;
    cout << "Enter year "<<endl;
    cin >>y;
    date actual(d,m,y);
    actual.checkdate();
    ++actual;
    actual.showdate();
    actual.printdate();
    return 0;
}