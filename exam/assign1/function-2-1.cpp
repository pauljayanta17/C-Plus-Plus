#include<iostream>
void print_as_binary(std::string decimal_number)
{
    std::string str = "";
    int num = stoi(decimal_number);
		
    for(;num>0;)
    {
        int r = num%2;
        str += r?'1':'0';
        num = num/2;
    }
    int i=str.size()-1;
    while( i>=0){
        std::cout<<str[i];
        i--;
    }
    
    
    
    std::cout<<std::endl;

}
