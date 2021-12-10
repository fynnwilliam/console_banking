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
    std::string const& first_name() const noexcept;
    std::string const&  last_name() const noexcept;
    std::string const&      email() const noexcept;
    unsigned    id() const noexcept;
    double balance() const noexcept;
    
    void  deposit(double) noexcept;
    void withdraw(double) noexcept;
    friend std::ofstream &operator<<(std::ofstream &outfile, account &acc);
    friend std::ifstream &operator>>(std::ifstream &infile, account &acc);
    friend std::ostream &operator<<(std::ostream &display, account &acc);
};