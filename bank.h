#include "account.h"

class bank
{
private:
    map<long, account> accounts;
public:
    bank();
    account openAccount(string fname, string lname, string email, float accBalance);
    account balanceEnquiry(long accountNumber);
    account makeDeposit(long accountNumber, float amount);
    account withdrawal(long accountNumber, float amount);
    void closeAccount(long accountNumber);
    void showAccounts();
    ~bank();
};