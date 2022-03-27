#pragma once
#include "account.h"

class account_builder {
private:
  account account_;

public:
  account_builder(std::string, std::string);

  operator account() const noexcept { return std::move(account_); }

  account_builder &email(std::string) noexcept;
  account_builder &last_name(std::string) noexcept;
  account_builder &first_name(std::string const &) noexcept;
  account_builder &balance(double) noexcept;
  account_builder &id(unsigned) noexcept;
  account_builder &type(account_t) noexcept;
};
