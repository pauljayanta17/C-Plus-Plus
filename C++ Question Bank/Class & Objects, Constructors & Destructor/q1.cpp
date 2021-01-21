// Define a class to represent a vector. Include member functions to perform the following 
// (a) Create a vector[CU 2013]
// (b) Modify the value of a given element 
// (c) Multiply by a scalar value 
// (d) Display the vector 
// (e) Add two vectors 
// Write suitable main ( ) function to test your class.

#include <iostream>
using namespace std;

class vector
{
   

public:
 int i, j, k;
    vector(){};
    vector(int ti, int tj, int tk)
    {
        i = ti;
        j = tj;
        k = tk;
    };
    void ScalarMultiply(int val)
    {
        i = val * i;
        j = val * j;
        k = val * k;
    };
    void AddTwoVectors(vector a, vector b)
    {
        i = a.i + b.i;
        j = a.j + b.j;
        k = a.k + b.k;
    };

    void displayVector(){
        cout << "The vector is "<<endl;
        cout << i << " i + "<<j<<" j + "<<k<< " k"<<endl;
    }
    
};

int main()
{
    vector v1,v2;
    int ch,v1i,v1j,v1k,v2i,v2j,v2k,scalar;
    cout << "1.For add two vector\n2.Multiply by scalar "<<endl;
    cout << "Choose your choice "<<endl;
    cin >>ch;
    if(ch==1){
        cout << "Enter the first vector "<<endl;
        cout << "For value of i -  ";
        cin >>v1i;
        cout << "For value of j -  ";
        cin >>v1j;
        cout << "For value of k -  ";
        cin >>v1k;
        cout << "Enter the Second vector "<<endl;
        cout << "For value of i -  ";
        cin >>v2i;
        cout << "For value of j -  ";
        cin >>v2j;
        cout << "For value of k -  ";
        cin >>v2k;
        v1 = vector(v1i,v1j,v1k);
        v2 = vector(v2i,v2j,v2k);
        v1.AddTwoVectors(v1,v2);
        v1.displayVector();
    }
    else if(ch==2){
        cout << "Enter the vector "<<endl;
        cout << "For value of i -  ";
        cin >>v1i;
        cout << "For value of j -  ";
        cin >>v1j;
        cout << "For value of k -  ";
        cin >>v1k;
        v1=vector(v1i,v1j,v1k);
        cout << "Enter the scalar multiplier ";
        cin >>scalar;
        v1.ScalarMultiply(scalar);
        v1.displayVector();
    }
}