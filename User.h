//
// Created by mattd on 2024-11-05.
//

#ifndef USER_H
#define USER_H

#include <string>
#include <utility>

using namespace std;

struct User {
    string pin;
    double balance;

    User() : balance(0.0) {}
    User(string pin, double balance) : pin(move(pin)), balance(balance) {}
};

#endif //USER_H
