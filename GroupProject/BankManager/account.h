#pragma once

//group3  - karls, madisont, adilf - prog71985 - group project - account object interface

#ifndef ACCOUNT_LIBRARY_H
#define ACCOUNT_LIBRARY_H

typedef enum accountType {
    SAVINGS,
    CHEQUING,
    CREDIT
} TYPE;

typedef struct account {
    int accountNumber;
    double balance;
    CUSTOMER accountHolder; // Customer information
    AccountType type; // Account type
    // Other account-related fields
} ACCOUNT;

#endif //ACCOUNT_LIBRARY_H