#define _CRT_SECURE_NO_WARNINGS
#include "account.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

//group3 - karls, madisont, adilf prog71985 - group project - account object implementation

/*
Dam it looks ugly here, IN MY DEFENSE I AM NOT GOOD AT CODING so there's that.

Anyways these are all the functions that makes the functionality of the bank system apart from the file loading and saving cause those are in file_operation.c

My sincerest apologies to whoever is going to read my code cause I did little to none commenting. Sorry Tehe ?(*°?°*)?

*/

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int isNumeric(const char* str) {
    while (*str) {
        if (!isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}

int isAlphabetic(const char* str) {
    while (*str) {
        if (!isalpha(*str))
            return 0;
        str++;
    }
    return 1;
}

int isDuplicateAccount(ACCOUNT accounts[], int numAccounts, int accountNumber) {
    // iterate through each element in the array
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].account_number == accountNumber) { // check for a matched account number
            return 1; // Duplicate found
        }
    }
    return 0; // No duplicate
}

bool isMaxAccountsReached(int numAccounts) {
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("Cannot add more accounts. Maximum limit reached.\n");
        return true;
    }
    return false;
}

void Add_Account(ACCOUNT accounts[], int* numAccounts) {
    // check if there are too many accounts
    if (isMaxAccountsReached(*numAccounts)) {
        return;
    }

    // Get user input
    int newAccountNumber = GetUserInput_AccountNumber(accounts, *numAccounts);  // account number

    char firstName[MAX_NAME_LENGTH], lastName[MAX_NAME_LENGTH]; // first and last names
    GetUserInput_Name(firstName, "Enter first name");
    GetUserInput_Name(lastName, "Enter last name");

    float balance = GetUserInput_Balance(); // starting balance
    AccountType type = GetUserInput_AccountType();// account type

    // Add the account
    Add_Account_ToArray(accounts, numAccounts, newAccountNumber, firstName, lastName, balance, type);
}

void Delete_Account(ACCOUNT accounts[], int* numAccounts, int accountNumber) {
    int i, found = 0;
    for (i = 0; i < *numAccounts; i++) {
        if (accounts[i].account_number == accountNumber) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (; i < *numAccounts - 1; i++) {
            accounts[i] = accounts[i + 1];
        }
        (*numAccounts)--;
        printf("Account deleted successfully.\n");
    }
    else {
        printf("Account not found.\n");
    }
}

void Update_Account(ACCOUNT accounts[], int numAccounts, int accountNumber) {
    int i, found = 0;
    for (i = 0; i < numAccounts; i++) {
        if (accounts[i].account_number == accountNumber) {
            found = 1;
            break;
        }
    }
    if (found) {
        printf("Enter new first name: ");
        if (scanf("%s", accounts[i].customer.firstName) == 0) {
            printf("Invalid input!\n");
            return;
        }
        printf("Enter new last name: ");
        if (scanf("%s", accounts[i].customer.lastName) == 0) {
            printf("Invalid input!\n");
            return;
        }
        printf("Enter new balance: ");
        if (scanf("%f", &accounts[i].balance) == 1) {
            printf("\nAccount updated successfully.\n");
        }
        printf("\nInvalid input!\n");
        return;
    }
    else {
        printf("\nAccount not found.\n");
    }
}

void Deposit(ACCOUNT accounts[], int numAccounts, int accountNumber) {
    int i, found = 0;
    float amount;
    for (i = 0; i < numAccounts; i++) {
        if (accounts[i].account_number == accountNumber) {
            found = 1;
            break;
        }
    }
    if (found) {
        printf("Enter deposit amount: ");
        if (scanf("%f", &amount) == 0) {
            printf("Invalid input!\n");
            return;
        }
        accounts[i].balance += amount;
        printf("\nDeposit successful. New balance: %.2f\n", accounts[i].balance);
    }
    else {
        printf("\nAccount not found.\n");
    }
}

void Withdraw(ACCOUNT accounts[], int numAccounts, int accountNumber) {
    int i, found = 0;
    float amount;
    for (i = 0; i < numAccounts; i++) {
        if (accounts[i].account_number == accountNumber) {
            found = 1;
            break;
        }
    }
    if (found) {
        printf("Enter withdrawal amount: ");
        if (scanf("%f", &amount) == 0) {
            printf("Invalid input!\n");
            return;
        }
        if (accounts[i].balance >= amount) {
            accounts[i].balance -= amount;
            printf("\nWithdrawal successful. New balance: %.2f\n", accounts[i].balance);
        }
        else {
            printf("\nInsufficient balance.\n");
        }
    }
    else {
        printf("\nAccount not found.\n");
    }
}

