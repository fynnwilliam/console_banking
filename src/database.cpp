#include <database.h>

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