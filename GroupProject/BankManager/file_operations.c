#define _CRT_SECURE_NO_WARNINGS
#include "file_operations.h"
#include <stdio.h>


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
        fprintf(fp, "%d %s %.2f %d\n", accounts[i].account_number, accounts[i].name, accounts[i].balance, accounts[i].type);
    }

    fclose(fp);
    printf("Accounts saved successfully.\n");
}
/*Function to Load Account data from the file*/
void Load_Accounts(ACCOUNT accounts[], int* numAccounts) {
    FILE* fp;
    int account_number, type;
    char name[MAX_NAME_LENGTH];
    float balance;

    fp = fopen("accounts.txt", "r");
    if (fp == NULL) {
        printf("No saved accounts found.\n");
        return;
    }

    *numAccounts = 0;
    while (fscanf(fp, "%d %s %f %d", &account_number, name, &balance, &type) != EOF) {
        accounts[*numAccounts].account_number = account_number;
        strcpy(accounts[*numAccounts].name, name);
        accounts[*numAccounts].balance = balance;
        accounts[*numAccounts].type = type;
        (*numAccounts)++;
    }

    fclose(fp);
    printf("Accounts loaded successfully.\n");
}
