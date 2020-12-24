//
//  Account.cpp
//  SlotMachine
//
//  Created by ZQ314159 on 17/7/2563 BE.
//  Copyright © 2563 ZQ314159. All rights reserved.
//

#include "Account.hpp"
Account::Account()
{
    this->name = "";
    this->surname = "";
    this->id = 0;
    this->password = "";
    this->balance = 0;
}
void Account::deposit(Account * account,int _id, string _password, double amount)
{
    bool isFound = false;
    int j=0;
    for (int i=0; i<MAX; i++) {
        if (_id == account[i].id) {
            isFound=true;
            j = i;
            break;
        }
    }
    if (isFound) {
        if (_password == account[j].password) {
            account[j].balance += amount;
        }
    }
    else
        cout<<"Account is not available"<<endl;
}

void Account::withdraw(Account * account,int _id, string _password, double amount)
{
    bool isFound = false;
    int j=0;
    for (int i=0; i<MAX; i++) {
        if (_id == account[i].id) {
            isFound = true;
            j = i;
            break;
        }
    }
    if (isFound) {
        if (_password == account[j].password) {
            if (account[j].balance < amount) {
                cout<<"money not enough"<<endl;
            }
            else
                account[j].balance -= amount;
        }
    }
}


double Account::getBalance()
{
    return this->balance;
}

int Account::getId()
{
    return this->id;
}

string Account::getPassword()
{
    return this->password;
}

void Account::setId(int id)
{
    this->id = id;
}

void Account::setName(string name)
{
    this->name = name;
}

void Account::setSurname(string surname)
{
    this->surname = surname;
}
void Account::setPassword(string password)
{
    this->password = password;
}

void Account::setBalance(double amount)
{
    this->balance = amount;
}

bool Account::check(Account *a, int id,string password)
{
    bool isValid = false;
    if (a->getId() == id) {
        isValid = true;
    }
    if (isValid && password == a->password) {
        cout<<"LOG IN SUCCESS"<<endl;
        return true;
    }
    else
    {
        cout<<"LOG IN FAILED"<<endl;
        return false;
    }
        
}
