#include <locale>
#include "activity.h"

activity_t activity::name() const noexcept
{
    return type_;
}

activity::clock_t::time_point activity::time() const noexcept
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

activity_t& activity::name() noexcept
{
    return type_;
}

activity::clock_t::time_point& activity::time() noexcept
{
    return time_;
}

double& activity::amount() noexcept
{
    return amount_;
}

unsigned& activity::from() noexcept
{
    return from_;
}
unsigned& activity::to() noexcept
{
   return to_;
}

std::ifstream& operator>>(std::ifstream& ifs, activity& act)
{
    ifs >> act.amount()
        >> act.from()
        >> act.to();
        
    return ifs;
}

std::istream& operator>>(std::istream& ifs, activity& act)
{
    return ifs >> act.amount()
               >> act.from()
               >> act.to();
}

std::ofstream& operator<<(std::ofstream& ofs, activity const& act)
{
    ofs << act.amount() << '\n'
        << act.from()   << '\n'
        << act.to()     << '\n';
        
    return ofs;
}

std::ostream&  operator<<(std::ostream& os, activity const& act)
{
    os.imbue(std::locale());
    return os <<   "amount: "       << act.amount()
              << "\nfrom: acc_no. " << act.from()
              << "\nto: acc_no. "   << act.to()
              << '\n';
}