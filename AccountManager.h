//
// Created by mattd on 2024-11-05.
//

#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H
#include <string>
#include <map>
#include "User.h"

using namespace std;

class AccountManager {
public:
    AccountManager();
    bool createAccount(const string& id, const string& pin);
    bool verifyLogin(const string& id, const string& pin);
    User& getUser(const string& id);
    void saveAccounts() const;
    void loadAccounts();
    static bool isNumeric(const string &string);

private:
    map<string, User> accounts;
};

#endif //ACCOUNTMANAGER_H
