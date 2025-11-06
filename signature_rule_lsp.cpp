#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Parent{
    public:
    virtual void print(string s){
        cout<<"parent: "<<s<<endl;
    }
};
class Child:public Parent{
    public:
    void print(string s) override{
        cout<<"child: "<<s<<endl;
    }
};
class Client{
    Parent *p;
    public:
    Client(Parent *p): p(p){}
    void print(){
        p->print("Hello LSP");
    }
};
int main() {
    Parent *p = new Child();
    Parent *p2 = new Parent();
    Client *c = new Client(p);
    Client *c2 = new Client(p2);
    c->print();
    c2->print();
    return 0;
}