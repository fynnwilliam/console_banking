#include "bank.h"

int main()
{
    bank gcb{database::instance()};
    
    while (int option = gcb.inquire())
        gcb.deliver(option);
    
    std::cout << "\n\tnice, have a great day!" << std::endl;

    return 0;
}