#include "bank.h"

int main()
{
    std::string fname{};
    std::string lname{};
    std::string email{};
    float amount{};
    float initialAmount{};
    long accNumber{};
    int option{};

    account acc{};
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
            std::cout << "enter first name: ";
            std::cin >> fname;
            std::cout << "enter last name: ";
            std::cin >> lname;
            std::cout << "enter email address: ";
            std::cin >> email;
            std::cout << "enter initial amount: ";
            std::cin >> initialAmount;

            acc = gcb.openAccount(fname, lname, email, initialAmount);

            std::cout << acc
                      << "\naccount created successfully.\n";
            break;
        case 2:
            std::cout << "enter account number: ";
            std::cin >> accNumber;

            acc = gcb.balanceEnquiry(accNumber);

            std::cout << "\nplease find current balance below...\n\n"
                      << acc;
            break;
        case 3:
            std::cout << "enter account number: ";
            std::cin >> accNumber;
            std::cout << "enter amount to deposit: ";
            std::cin >> amount;

            acc = gcb.makeDeposit(accNumber, amount);

            std::cout << "\ndeposit complete.\nfind current details below...\n\n"
                      << acc;
            break;
        case 4:
            std::cout << "enter account number: ";
            std::cin >> accNumber;
            std::cout << "enter amount to withdraw: ";
            std::cin >> amount;

            try { acc = gcb.withdrawal(accNumber, amount); }
            catch (const std::exception& e) { std::cerr << '\n' << e.what() << '\n'; break;}            

            std::cout << "\nwithdrawal complete.\nfind current details below...\n\n"
                      << acc;
            break;
        case 5:
            std::cout << "enter account number to be closed: ";
            std::cin  >> accNumber;

            gcb.closeAccount(accNumber);

            std::cout << "account deleted.\n"
                      << acc;
            break;
        case 6:
            gcb.showAccounts();
            break;
        case 7:
            std::cout << "\nthank you, for banking with us" << std::endl;
            break;
        default:
            std::cout << "\nselect any of options 1 through 7\n";
        }
    } while (option != 7);

    return 0;
}