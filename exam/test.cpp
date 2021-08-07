#include<iostream>
using namespace std;

int main()
{
    int n1, my_item1 = 0,my_item2 = 0,my_item3 = 0, num, total,i ;
    cout<<"Please enter the total number of items sold: ";
    cin>>n1;

    for(i=0;i<n1;i++)
    {
        cin>>num;
        cin>>total;
        if(num == 1)
            my_item1+=total;
        else if (num == 2)
            my_item2+=total;
        else if (num == 3)
            my_item3+=total;
    }

    cout<<"Total sales of item 1 is "<<my_item1<<endl;
    cout<<"Total sales of item 2 is "<<my_item2<<endl;
    cout<<"Total sales of item 3 is "<<my_item3<<endl;

    if(my_item1 < my_item2 && my_item1 < my_item3)
        cout<<"Item 1 has least sales"<<endl;
    else if(my_item2 < my_item3 && my_item2 < my_item1)
        cout<<"Item 2 has least sales"<<endl;
    else
        cout<<"Item 3 has least sales"<<endl;

        if (my_item1 > my_item2)
    {
        if (my_item1 > my_item3)
            cout<<"Item 1 has most sales"<<endl;
        else
            cout<<"Item 3 has most sales"<<endl;
    }

    else if (my_item2 > my_item3)
        cout<<"Item 2 has most sales"<<endl;
    else
        cout<<"Item 3 has most sales"<<endl;

    return 0;

}