void Display_Single_Account(ACCOUNT accounts[], int numAccounts, int accountNumber) {
    int i, found = 0;
    for (i = 0; i < numAccounts; i++) {
        if (accounts[i].account_number == accountNumber) {
            found = 1;
            break;
        }
    }
    if (found) {
        Print_Account_Info(&accounts[i]);
    }
    else {
        printf("Account not found.\n");
    }
}

void Display_Range_Of_Accounts(ACCOUNT accounts[], int numAccounts, float minBalance, float maxBalance) {
    int i, found = 0;
    printf("Accounts in the range %.2f to %.2f:\n", minBalance, maxBalance);
    for (i = 0; i < numAccounts; i++) {
        if (accounts[i].balance >= minBalance && accounts[i].balance <= maxBalance) {
            Print_Account_Info(&accounts[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No accounts found in the specified range.\n");
    }
}

void Display_All_Accounts(ACCOUNT accounts[], int numAccounts) {
    int i;
    if (numAccounts == 0) {
        printf("No accounts found.\n");
    }
    else {
        printf("All Accounts:\n");
        for (i = 0; i < numAccounts; i++) {
            Print_Account_Info(&accounts[i]);
        }
    }
}

void Search_Account(ACCOUNT accounts[], int numAccounts, char name[]) {
    int i, found = 0;
    for (i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].customer.firstName, name) == 0) {
            Print_Account_Info(&accounts[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Account not found.\n");
    }
}

// print account information
void Print_Account_Info(ACCOUNT* account)
{
    printf("#Account Number: %d\n# Name: %s %s\n# Balance: %.2f\n# Type: %s\n \n",
        account->account_number,
        account->customer.firstName,
        account->customer.lastName, 
        account->balance, 
        account->type == CHECKING ? "Checking" : "Savings");
}

// Enhancing error handling with descriptive messages :D cause I am nice and shit now . Ya all flamed me for not adding "descriptive messgages"

// get a valid and unique account number from user
int GetUserInput_AccountNumber(ACCOUNT accounts[], int numAccounts) {
    int newAccountNumber;
    do {
        printf("Enter account number: ");
        //check if account number is valid and no duplicates
        if (scanf("%d", &newAccountNumber) == 1) {
            if (!isDuplicateAccount(accounts, numAccounts, newAccountNumber)) {
                clearInputBuffer();
                return newAccountNumber;
            }
            else {
                printf("Account number already exists. Please enter a different account number.\n");
            }
        }
        else {
            printf("Invalid input! Please enter a valid account number.\n");
        }
        clearInputBuffer();
    } while (true);
}


// get a name from user input
void GetUserInput_Name(char *name, const char *prompt) {
    do {
        printf("%s (alphabetic characters only, max %d characters): ", prompt, MAX_NAME_LENGTH - 1);
        if (scanf("%s", name) == 1 && isAlphabetic(name)) {
            clearInputBuffer();
            return;
        }
        printf("Invalid name! Please enter alphabetic characters only.\n");
        clearInputBuffer();
    } while (true);
}

// get valid balance input from user
float GetUserInput_Balance() {
    float balance;
    do {
        printf("Enter balance: ");
        // check if balance is valid
        if (scanf("%f", &balance) == 1 && balance >= 0) {
            clearInputBuffer();
            return balance;
        }
        printf("Invalid balance! Please enter a valid positive number.\n");
        clearInputBuffer();
    } while (true);
}

// get account type from the user
AccountType GetUserInput_AccountType() {
    int typeInput;
    do {
        printf("Enter account type (0 for Checking, 1 for Savings): ");
        // check if account type is valid
        if (scanf("%d", &typeInput) == 1 && (typeInput == 0 || typeInput == 1)) {
            clearInputBuffer();
            return (typeInput == 0) ? CHECKING : SAVINGS;
        }
        printf("Invalid account type! Please enter 0 for Checking or 1 for Savings.\n");
        clearInputBuffer();
    } while (true);
}

// add a new account to an accounts array
void Add_Account_ToArray(ACCOUNT accounts[], int* numAccounts, int accountNumber, const char* firstName, const char* lastName, float balance, AccountType type) {
    accounts[*numAccounts].account_number = accountNumber;
    strcpy(accounts[*numAccounts].customer.firstName, firstName);
    strcpy(accounts[*numAccounts].customer.lastName, lastName);
    accounts[*numAccounts].balance = balance;
    accounts[*numAccounts].type = type;
    (*numAccounts)++;
    printf("Account added successfully.\n");
}
