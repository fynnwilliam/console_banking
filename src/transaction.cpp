#include <utility>

#include "transaction.h"

void transaction::log(activity&& a) noexcept
{
    logs_.insert({++id_, a});
}

void transaction::read(std::string const& acc_id) noexcept
{
    std::ifstream file{acc_id, std::ios::in};
    std::uint64_t t_id{}; activity act{{}, {}};
    
    while (file >> t_id >> act)
        logs_.insert({t_id, act});
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

transaction::t_itr transaction::begin() noexcept
{
    return logs_.begin();
}

transaction::t_citr transaction::begin() const noexcept
{
    return logs_.cbegin();
}

transaction::t_itr transaction::end() noexcept
{
    return logs_.end();
}

transaction::t_citr transaction::end() const noexcept
{
    return logs_.cend();
}