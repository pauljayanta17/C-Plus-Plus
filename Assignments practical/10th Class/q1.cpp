// Create a class object with show as virtual function. 
// Inherit two other classes sphere and cube from object.
// Calculate volume of sphere and cube using necessary parameters and member function.
#include<iostream>
using namespace std;
class object{
    public:
        double radius;
        double volume_sphere;
        double length;
        double volume_cube;
        object(){

        }
        virtual void show(){
            cout << "This is the object class "<<endl;
        };
        
};

class Sphere : public object{
     public:
        void get_radius(){
            cout << "Enter the radius of the sphere ";
            cin >> radius;
        };
        void vol_sphere(){
          volume_sphere = (4/3)*3.14*radius*radius*radius;
        };
        void show(){
            cout << "Volume of the sphere is "<<volume_sphere<<endl;
        };
};

class Cube : public object{
      
    public:
        void get_length(){
            cout << "Enter the radius of the sphere ";
            cin >> length;
        };
        void vol_cube(){
            volume_cube=  length*length*length;
        };
        void show(){
            cout << "Volume of the cube is "<<volume_cube<<endl;
        };
};


int main(){
    object* obj;
    object o;
    Sphere sphere;
    Cube cube;
    obj = &o;
    cout << "For Base class"<<endl;
    obj->show();
    obj=&sphere;

    cout << "For Sphere "<<endl;
    sphere.get_radius();
    sphere.vol_sphere();
    obj->show();
    obj=&cube;
    cout << "For Cube "<<endl;
    cube.get_length();
    cube.vol_cube();
    obj->show();


}