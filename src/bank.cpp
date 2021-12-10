#include "bank.h"

auto bank::open_account(account_builder& builder) noexcept
{
    unsigned   id{new_id()};
    builder.id(id)
           .type(account_t::savings);
    
    auto const& [acc_itr, is_successful] = accounts_.insert({id, builder});
    
    return is_successful ? std::optional<std::reference_wrapper<account>>{acc_itr->second}
                         : std::nullopt;
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