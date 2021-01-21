// #include<iostream>
// using namespace std;
// class A
// {
// 	int a;    //Private; not inherited
// 	public:
// 		int b;
// 		void get_ab();
// 		void get_a();
// 		void show_a();
// };

// void A :: get_ab()
// {
// 	cout<<"Enter input a:"<<"\n";
// 	cin>>a;
// 	cout<<"Enter input b:"<<"\n";
// 	cin>>b;

// }

// void A :: get_a()
// {
// 	cout<<"Enter input a:"<<"\n";
// 	cin>>a;
// }

// void A::show_a()
// {
// 	cout<<"Output of A:"<<a<<endl;

// }

// class D : public A
// {
// 	int c = 4;
// 	public:
// 		void mul()
// 		{
// 			cout<<"Multiplication result: "<<b*c<<"\n";
// 		}
// 		void display()
// 		{
// 			cout<<"Values of b and c are:"<<b<<" "<<c<<endl;
// 		}
// };

// int main()
// {
// 	D d;
// 	d.get_ab();
// 	d.show_a();
// 	d.b=20;
// 	d.display();
// 	d.mul();

// }

//Implement Multilevel Inheritance by modifying the below code.
// #include<iostream>
// using namespace std;
// class Student
// {
// protected:
// 	int roll_no;

// public:
// 	void get_number(int a){
// 		roll_no = a;
// 	};
// 	void put_number(){
// 		cout << "Your Roll No is "<< roll_no<<endl;
// 	};
// };
// class test : public Student
// {
// protected:
// 	float sub1, sub2;

// public:
// 	void get_marks(float a, float b){
// 		sub1 = a;
// 		sub2 = b;
// 	};
// 	void put_marks(){
// 		cout << "Your Marks in subject 1 is " << sub1 << "\nSubject 2 is "<< sub2<<endl;
// 	};
// };
// class result : public test
// {
// 	float total;

// public:
// 	void display(){
// 		put_number();
// 		put_marks();
// 	}
// };

// int main()
// {
// 	result r;
// 	int roll;
// 	float sub1,sub2;
// 	cout << "Enter your Roll no ";
// 	cin >> roll;
// 	r.get_number(roll);
// 	cout << "Enter marks in subject 1" <<endl;
// 	cin >> sub1;
// 	cout << "Enter marks in subject 2" <<endl;
// 	cin >> sub2;
// 	r.get_marks(sub1,sub2);
// 	r.display();
// 	return 0;
// }

// #include <iostream>
// using namespace std;
// class M
// {
// protected:
// 	int m;

// public:
// 	void get_m(){
// 		cout << "Enter value of m ";
// 		cin >> m;
// 	};
// 	void put_m(){
// 		cout << "Value of m is "<<m<<endl;
// 	};
// };
// class N
// {
// protected:
// 	int n;

// public:
// 	void get_n(){
// 		cout << "Enter value of n ";
// 		cin >> n;
// 	};
// 	void put_n(){
// 		cout << "Value of n is "<< n;
// 	};
// };
// class P : public M, public N
// {
// public:
// 	void display(){
// 		put_m();
// 		put_n();
// 	};
// };


// int main()
// {
// 	P p;
// 	p.get_m();
// 	p.get_n();
// 	p.display();
// 	return 0;
// }

