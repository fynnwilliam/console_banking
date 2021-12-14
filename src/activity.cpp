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
   return to;
}