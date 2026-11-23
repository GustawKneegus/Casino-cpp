#pragma once
#include <stdexcept>
#include <string>

class InsufficientFundsException : public std::runtime_error {
public:
    explicit InsufficientFundsException(const std::string& msg)
        : std::runtime_error(msg) {}
};

class InvalidBetException : public std::runtime_error {
public:
    explicit InvalidBetException(const std::string& msg)
        : std::runtime_error(msg) {}
};

class LoanLimitException : public std::runtime_error {
public:
    explicit LoanLimitException(const std::string& msg)
        : std::runtime_error(msg) {}
};
