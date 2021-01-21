// Two way measuring time: 12 hours time and 24 hour time is known as civilian and
// military time. Define two classes Time-12 and Time-24 to represent time.
// Include a conversion routine to convert from Time-24 to Time-12.
#include <iostream>
#include <string>
using namespace std;
class Time_12
{
    int hr, min, sec;
    char ch;

public:
    void getTime()
    {
        cout << "Enter hours ";
        cin >> hr;
        cout << "Enter minutes ";
        cin >> min;
        cout << "Enter seconds ";
        cin >> sec;
        cout << "AM or PM ";
        cin >>ch;
    }
    void ConvertTo24()
    {
        if ((ch=='A' || ch=='a' ) && hr==12)
        {
            hr = 00;
        }
        else
        {
            hr+=12;
        }
    };
    void DisplayTime()
    {
        cout << "Convert time in 12 is " << endl;
        cout << hr << " hr : " << min << " min : " << sec << " sec  " << endl;
    };
};

class Time_24
{
    int hr, min, sec;
    string decide;

public:
    void getTime()
    {
        cout << "Enter hours ";
        cin >> hr;
        cout << "Enter minutes ";
        cin >> min;
        cout << "Enter seconds ";
        cin >> sec;
    }
    void ConvertTo12()
    {
        if (hr == 0)
        {
            hr = 12;
            decide = "am";
        }
        else
        {
            decide =( hr >= 12) ? "pm" : "am";
            decide == "am" ? (hr = hr) : (hr -= 12);
        }
    };
    void DisplayTime()
    {
        cout << "Convert time in 12 is " << endl;
        cout << hr << " hr : " << min << " min : " << sec << " sec  " << decide << endl;
    };
};

int main()
{
    Time_24 time24;
    Time_12 time12;
    cout << "For time 24 " << endl;
    time24.getTime();
    time24.ConvertTo12();
    time24.DisplayTime();
    cout << "For time 12 " << endl;
    time12.getTime();
    time12.ConvertTo24();
    time12.DisplayTime();
}