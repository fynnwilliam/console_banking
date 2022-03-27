#include "account.h"
#include "account_builder.h"
#include <locale>

account::account(std::string l, std::string f)
    : last_name_{std::move(l)}, first_name_{std::move(f)} {}

account_builder account::create(std::string const &l_name,
                                std::string const &f_name) {
  return account_builder{l_name, f_name};
}

void account::first_name(std::string const &f) noexcept { first_name_ = f; }

void account::last_name(std::string const &l) noexcept { last_name_ = l; }

void account::email(std::string address) noexcept {
  email_ = std::move(address);
}

void account::type(account_t t) noexcept { type_ = t; }

void account::id(unsigned id) noexcept { id_ = id; }

void account::balance(double b) noexcept { balance_ = b; }

std::string const &account::first_name() const noexcept { return first_name_; }

std::string const &account::last_name() const noexcept { return last_name_; }

std::string const &account::email() const noexcept { return email_; }

account_t account::type() const noexcept { return type_; }

unsigned account::id() const noexcept { return id_; }

double account::balance() const noexcept { return balance_; }

void account::deposit(double amount) noexcept {
  balance_ += amount;
  logs_.log({activity_t::received, amount});
}

void account::withdraw(double amount) noexcept {
  balance_ -= amount;
  logs_.log({activity_t::withdrew, amount});
}

bool account::withdrawable(double amount) const noexcept {
  return amount <= balance() - 100;
}

void account::list_transactions() noexcept {
  read_logs();
  !logs_.empty() ? _list_transactions() : no_activity();
}

void account::_list_transactions() const noexcept {
  for (auto const &[t_id, act] : logs_)
    std::cout << "transaction id: " << t_id << '\n' << act;
}

void account::no_activity() const noexcept {
  std::cout << "no activities yet\n";
}

void account::read_logs() noexcept { logs_.read(std::to_string(id())); }

void account::write_logs() const noexcept {
  if (!logs_.empty())
    logs_.write(std::to_string(id()));
}

std::ofstream &operator<<(std::ofstream &ofs, account const &acc) {
  ofs << acc.id() << '\n'
      << acc.last_name() << '\n'
      << acc.first_name() << '\n'
      << acc.email() << '\n'
      << acc.balance() << '\n';

  acc.write_logs();
  return ofs;
}

std::ifstream &operator>>(std::ifstream &ifs, account &acc) {
  ifs >> acc.id_ >> acc.last_name_ >> acc.first_name_ >> acc.email_ >>
      acc.balance_;

  return ifs;
}

std::ostream &operator<<(std::ostream &os, account const &acc) {
  os.imbue(std::locale("en_US.UTF-8"));
  return os << "\taccount id: " << acc.id()
            << "\n\tlast  name: " << acc.last_name()
            << "\n\tfirst name: " << acc.first_name()
            << "\n\temail: " << acc.email() << "\n\tbalance: " << acc.balance()
            << '\n';
}
