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
    void read_from_file() noexcept;

public:
    static database& instance() noexcept
    {
        static database db{};
        return db;
    }
    
    auto insert(unsigned, account)              noexcept;
    void write_to_file()                  const noexcept;
    std::optional<account> find(unsigned)       noexcept;
    std::optional<account> find(unsigned) const noexcept;
    void erase(unsigned) noexcept;
    auto  begin()  const noexcept;
    auto cbegin()  const noexcept;
    auto    end()  const noexcept;
    auto   cend()  const noexcept;
    bool  empty()  const noexcept;
};