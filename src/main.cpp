#include <iostream>
#include "Player.h"
#include "Exceptions.h"

int main() {
    Player p("Jan", 100);
    std::cout << p.getWallet() << "\n";

    try {
        p.getWallet() -= 500;
    } catch (const InsufficientFundsException& e) {
        std::cout << "Blad: " << e.what() << "\n";
        p.getWallet().borrow(300);
    }
    std::cout << p.getWallet() << "\n";
    return 0;
}