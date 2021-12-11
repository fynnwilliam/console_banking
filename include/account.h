#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "account_t.h"
#include "account_builder.h"

class account
{
private:
    unsigned id_;
    double balance_;
    account_t  type_;
    std::string email_;
    std::string last_name_;
    std::string first_name_;
    
    void first_name(std::string const&) noexcept;
    void  last_name(std::string const&) noexcept;
    void      email(std::string const&) noexcept;
    void                type(account_t) noexcept;
    void                   id(unsigned) noexcept;
    void                balance(double) noexcept;

public:
    account() = default;
    account(std::string const&, std::string const&);
    
    std::string const& first_name() const noexcept;
    std::string const&  last_name() const noexcept;
    std::string const&      email() const noexcept;
    account_t                type() const noexcept;
    unsigned                   id() const noexcept;
    double                balance() const noexcept;
    
    void  deposit(double) noexcept;
    void withdraw(double) noexcept;
    
    friend std::ofstream& operator<<(std::ofstream&, account const&);
    friend std::ifstream& operator>>(std::ifstream&, account&);
    friend std::ostream&  operator<<(std::ostream& , account const&);
    
    friend class account_builder;
    static account_builder create(std::string const&, std::string const&);
};