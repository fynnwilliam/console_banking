#include "bank.h"

bank::bank()
{
    loadBankData();
}

account bank::openAccount(string fname, string lname, string email, float accBalance)
{
    account acc(fname, lname, email, accBalance);
    accounts.insert({acc.getAccountNumber(), acc});

    updateBankData(accounts);

    return acc;
}

account bank::balanceEnquiry(long accountNumber)
{
    map<long, account>::iterator itr = accounts.find(accountNumber);
    return itr->second;
}

account bank::makeDeposit(long accountNumber, float amount)
{
    map<long, account>::iterator itr = accounts.find(accountNumber);
    itr->second.deposit(amount);
    return itr->second;
}

account bank::withdrawal(long accountNumber, float amount)
{
    map<long, account>::iterator itr = accounts.find(accountNumber);
    itr->second.withdraw(amount);
    return itr->second;
}

void bank::closeAccount(long accountNumber)
{
    map<long, account>::iterator itr = accounts.find(accountNumber);
    cout << "deleting account " << itr->second.getAccountNumber() << "...\n";
    accounts.erase(accountNumber);
}

void bank::updateBankData(map<long, account> activeAccounts)
{
    ofstream outfile("bank.data", ios::trunc);
    for (auto x : activeAccounts)
    {
        outfile << x.second;
    }
    outfile.close();
}

void bank::loadBankData()
{
    account acc{};

    ifstream infile;
    infile.open("bank.data");

    if (!infile.is_open())
    {
        cout << "unable to open 'bank.data', file may not exist." << endl;
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
    map<long, account>::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++)
    {
        cout << count << ":\n"
             << itr->second
             << endl;
        count++;
    }
}

bank::~bank()
{
    if (accounts.empty())
    {
        cout << "no account created yet." << endl;
    }
    else
    {
        updateBankData(accounts);
    }
}
