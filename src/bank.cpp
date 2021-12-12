#include "bank.h"
#include "account_builder.h"
#include <regex>

auto bank::open_account(account_builder&& builder) noexcept
{
    unsigned id{new_id()};
    builder.email(email())
           .balance(amount())
           .id(id)
           .type(account_t::savings);
    
    auto const& [acc_itr, is_successful] = accounts_.insert(id, builder);
    return is_successful ? std::make_optional(acc_itr->second) : std::nullopt;
}

void bank::open_account() noexcept
{
    if (auto const& acc = open_account(account::create(last_name(), first_name())))
        std::cout << *acc;
    else
        std::cout << "could not creat account\n";
}

unsigned bank::new_id() const noexcept
{
    static unsigned id{_new_id()};
    return ++id;
}

unsigned bank::_new_id() const noexcept
{
    if (accounts_.empty()) return {};
    
    unsigned a{};
    if (std::ifstream source{"data"}; source.is_open() && !source.eof())
        source >> a;
    return a;
}

void bank::check_balance(unsigned id) const noexcept
{
    if (accounts_.count(id))
        std::cout << accounts_[id].balance() << '\n';
    else
        account_not_found();
}

void bank::check_balance() const noexcept
{
    check_balance(id());
}

void bank::deposit(unsigned id, double amount) noexcept
{
    accounts_.count(id) ? accounts_[id].deposit(amount) : account_not_found();
}

void bank::deposit() noexcept
{
    deposit(id(), amount());
}

void bank::withdraw(unsigned id, double amount) noexcept
{
    accounts_.count(id) ? accounts_[id].withdraw(amount) : account_not_found();
}

void bank::withdraw() noexcept
{
    withdraw(id(), amount());
}

void bank::close_account(unsigned id) noexcept
{
    accounts_.count(id) ? accounts_.erase(id) : account_not_found();
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
    return valid(input) ? std::atol(input.c_str()) : id();
}

double bank::amount() const noexcept
{
    std::string const& input{request("amount")};
    return valid(input) ? std::atol(input.c_str()) : amount();
}

std::string bank::first_name() const noexcept
{
    return std::move(request("first name"));
}

std::string bank::last_name() const noexcept
{
    return std::move(request("last name"));
}

std::string bank::email() const noexcept
{
    std::regex pattern{"(\\w+)(\\.|_)?(\\w+)@(\\w+)(\\.(\\w+))+"};
    std::string& input{request("valid email address")};
    
    return std::regex_match(input, pattern) ? std::move(input) : email();
}

int bank::option() const noexcept
{
    std::string const& s{request("\tselect an option, 0 - 6")};
    return s.size() == 1 && valid(s) && s[0] < '7' ? atoi(s.c_str()) : option();
}

std::string& bank::request(std::string&& statement) const noexcept
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

int bank::inquire() const noexcept
{
    std::cout << "\n\t1. open account"
              << "\n\t2. check balance"
              << "\n\t3. make deposit"
              << "\n\t4. withdraw"
              << "\n\t5. close account"
              << "\n\t6. list accounts"
              << "\n\t0. exit"
              << "\n\n";

    return option();
}