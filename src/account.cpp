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

std::string const& account::first_name() const noexcept
{
    return first_name_;
}

std::string const& account::last_name() const noexcept
{
    return last_name_;
}

std::string const& account::email() const noexcept
{
    return email_;
}

unsigned account::id() const noexcept
{
    return id_;
}

double account::balance() const noexcept
{
    return balance_;
}

void account::withdraw(float amount)
{
    if (accountBalance <= 1000)
        { throw std::out_of_range("you have only a minimum balance"); }
    if (amount > accountBalance - 1000)
        { throw std::invalid_argument("you are trying to pull more than you have"); }
    accountBalance -= amount;
}

std::ofstream& operator<<(std::ofstream& ofs, account const& acc)
{
    return ofs << acc.id()         << '\n'
               << acc.first_name() << '\n'
               << acc.last_name()  << '\n'
               << acc.email()      << '\n'
               << acc.balance()    << '\n';
}

std::ifstream& operator>>(std::ifstream& ifs, account& acc)
{
    return ifs >> acc.id_
               >> acc.first_name_
               >> acc.last_name_
               >> acc.email_
               >> acc.balance_;
}

std::ostream& operator<<(std::ostream& os, account const& acc)
{
    return os << "\n\taccount id: " << acc.id()
              << "\n\tlast  name: " << acc.last_name()
              << "\n\tfirst name: " << acc.first_name()
              << "\n\temail: "      << acc.email()
              << "\n\tbalance: "    << acc.balance()
              << '\n';
}