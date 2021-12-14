#include "transactions.h"

std::uint64_t transaction::id() const noexcept
{
}

void transaction::log(activity&& a) noexcept
{
    logs_[id()] = std::move(a);
}

void transaction::read() noexcept
{
}

void transaction::write() const noexcept
{
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

