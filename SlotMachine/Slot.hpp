#ifndef Slot_hpp
#define Slot_hpp
#include "Account.hpp"
#include <iostream>
#include <time.h>
using namespace std;
class Slot
{
private:
    char token[8] = {'!','@','#','$','%','&','?','7'};
    char result[3]{};
    bool checkT[3]{false,false,false};
    
public:
    Account *account;
    Slot();
    void play();
    void signOut();
    bool check(int _id);
};

#endif /* Slot_hpp */
