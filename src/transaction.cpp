#include <utility>

#include "transaction.h"

std::uint64_t transaction::id() noexcept
{
    static std::uint64_t t_id{_id()};
    return ++t_id;
}

std::uint64_t transaction::_id() noexcept
{
    std::uint64_t id{};
    if (std::ifstream source{"id", std::ios::in})
        source >> id;
    return id;
}

void transaction::save_last_id() const noexcept
{
    if (std::ofstream source{"id", std::ios::trunc})
        source << id() - 1;
}

void transaction::log(activity&& a) noexcept
{
    logs_.insert({id(), std::move(a)});
}

void transaction::read(std::string const& acc_id) noexcept
{
    std::ifstream file{acc_id, std::ios::in};
    std::uint64_t t_id{}; activity act{{}, {}};
    
    while (file >> t_id >> act)
        logs_.insert({t_id, std::move(act)});
}

void transaction::write(std::string const& acc_id) const noexcept
{
    std::ofstream file{acc_id, std::ios::trunc};
    for (auto const& [t_id, act] : logs_)
    {   
        file << t_id << '\n';
        file << act;
    }
}

bool transaction::empty() const noexcept
{
    return logs_.empty();
}

std::optional<activity> transaction::find(std::uint64_t id) const noexcept
{
    auto const& act{logs_.find(id)};
    return act != logs_.end() ? std::make_optional(act->second) : std::nullopt;
}