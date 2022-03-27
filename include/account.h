#pragma once

#include "account_t.h"
#include "transaction.h"

class account_builder;

class account {
private:
  unsigned id_{0};
  account_t type_;
  double balance_{0.0};
  std::string email_;
  std::string last_name_;
  std::string first_name_;
  transaction logs_;

  void first_name(std::string const &) noexcept;
  void last_name(std::string const &) noexcept;
  void email(std::string const &) noexcept;
  void _list_transactions() const noexcept;
  void type(account_t) noexcept;
  void id(unsigned) noexcept;
  void balance(double) noexcept;
  void no_activity() const noexcept;

public:
  account() = default;
  account(std::string, std::string);

  std::string const &first_name() const noexcept;
  std::string const &last_name() const noexcept;
  std::string const &email() const noexcept;

  account_t type() const noexcept;
  unsigned id() const noexcept;
  double balance() const noexcept;

  void read_logs() noexcept;
  void write_logs() const noexcept;
  void list_transactions() noexcept;
  void deposit(double) noexcept;
  void withdraw(double) noexcept;
  bool withdrawable(double) const noexcept;

  friend std::ifstream &operator>>(std::ifstream &, account &);

  friend class account_builder;
  static account_builder create(std::string const &, std::string const &);
};

std::ofstream &operator<<(std::ofstream &, account const &);
std::ostream &operator<<(std::ostream &, account const &);