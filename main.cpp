#include "bank.h"

int main()
{
    string fname;
    string lname;
    string email;
    float amount;
    float initialAmount;
    long accNumber;
    int option;

    account acc;
    bank gcb;

    cout << "welcome to console banking! :)\n\n";

    do
    {
        cout << "\n"
             << "\t1. open an account\n"
             << "\t2. balance enquiry\n"
             << "\t3. deposit\n"
             << "\t4. withdrawal\n"
             << "\t5. close an account\n"
             << "\t6. show accounts\n"
             << "\t7. exit\n"
             << "\nselect an option: ";

        cin  >> option;

        switch (option)
        {
            case 1:
                cout << "enter first name: ";
                cin  >> fname;
                cout << "enter last name: ";
                cin  >> lname;
                cout << "enter email address: ";
                cin  >> email;
                cout << "enter initial amount: ";
                cin  >> initialAmount;

                acc = gcb.openAccount(fname, lname, email, initialAmount);

                cout << acc 
                     << "\naccount created successfully.\n";
                break;
            case 2:
                cout << "enter account number: ";
                cin  >> accNumber;

                acc = gcb.balanceEnquiry(accNumber);

                cout << "\nplease find current balance below...\n\n"
                     << acc;
                break;
            case 3:
                cout << "enter account number: ";
                cin  >> accNumber;
                cout << "enter amount to deposit: ";
                cin  >> amount;

                acc = gcb.makeDeposit(accNumber, amount);

                cout << "\ndeposit complete.\nfind current details below...\n\n"
                     << acc;
                break;
            case 4:
                cout << "enter account number: ";
                cin  >> accNumber;
                cout << "enter amount to withdraw: ";
                cin  >> amount;

                acc = gcb.withdrawal(accNumber, amount);

                cout << "\nwithdrawal complete.\nfind current details below...\n\n"
                     << acc;
                break;
            case 5:
                cout << "enter account number to be closed: ";
                cin  >> accNumber;

                gcb.closeAccount(accNumber);

                cout << "account deleted.\n"
                     << acc;
                break;
            case 6:
                gcb.showAccounts();
                break;
            case 7: break;
            default:
                cout << "\nselect any of options 1 through 7\n";
                exit(0);
        }
    } while (option != 7);
    
    return 0;
}