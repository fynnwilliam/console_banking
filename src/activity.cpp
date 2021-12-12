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

std::string const& activity::from() const noexcept
{
    return from_;
}
std::string const& activity::to() const noexcept
{
   return to;
}