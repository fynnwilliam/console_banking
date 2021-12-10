#pragma once

#include "database.h"
#include "account.h"

class bank
{
private:
    database& accounts_;

public:
    bank();
    account openAccount(std::string fname, std::string lname, std::string email, float accBalance);
    account balanceEnquiry(long accountNumber);
    account makeDeposit(long accountNumber, float amount);
    account withdrawal(long accountNumber, float amount);
    void closeAccount(long accountNumber);
    void updateBankData(std::map<long, account> activeAccounts);
    void loadBankData();
    void showAccounts();
    ~bank();
};