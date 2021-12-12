#include "account_builder.h"

account_builder::account_builder(std::string const& l_name, std::string const& f_name)
    : account_{l_name, f_name}
{
}

account_builder& account_builder::email(std::string const& address) noexcept
{
    account_.email(address);
    return *this;
}

account_builder& account_builder::last_name(std::string const& l) noexcept
{
    account_.last_name(l);
    return *this;
}

account_builder& account_builder::first_name(std::string const& f) noexcept
{
    account_.first_name(f);
    return *this;
}

account_builder& account_builder::balance(double b) noexcept
{
    account_.balance(b);
    return *this;
}

account_builder& account_builder::id(unsigned i) noexcept
{
    account_.id(i);
    return *this;
}

account_builder& account_builder::type(account_t t) noexcept
{
    account_.type(t);
    return *this;
}