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

void bank::check_balance() const noexcept
{
    check_balance(id());
}

void bank::deposit(unsigned id, double amount) noexcept
{
    (auto& acc = accounts_.find(id)) ? acc->deposit(amount) : account_not_found();
}

void bank::deposit() noexcept
{
    deposit(id(), amount());
}

void bank::withdraw(unsigned id, double amount) noexcept
{
    (auto& acc = accounts_.find(id)) ? acc->withdraw(amount) : account_not_found();
}

void bank::withdraw() noexcept
{
    withdraw(id(), amount());
}

void bank::close_account(unsigned id) noexcept
{
    accounts_.find(id) ? accounts_.erase(id) : account_not_found();
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

bool bank::valid(std::string const& s) const noexcept
{
    for (char c : s)
        if (!std::isdigit(c)) return false;
    return true;
}

unsigned bank::id() const noexcept
{
    std::string const& input{request("account id")};    
    return valid(input) ? atol(input.c_str()) : id();
}

double bank::amount() const noexcept
{
    std::string const& input{request("amount")};
    return valid(input) ? atol(input.c_str()) : amount();
}

std::string const& bank::first_name() const noexcept
{
    return request("first name");
}

std::string const& bank::last_name() const noexcept
{
    return request("last name");
}

std::string const& bank::email() const noexcept
{
    std::regex pattern{"(\\w+)(\\.|_)?(\\w+)@(\\w+)(\\.(\\w+))+"};
    std::string const& input{request("valid email address")};
    
    return std::regex_match(input, pattern) ? input : email();
}

std::string const& bank::request(std::string&& statement) const noexcept
{
    static std::string input{};
    std::cout << statement << ": ";
    std::getline(std::cin, input);
    
    return input;
}

void bank::account_not_found() const noexcept
{
    std::cout << "account not found\n";
}