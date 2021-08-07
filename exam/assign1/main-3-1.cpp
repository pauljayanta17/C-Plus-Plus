#include<iostream>
#include"function-3-1edi.cpp"
using namespace std;
int main(){
    int customer[10],i=0,total=0;
    double amount;
    while(i<10){
        cout << "customer "<<i+1<< " amount "<<endl;
        cin >> amount;
        total+=amount;
        i++;
    }
    cout << "The total amount is "<<total;
    
    return 0;
}