#include "bank.h"

account bank::openAccount(std::string fname, std::string lname, std::string email, float accBalance)
{
    account acc(fname, lname, email, accBalance);
    accounts.insert({acc.getAccountNumber(), acc});

    updateBankData(accounts);

    return acc;
}

void bank::check_balance(unsigned id) const noexcept
{
    std::cout << accounts_.find(id).value_or("account not found\n");
}

void bank::deposit(long accountNumber, double amount) noexcept
{
    if (amount < 0)
        std::cout << "cannot deposit negative values\n";
    else if (auto& acc = accounts_.find(id))
        acc->deposit(amount);
    else
        std::cout << "account not found\n";
}

void bank::withdraw(unsigned id, double amount) noexcept
{
    if (amount < 0)
        std::cout << "cannot withdraw negative values\n";
    else if (auto& acc = accounts_.find(id))
        acc->withdraw(amount);
    else
        std::cout << "account not found\n";
}

void bank::close_account(unsigned id) noexcept
{
    if (accounts_.find(id))
        accounts_.erase(id);
    else
        std::cout << "account not found\n";
}

void bank::list_accounts() const noexcept
{
    std::size_t count{};
    for (auto const& [_, acc] : accounts_)
        std::cout << ++count << '\n' << acc << '\n';
}