#include "bank.h"

int main()
{
    bank gcb{database::instance()};
    while (int option = gcb.inquire())
    {
        switch (option)
        {
            case 1:
                gcb.open_account();  break;
            case 2:
                gcb.check_balance(); break;
            case 3:
                gcb.deposit();       break;
            case 4:
                gcb.withdraw();      break;
            case 5:
                gcb.close_account(); break;
            case 6:
                gcb.list_accounts(); break;
            default:
                continue;
        }
    }
    
    std::cout << "\n\tnice, have a great day!" << std::endl;

    return 0;
}