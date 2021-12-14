#pragma once
#include <unordered_map>

#include "activity_t.h"

class transaction
{
private:
    std::unordered_map<std::uint64_t, activity> logs_;
    
    static std::uint64_t id()                   const noexcept;

public:
    transaction() = default;
    
    void log(activity&&)                              noexcept;
    void read(unsigned)                               noexcept;
    void write()                                const noexcept;
    bool empty()                                const noexcept;
    
    std::optional<activity> find(std::uint64_t) const noexcept;
    
    ~transaction();
};