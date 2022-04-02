#pragma once
#include <functional>
#include <mutex>
#include <optional>
#include <unordered_map>

#include "account.h"

class database {
private:
  std::unordered_map<unsigned, account> db_;
  std::mutex mtx_;

  database() = default;
  database(database const &) = delete;
  database &operator=(database const &) = delete;
  void read_from_file() noexcept;
  void write_to_file() const noexcept;

public:
  static database &instance() noexcept {
    static database db{};
    if (db.empty())
      db.read_from_file();

    return db;
  }

  typedef decltype(db_.cbegin()) db_citr;
  typedef decltype(db_.begin()) db_itr;
  typedef std::pair<db_itr, bool> ins_itr;
  typedef std::optional<std::reference_wrapper<account>> acc_ref;

  ins_itr insert(unsigned, account) noexcept;
  void erase(unsigned) noexcept;
  bool contains(unsigned) const noexcept;
  db_itr begin() noexcept;
  db_citr cbegin() const noexcept;
  db_itr end() noexcept;
  db_citr cend() const noexcept;
  bool empty() const noexcept;
  acc_ref find(unsigned) noexcept;
  account &operator[](unsigned) noexcept;
  account const &operator[](unsigned) const noexcept;
  std::optional<account> find(unsigned) const noexcept;
  ~database();
};