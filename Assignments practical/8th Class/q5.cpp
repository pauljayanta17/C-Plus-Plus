// Write a program to overload +, &lt;, and &gt; operators to concatenate and compare two strings
// respectively.
#include <iostream>
using namespace std;
class concatenate
{

    string str1, act;

public:
    concatenate(string a = "")
    {
        str1 = a;
    }
    concatenate operator+(concatenate &obj)
    {
        concatenate temp;
        temp.act = str1 + obj.str1;
        return temp;
    };
    concatenate operator>(concatenate &obj)
    {
        concatenate temp;
        if (str1.compare(obj.str1) == 0)
        {
            temp.act = " Equal to ";
            return temp;
        }
        else
        {
            temp.act = (str1.compare(obj.str1) < 0) ? " Greater than from " : " Less than from ";
            return temp;
        }
    };
    concatenate operator<(concatenate &obj)
    {
        concatenate temp;
        if (str1.compare(obj.str1) == 0)
        {
            temp.act = " Equal ";
            return temp;
        }
        else
        {
            temp.act = ((obj.str1).compare(str1) < 0) ? " Greater than from  " : " Less than from ";
            return temp;
        }
    };
    void printstring()
    {
        cout << act;
    }
    void showstr()
    {
        cout << str1;
    }
};

int main()
{
    string temp1, temp2;
    cout << "Enter first string " << endl;
    cin >> temp1;
    cout << "Enter second string " << endl;
    cin >> temp2;
    concatenate c1(temp1), c2(temp2), res;

    //concatenate
    res = c1 + c2;
    cout << "Concatenate string is ";
    res.printstring();

    //compaire
    cout << endl;
    c1.showstr();
    res = c1 > c2;
    cout << " is ";
    res.printstring();
    c2.showstr();
    res = c1 < c2;
    cout << endl;
    c2.showstr();
    cout << " is ";
    res.printstring();
    c1.showstr();
    return 0;
}