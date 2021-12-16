#include "id_generator.h"

std::uint64_t id_generator::read_id() noexcept
{
    std::uint64_t id{};
    if (std::ifstream source{"id", std::ios::in})
        source >> id;
    return id;
}

void id_generator::save_last_id() const noexcept
{
    if (std::ofstream source{"id", std::ios::trunc})
        source << id_.load();
}

std::uint64_t id_generator::operator++() noexcept
{
    return ++id_;
}

std::uint64_t id_generator::operator++(int) noexcept
{
    return id_++;
}

id_generator::~id_generator()
{
    save_last_id();
}