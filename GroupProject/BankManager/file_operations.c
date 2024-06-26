#define _CRT_SECURE_NO_WARNINGS
#include "file_operations.h"
#include <stdio.h>

//group3 - karls, madisont, adilf prog71985 - group project - file operations implementation

/*I would LOVE I MEAN LOVEEE if you guys can do file cause I hate it*/

/*Function to Save Accounts data to the file*/
void Save_Accounts(ACCOUNT accounts[], int numAccounts) {
    FILE* fp;
    int i;

    fp = fopen("accounts.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (i = 0; i < numAccounts; i++) {
        fprintf(fp, "%d %s %s %.2f %d\n", accounts[i].account_number, accounts[i].customer.firstName, accounts[i].customer.lastName, accounts[i].balance, accounts[i].type);
    }

    fclose(fp);
    printf("Accounts saved successfully.\n");
}
/*Function to Load Account data from the file*/
void Load_Accounts(ACCOUNT accounts[], int* numAccounts) {
    FILE* fp;
    int account_number, type;
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    float balance;

    fp = fopen("accounts.txt", "r");
    if (fp == NULL) {
        printf("No saved accounts found.\n");
        return;
    }

    *numAccounts = 0;
    while (fscanf(fp, "%d %s %s %f %d", &account_number, firstName, lastName, &balance, &type) != EOF) {

        if (balance < 0 || (type != CHECKING && type != SAVINGS)) {
            continue;
        }
        accounts[*numAccounts].account_number = account_number;
        strcpy(accounts[*numAccounts].customer.firstName, firstName);
        strcpy(accounts[*numAccounts].customer.lastName, lastName);
        accounts[*numAccounts].balance = balance;
        accounts[*numAccounts].type = type;
        (*numAccounts)++;
    }

    fclose(fp);
    printf("Accounts loaded successfully.\n\n");
}