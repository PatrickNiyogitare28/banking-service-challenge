#include<iostream>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include<cstring>
#include<vector>
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
     void save_account(string account_name, string name, int age, string address, string type, float balance);
     void get_account(string account_number);
     void get_accounts();
     void update_account(string account_name, string name, int age, string address, string type, float balance);
     void log_account_info(string account);
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

    string account_number = generate_uuid();
    save_account(account_number, name, age, address, type, balance);

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
    string account_number;
    cout<<"\n Enter the amount you want to withdraw: ";
    cin.ignore();
    cin>>withdraw_amount;

    cout <<"\n Enter your account number: ";
    cin.ignore();
    cin>>account_number;

    balance-=withdraw_amount;
    ifstream accounts;
    accounts.open("src/domains/accounts.txt");

    string line;
    while(getline(accounts, line)){
       if(line.find(account_number) != string::npos){
              break;
       }
    }

    accounts.close();
   
   if(line.empty()){
    cout<<"\n Account not found";
   }
    else{
        char *tokens = strtok((char*)line.c_str(), " ");
            int i = 0;
            string account_number, name, address, type;
            float balance;
            while(tokens != NULL){
                if(i == 0){
                    account_number = tokens;
                }
                else if(i == 1){
                    name = tokens;
                }
                else if(i == 2){
                    age = atoi(tokens);
                }
                else if(i == 3){
                    address = tokens;
                }
                else if(i == 4){
                    type = tokens;
                }
                else if(i == 5){
                    balance = atof(tokens);
                }
                tokens = strtok(NULL, " ");
                i++;
            }

            if(balance < withdraw_amount){
                cout<<"\n Insufficient balance";
            }
            else{
                balance-=withdraw_amount;
                cout<<"\n Withdrawal successful, your balance is: "<<balance;
                update_account(account_number, name, age, address, type, balance);
            }
    }
    
}

void bank::display_account(){
    string account_number;
    cout<<"\n Enter your account number: ";
    cin>>account_number;
    get_account(account_number);
}

void bank::save_account(string account_number, string name, int age, string address, string type, float balance){
    ofstream accounts;
    accounts.open("src/domains/accounts.txt",ios::app);
    accounts<<"\n"<<account_number<<" "<<name<<" "<<age<<" "<<address<<" "<<type<<" "<<balance<<endl;
    accounts.close();
}

void bank::get_account(string account_number){
    ifstream accounts;
    accounts.open("src/domains/accounts.txt");
    string line;
    string account;
    while(getline(accounts,line)){
        if(line.find(account_number)!=string::npos){
            account = line;
            break;
        }
    }
    if(account.empty()) cout<<"\n Invalid Acccount Number"<<endl;
    else{
       log_account_info(account);
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

void bank::update_account (string account_number, string name, int age, string address, string type, float balance){
  vector<string> lines;
    ifstream accounts;
    accounts.open("src/domains/accounts.txt");
    string line;
    while(getline(accounts,line)){
        if(line.find(account_number)!=string::npos){
           continue;
        }
        else{
            lines.push_back(line);
        }
    }
    lines.push_back("\n"+account_number+" "+name+" "+to_string(age)+" "+address+" "+type+" "+to_string(balance));
    accounts.close();
   
    ofstream accounts_new;
    accounts_new.open("src/domains/accounts.txt");
    for(int i=0; i<lines.size(); i++){
        accounts_new<<lines[i]<<endl;
    }
    accounts_new.close();
}


void bank::log_account_info(string account){
     char *tokens = strtok((char*)account.c_str(), " ");
            int i = 0;
            string account_number, name, address, type;
            float balance;
            while(tokens != NULL){
                if(i == 0){
                    account_number = tokens;
                }
                else if(i == 1){
                    name = tokens;
                }
                else if(i == 2){
                    age = atoi(tokens);
                }
                else if(i == 3){
                    address = tokens;
                }
                else if(i == 4){
                    type = tokens;
                }
                else if(i == 5){
                    balance = atof(tokens);
                }
                tokens = strtok(NULL, " ");
                i++;
            }
            cout<<"\n Account Number: "<<account_number<<endl;
            cout<<"\n Name: "<<name<<endl;
            cout<<"\n Age: "<<age<<endl;
            cout<<"\n Address: "<<address<<endl;
            cout<<"\n Type: "<<type<<endl;
            cout<<"\n Balance: "<<balance<<endl;
}