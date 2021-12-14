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

transaction::~transaction()
{
    if (!logs_.empty()) write();
}

