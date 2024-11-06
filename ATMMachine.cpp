//
// Created by mattd on 2024-11-05.
//

#include "ATMMachine.h"

#include <iomanip>
#include <iostream>

using namespace std;

ATMMachine::ATMMachine() : isLoggedIn(false){}

void ATMMachine::start() {
    char menuInput;
    do {
        printIntroMenu();
        cin >> menuInput;
        switch (menuInput) {
            case 'l':
                login();
                break;
            case 'c':
                createAccount();
                break;
            case 'q':
                accountManager.saveAccounts();
                cout << "Goodbye!" << endl;
                exit(0);
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (menuInput != 'q');
}

void ATMMachine::printIntroMenu() {
    cout << "\nPlease select an option from the menu below:" << endl;
    cout << "l -> Login" << endl;
    cout << "c -> Create New Account" << endl;
    cout << "q -> Quit" << endl;
    cout << "> ";
}

void ATMMachine::printMainMenu() {
    cout << "\nPlease select an option from the menu below:" << endl;
    cout << "d -> Deposit Money" << endl;
    cout << "w -> Withdraw Money" << endl;
    cout << "r -> Request Balance" << endl;
    cout << "q -> Quit" << endl;
    cout << "> ";
}

void ATMMachine::login() {
    string id, pin;
    cout << "Enter your user ID: ";
    cin >> id;
    cout << "Enter your PIN: ";
    cin >> pin;

    if (accountManager.verifyLogin(id, pin)) {
        isLoggedIn = true;
        currentUser = id;
        cout << "Login successful." << endl;
        char menuInput;
        do {
            printMainMenu();
            cin >> menuInput;
            switch (menuInput) {
                case 'd':
                    double depositAmount;
                    cout << "Please enter your deposit amount: ";
                    cin >> depositAmount;
                    deposit(depositAmount);
                    break;
                case 'w':
                    double withdrawAmount;
                    cout << "Please enter your withdrawal amount: ";
                    cin >> withdrawAmount;
                    withdraw(withdrawAmount);
                    break;
                case 'r':
                    checkBalance();
                    break;
                case 'q':
                    //This exits the program entirely, could be reworked to only log out of current account
                    isLoggedIn = false;
                    accountManager.saveAccounts();
                    cout << "Goodbye!" << endl;
                    exit(0);
                default:
                    cout << "Invalid option. Please try again." << endl;
            }
        } while (menuInput != 'q' && isLoggedIn); //isLoggedIn is redundant, kept in case simple logout is desired
    } else {
        cout << "******** LOGIN FAILED! ********" << endl;
    }
}

//Account is created with a balance of 0, must deposit money first :)
void ATMMachine::createAccount() {
    string id, pin;
    cout << "Enter your user ID: ";
    cin >> id;
    cout << "Enter your PIN: ";
    cin >> pin;
    accountManager.createAccount(id, pin);
    accountManager.saveAccounts();
    //TODO - check if this works to save, then loads the info at intro menu
}

void ATMMachine::deposit(double amount) {
    if (amount > 0) {
        accountManager.getUser(currentUser).balance += amount;
        cout << "Deposited " << amount << "\n Your balance is now: $" << accountManager.getUser(currentUser).balance << endl;
    } else {
        cout << "Deposit amount must be above 0." << endl;
    }
}

void ATMMachine::withdraw(double amount) {
    if (amount > 0) {
        if (amount < accountManager.getUser(currentUser).balance) {
            accountManager.getUser(currentUser).balance -= amount;
            cout << "Withdrew " << amount << "\n Your balance is now: $" << accountManager.getUser(currentUser).balance << endl;
        } else {
            cout << "Insufficient funds." << endl;
        }
    } else {
        cout << "Withdraw amount must be above 0." << endl;
    }
}

void ATMMachine::checkBalance() {
    cout << "Current Balance: $" << fixed << setprecision(2) << accountManager.getUser(currentUser).balance << endl;
}



