#pragma once
#include <string>
#include <chrono>

#include "activity_t.h"

class activity
{
private:
    using clock_t = std::chrono::system_clock;
    
    activity_t          type_;
    clock_t::time_point time_{clock_t::now()};
    double              amount_;
    std::string         from_;
    std::string         to_;
    
public:
    activity(activity_t type, double amount)
        : type_{type}, amount_{amount} {}
    
    activity(activity_t type, double amount, std::string const& f, std::string const& t)
        : type_{type}, amount_{amount}, from_{f}, to_{t} {}
};