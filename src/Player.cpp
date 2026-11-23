#include "Player.h"

Player::Player() : name_("Gracz"), wallet_() {}

Player::Player(const std::string& name, int startBalance)
    : name_(name), wallet_(startBalance) {}

const std::string& Player::getName() const { return name_; }
void Player::setName(const std::string& name) { name_ = name; }

Wallet& Player::getWallet() { return wallet_; }
const Wallet& Player::getWallet() const { return wallet_; }