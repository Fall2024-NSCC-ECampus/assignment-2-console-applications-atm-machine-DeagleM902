//
// Created by mattd on 2024-10-24.
//

#include <iomanip>
#include <iostream>
#include <map>
using namespace std;

void printIntroMenu();
void printMainMenu();
void start();
void login();
void createAccount();

//TODO - For part B, use header files, persistent user data, regex for ID and PIN

//Global variables
char menuInput;

//For part B, create a User struct to store the PIN and balance. change this to "map<string, User> accounts"
//For the map - a unique ID is needed -> error handling in user creation. Or use a different list/set/etc
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

// void printIntroMenu() {
//     cout << "\nPlease select an option from the menu below:" << endl;
//     cout << "l -> Login" << endl;
//     cout << "c -> Create New Account" << endl;
//     cout << "q -> Quit" << endl;
//     cout << "> ";
// }
//
// void printMainMenu() {
//     cout << "\nPlease select an option from the menu below:" << endl;
//     cout << "d -> Deposit Money" << endl;
//     cout << "w -> Withdraw Money" << endl;
//     cout << "r -> Request Balance" << endl;
//     cout << "q -> Quit" << endl;
//     cout << "> ";
// }
//
// //Logic to handle interaction
// void start() {
//     do {
//         printIntroMenu();
//         cin >> menuInput;
//         switch (menuInput) {
//             case 'l':
//                 login();
//                 break;
//             case 'c':
//                 createAccount();
//                 break;
//             case 'q':
//                 cout << "Goodbye!" << endl;
//                 exit(0);
//             default:
//                 cout << "Invalid option. Please try again." << endl;
//         }
//     } while (menuInput != 'q');
// }
//
// //Ideally, there should be a way to back out of account creation
// //Currently accepts a generic string input, regex / error handling will be added
// //TODO - PART B - "Database" file to read/write accounts (also needs the balance) - User ID must be unique!!!
// void createAccount() {
//     string id, password;
//     cout << "Please enter your user id: ";
//     cin >> id;
//     cout << "Please enter your PIN: ";
//     cin >> password;
//
//     accounts[id] = password;
//     cout << "Account successfully created." << endl;
// }
//
// //Handles login, actions once logged in
// //TODO - PART B - Move logic to align with OOP, read file for login
// void login() {
//     string id, password;
//     cout << "Please enter your user id: ";
//     cin >> id;
//     cout << "Please enter your PIN: ";
//     cin >> password;
//
//     if (accounts.find(id) != accounts.end() && accounts[id] == password) {
//         cout << "Access Granted!" << endl;
//         isLoggedIn = true;
//         currentUser = id;
//
//         do {
//             printMainMenu();
//             cin >> menuInput;
//             //Divide logic, each case should call its respective function
//             switch (menuInput) {
//                 case 'd':
//                     double depositAmount;
//                     cout << "Please enter your deposit amount: ";
//                     cin >> depositAmount;
//                     balance += depositAmount;
//                     cout << "Your balance is now: $" << fixed << setprecision(2) << balance << endl;
//                     break;
//                 case 'w':
//                     double withdrawAmount;
//                     cout << "Please enter your withdrawal amount: ";
//                     cin >> withdrawAmount;
//                     if (withdrawAmount <= balance) {
//                         balance -= withdrawAmount;
//                         cout << "Your balance is now: $" << fixed << setprecision(2) << balance << endl;
//                     } else {
//                         cout << "Insufficient funds." << endl;
//                     }
//                     break;
//                 case 'r':
//                     cout << "Your balance is: $" << fixed << setprecision(2) << balance << endl;
//                     break;
//                 case 'q':
//                     cout << "Goodbye!" << endl;
//                     exit(0);
//                 default:
//                     cout << "Invalid option. Please try again." << endl;
//             }
//         } while (menuInput != 'q');
//     } else {
//         cout << "******** LOGIN FAILED! ********" << endl;
//     }
// }
