
//group3 - karls, madisont, adilfprog71985 - group project - account object implementation


/*
Dam it looks ugly here , IN MY DEFENSE I AM NOT GOOD AT CODING so there's that.

Anyways these are all the functions that makes the functionality of the bank system apart from the file loading and saving cause those are in file_operation.c

My sincerest apologies to whoever is going to read my code cause I did little to none commenting . Sorry Tehe ?(*°?°*)?

*/
#define _CRT_SECURE_NO_WARNINGS
#include "account.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].account_number == accountNumber) {
            return 1; // Duplicate found
        }
    }
    return 0; // No duplicate
}

void Add_Account(ACCOUNT accounts[], int* numAccounts) {
    if (*numAccounts >= MAX_ACCOUNTS) {
        printf("Cannot add more accounts. Maximum limit reached.\n");
        return;
    }

    int newAccountNumber;
    char name[MAX_NAME_LENGTH];
    float balance;
    AccountType type;

    do {
        printf("Enter account number: ");
        if (scanf("%d", &newAccountNumber) != 1 || isDuplicateAccount(accounts, *numAccounts, newAccountNumber)) {
            printf("Invalid account number or already exists. Please enter a different account number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        printf("Enter name (alphabetic characters only, max %d characters): ", MAX_NAME_LENGTH - 1);
        if (scanf("%s", name) != 1 || !isAlphabetic(name)) {
            printf("Invalid name! Please enter alphabetic characters only.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        printf("Enter balance: ");
        if (scanf("%f", &balance) != 1 || balance < 0) {
            printf("Invalid balance! Please enter a valid positive number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        printf("Enter account type (0 for Checking, 1 for Savings): ");
        int typeInput;
        if (scanf("%d", &typeInput) != 1 || (typeInput != 0 && typeInput != 1)) {
            printf("Invalid account type! Please enter 0 for Checking or 1 for Savings.\n");
            clearInputBuffer();
            continue;
        }
        type = (typeInput == 0) ? CHECKING : SAVINGS;
        clearInputBuffer();

        // Add the account
        accounts[*numAccounts].account_number = newAccountNumber;
        strcpy(accounts[*numAccounts].name, name);
        accounts[*numAccounts].balance = balance;
        accounts[*numAccounts].type = type;
        (*numAccounts)++;
        printf("Account added successfully.\n");
        break;
    } while (1);
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
        printf("Enter new name: ");
        if (scanf("%s", accounts[i].name) == 0) {
            printf("Invalid input!\n");
            return;
        }
        printf("Enter new balance: ");
        if (scanf("%f", &accounts[i].balance) == 1) {
            printf("Account updated successfully.\n");
        }
        printf("Invalid input!\n");
        return;
    }
    else {
        printf("Account not found.\n");
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
        printf("Deposit successful. New balance: %.2f\n", accounts[i].balance);
    }
    else {
        printf("Account not found.\n");
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
            printf("Withdrawal successful. New balance: %.2f\n", accounts[i].balance);
        }
        else {
            printf("Insufficient balance.\n");
        }
    }
    else {
        printf("Account not found.\n");
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
        printf("Account Number: %d\n", accounts[i].account_number);
        printf("Name: %s\n", accounts[i].name);
        printf("Balance: %.2f\n", accounts[i].balance);
        printf("Type: %s\n", accounts[i].type == CHECKING ? "Checking" : "Savings");
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
            printf("#Account Number: %d\n# Name: %s\n# Balance: %.2f\n# Type: %s\n", accounts[i].account_number, accounts[i].name, accounts[i].balance, accounts[i].type == CHECKING ? "Checking" : "Savings");
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
            printf("\n#Account Number: %d\n# Name: %s\n# Balance: %.2f\n# Type: %s\n", accounts[i].account_number, accounts[i].name, accounts[i].balance, accounts[i].type == CHECKING ? "Checking" : "Savings");
        }
    }
}

void Search_Account(ACCOUNT accounts[], int numAccounts, char name[]) {
    int i, found = 0;
    for (i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].name, name) == 0) {
            printf("#Account Number: %d\n# Name: %s\n# Balance: %.2f\n# Type: %s\n", accounts[i].account_number, accounts[i].name, accounts[i].balance, accounts[i].type == CHECKING ? "Checking" : "Savings");
            found = 1;
        }
    }
    if (!found) {
        printf("Account not found.\n");
    }
}
