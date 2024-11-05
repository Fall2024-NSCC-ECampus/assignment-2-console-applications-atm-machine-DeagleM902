//
// Created by mattd on 2024-11-05.
//

#include "AccountManager.h"
#include <fstream>
#include <iostream>

using namespace std;

AccountManager::AccountManager() {
    loadAccounts();
}

bool AccountManager::createAccount(const string& id, const string& pin) {
}

bool AccountManager::verifyLogin(const string& id, const string& pin) {
}

User & AccountManager::getUser(const string& id) {
}

void AccountManager::saveAccounts() {
}

void AccountManager::loadAccounts() {
}

