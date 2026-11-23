#include "Wallet.h"
#include "Exceptions.h"

Wallet::Wallet() : balance_(1000), debt_(0) {}

Wallet::Wallet(int balance) : balance_(balance), debt_(0) {
    if (balance < 0) throw InvalidBetException("Saldo nie moze byc ujemne");
}

int Wallet::getBalance() const { return balance_; }
int Wallet::getDebt() const { return debt_; }

void Wallet::setBalance(int balance) {
    if (balance < 0) throw InvalidBetException("Saldo nie moze byc ujemne");
    balance_ = balance;
}

bool Wallet::canAfford(int amount) const { return balance_ >= amount; }

void Wallet::deposit(int amount) {
    if (amount <= 0) throw InvalidBetException("Kwota musi byc dodatnia");
    balance_ += amount;
}

void Wallet::withdraw(int amount) {
    if (amount <= 0) throw InvalidBetException("Kwota musi byc dodatnia");
    if (!canAfford(amount))
        throw InsufficientFundsException("Za malo srodkow na koncie");
    balance_ -= amount;
}

void Wallet::borrow(int amount) {
    if (amount <= 0) throw InvalidBetException("Kwota musi byc dodatnia");
    int totalDebt = amount + amount * LOAN_FEE_PERCENT / 100;
    if (debt_ + totalDebt > MAX_DEBT)
        throw LoanLimitException("Przekroczono limit zadluzenia");
    balance_ += amount;
    debt_ += totalDebt;
}

void Wallet::repay(int amount) {
    if (amount <= 0) throw InvalidBetException("Kwota musi byc dodatnia");
    if (amount > debt_) amount = debt_;
    withdraw(amount);
    debt_ -= amount;
}

Wallet& Wallet::operator+=(int amount) {
    deposit(amount);
    return *this;
}

Wallet& Wallet::operator-=(int amount) {
    withdraw(amount);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Wallet& w) {
    os << "Saldo: " << w.balance_ << " zl | Dlug: " << w.debt_ << " zl";
    return os;
}