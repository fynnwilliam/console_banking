#pragma once
#include <unordered_map>
#include <string>
#include <optional>

#include "activity.h"

class transaction
{
private:
    std::unordered_map<std::uint64_t, activity> logs_;
    
    static std::uint64_t id()                         noexcept;

public:
    transaction() = default;
    
    void log(activity&&)                              noexcept;
    void read(std::string const&)                     noexcept;
    void write(std::string const&)              const noexcept;
    bool empty()                                const noexcept;
    
    std::optional<activity> find(std::uint64_t) const noexcept;
};