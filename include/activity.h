#pragma once
#include <chrono>
#include <fstream>
#include <iostream>

#include "activity_t.h"

class activity
{
private:
    using clock_t = std::chrono::system_clock;
    
    activity_t          type_;
    clock_t::time_point time_{clock_t::now()};
    double              amount_;
    unsigned            from_{0};
    unsigned            to_{0};
    
public:
    activity(activity_t type, double amount)
        : type_{type}, amount_{amount} {}
    
    activity(activity_t type, double amount, unsigned f, unsigned t)
        : type_{type}, amount_{amount}, from_{f}, to_{t} {}
    
    activity_t          name()   const noexcept;
    clock_t::time_point time()   const noexcept;
    double              amount() const noexcept;
    unsigned            from()   const noexcept;
    unsigned            to()     const noexcept;
    
    activity_t&          name()        noexcept;
    clock_t::time_point& time()        noexcept;
    double&              amount()      noexcept;
    unsigned&            from()        noexcept;
    unsigned&            to()          noexcept;
    
    friend std::ifstream& operator>>(std::ifstream&, activity&);
    friend std::istream&  operator>>(std::istream&,  activity&);
};

    std::ofstream& operator<<(std::ofstream&, activity const&);
    std::ostream&  operator<<(std::ostream& , activity const&);