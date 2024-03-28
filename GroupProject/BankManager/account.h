#pragma once
#include "customer.h"

//group3  - karls, madisont, adilf - prog71985 - group project - account object interface

#ifndef ACCOUNT_LIBRARY_H
#define ACCOUNT_LIBRARY_H

typedef enum accountType {SAVINGS, CHEQUING} TYPE;

typedef struct account {
    int accountNumber;
    double balance;
    CUSTOMER customer; //Customer information
    TYPE type; //Account type
} ACCOUNT;

#endif //ACCOUNT_LIBRARY_H