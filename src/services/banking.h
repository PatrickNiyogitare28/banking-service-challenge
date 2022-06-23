#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

char name[100], address[100], type[100];
int age;
float balance;

class bank{
    public:
     void open_account();
     void deposit_money();
     void withdraw_money();
     void display_account();
};

void bank::open_account(){
    cout<<"\n Enter your name: ";
    cin.ignore();
    cin>>name;

    cout<<"\n Enter your age: ";
    cin.ignore();
    cin>>age;

    cout<<"\n Enter your address: ";
    cin.ignore();
    cin>>address;

    cout<<"\n Type of Account you want to open: ";
    cin.ignore();
    cin>>type;

    cout<<"\n Enter your first deposit amount: ";
    cin.ignore();
    cin>>balance;

    cout<<"\n Account opened successfully";
}

void bank::deposit_money(){
    int deposit_amount;
    cout<<"\n Enter the amount you want to deposit: ";
    cin.ignore();
    cin>>deposit_amount;
    balance+=deposit_amount;

    cout<<"\n Amount deposited successfully, your balance is: "<<balance;
}

void bank::withdraw_money(){
    int withdraw_amount;
    cout<<"\n Enter the amount you want to withdraw: ";
    cin.ignore();
    cin>>withdraw_amount;
    balance-=withdraw_amount;

    cout<<"\n Amount withdrawn successfully, your balance is: "<<balance;
}

void bank::display_account(){
    cout<<"\n Name: "<<name;
    cout<<"\n Age: "<<age;
    cout<<"\n Address: "<<address;
    cout<<"\n Type of Account: "<<type;
    cout<<"\n Balance: "<<balance;
}