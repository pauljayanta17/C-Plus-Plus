#include <iostream>
using namespace std;

class Date
{
    int day, month, year;

public:
    void getDate()
    {
        do
        {
            cout << "Enter Days ";
            cin >> day;
            cout << "Enter Months";
            cin >> month;
            cout << "Enter Years ";
            cin >> year;
            if (day >= 30 || month >= 12)
            {
                cout << "Enter a valid date " << endl;
            }
        } while (day >= 30 || month >= 12);
        // if (month != 2)
        // {
        //     while (day >= 30)
        //     {
        //         day -= 30;
        //         month += 1;
        //     };
        //     while (month >= 12)
        //     {
        //         month -= 12;
        //         year += 1;
        //     };
        // }
    }

    void DifferenceDate(Date d1, Date d2)
    {
        day = abs(d1.day - d2.day);
        month = abs(d1.month - d2.month);
        year = abs(d1.year - d2.year);
        while (month >= 12)
        {
            month -= 12;
            year += 1;
        };
        if (month == 2 && (year % 4 == 0 || year % 100 == 0 || year % 400 == 0))
        {
            while (day >= 28)
            {
                day -= 28;
                month += 1;
            };
            while (month >= 12)
            {
                month -= 12;
                year += 1;
            };
        }
        else
        {
            while (day >= 30)
            {
                day -= 30;
                month += 1;
            };
            while (month >= 12)
            {
                month -= 12;
                year += 1;
            };
        }
    }
    void displayDate(){
        cout << "Day is "<<day<<endl;
        cout << "Month is "<<month<<endl;
        cout << "Year is "<<year<<endl;
    }
};

int main()
{
    Date date1,date2,date;
    cout << "Enter the first date "<<endl;
    date1.getDate();
    cout << "Enter the second date "<<endl;
    date2.getDate();
    date.DifferenceDate(date1,date2);
    cout << "Difference of date is "<<endl;
    date.displayDate();
}