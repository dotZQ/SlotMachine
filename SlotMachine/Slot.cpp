//
//  Slot.cpp
//  SlotMachine
//
//  Created by ZQ314159 on 17/7/2563 BE.
//  Copyright © 2563 ZQ314159. All rights reserved.
//

#include "Slot.hpp"
Slot::Slot()
{
    account = nullptr;
    
}

void Slot::play()
{
    srand((unsigned int)(time(NULL)));
    cout<<"*********SLOT++**********"<<endl;
    cout<<"*                       *"<<endl;
    cout<<"* INSERT MONEY  :       *"<<endl;
    cout<<"*                       *"<<endl;
    cout<<"*************************"<<endl;
    double amount;
    cin>>amount;
    if ((this->account)->getBalance()<amount) {
        cout<<"NOT ENOUGH MONEY!!!"<<endl;
        cout<<"YOU HAVE :"<<(this->account)->getBalance()<<endl;
        cout<<"  IF YOU WANT TO PLAY "<<endl;
        cout<<"PLEASE GO TO TOPUP MENU"<<endl;
        return;
    }
    (this->account)->withdraw(this->account, (this->account)->getId(), (this->account)->getPassword(), amount);
    
    
    for (int i=0; i<3; i++) {
        
        int x = rand()%8;
        int y = rand()%8;
        int z = rand()%8;
        
        (this->result)[0] = x;
        (this->result)[1] = y;
        (this->result)[2] = z;
        cout<<"*********SLOT++**********"<<endl;
        cout<<"*  ____________________ *"<<endl;
        cout<<"* |      |      |      |*"<<endl;
        cout<<"* |  "<<token[x]<<"   |  "<<token[y]<<"   |   "<<token[z]<<"  |*"<<endl;
        cout<<"* |______|______|______|*"<<endl;
        cout<<"*                       *"<<endl;
        cout<<"*************************"<<endl;
        if (x==y && x==z) {
            checkT[i]=true;
        }
        else
        {
            checkT[i]=false;
           
            
        }
    }
    int got=0;
    
    for (int i=0; i<3; i++) {
        if (checkT[i] == true) {
            got++;
        }
    }
    if (got ==0) {
        cout<<"*********SLOT++**********"<<endl;
        cout<<"*                       *"<<endl;
        cout<<"*   B A D  L U C K ~~   *"<<endl;
        cout<<"*                       *"<<endl;
        cout<<"*************************"<<endl;
    }
    else if (got == 1 ){
        cout<<"*********SLOT++**********"<<endl;
        cout<<"*                       *"<<endl;
        cout<<"*   J A C K P O T !!    *"<<endl;
        cout<<"*                       *"<<endl;
        cout<<"*************************"<<endl;
        cout<<"~~~~~YOU GOT : "<<amount*10<<"~~~~~"<<endl;
        (this->account)->deposit(this->account, (this->account)->getId(), (this->account)->getPassword(), amount*10);
    }
    else if (got ==2 ){
        cout<<"*********SLOT++**********"<<endl;
        cout<<"*                       *"<<endl;
        cout<<"*   J A C K P O T !!    *"<<endl;
        cout<<"*        X 2            *"<<endl;
        cout<<"*************************"<<endl;
        cout<<"~~~~~YOU GOT : "<<amount*100<<"~~~~~"<<endl;
        (this->account)->deposit(this->account, (this->account)->getId(), (this->account)->getPassword(), amount*220);
    }
    else if (got == 3 ){
        cout<<"*********SLOT++**********"<<endl;
        cout<<"*                       *"<<endl;
        cout<<"*   J A C K P O T !!    *"<<endl;
        cout<<"*        X 3            *"<<endl;
        cout<<"*************************"<<endl;
        cout<<"~~~~~YOU GOT : "<<amount*1000<<"~~~~~"<<endl;
        (this->account)->deposit(this->account, (this->account)->getId(), (this->account)->getPassword(), amount*330);
    }
    
}


void Slot::signOut()
{
    account = nullptr;
   
}

bool Slot::check(int _id)
{
    bool isValid = false;
    for (int i=0; i<MAX; i++) {
        if (_id == account[i].getId()) {
            isValid = true;
        }
    }
    if (isValid) {
        return true;
    }
    else
        return false;
}
