#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class DepositeOnlyAccount{
    public:
    virtual void deposite(double amount)=0;
};
class WithdrawableAccount: public DepositeOnlyAccount{
    public:
    virtual void withdraw(double amount)=0;
};
class SavingAccount: public WithdrawableAccount{
    private:
    double balance;
    public:
    SavingAccount(double b): balance(b){}
    void deposite(double amount) override {
        balance += amount;
        cout<<"SavingAccount balance is: "<<balance<<endl;
    }
    void withdraw(double amount)override {
        if(amount <= balance){
            balance -= amount;
            cout<<"SavingAccount balance is: "<<balance<<endl;
        }else{
            cout<<"Insufficient balance"<<endl;
        }
    }
};
class CurrentAccount: public WithdrawableAccount{
    private:
    double balance;
    public:
    CurrentAccount(double b): balance(b){}
    void deposite(double amount) override {
        balance += amount;
        cout<<"CurrentAccount balance is: "<<balance<<endl;
    }
    void withdraw(double amount)override {
        if(amount <= balance){
            balance -= amount;
            cout<<"CurrentAccount balance is: "<<balance<<endl;
        }else{
            cout<<"Insufficient balance"<<endl;
        }
    }
};
class FixedTermAccount: public DepositeOnlyAccount{
    private:
    double balance;
    public:
    FixedTermAccount(double b): balance(b){}
    void deposite(double amount) override {
        balance += amount;
        cout<<"Fixed Term Account balance is: "<<balance<<endl;
    }
};
class BankClient{
    private:
    vector<DepositeOnlyAccount*>depositeAccount;
    vector<WithdrawableAccount*>withdrawAccount;
    public:
    BankClient(vector<DepositeOnlyAccount*> da, vector<WithdrawableAccount*> wa): depositeAccount(da), withdrawAccount(wa){}
    void processTransaction(){
        for(auto acc: depositeAccount){
            acc->deposite(1000);
        }
        for(auto acc: withdrawAccount){
            acc->deposite(1000);
            acc->withdraw(500);
        }
    }
};

int main() {
    vector<DepositeOnlyAccount*> da;
    vector<WithdrawableAccount*>wa;
    da.push_back(new FixedTermAccount(5000));
    wa.push_back(new SavingAccount(2000));
    wa.push_back(new CurrentAccount(2000));
    BankClient* client= new BankClient(da,wa);
    client->processTransaction();
    return 0;
}
