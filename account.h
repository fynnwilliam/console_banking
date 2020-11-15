#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using std::ios;
using std::cin;
using std::map;
using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::ostream;
using std::ofstream;
using std::ifstream;
using std::exception;

class insufficientFunds : exception {};

class account
{
private:
    long accountNumber;
    float accountBalance;
    string firstName;
    string lastName;
    string email;
    static long nextAccountNumber;
public:
    account () {}
    account (string fname, string lname, string email, float accBalance);
    string getFirstName() {return firstName;}
    string getLastName() {return lastName;}
    string getEmail() {return email;}
    long getAccountNumber() {return accountNumber;}
    float getAccountBalance() {return accountBalance;}
    //---------------------------------------------------------------
    void deposit(float amount);
    void withdraw(float amount);
    static void setLastAccountNumber(long accountNumber);
    static long getLastAccountNumber();
    friend ofstream& operator << (ofstream& outfile, account& acc);
    friend ifstream& operator >> (ifstream& infile, account& acc);
    friend ostream& operator << (ostream& display, account& acc);
    ~account();
};
