#pragma once
#define MAX_ACCOUNTS 100
#define MAX_NAME_LENGTH 50
#include "customer.h"
#include "stdbool.h"

//group3  - karls, madisont, adilf - prog71985 - group project - account object interface

#ifndef ACCOUNT_H_LIBRARY
#define ACCOUNT_H_LIBRARY

/*NGL I had to watch 2 hour videos on ENUM alone and after learning it I feel stupid cause it was such a simple concept*/

/*Structs and Enum*/
typedef enum {
    CHECKING,
    SAVINGS
} AccountType;

/*This is our bread and butter the account struct*/
typedef struct {
    int account_number;
    CUSTOMER customer;
    float balance;
    AccountType type;
} ACCOUNT;

/*Functions*/
void Add_Account(ACCOUNT accounts[], int* numAccounts);
void Delete_Account(ACCOUNT accounts[], int* numAccounts, int accountNumber);
void Update_Account(ACCOUNT accounts[], int numAccounts, int accountNumber);
void Deposit(ACCOUNT accounts[], int numAccounts, int accountNumber);
void Withdraw(ACCOUNT accounts[], int numAccounts, int accountNumber);
void Display_Single_Account(ACCOUNT accounts[], int numAccounts, int accountNumber);
void Display_Range_Of_Accounts(ACCOUNT accounts[], int numAccounts, float minBalance, float maxBalance);
void Display_All_Accounts(ACCOUNT accounts[], int numAccounts);
void Search_Account(ACCOUNT accounts[], int numAccounts, char name[]);
void Print_Account_Info(ACCOUNT* account);
void Add_Account_ToArray(ACCOUNT accounts[], int* numAccounts, int accountNumber, const char* firstName, const char* lastName, float balance, AccountType type);

// User input functions
int GetUserInput_AccountNumber(ACCOUNT accounts[], int numAccounts);
void GetUserInput_Name(char* name, const char* prompt);
float GetUserInput_Balance();
AccountType GetUserInput_AccountType();

// helper functions
void clearInputBuffer();
int isNumeric(const char* str);
int isAlphabetic(const char* str);
int isDuplicateAccount(ACCOUNT accounts[], int numAccounts, int accountNumber);
bool isMaxAccountsReached(int numAccounts);

#endif //ACCOUNT_H_LIBRARY
