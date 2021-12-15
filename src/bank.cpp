#include <regex>

#include "bank.h"
#include "account_builder.h"

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
    
    unsigned a{accounts_.cbegin()->first};
    unsigned b{};
    if (std::ifstream source{"data", std::ios::in})
        source >> b;
    return std::max(a, b);
}

void bank::check_balance(unsigned id) const noexcept
{
    if (std::optional<account> acc{accounts_.find(id)}; acc)
        std::cout << "your balance is " << acc->balance() << '\n';
    else
        account_not_found();
}

void bank::check_balance() const noexcept
{
    check_balance(id());
}

void bank::deposit(unsigned id, double amount) noexcept
{
    auto acc{accounts_.find(id)};
    acc ? acc->get().deposit(amount) : account_not_found();
}

void bank::deposit() noexcept
{
    deposit(id(), amount());
}

void bank::withdraw(unsigned id, double amt) noexcept
{
    if (auto acc{accounts_.find(id)}; acc)
        acc->get().withdrawable(amt) ? acc->get().withdraw(amt) : low_funds();
    else account_not_found();
}

void bank::low_funds() const noexcept
{
    std::cout << "could not withdraw amount - insufficient funds\n";
}

void bank::withdraw() noexcept
{
    withdraw(id(), amount());
}

void bank::close_account(unsigned id) noexcept
{
    accounts_.contains(id) ? deprecate_account(id) : account_not_found();
}

void bank::deprecate_account(unsigned id) noexcept
{
    archive_account(id);
    accounts_.erase(id);
}

void bank::archive_account(unsigned id) const noexcept
{
    std::ofstream archive{"archive", std::ios::app};
    archive << accounts_[id];
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

void bank::list_transactions() const noexcept
{
    for (auto const& [_, acc] : accounts_)
        acc.list_transactions();
}

bool bank::inspect(std::string const& input) const noexcept
{
    for (char c : input)
        if (!std::isdigit(c)) return false;
    return true;
}

bool bank::valid(std::string const& s) const noexcept
{    
    return s.size() == 1 && s[0] == '0' ? false : inspect(s);
}

unsigned bank::id() const noexcept
{
    std::string const& input{request("account id")};    
    return valid(input) ? std::atoi(input.c_str()) : id();
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
    std::string const& s{request("\tselect an option, 0..6")};
    return s.size() == 1 && s[0] >= '0' && s[0] < '8' ? atoi(s.c_str()) : option();
}

std::string& bank::request(std::string&& statement) const noexcept
{
    static std::string input{};
    std::cout << statement << ": ";
    std::getline(std::cin, input);
    
    return trim(input);
}

std::string& bank::trim(std::string& s) const noexcept
{
    trim_back(s);
    trim_front(s);
    return s;
}

void bank::trim_back(std::string& s) const noexcept
{
    while (s.ends_with(' ') || s.ends_with('\t')) s.pop_back();
}

void bank::trim_front(std::string& s) const noexcept
{
    while (s.starts_with(' ') || s.starts_with('\t')) s.erase(0, 1);
}

void bank::account_not_found() const noexcept
{
    std::cout << "account not found\n";
}

int bank::_inquire() const noexcept
{
    std::cout << "\n\t1. open account"
              << "\n\t2. check balance"
              << "\n\t3. make deposit"
              << "\n\t4. withdraw"
              << "\n\t5. close account"
              << "\n\t6. list accounts"
              << "\n\t7. list transactions"
              << "\n\t0. exit"
              << "\n\n";

    return option();
}

void bank::inquire() noexcept
{
    while (int option = _inquire())
        deliver(option);
    
    std::cout << "\n\tnice, have a great day!" << std::endl;
}

void bank::deliver(int option) noexcept
{
    switch (option)
    {
        case 1: open_account();      break;
        case 2: check_balance();     break;
        case 3: deposit();           break;
        case 4: withdraw();          break;
        case 5: close_account();     break;
        case 6: list_accounts();     break;
        case 7: list_transactions(); break;
    }
}