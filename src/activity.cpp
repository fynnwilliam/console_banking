#include "activity.h"

activity_t activity::name() const noexcept
{
    return type_;
}

clock_t::time_point activity::time() const noexcept
{
    return time_;
}

double activity::amount() const noexcept
{
    return amount_;
}

unsigned activity::from() const noexcept
{
    return from_;
}
unsigned activity::to() const noexcept
{
   return to_;
}

std::ifstream& operator>>(std::ifstream& ifs, activity& act)
{
    ifs >> act.amount_
        >> act.from_
        >> act.to_;
        
    return ifs;
}

std::ofstream& operator<<(std::ofstream& ofs, activity const& act)
{
    ofs << act.amount()
        << act.from()
        << act.to();
        
    return ofs;
}

std::ostream&  operator<<(std::ostream& os, activity const& act)
{
    return os << act.amount()
              << act.from()
              << act.to();
              
}