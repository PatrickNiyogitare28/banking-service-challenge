#include<iostream>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include"../helpers/utils/random-uuid.h"
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
     void save_account(string name, int age, string address, string type, float balance);
     void get_account(string account_number);
     void get_accounts();
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

    save_account(name, age, address, type, balance);

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
    string account_number;
    cout<<"\n Enter your account number: ";
    cin>>account_number;
    get_account(account_number);
}

void bank::save_account(string name, int age, string address, string type, float balance){
    string id = generate_uuid();
    ofstream accounts;
    accounts.open("src/domains/accounts.txt",ios::app);
    accounts<<"\n"<<id<<" "<<name<<" "<<age<<" "<<address<<" "<<type<<" "<<balance<<endl;
    accounts.close();
}

void bank::get_account(string account_number){
    ifstream accounts;
    accounts.open("src/domains/accounts.txt");
    string line;
    while(getline(accounts,line)){
        if(line.find(account_number)!=string::npos){
            cout<<"\n"<<line;
        }
    }
    accounts.close();
}

void bank::get_accounts(){
    ifstream accounts;
    accounts.open("src/domains/accounts.txt");
    string line;
    while(getline(accounts,line)){
        cout<<"\n"<<line;
    }
    accounts.close();
}
