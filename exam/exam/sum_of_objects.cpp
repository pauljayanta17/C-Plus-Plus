#include<iostream>
using namespace std;

template <class T>

class addObjects{
    private : 
        T item;
    public:
        addObjects(){

        };
        void set(T value){
            item =value;
        };
        void print(){
            cout << "The variable is "<<item<<endl;
        };
        addObjects operator +(const addObjects& obj){
            addObjects adobj;
            char ch;
            if(typeid(T)==typeid(ch)){
                adobj.item = 'X';
            }
            else{
                adobj.item = item + obj.item;
            }
            return adobj;
        };


};

int main(){
    return 0;
}

