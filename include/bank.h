#pragma once

#include "database.h"
#include "account.h"

class bank
{
private:
    database& accounts_;

public:
    bank(database& db) : accounts_{db} {}
    account openAccount(std::string fname, std::string lname, std::string email, float accBalance);
    void check_balance(unsigned id) const noexcept;
    account makeDeposit(long accountNumber, float amount);
    account withdrawal(long accountNumber, float amount);
    void closeAccount(long accountNumber);
    void updateBankData(std::map<long, account> activeAccounts);
    void loadBankData();
    void showAccounts();
    ~bank();
};