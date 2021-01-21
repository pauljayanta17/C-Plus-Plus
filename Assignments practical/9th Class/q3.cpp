#include<iostream>
#include<string>
using namespace std;

class Vehicle{
    string name;
    int wheel;
    public:
        void get_data(string n,int w){
            name=n;wheel=w;
        }
        void display(){
            cout <<"Vehicle name is "<<name<<endl;
            cout << "No of wheels is "<<wheel<<endl;
        }
};

class light_motor: public Vehicle{
    double speed_limit,capacity;
    public:
        void get_speed_limit(double s,double c){
            speed_limit=s;capacity=c;
        };
        void display_speed(){
            cout << "Speed limit "<<speed_limit<<endl;
            cout << "Capacity "<<capacity<<endl;
        }
        
};

class gear : public light_motor{
   int count;
   public:
    void get_gear(int g){
        count=g;
    }
    void display_gear(){
        cout << "No of gears "<<count<<endl;
    } 
};

class non_gear:public light_motor{
    public:
        void display_nonGear(){
            cout << "This is a non gear vehicle"<<endl;
        }
};

int main(){
    light_motor lm;
     non_gear n1;
     gear g;
    string v;
    char ch;
    int whe,c;
    double sl,capa;
    cout << "Enter the name of the vehicle ";
    getline(cin,v);
    cout << "Enter no of wheels ";
    cin >> whe;
    cout << "Enter the capacity of the vehicle ";
    cin >>capa;
    cout << "Enter speed limit of the vehicle ";
    cin >>sl;
    cout << "The vehicle is gear (y/n) ";
    cin >>ch;
    lm.get_data(v,whe);
    lm.get_speed_limit(sl,capa);
    if(ch=='y' || ch=='Y'){
        cout << "How many gear in the vehicle ? "<<endl;
        cin >>c;
        g.get_gear(c);
        lm.display();
        lm.display_speed();
        g.display_gear();
    }
    else
    {
        lm.display();
        lm.display_speed();
        n1.display_nonGear();
    }
    
    

    return 0;
}