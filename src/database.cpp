#include <database.h>

#include <optional>

auto database::insert(unsigned id, account acc) noexcept
{
    return db_.insert({id, acc});
}

void database::write_to_file() const noexcept
{
    std::ofstream file{"data", std::ios::truc};
    for (auto& [id, acc] : db_)
        file << acc;
}

std::optional<account&> database::find(unsigned id) noexcept
{
    return db_.count(id) ? {db_[id]} : std::nullopt;
}

std::optional<account const&> database::find(unsigned id) const noexcept
{
    return db_.count(id) ? {db_.at(id)} : std::nullopt;
}

void database::erase(unsigned id) noexcept
{
    db_.erase(id);
}