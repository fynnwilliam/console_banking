#pragma once
#include <unordered_map>

#include "activity_t.h"

class transaction
{
private:
    std::unordered_map<std::uint64_t, activity> logs_;
    std::uint64_t id_;
    
    static std::uint64_t new_id()       noexcept;
    void                 write()  const noexcept;

public:
    transaction() = default;
    
    void log(activity&&)                noexcept;
    void read()                         noexcept;
    
    ~transaction();
};