#include<iostream>
#include<stdio.h>
#include<string.h>
#include"./services/banking.h"

using namespace std;

int main(){
   bank obj;
   int ch;
   string option;
   bool continue_loop=true;

   do{
   cout<<"--------------------------------------------------------------------------"<<endl;
   cout<<"-----------------------------   THE BANK APP -----------------------------"<<endl;
   cout<<"--------------------------------------------------------------------------"<<endl;

    cout<<"\n 1. Open Account"<<endl;
    cout<<"\n 2. Deposit Money"<<endl;
    cout<<"\n 3. Withdraw Money"<<endl;
    cout<<"\n 4. Display Account"<<endl;
    cout<<"\n 5. Exit"<<endl;
    cout<<"\n\n ";

    cin>>ch;

   cout<<"--------------------------------------------------------------------------"<<endl;



    switch (ch)
    {
    case 1:
        cout<<"\n Opening Account..."<<endl;
        obj.open_account();
        break;
    case 2:
        cout<<"\n Depositing Money..."<<endl;
        obj.deposit_money();
        break;
    case 3:
        cout<<"\n Withdrawing Money..."<<endl;
        obj.withdraw_money();
        break;
    case 4:
        cout<<"\n Displaying Account..."<<endl;
        obj.display_account();
        break;
    case 5:
        cout<<"\n Exiting..."<<endl;
        exit(0);
    default:
        cout<<"\n Invalid Choice, Try again"<<endl;
        break;
    }

    cout<<"\n\n Do you want to continue banking without exiting, Press (Y/N) ! ";
    cin>>option;
    cout<<"\n";

   if(option=="Y"||option=="y"){
       continue_loop=true;
   }
   else{
       continue_loop=false;
   }
   }
   while (continue_loop);
   

    return 0;
}