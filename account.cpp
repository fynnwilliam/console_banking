#include "account.h"

long account::nextAccountNumber = 0.00;

account::account(string fname, string lname, string email, float accBalance)
{
    firstName = fname;
    lastName = lname;
    this -> email = email;
    accountBalance = accBalance;
    nextAccountNumber++;
    accountNumber = nextAccountNumber;
}

void account::deposit(float amount)
{
    accountBalance += amount;
}

void account::withdraw(float amount)
{
    if (accountBalance < 1000)
        throw insufficientFunds();
    accountBalance -= amount;
}

void account::setLastAccountNumber(long accountNumber)
{
    nextAccountNumber = accountNumber;
}

long account::getLastAccountNumber()
{
    return nextAccountNumber;
}

ofstream& operator << (ofstream& outfile, account& acc)
{
    outfile << acc.accountNumber << "\n"
            << acc.firstName << "\n"
            << acc.lastName << "\n"
            << acc.email << "\n"
            << acc.accountBalance << "\n";

    return outfile;
}

ifstream& operator >> (ifstream& infile, account& acc)
{
    infile >> acc.accountNumber
           >> acc.firstName
           >> acc.lastName
           >> acc.email
           >> acc.accountNumber;

    return infile;
}

ostream& operator << (ostream& display, account& acc)
{
    display << "\n\tfirst name: " << acc.getFirstName() << "\n"
            << "\tlast name: " << acc.getLastName() << "\n"
            << "\temail: " << acc.getEmail() << "\n"
            << "\taccount number: " << acc.getAccountNumber() << "\n"
            << "\taccount balance: " << acc.getAccountBalance() << "\n";

    return display;
}

account::~account()
{

}