#pragma once
#include <iostream>
#include <fstream>
#include <string>

class account
{
private:
    unsigned id_;
    double balance_;
    std::string email_;
    std::string last_name_;
    std::string first_name_;

public:
    account() = default;
    account(std::string fname, std::string lname, std::string email, float accBalance);
    std::string getFirstName() { return firstName; }
    std::string getLastName() { return lastName; }
    std::string getEmail() { return email; }
    long getAccountNumber() { return accountNumber; }
    float getAccountBalance() { return accountBalance; }

    void deposit(float amount);
    void withdraw(float amount);
    friend std::ofstream &operator<<(std::ofstream &outfile, account &acc);
    friend std::ifstream &operator>>(std::ifstream &infile, account &acc);
    friend std::ostream &operator<<(std::ostream &display, account &acc);
};