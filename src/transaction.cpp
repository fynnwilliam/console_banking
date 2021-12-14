#include "transactions.h"

std::uint64_t transaction::id() const noexcept
{
}

void transaction::log(activity&& a) noexcept
{
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

transaction::~transaction()
{
    if (!logs_.empty()) write();
}

