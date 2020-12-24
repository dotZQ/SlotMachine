//
//  Account.hpp
//  SlotMachine
//
//  Created by ZQ314159 on 17/7/2563 BE.
//  Copyright © 2563 ZQ314159. All rights reserved.
//

#ifndef Account_hpp
#define Account_hpp
#define MAX 10
#include <iostream>
using namespace std;
class Account
{
private:
    int id;
    string password;
    double balance;
public:
    Account();
    string name;
    string surname;
    void deposit(Account * account,int _id,string _password,double amount);
    void withdraw(Account * account,int _id,string _password,double amount);
    double getBalance();
    int getId();
    string getPassword();
    void setId(int id);
    void setPassword(string password);
    void setName(string name);
    void setSurname(string surname);
    void setBalance(double amount);
    bool check(Account * a,int id,string password);
};
#endif /* Account_hpp */
