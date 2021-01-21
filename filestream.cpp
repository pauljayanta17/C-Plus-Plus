#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    ofstream fout;
    string line;
    fout.open("simple.txt");
    while(fout){
        getline(cin,line);
        if(line=="-1"){
            break;
        }
        fout << line<<endl;
    }
    fout.close();

}