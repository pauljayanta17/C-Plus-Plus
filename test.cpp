// Find a string name ///////////////////////////////////////////
// #include<iostream>
// #include<string>
// using namespace std;
// int main()
// {
//     string firstname="Jayanta ";
//     string lastname="Paul";
//     string fullname=firstname+lastname;
//     int len;
//     len=firstname.length();
//     cout << "The length of " << fullname << " is " <<len-1;
//     return 0;
// }
/////////////////////////////////////////////////////////////////////

 // Print name //////////////////////////////////////////////////////

// #include<iostream>
// #include<string>
// using namespace std;
// int main()
// {
//     string fullname;
//     cout << "Enter your name ";
//     getline(cin,fullname);
//     cout << "Full name is " << fullname;
//     return 0;
// }

/////////////////////////////////////////////////////////////////////////////
// Even or Odd check/////////////////////////////////////////////////////////


// #include<iostream>
// using namespace std;
// int main()
// {
//     int value;
//     cout << "Enter a number to check its even or odd ";
//     cin >> value;
//     if(value == 0)
//     {
//         cout << "The value is 0";
//     }
//     else if(value %2==0)
//     {
//         cout << value <<" is Even";
//     }
//     else
//     {
//         cout << value << " is Odd";
//     }
//     return 0;
// }

///////////////////////////////////////////////////////////////////////////////
//Swap the values using call by value//////////////////////////////////////////

// #include<iostream>
// using namespace std;

// void swap(int* num1,int* num2)
// {
//     int temp;
//     temp=*num2;
//     *num2=*num1;
//     *num1=temp;
// }

// int main()
// {
//     int a,b;
//     cout << "Enter Two numbers " << endl;
//     cin >>a >>b;
//     swap(&a,&b);
//     cout << "After swap the values are " << a << " "<<b;
//     return 0;
// }

///////////////////////////////////////////////////////////////////////////////
// Function Overloading using additon//////////////////////////////////////////

// #include<iostream>
// using namespace std;

// int sum(int ,int ,int);
// int sum(int ,int);

// int main()
// {
//     int num1,num2,num3,ch;
//     cout << "Enter your choice " << endl;
//     cout << "1. Two number addition " << endl;
//     cout << "2. Three number addition " << endl;
//     cin >> ch;

//     if(ch==1)
//     {
//         cout << "Enter number 1 " <<endl;
//         cin >> num1;
//         cout << "Enter number 2 " <<endl;
//         cin >> num2;
//         cout << "The addition is " << sum(num1,num2);
//     }
//     else
//     {
//         cout << "Enter number 1 " <<endl;
//         cin >> num1;
//         cout << "Enter number 2 " <<endl;
//         cin >> num2;
//         cout << "Enter number 3 " <<endl;
//         cin >> num3;
//         cout << "The addition is " << sum(num1,num2,num3);
//     }
    
// }

// int sum(int a,int b,int c)
// {
//     return a+b+c;
// }

// int sum(int a,int b)
// {
//     return a+b;
// }




// #include <iostream>
// #include <string>
// using namespace std;

// class staff {
// 	public:
// 	int code;
// 	string name;
// 	public:
//   void set_information() {
//   	cout<<"Enter Name :\n";
//   	getline(cin,name);
//   	cout<<"Enter code :\n";
//   	cin>>code;
//   }
//   /*
// 	void show()
// 	{
// 		cout<<name<<"\n"<<code<<"\n";
// 	}
// 	*/
// };

// class teacher: public staff {
// 	private:
// 	  string subject, publication;
// 	public:
// 	  void set_teacher_information() {
// 	  	cout<<"Enter Subject Name :\n";
// 	  	getline(cin,subject);
// 	  	cout<<"Enter Publication House Name :\n";
// 	  	getline(cin,publication);
		
//   	}
	
//   	void show_teacher_information() {
// 	   	cout <<"Teacher Name : "<<name<<"\nTeacher Code : "<<code<<"\nTeacher Book Publication House Name :"<<publication<<"\n";
 		
//   	}
// };

// class officer: public staff {
// 	private:
// 	string grade;
// 	public:
// 	void set_officer_information() {
// 		cout<<"Enter Officer Grade:\n";
// 	  getline(cin,grade);
	  
// 	}
	
// 	void show_officer_information() {
// 	   	cout <<"Officer Name : "<<name<<"\nOfficer Code : "<<code<<"\nOfficer Grade :"<<grade<<"\n";
 		
//   	}
	
// };

// class typist: public staff {
// 	private:
// 	float speed;
// 	public:
// 	void set_typist_information() {
// 		cout<<"Enter Typist Speed: ";
// 		cin>>speed;
		
// 	}
	
// 	void show_typist_information() {
// 		cout<<"Typist Name :"<<name<<"\nTypist Code :"<<code<<"\nTypist Speed :"<<speed<<"\n";
// 	}
// };
// int main()
// {
// 	teacher x;
// 	officer y;
// 	typist z;
// 	cout<<"Enter Teacher Information:\n";
// 	x.set_information();
//     cin.ignore(20,'\n');
// 	x.set_teacher_information();
// 	cout<<"\n\nEnter Officer Inromation:\n";
// 	y.set_information();
//     cin.ignore(20,'\n');
// 	y.set_officer_information();
// 	cout<<"\n\nEnter Typist Information:\n";
// 	z.set_information();
// 	z.set_typist_information();
// 	cout<<"\nTeacher Information:\n";
// 	x.show_teacher_information();
// 	cout<<"\nOfficer Information:\n";
// 	y.show_officer_information();
// 	cout<<"\nTypist Information:\n";
// 	z.show_typist_information();
	

// }

#include<iostream>
using namespace std;
int main(){
	cout << "This is a simpe code";
	return 0;
}