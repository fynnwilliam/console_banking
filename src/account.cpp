#include "account.h"
#include "account_builder.h"

account::account(std::string const& l, std::string const& f)
    : last_name_{std::move(l)}, first_name_{std::move(f)}
{
}

account_builder account::create(std::string const& l_name, std::string const& f_name)
{
    return account_builder{l_name, f_name};
}

void account::first_name(std::string const& f) noexcept
{
    first_name_ = std::move(f);
}

void account::last_name(std::string const& l) noexcept
{
    last_name_ = std::move(l);
}

void account::email(std::string const& address) noexcept
{
    email_ = std::move(address);
}

void account::type(account_t t) noexcept
{
    type_ = t;
}

void account::id(unsigned id) noexcept
{
    id_ = id;
}

void account::balance(double b) noexcept
{
    balance_ = b;
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

account_t account::type() const noexcept
{
    return type_;
}

unsigned account::id() const noexcept
{
    return id_;
}

double account::balance() const noexcept
{
    return balance_;
}

void account::deposit(double amount) noexcept
{
    if (amount) balance_ += amount;
}

void account::withdraw(double amount) noexcept
{
    if (amount < balance_ - 100)
        balance_ -= amount;
    else
        std::cout << "could not perform withdraw - insuficient funds\n";
}

std::ofstream& operator<<(std::ofstream& ofs, account const& acc)
{
    ofs << acc.id()         << '\n'
        << acc.last_name()  << '\n'
        << acc.first_name() << '\n'
        << acc.email()      << '\n'
        << acc.balance()    << '\n';

     return ofs;
}

std::ifstream& operator>>(std::ifstream& ifs, account& acc)
{
    ifs >> acc.id_
        >> acc.last_name_
        >> acc.first_name_
        >> acc.email_
        >> acc.balance_;

    return ifs;
}

std::ostream& operator<<(std::ostream& os, account const& acc)
{
    return os <<   "\taccount id: " << acc.id()
              << "\n\tlast  name: " << acc.last_name()
              << "\n\tfirst name: " << acc.first_name()
              << "\n\temail: "      << acc.email()
              << "\n\tbalance: "    << acc.balance()
              << '\n';
}