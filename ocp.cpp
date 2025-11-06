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
    string getName(){
        return name;
    }
};
class Cart{
    public:
    vector<Product*>products;
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
        for(auto x:cart->products){
            cout<<x->getName()<<" "<<x->getPrice()<<"$"<<endl;
        }
        cout<<"Total: "<<cart->calculateTotal()<<"$"<<endl;
    }
};
class DBPersister{
    protected:
    Cart* cart;
    public:
    DBPersister(Cart *cart): cart(cart){}
    virtual void save()=0;
};
class SaveToDb: public DBPersister{
    public:
    SaveToDb(Cart * cart): DBPersister(cart){}
    void save() override {
        cout<<cart->calculateTotal()<<endl;
        cout<<"Saving cart to database..."<<endl;
    }
};
class saveMonGoDB: public DBPersister{
    public:
    saveMonGoDB(Cart * cart): DBPersister(cart){}
    void save() override {
        cout<<cart->calculateTotal()<<endl;
        cout<<"Saving cart to MongoDb..."<<endl;
    }
};
class saveFile: public DBPersister{
    public:
    saveFile(Cart * cart): DBPersister(cart){}
    void save() override {
        cout<<cart->calculateTotal()<<endl;
        cout<<"Saving cart to file..."<<endl;
    }
};

int main() {
    Product* p1 = new Product("Laptop", 1000.0);
    Product* p2 = new Product("Mouse", 50.0);
    Cart* cart = new Cart();
    cart->addProduct(p1);
    cart->addProduct(p2);
    Invoice* invoice = new Invoice(cart);
    DBPersister* db= new SaveToDb(cart);
    // DBPersister* db= new saveMonGoDB(cart);
    // DBPersister* db= new saveFile(cart);
    invoice->generateInvoice();
    db->save();
    return 0;
}