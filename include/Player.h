#pragma once
#include <string>
#include "Wallet.h"

class Player {
private:
    std::string name_;
    Wallet wallet_;

public:
    Player();
    Player(const std::string& name, int startBalance);

    const std::string& getName() const;
    void setName(const std::string& name);

    Wallet& getWallet();
    const Wallet& getWallet() const;
};