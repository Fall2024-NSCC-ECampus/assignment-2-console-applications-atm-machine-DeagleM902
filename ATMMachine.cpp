//
// Created by mattd on 2024-10-24.
//

#include <iostream>
#include <map>
using namespace std;

void printIntroMenu();
void printMainMenu();
void start();
void login();
void createAccount();

//Global variables
char menuInput;
map<string, string> accounts;
double balance;
bool isLoggedIn = false;
string currentUser;

//Main function, header files will be used for part B
int main() {
    cout << "ATM machine start." << endl;
    start();
    return 0;
}

void printIntroMenu() {
    cout << "Please select an option from the menu below:" << endl;
    cout << "l -> Login" << endl;
    cout << "c -> Create New Account" << endl;
    cout << "q -> Quit" << endl;
    cout << "> ";
}

void printMainMenu() {
    cout << "Please select an option from the menu below:" << endl;
    cout << "d -> Deposit Money" << endl;
    cout << "w -> Withdraw Money" << endl;
    cout << "r -> Request Balance" << endl;
    cout << "l -> Logout" << endl;
    cout << "q -> Logout and Quit" << endl;
    cout << "> ";
}

//Logic to handle interaction
void start() {
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
                cout << "Goodbye!" << endl;
                exit(0);
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (menuInput != 'q');
}

//Ideally, there should be a way to back out of account creation
//TODO - PART B - "Database" file to read/write accounts
void createAccount() {
    string id, password;
    cout << "Please create your user id:" << endl;
    cin >> id;
    cout << "Please enter your PIN:" << endl;
    cin >> password;

    accounts[id] = password;
    cout << "Account successfully created." << endl;
}

//Handles login, actions once logged in
//TODO - PART B - Move logic to align with OOP, read file for login
void login() {
    // PHASE 2
}
