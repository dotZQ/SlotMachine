#include <iostream>
#include "Account.hpp"
#include "Slot.hpp"
using namespace std;
int showSignUp()
{
    int result = 0;
    while (result <= 0 || result > 3) {
        cout<<"*********SLOT++**********"<<endl;
        cout<<"*                       *"<<endl;
        cout<<"*  (1)LOG IN            *"<<endl;
        cout<<"*  (2)SIGN UP           *"<<endl;
        cout<<"*  (3)EXIT              *"<<endl;
        cout<<"*                       *"<<endl;
        cout<<"*************************"<<endl;
        cin>>result;
    }
    
    return result;
}
int showMenu()
{
    int result = 0;
    while (result <=0 || result > 5) {
        cout<<"*********SLOT++**********"<<endl;
        cout<<"* 1.PLAY                *"<<endl;
        cout<<"* 2.TOP UP              *"<<endl;
        cout<<"* 3.Balance             *"<<endl;
        cout<<"* 4.Withdraw            *"<<endl;
        cout<<"* 5.SIGN OUT            *"<<endl;
        cout<<"*************************"<<endl;
        cin>>result;
    }
    return result;
    
}

int main(int argc, const char * argv[]) {
    
    Slot slot;
    int currentAcc=0;
    int id;
    double amount;
    string password;
    string name;
    Account *currentAccount;
    Account account[MAX];
    currentAccount = &account[0];
    
    int result1 = showSignUp();
    while (result1!=3 ) {
        if (result1 == 1) {
            cout<<"please input your id [0-9]"<<endl;
            cin>>id;
            if (id < 10) {
                cout<<"please input your password"<<endl;
                cin>>password;
                currentAccount = &account[id];
                
                if (currentAccount->check(currentAccount, id,password) ) {
                    currentAccount = &account[id];
                    slot.account = currentAccount;
                    int result = showMenu();
                    while (result>0 && result <7) {
                        if (result == 1) {
                            slot.play();
                        }
                        else if (result == 2) {
                            cout<<"Input amount :";
                            cin>>amount;
                            currentAccount->deposit(currentAccount, id, password, amount);
                        }
                        else if (result==3){
                            cout<<currentAccount->name<<" balance is :";
                            cout<<currentAccount->getBalance();
                            cout<<endl;
                        }
                        
                        else if (result==4){
                            cout<<"input password :";
                            cin>>password;
                            cout<<"input amount :";
                            cin>>amount;
                            currentAccount->withdraw(currentAccount, id, password, amount);
                        }
                        else if (result==5){
                            slot.signOut();
                            break;
                        }
                        result = showMenu();
                    }
                }
            }
            else
                cout<<"id is not Valid"<<endl;
            

        }
        else if(result1==2)
        {
            string surname;
            cout<<"name and surname :";
            cin>>name>>surname;
            cout<<"password : ";
            cin>>password;
            cout<<"amount :";
            cin>>amount;
            account[currentAcc].setBalance(amount);
            account[currentAcc].setId(currentAcc);
            account[currentAcc].setName(name);
            account[currentAcc].setSurname(surname);
            account[currentAcc].setPassword(password);
            cout<<"your id is :"<<currentAcc<<endl;
            currentAcc++;
            
        }
        else if (result1==3)
        {
            break;
        }
        result1 = showSignUp();
    }
    return 0;
}
