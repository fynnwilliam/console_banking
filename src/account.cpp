#include "account.h"

account::account(std::string fname, std::string lname, std::string email, float accBalance)
    : firstName(fname),
      lastName(lname),
      email(email),
      accountBalance(accBalance),
      accountNumber(++nextAccountNumber)
{
}

void account::deposit(float amount)
{
    accountBalance += amount;
}


unsigned account::id() const noexcept
{
    return id_;
}

void account::withdraw(float amount)
{
    if (accountBalance <= 1000)
        { throw std::out_of_range("you have only a minimum balance"); }
    if (amount > accountBalance - 1000)
        { throw std::invalid_argument("you are trying to pull more than you have"); }
    accountBalance -= amount;
}

std::ofstream &operator<<(std::ofstream &outfile, account &acc)
{
    outfile << acc.accountNumber << "\n"
            << acc.firstName << "\n"
            << acc.lastName << "\n"
            << acc.email << "\n"
            << acc.accountBalance << "\n";

    return outfile;
}

std::ifstream &operator>>(std::ifstream &infile, account &acc)
{
    infile >> acc.accountNumber >> acc.firstName >> acc.lastName >> acc.email >> acc.accountNumber;

    return infile;
}

std::ostream &operator<<(std::ostream &display, account &acc)
{
    display << "\n\tfirst name: " << acc.getFirstName() << "\n"
            << "\tlast name: " << acc.getLastName() << "\n"
            << "\temail: " << acc.getEmail() << "\n"
            << "\taccount number: " << acc.getAccountNumber() << "\n"
            << "\taccount balance: " << acc.getAccountBalance() << "\n";

    return display;
}