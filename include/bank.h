#pragma once

#include "database.h"
#include "account.h"

class bank
{
private:
    database& accounts_;

public:
    bank(database& db) : accounts_{db} {}
    
    auto open_account(account_builder&)           noexcept;
    void check_balance(unsigned id)         const noexcept;
    void deposit(unsigned id, double amount)      noexcept;
    void withdraw(unsigned id, double amount)     noexcept;
    void close_account(unsigned id)               noexcept;
    void list_accounts()                    const noexcept;
};