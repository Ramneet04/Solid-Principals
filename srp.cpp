#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Product{
    string name;
    double price;
public:
    Product(string s, double p): name(s),price(p){}
    double getPrice(){
        return price;
    }
};
class Cart{
    vector<Product*>products;
public:
    void addProduct(Product* p){
        products.push_back(p);
    }
    double calculateTotal(){
        double total=0.0;
        for(auto x:products){
            total += x->getPrice();
        }
        return total;
    }
};
class Invoice{
    Cart* cart;
    public:
    Invoice(Cart* c): cart(c){}
    double generateInvoice(){
        cout<<"Generating Invoice..."<<endl;
        cout<<"Total: "<<cart->calculateTotal()<<endl;
    }
};
class SaveToDb{
    Cart* cart;
    public:
    SaveToDb(Cart *cart): cart(cart){}
    void save(){
        cout<<"Saving cart to database..."<<endl;
    }
};
int main() {
    Product* p1 = new Product("Laptop", 1000.0);
    Product* p2 = new Product("Mouse", 50.0);
    Cart* cart = new Cart();
    cart->addProduct(p1);
    cart->addProduct(p2);
    Invoice* invoice = new Invoice(cart);
    SaveToDb* db= new SaveToDb(cart);
    invoice->generateInvoice();
    db->save();
    return 0;
}