#include "bank.h"

int main()
{
    bank{database::instance()}.inquire();
    return 0;
}