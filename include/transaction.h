#pragma once
#include <unordered_map>
#include <string>
#include <optional>

#include "activity.h"
#include "id_generator.h"

class transaction
{
private:
    std::unordered_map<std::uint64_t, activity> logs_;
    id_generator& id_{id_generator::instance()};
    
    typedef decltype(logs_.cbegin()) t_citr;
    typedef decltype(logs_.begin())   t_itr;

public:
    transaction() = default;
    
    void   log(activity&&)                              noexcept;
    void   read(std::string const&)                     noexcept;
    void   write(std::string const&)              const noexcept;
    bool   empty()                                const noexcept;
    t_itr  begin()                                      noexcept;
    t_citr begin()                                const noexcept;
    t_itr  end()                                        noexcept;
    t_citr end()                                  const noexcept;
    
    std::optional<activity> find(std::uint64_t)   const noexcept;
};