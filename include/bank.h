#pragma once

#include "database.h"

class bank
{
private:
    database& accounts_;
    
    unsigned  new_id() const noexcept;
    unsigned _new_id() const noexcept;
    unsigned  id()     const noexcept;
    double    amount() const noexcept;
    int       option() const noexcept;

    std::string last_name()  const noexcept;
    std::string first_name() const noexcept;
    std::string email()      const noexcept;
    
    void account_not_found()       const noexcept;
    bool valid(std::string const&) const noexcept;
    void check_balance(unsigned)   const noexcept;
    void deposit(unsigned, double)       noexcept;
    void withdraw(unsigned, double)      noexcept;
    void close_account(unsigned)         noexcept;
    
    std::string& request(std::string&&) const noexcept;
    auto open_account(account_builder&&)      noexcept;

public:
    bank(database& db) : accounts_{db} {}
    
    void list_accounts() const noexcept;
    void close_account()       noexcept;
    void withdraw()            noexcept;
    void deposit()             noexcept;
    void check_balance() const noexcept;
    void open_account()        noexcept;
    void deliver(int)          noexcept;
    int  inquire()       const noexcept;
};