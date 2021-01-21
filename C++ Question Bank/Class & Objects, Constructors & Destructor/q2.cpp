// Design a class Time containing two members { hours and minutes and the following member functions -
// (a) To read time
// (b) To display time
// (c) To get the sum of two times passed as arguments
// (d) To get the difference of two times passed as arguments
// Write a main() function to implement the class.
#include <iostream>
using namespace std;
class Time
{
    int hr, min, sec, day = 0;

public:
    void ReadTime()
    {
        cout << "Enter Hours ";
        cin >> hr;
        cout << "Enter Minutes ";
        cin >> min;
        cout << "Enter Seconds ";
        cin >> sec;
    };
    void DisplayTime()
    {
        cout << "The time is " << endl;
        if (day == 0)
        {
            cout << hr << " hr : " << min << " min : " << sec << " sec" << endl;
        }
        else
        {
            cout << day << " days : " << hr << " hr : " << min << " min : " << sec << " sec" << endl;
        }
    };
    void SumTime(Time t1, Time t2)
    {
        hr = t1.hr + t2.hr;
        min = t1.min + t2.min;
        sec = t1.sec + t2.sec;
        while (sec >= 60)
        {
            sec -= 60;
            min += 1;
        };
        while (min >= 60)
        {
            min -= 60;
            hr += 1;
        };
        while (hr >= 24)
        {
            hr -= 24;
            day += 1;
        };
    };
    void DifferenceTime(Time t1, Time t2)
    {
        hr = t1.hr - t2.hr;
        min = t1.min - t2.min;
        sec = t1.sec - t2.sec;
        hr = abs(hr);
        min = abs(min);
        sec = abs(sec);
        while (sec >= 60)
        {
            sec -= 60;
            min += 1;
        };
        while (min >= 60)
        {
            min -= 60;
            hr += 1;
        };
        while (hr >= 24)
        {
            hr -= 24;
            day += 1;
        };
    };
};

int main()
{
    Time time1, time2;
    cout << "For Time 1" << endl;
    time1.ReadTime();
    cout << "For Time 2" << endl;
    time2.ReadTime();
    cout << "The entire time is " << endl;
    time1.DisplayTime();
    time2.DisplayTime();
    cout << "Sum of two times is " << endl;
    time1.SumTime(time1, time2);
    time1.DisplayTime();
    cout << "Difference of two times is " << endl;
    time1.DifferenceTime(time1, time2);
    time1.DisplayTime();
}