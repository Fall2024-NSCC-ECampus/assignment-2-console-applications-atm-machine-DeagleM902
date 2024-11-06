//
// Created by mattd on 2024-11-05.
//

#include "AccountManager.h"
#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

AccountManager::AccountManager() {
    loadAccounts();
}

//Check if account number exists already
bool AccountManager::createAccount(const string& id, const string& pin) {
    if (!isNumeric(id) || !isNumeric(pin)) {
        cout << "User ID and PIN must contain only numbers (0-9)." << endl;
        return false;
    }
    if (accounts.find(id) != accounts.end()) {
        cout << "User already exists." << endl;
        return false;
    }
    accounts[id] = User(pin, 0.0);
    cout << "Account created successfully." << endl;
    return true;
}

//Check if account number exists and pin is correct
bool AccountManager::verifyLogin(const string& id, const string& pin) {
    if (!isNumeric(id) || !isNumeric(pin)) {
        cout << "User ID and PIN must contain only numbers (0-9)." << endl;
        return false;
    }
    return accounts.find(id) != accounts.end() && accounts[id].pin == pin;
}

User & AccountManager::getUser(const string& id) {
    return accounts.at(id);
}

//Saves account info to text file
void AccountManager::saveAccounts() const {
    ofstream outFile("accounts.txt");
    if(outFile.is_open()) {
        for (const auto& entry: accounts) {
            outFile << entry.first << " " << entry.second.pin << " " << entry.second.balance << endl;
        }
        outFile.close();
    } else {
        cout << "Error occurred while saving accounts." << endl;
    }
}

//Loads account info from text file
void AccountManager::loadAccounts() {
    ifstream inFile("accounts.txt");
    if (inFile.is_open()) {
        accounts.clear();
        string id, pin;
        double balance;
        while (inFile >> id >> pin >> balance) {
            accounts[id] = User(pin, balance);
        }
        inFile.close();
    } else {
        cout << "Error occurred while loading accounts. Starting with empty list." << endl;
    }
}

//To check if given input consists of numbers only
bool AccountManager::isNumeric(const string &string) {
    return regex_match(string, regex("\\d+"));
}

