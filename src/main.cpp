#include "bank.h"

int main()
{
    bank gcb{};

    std::cout << "welcome to console banking! :)\n\n";

    do
    {
        std::cout << "\n"
                 << "\t1. open an account\n"
                 << "\t2. balance enquiry\n"
                 << "\t3. deposit\n"
                 << "\t4. withdrawal\n"
                 << "\t5. close an account\n"
                 << "\t6. show accounts\n"
                 << "\t7. exit\n"
                 << "\nselect an option: ";

        std::cin >> option;

        switch (option)
        {
        case 1:
            gcb.open_account();                               break;
        case 2:
            gcb.check_balance();                              break;
        case 3:
            gcb.deposit();                                    break;
        case 4:
            gcb.withdraw();                                   break;
        case 5:
            gcb.close_account();                              break;
        case 6:
            gcb.list_accounts();                              break;
        case 7:
            std::cout << "\nthave a great day!" << std::endl; break;
        default:
            std::cout << "\nselect an option\n";
        }
    } while (option != 7);

    return 0;
}