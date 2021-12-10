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

std::optional<account> database::find(unsigned id) noexcept
{
    return db_.count(id) ? std::optional{db_[id]} : std::nullopt;
}

std::optional<account> database::find(unsigned id) const noexcept
{
    return db_.count(id) ? std::optional{db_.at(id)} : std::nullopt;
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