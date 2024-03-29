#include "account_builder.h"

account_builder::account_builder(std::string l_name, std::string f_name)
    : account_{std::move(l_name), std::move(f_name)} {}

account_builder &account_builder::email(std::string address) noexcept {
  account_.email(std::move(address));
  return *this;
}

account_builder &account_builder::last_name(std::string l) noexcept {
  account_.last_name(std::move(l));
  return *this;
}

account_builder &account_builder::first_name(std::string f) noexcept {
  account_.first_name(std::move(f));
  return *this;
}

account_builder &account_builder::balance(double b) noexcept {
  account_.balance(b);
  return *this;
}

account_builder &account_builder::id(unsigned i) noexcept {
  account_.id(i);
  return *this;
}

account_builder &account_builder::type(account_t t) noexcept {
  account_.type(t);
  return *this;
}
