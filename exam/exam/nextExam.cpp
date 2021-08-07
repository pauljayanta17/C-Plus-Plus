// #include<iostream>
// #include<string.h>
// using namespace std;

// string gateNameID()
// {
//     cout <<"Enter the id of the student\n";
//     string s;
//     cin >> s;
//     return s;
// }

// getGrades(int a[])
// {
//     cout<<"Enter Attendence and participation grade: ";
//     cin >> a[0];

//     cout<<"Enter total HWK grade: ";
//     cin >> a[1];

//     cout<<"Enter total Lab grade: ";
//     cin >> a[2];

//     cout<<"Enter total midterm grade: ";
//     cin >> a[3];

//     cout<<"Enter total quizzes grade: ";
//     cin >> a[4];

//     cout<<"Enter midterm #1 grade: ";
//     cin >> a[5];

//     cout<<"Enter midterm #2 grade: ";
//     cin >> a[6];

//     cout<<"Enter Final Exam grade: ";
//     cin >> a[7];

// }

// float computeFinalgrade(int a[])
// {
//     float res=0;
//     res = a[0]*0.03 + a[1]*0.04 + a[2]*0.1 + a[3]*0.1 + a[4]*0.05 + a[5]*0.19 + a[6]*0.19 + a[7]*0.3;
//     return res;

// }


// string outInfo(string id ,int arr[],float g)
// {
//     string s;
//     cout << "Student id is:" << id << endl;
//     cout<<"Student Grade is: "<<g<<endl;
//     if(g>=95)
//     s = "A";
//     else if(g>=90)
//     s = "A-";
//     else if(g>=85)
//     s = "B+";
//     else if(g>=80)
//     s = "B";
//     else if(g>=75)
//     s = "B-";
//     else if(g>=70)
//     s = "C+";
//     else if(g>=65)
//     s = "C";
//     else if(g>=60)
//     s = "C-";
//     else if(g>=55)
//     s = "D";
//     else
//     s = "F";
//     cout<<"Student letter-grade : "<<s<<endl;
//     return s;
//     }
// void outMsg(string s)
// {

//     if(s =="A" or s == "A-")
//     cout << "EXCELLENT\n";
//     else if(s =="B" or s == "B+" or s=="B-")
//     cout << "GOOD\n";
//     else if(s =="D" or s =="F")
//     cout << "Good-Luck-Next-Time";
// }


// int main()
// {
//     int num,i;
//     int lg[10]={0};
//     int arr[8];
//     float s;
//     string str,g;
//     cout << "Enter the number of students\n";
//     cin >> num;
//     int x = 1;
//     while(num>=x)
//     {
//         cout<<endl<<"Enter the details for student "<<x<<endl;
//         str = gateNameID();
//         getGrades(arr);
//         s = computeFinalgrade(arr);
//         g = outInfo(str,arr,s);
//         outMsg(g);
//         if(g == "A")
//             lg[0]++;
//         else if (g == "A-")
//             lg[1]++;
//         else if (g == "B+")
//             lg[2]++;
//         else if (g == "B")
//             lg[3]++;
//         else if (g == "B-")
//             lg[4]++;
//         else if (g == "C+")
//             lg[5]++;
//         else if (g == "C")
//             lg[6]++;
//         else if (g == "C-")
//             lg[7]++;
//         else if (g == "D")
//             lg[8]++;
//         else if (g == "F")
//             lg[9]++;
//         cout<<endl;
//         x++;
//     }

//     cout<<endl<<"Total students, who got A: "<<lg[0]<<endl;
//     cout<<"Total students, who got A-: "<<lg[1]<<endl;
//     cout<<"Total students, who got B+: "<<lg[2]<<endl;
//     cout<<"Total students, who got B: "<<lg[3]<<endl;
//     cout<<"Total students, who got B-: "<<lg[4]<<endl;
//     cout<<"Total students, who got C+: "<<lg[5]<<endl;
//     cout<<"Total students, who got C: "<<lg[6]<<endl;
//     cout<<"Total students, who got C-: "<<lg[7]<<endl;
//     cout<<"Total students, who got D: "<<lg[8]<<endl;
//     cout<<"Total students, who got F: "<<lg[9]<<endl;

//     return 0;
// }







 #include<iostream>
 using namespace std;
 void getNameID(char name[20], int id){
 char name1[20];
 for(int i=0;1<20;i++){
 name1[i]=name[i];
}
int id1=id;

 }
 void getGrades(int attAndpart,int HWK,int lab,int labmid,int quiz, int mid1,int mid2,int final){

 int attAndparti=attAndpart ;
 int HWK1=HWK;
 int labi=lab;
int labmid1=labmid;
 int quizi=quiz;
 int mid11=mid1;
 int mid21=mid2;
 int finall= final;

 }
 int computeFinalgrade(int attAndpart,int HWK,int lab,int labmid,int quiz, int mid1,int mid2,int final){
 if(attAndpart<=3 && HWK<=4 && lab<=10 && labmid<=10 && quiz<=5 && mid1<= 19 && mid2<=19 && final<=30){
 return (attAndpart + HWK + lab +labmid + quiz + mid1 + mid2 + final);
 }
 return 0;
 }
 void outInfo(char name[20], int id, int grade){
 cout<<name<<id<<" Your weight "<<grade<<"%"<<endl;
 if(grade>=95 && grade<=100){
 cout<<"Your grade is A"<<endl;
 }
 if(grade>=90 && grade<=95){
 cout<<"Your grade is A-"<<endl;
 }
 if(grade>=85 && grade<=90){
 cout<<"Your grade is B+"<<endl;
 }
 if(grade>=80 && grade<=85){
 cout<<"Your grade is B"<<endl;
 }
 if(grade>=75 && grade<=80){
 cout<<"Your grade is B-"<<endl;
}
 if(grade>=70 && grade<=75){
cout<<"Your grade is C+"<<endl;
 }
 if(grade>= 65 && grade<=70){
 cout<<"Your grade is C"<<endl;
 }
 if(grade>=60 && grade<=65){
 cout<<"Your grade is C-"<<endl;
 }
 if(grade>=55 && grade<=60){
 cout<<"Your grade is D"<<endl;
 }


if(grade>=0 && grade<=55){
cout<<"Your grade is F"<<endl;
}
 }
 void outMsg(int grade){

 if(grade>=90 && grade<=100){

cout<<"Excellent"<<endl;
 }
 if(grade>=80 && grade<=90){

 cout<<"GOOD"<<endl;

 }

 if(grade>=0 && grade<=60){

 cout<<"Good-Luck-Next-Time"<<endl;

}

 }



 int main(){

 char name[20];



 int id;

 cout<<"Enter your name ";

cin>>name;

 cout<<"Enter your ID ";

 cin>>id;

getNameID(name, id);

 int attAndpart, HWK, lab, labmid, quiz, mid1,mid2,final;

 cout<<"Enter your grades for Attendence and Participation, Total HWK grade, Tota Lab grade, Lab midterm, total quizes, midterm #1, Midterm#2, Final exam"<<endl;

 cin>>attAndpart>>HWK>>lab>>labmid>>quiz>>mid1>>mid2>>final;

computeFinalgrade(attAndpart, HWK, lab, labmid, quiz, mid1,mid2,final);

 outInfo(name, id, computeFinalgrade(attAndpart, HWK, lab, labmid, quiz, mid1,mid2,final));

 outMsg(computeFinalgrade(attAndpart, HWK, lab, labmid, quiz, mid1,mid2,final));

return 0;

 }