
#ifndef BANKING_SYSTEM_ACCOUNT_H
#define BANKING_SYSTEM_ACCOUNT_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

class account {
public:
    void readData();
    void showRecord();
    void addRecord();
    void searchRecord();
    void updateRecord();
    void deleteRecord();
    void quit();

private:
    char account_number[20];
    char first_name[20];
    char last_name[20];
    double account_balance;

};


#endif //BANKING_SYSTEM_ACCOUNT_H
