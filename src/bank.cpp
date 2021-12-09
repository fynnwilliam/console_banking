#include "bank.h"

bank::bank()
{
    loadBankData();
}

account bank::openAccount(std::string fname, std::string lname, std::string email, float accBalance)
{
    account acc(fname, lname, email, accBalance);
    accounts.insert({acc.getAccountNumber(), acc});

    updateBankData(accounts);

    return acc;
}

account bank::balanceEnquiry(long accountNumber)
{
    std::map<long, account>::iterator itr = accounts.find(accountNumber);
    return itr->second;
}

account bank::makeDeposit(long accountNumber, float amount)
{
    std::map<long, account>::iterator itr = accounts.find(accountNumber);
    itr->second.deposit(amount);
    return itr->second;
}

account bank::withdrawal(long accountNumber, float amount)
{
    std::map<long, account>::iterator itr = accounts.find(accountNumber);
    itr->second.withdraw(amount);
    return itr->second;
}

void bank::closeAccount(long accountNumber)
{
    std::map<long, account>::iterator itr = accounts.find(accountNumber);
    std::cout << "deleting account " << itr->second.getAccountNumber() << "...\n";
    accounts.erase(accountNumber);
}

void bank::updateBankData(std::map<long, account> activeAccounts)
{
    std::ofstream outfile("bank.data", std::ios::trunc);
    for (auto x : activeAccounts)
    {
        outfile << x.second;
    }
    outfile.close();
}

void bank::loadBankData()
{
    account acc{};

    std::ifstream infile;
    infile.open("bank.data");

    if (!infile.is_open())
    {
        std::cout << "unable to open 'bank.data', file may not exist." << std::endl;
    }
    else
    {
        while (!infile.eof())
        {
            infile >> acc;
            accounts.insert({acc.getAccountNumber(), acc});
        }
    }
    
    account::setLastAccountNumber(acc.getAccountNumber());

    infile.close();
}

void bank::showAccounts()
{
    int count = 1;
    std::map<long, account>::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++)
    {
        std::cout << count << ":\n"
                  << itr->second
                  << std::endl;
        count++;
    }
}

bank::~bank()
{
    if (accounts.empty())
    {
        std::cout << "no account created yet." << std::endl;
    }
    else
    {
        updateBankData(accounts);
    }
}
