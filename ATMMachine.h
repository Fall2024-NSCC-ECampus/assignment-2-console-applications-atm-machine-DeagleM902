//
// Created by mattd on 2024-11-05.
//

#ifndef ATMMACHINE_H
#define ATMMACHINE_H
#include "AccountManager.h"

using namespace std;

class ATMMachine {
public:
    ATMMachine();
    void start();

private:
    void printIntroMenu();
    void printMainMenu();
    void login();
    void createAccount();
    void deposit(double amount);
    void withdraw(double amount);
    void checkBalance();

    bool isLoggedIn;
    string currentUser;
    AccountManager accountManager;
};



#endif //ATMMACHINE_H
