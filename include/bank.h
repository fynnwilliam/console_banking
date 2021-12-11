#pragma once

#include "database.h"
#include "account.h"

class bank
{
private:
    database& accounts_;
    
    unsigned  new_id() const noexcept;
    unsigned _new_id() const noexcept;
    unsigned      id() const noexcept;
    double    amount() const noexcept;
    bool            valid(std::string const&) const noexcept;
    std::string const& request(std::string&&) const noexcept;
    std::string const& bank::last_name() const noexcept;
    std::string const& bank::first_name() const noexcept;
    std::string const& bank::email() const noexcept;
    void               account_not_found()    const noexcept;

public:
    bank(database& db) : accounts_{db} {}
    
    auto open_account(account_builder&&)        noexcept;
    void check_balance(unsigned)         const noexcept;
    void       deposit(unsigned, double)       noexcept;
    void      withdraw(unsigned, double)       noexcept;
    void close_account(unsigned)               noexcept;
    void list_accounts()                 const noexcept;
    void close_account() noexcept;
    void withdraw()      noexcept;
    void  deposit()      noexcept;
    void check_balance() const noexcept;
    void open_account() noexcept;
    void inquire() const noexcept;
};