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
#include<stack>
#include<string>
#include<iterator>
#include<map>
#include <bits/stdc++.h>
using namespace std;

string gateNameID()
{
    cout <<"Enter the id of the student\n";
    string s;
    cin >> s;
    return s;
}

stack<string> sortStackfgr(stack<string> &input,map<string,int> m) 
{ 

    stack<string> tmpStack; 

    while (!input.empty()) 

    { 

        string tmp = input.top(); 

        input.pop();                           

        while (!tmpStack.empty() && m.at(tmpStack.top()) > m.at(tmp)) 

        { 

            input.push(tmpStack.top()); 

            tmpStack.pop(); 

        }  

        tmpStack.push(tmp); 

    } 

  

    return tmpStack; 
} 

stack<string> sortStacktgr(stack<string> &input,map<string,float> m) 
{ 

    stack<string> tmpStack; 

    while (!input.empty()) 

    { 

        string tmp = input.top(); 

        input.pop();                           

        while (!tmpStack.empty() && m.at(tmpStack.top()) > m.at(tmp)) 

        { 

            input.push(tmpStack.top()); 

            tmpStack.pop(); 

        }  

        tmpStack.push(tmp); 

    } 

  

    return tmpStack; 
} 

stack<string> sortStacklgr(stack<string> &input,map<string,string> m) 
{ 

    stack<string> tmpStack; 
    map<string,int> q;
    q.insert(pair<string,int>("F",1));
    q.insert(pair<string,int>("D",2));
    q.insert(pair<string,int>("C-",3));
    q.insert(pair<string,int>("C",4));
    q.insert(pair<string,int>("C+",5));
    q.insert(pair<string,int>("B-",6));
    q.insert(pair<string,int>("B",7));
    q.insert(pair<string,int>("B+",8));
    q.insert(pair<string,int>("A-",9));
    q.insert(pair<string,int>("A",10));
    while (!input.empty()) 

    { 

        string tmp = input.top(); 

        input.pop();                           

        while (!tmpStack.empty() && q.at(m.at(tmpStack.top())) > q.at(m.at(tmp))) 

        { 

            input.push(tmpStack.top()); 

            tmpStack.pop(); 

        }  

        tmpStack.push(tmp); 

    } 

  

    return tmpStack; 
} 


getGrades(int a[])
{
    cout<<"Enter Participation grade: ";
    cin >> a[0];

    cout<<"Enter total HWK grade: ";
    cin >> a[1];

    cout<<"Enter total Lab grade: ";
    cin >> a[2];

    cout<<"Enter total midterm grade: ";
    cin >> a[3];

    cout<<"Enter total quizzes grade: ";
    cin >> a[4];

    cout<<"Enter midterm #1 grade: ";
    cin >> a[5];

    cout<<"Enter midterm #2 grade: ";
    cin >> a[6];

    cout<<"Enter Final Exam grade: ";
    cin >> a[7];

}

float computeFinalgrade(int a[])
{
    float res=0;
    res = a[0]*0.03 + a[1]*0.04 + a[2]*0.1 + a[3]*0.1 + a[4]*0.05 + a[5]*0.19 + a[6]*0.19 + a[7]*0.3;
    return res;

}


string outInfo(string id ,int arr[],float g)
{
    string s;
    cout << "Student id is:" << id << endl;
    cout<<"Student Grade is: "<<g<<endl;
    if(g>=95)
    s = "A";
    else if(g>=90)
    s = "A-";
    else if(g>=85)
    s = "B+";
    else if(g>=80)
    s = "B";
    else if(g>=75)
    s = "B-";
    else if(g>=70)
    s = "C+";
    else if(g>=65)
    s = "C";
    else if(g>=60)
    s = "C-";
    else if(g>=55)
    s = "D";
    else
    s = "F";
    cout<<"Student letter-grade : "<<s<<endl;
    return s;
    }


int main()
{
    int num,i;
    map<string,float> tgr;
    map<string,int> fgr;
    map<string,string> lgr;
    stack<string> tg1;
    stack<string> fg1;
    stack<string> lg1;
    int lg[10]={0};
    int arr[8];
    float s;
    string str,g;
    cout << "Enter the number of students\n";
    cin >> num;
    int x = 1;
    while(num>=x)
    {
        cout<<endl<<"Enter the details for student "<<x<<endl;
        str = gateNameID();
        getGrades(arr);
        s = computeFinalgrade(arr);
        tgr.insert(pair<string,float>(str,s));
        fgr.insert(pair<string,int>(str,arr[7]));
        g = outInfo(str,arr,s);
        lgr.insert(pair<string,string>(str,g));
        tg1.push(str);
        lg1.push(str);
        fg1.push(str);
        if(g == "A")
            lg[0]++;
        else if (g == "A-")
            lg[1]++;
        else if (g == "B+")
            lg[2]++;
        else if (g == "B")
            lg[3]++;
        else if (g == "B-")
            lg[4]++;
        else if (g == "C+")
            lg[5]++;
        else if (g == "C")
            lg[6]++;
        else if (g == "C-")
            lg[7]++;
        else if (g == "D")
            lg[8]++;
        else if (g == "F")
            lg[9]++;
        cout<<endl;
        x++;
    }
    stack<string> fg2 = sortStackfgr(fg1,fgr);
    stack<string> tg2 = sortStacktgr(tg1,tgr);
    stack<string> lg2 = sortStacklgr(lg1,lgr);
    cout<<endl<<"Total students, who got A: "<<lg[0]<<endl;
    cout<<"Total students, who got A-: "<<lg[1]<<endl;
    cout<<"Total students, who got B+: "<<lg[2]<<endl;
    cout<<"Total students, who got B: "<<lg[3]<<endl;
    cout<<"Total students, who got B-: "<<lg[4]<<endl;
    cout<<"Total students, who got C+: "<<lg[5]<<endl;
    cout<<"Total students, who got C: "<<lg[6]<<endl;
    cout<<"Total students, who got C-: "<<lg[7]<<endl;
    cout<<"Total students, who got D: "<<lg[8]<<endl;
    cout<<"Total students, who got F: "<<lg[9]<<endl;
    
    cout << "Total Grades\n";
    while(!tg2.empty()){
      cout << tg2.top() << " Grade " << tgr.at(tg2.top()) << endl;
      tg2.pop();
    }
    cout << "Final Exam Grades\n";
    while(!fg2.empty()){
      cout << fg2.top() << " Grade " << fgr.at(fg2.top()) << endl;
      fg2.pop();
    }
    cout << "Letter Grades\n";
    while(!lg2.empty()){
      cout << lg2.top() << " Grade " << lgr.at(lg2.top()) << endl;
      lg2.pop();
    }
    return 0;
}