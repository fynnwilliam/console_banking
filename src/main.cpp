#include "bank.h"

int main()
{
    bank gcb{};
    int option{};
    std::cout << "welcome to console banking! :)\n\n";

    do
    {
        gcb.inquire();
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
                std::cout << "\nselect among options 1 through 7\n";
        }
    } while (option != 7);

    return 0;
}