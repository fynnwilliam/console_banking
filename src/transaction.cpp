#include "transactions.h"

std::uint64_t transaction::id() const noexcept
{
}

void transaction::log(activity&& a) noexcept
{
    logs_[id()] = std::move(a);
}

void transaction::read(unsigned acc_id) noexcept
{
    std::ifstream file{std::to_string(acc_id), std::ios::in};
    std::uint64_t t_id{}; activity act{{}, {}};
    
    while (file >> t_id >> act) logs_[t_id] = std::move(act);
}

void transaction::write(std::string const& acc_id) const noexcept
{
    std::ofstream file{"", std::ios::trunc};
    for (auto const& [id, act] : logs_)
        file << id << '\n' << act;
}

bool transaction::empty() const noexcept
{
    return logs_.empty();
}

std::optional<activity> transaction::find(std::uint64_t id) const noexcept
{
    logs_.contains(id) ? std::make_optional(logs_.at(id)) : std::nullopt;
}

transaction::~transaction()
{
    if (!empty()) write();
}