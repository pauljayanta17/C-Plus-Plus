    // Design a class Fraction which contains data members for numerator and denominator.
    // Include default constructor with default arguments 0 taken as numerator and denominator
    // Overload the operators + and -.
    #include<iostream>
    using namespace std;

    class fraction{
        double numerator,denominator,actual;
        public:
            fraction(double a=0,double b=0){
                numerator =a;
                denominator = b;
            }
            fraction operator + (const fraction& f){
                fraction res;
                res.actual = actual + f.actual;
                return res;
            }
            fraction operator - (const fraction& f){
                fraction res;
                res.actual = actual - f.actual;
                return res;
            }
            void getdata(){
                cout << "Enter numerator "<<endl;
                cin >> numerator;
                cout << "Enter denominator "<<endl;
                cin >> denominator;
                actual = numerator/denominator;
            }
            void printdata(){
                cout <<actual;
            }
    };

    int main(){
        fraction f1,f2,sum,sub;
        cout << "For first fraction "<<endl;
        f1.getdata();
        cout << "For Second fraction " <<endl;
        f2.getdata();
        sum=f1+f2;
        sub=f1-f2;
        cout << "\nSum of fraction is ";
        sum.printdata();
        cout << "\nSubtraction of fraction is ";
        sub.printdata();
        return 0;
    }