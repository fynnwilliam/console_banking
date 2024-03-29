#include "database.h"

database::ins_itr database::insert(unsigned id, account acc) noexcept {
  std::scoped_lock{mtx_};
  return db_.insert({id, acc});
}

void database::write_to_file() const noexcept {
  std::ofstream file{"data", std::ios::trunc};
  for (auto &[_, acc] : db_)
    file << acc;
}

void database::read_from_file() noexcept {
  std::ifstream file{"data", std::ios::in};
  account acc{};

  while (file >> acc)
    insert(acc.id(), acc);
}

std::optional<account> database::find(unsigned id) const noexcept {
  auto const &itr{db_.find(id)};
  return itr != cend() ? std::make_optional(itr->second) : std::nullopt;
}

database::acc_ref database::find(unsigned id) noexcept {
  if (auto itr{db_.find(id)}; itr != end()) {
    account &acc = itr->second;
    return database::acc_ref{acc};
  }

  return std::nullopt;
}

void database::erase(unsigned id) noexcept {
  std::scoped_lock{mtx_};
  db_.erase(id);
}

database::db_itr database::begin() noexcept { return db_.begin(); }

database::db_citr database::cbegin() const noexcept { return db_.cbegin(); }

database::db_itr database::end() noexcept { return db_.end(); }

database::db_citr database::cend() const noexcept { return db_.cend(); }

bool database::empty() const noexcept { return db_.empty(); }

bool database::contains(unsigned id) const noexcept { return db_.contains(id); }

account &database::operator[](unsigned id) noexcept { return db_[id]; }

account const &database::operator[](unsigned id) const noexcept {
  return db_.at(id);
}

database::~database() {
  if (!empty())
    write_to_file();
}
