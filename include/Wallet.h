#pragma once
#include <iostream>

class Wallet {
private:
    int balance_;
    int debt_;
    static const int MAX_DEBT = 1000;
    static const int LOAN_FEE_PERCENT = 10;

public:
    Wallet();
    explicit Wallet(int balance);

    int getBalance() const;
    int getDebt() const;
    void setBalance(int balance);

    bool canAfford(int amount) const;
    void deposit(int amount);
    void withdraw(int amount);
    void borrow(int amount);
    void repay(int amount);

    Wallet& operator+=(int amount);
    Wallet& operator-=(int amount);
    friend std::ostream& operator<<(std::ostream& os, const Wallet& w);
};