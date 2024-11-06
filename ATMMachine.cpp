//
// Created by mattd on 2024-11-05.
//

#include "ATMMachine.h"

#include <iomanip>
#include <iostream>
#include <limits>

using namespace std;

ATMMachine::ATMMachine() : isLoggedIn(false){}

void ATMMachine::start() {
    char menuInput;
    do {
        printIntroMenu();
        cin >> menuInput;

        //Ignore all but the first character entered
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        //The other input error handling does not work here
        // if (cin.fail()) {
        //     cin.clear();
        //     cin.ignore(1000, '\n');
        //     cout << "Invalid input. Please enter 'l', 'c', or 'q'." << endl;
        //     continue;
        // }

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
    cout << "l -> Logout" << endl;
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

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
                case 'l': //Ideally this would clear the screen to hide previous information
                    isLoggedIn = false;
                    accountManager.saveAccounts();
                    cout << "Logging out." << endl;
                    break;
                case 'q':
                    isLoggedIn = false;
                    accountManager.saveAccounts();
                    cout << "Goodbye!" << endl;
                    exit(0);
                default:
                    cout << "Invalid option. Please try again." << endl;
            }
        } while (menuInput != 'q' && isLoggedIn);
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
    accountManager.saveAccounts(); //Likely redundant, as quitting correctly will save user info
}

void ATMMachine::deposit(double amount) {
    //Clear the input buffer if there is an error.
    if (cin.fail() || amount <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Deposit amount must be above 0." << endl;
        return;
    }
    accountManager.getUser(currentUser).balance += amount;
    cout << "Deposited: $" << amount << "\nYour balance is now: $" << accountManager.getUser(currentUser).balance << endl;
}

void ATMMachine::withdraw(double amount) {
    //Clear the input buffer if there is an error.
    if (cin.fail() || amount <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Withdraw amount must be above 0." << endl;
        return;
    }
    if (amount > accountManager.getUser(currentUser).balance) {
        cout << "Insufficient funds." << endl;
        return;
    }
    accountManager.getUser(currentUser).balance -= amount;
    cout << "Withdrew: $" << amount << "\nYour balance is now: $" << accountManager.getUser(currentUser).balance << endl;
}

void ATMMachine::checkBalance() {
    cout << "Current Balance: $" << fixed << setprecision(2) << accountManager.getUser(currentUser).balance << endl;
}



