#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class twoDShape{
    public:
    virtual double area()=0;
};
class ThreeDsShape{
    public:
    virtual double area()=0;
    virtual double volume()=0;
};
class Cube:public ThreeDsShape{
    double side;
    public:
    Cube(double s):side(s){}
    double area() override{
        return 6*side*side;
    }
    double volume() override{
        return side*side*side;
    }
};
class Square: public twoDShape{
    double side;
    public:
    Square(double s): side(s){}
    double area() override{
        return side*side;
    }
};
int main() {
    Cube* c = new Cube(3);
    Square* s = new Square(5);
    cout<<"area of cube: "<<c->area()<<endl;
    cout<<"volume of cube: "<<c->volume()<<endl;
    cout<<"area of sqaure: "<<s->area()<<endl;
    return 0;
}