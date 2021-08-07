#include<iostream>
#include<string.h>

using namespace std;

int maxCount(char ch[]){
    int count=0;
    char ch1[3000];
    char ch2[3000];
    int length = string(ch).length();
    cout << length <<endl;
    for(int i=0;i<length;i++){
        for(int j=1;j<length;j++){
            ch1[i] = ch[i]+ch[j];
            cout << ch1 <<endl;
            string t=ch1;
            string temp=string(ch1);
            temp.reserve();
            if(t==temp){
                count++;
            }

        }
    }
    return count;
}

int main(){
    char ch[3000];
    int total;
    cout << "Enter a string "<<endl;
    cin >> ch;
    total = maxCount(ch);
    cout << "Total palindrom is "<<total<<endl;


}