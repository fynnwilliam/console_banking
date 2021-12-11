#include "bank.h"
#include <functional>

auto bank::open_account(account_builder& builder) noexcept
{
    unsigned   id{new_id()};
    builder.id(id)
           .type(account_t::savings);
    
    auto const& [acc_itr, is_successful] = accounts_.insert({id, builder});
    
    return is_successful ? std::optional<std::reference_wrapper<account>>{acc_itr->second}
                         : std::nullopt;
}

unsigned bank::new_id() const noexcept
{
    static unsigned id{_new_id()};
    return ++id;
}

unsigned bank::_new_id() const noexcept
{
    if (accounts_.empty()) return {};
    
    auto a{accounts_.begin()->id()};
    auto b{(accounts_.end() - 1)->id()};
    
    return std::max(a, b);
}

void bank::check_balance(unsigned id) const noexcept
{
    std::cout << accounts_.find(id).value_or("account not found\n");
}

void bank::deposit(unsigned id, double amount) noexcept
{
    if (auto& acc = accounts_.find(id))
        acc->deposit(amount);
    else
        std::cout << "account not found\n";
}

void bank::deposit() noexcept
{
    deposit(id(), amount());
}

void bank::withdraw(unsigned id, double amount) noexcept
{
    if (auto& acc = accounts_.find(id))
        acc->withdraw(amount);
    else
        std::cout << "account not found\n";
}

void bank::withdraw() noexcept
{
    withdraw(id(), amount());
}

void bank::close_account(unsigned id) noexcept
{
    if (accounts_.find(id))
        accounts_.erase(id);
    else
        std::cout << "account not found\n";
}

void bank::close_account() noexcept
{   
    close_account(id());
}

void bank::list_accounts() const noexcept
{
    std::size_t count{};
    for (auto const& [_, acc] : accounts_)
        std::cout << ++count << '\n' << acc << '\n';
}

unsigned bank::id() const noexcept
{
    std::string const& input{request("enter a valid account id")};    
    return valid(input) ? atol(input.c_str()) : id();
}

bool bank::valid(std::string const& s) const noexcept
{
    for (char c : s)
        if (!std::isdigit(c)) return false;
    return true;
}

double bank::amount() const noexcept
{
    std::string const& input{request("enter an amount")};
    return valid(input) ? atol(input.c_str()) : amount();
}

std::string const& bank::request(std::string&& statement) const noexcept
{
    static std::string input{};
    std::cout << statement << ": ";
    std::getline(std::cin, input);
    
    return input;
}