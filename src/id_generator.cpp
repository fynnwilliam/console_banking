#include "id_generator"

std::uint64_t id_generator::read_id() noexcept
{
    std::uint64_t id{};
    if (std::ifstream source{"id", std::ios::in})
        source >> id;
    return id;
}