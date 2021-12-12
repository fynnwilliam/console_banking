#pragma once
#include <unordered_map>
#include <optional>
#include <mutex>

#include "account.h"

class database
{
private:
    std::unordered_map<unsigned, account> db_;
    std::mutex mtx_;
    
    database() = default;
    void read_from_file()                       noexcept;
    void write_to_file()                  const noexcept;

public:
    static database& instance()                 noexcept
    {
        static database db{};
        // static std::once_flag once;
        // std::call_once(once, [&] { db.read_from_file(); });
        if (db.empty()) db.read_from_file();
        return db;
    }

    typedef decltype(db_.cbegin())  db_citr;
    typedef decltype(db_.begin())    db_itr;
    typedef std::pair<db_itr, bool> ins_itr;
    
    ins_itr insert(unsigned, account)           noexcept;
    void    erase(unsigned)                     noexcept;
    bool    count(unsigned)               const noexcept;
    db_itr  begin()                             noexcept;
    db_citr cbegin()                      const noexcept;
    db_itr  end()                               noexcept;
    db_citr cend()                        const noexcept;
    bool    empty()                       const noexcept;
    account&         operator[](unsigned)       noexcept;
    account const&   operator[](unsigned) const noexcept;
    std::optional<account> find(unsigned) const noexcept;
    ~database();
};