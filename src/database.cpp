#include "database.h"

auto database::insert(unsigned id, account acc) noexcept
{
    std::scoped_lock{mtx_};
    return db_.insert({id, acc});
}

void database::write_to_file() const noexcept
{
    std::ofstream file{"data", std::ios::trunc};
    for (auto& [id, acc] : db_)
        file << acc;
}

void database::read_from_file() noexcept
{
    std::ifstream file{"data"};
    account acc{};
    
    while (file.is_open() && !file.eof())
    {
        file >> acc;
        insert(acc.id(), acc);
    }
}

std::optional<account> database::find(unsigned id) const noexcept
{
    return db_.count(id) ? std::make_optional(db_.at(id)) : std::nullopt;
}

void database::erase(unsigned id) noexcept
{
    std::scoped_lock{mtx_};
    db_.erase(id);
}

auto database::begin() const noexcept
{
    return db_.begin();
}

auto database::cbegin() const noexcept
{
    return db_.cbegin();
}

auto database::end() const noexcept
{
    return db_.end();
}

auto database::cend() const noexcept
{
    return db_.cend();
}

bool database::empty() const noexcept
{
    return db_.empty();
}

database::~database()
{
    if (!empty()) write_to_file();
}