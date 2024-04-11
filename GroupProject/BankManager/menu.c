//group3 - karls, madisont, adilf prog71985 - group project - menu function definitions

#include"account.h"
#include "menu.h"
#include"file_operations.h"

void Display_Menu() {
    printf("\nBank Management System Menu\n");
    printf("1. Add Account\n");
    printf("2. Delete Account\n");
    printf("3. Update Account\n");
    printf("4. Deposit\n");
    printf("5. Withdraw\n");
    printf("6. Display Single Account\n");
    printf("7. Display Range of Accounts\n");
    printf("8. Display All Accounts\n");
    printf("9. Search Account\n");
    printf("10. Save Accounts\n");
    printf("11. Exit\n");
    printf("Enter your choice: ");
}
void Process_User_Choice(int choice, ACCOUNT accounts[], int* numAccounts) {
    int accountNumber;
    float minBalance, maxBalance;
    char name[MAX_NAME_LENGTH];

    switch (choice) {
    case 1: // Add Account
        Add_Account(accounts, numAccounts);
        break;
    case 2: // Delete Account
        printf("Enter account number to delete: ");
        if (scanf("%d", &accountNumber) == 1) {
            Delete_Account(accounts, numAccounts, accountNumber);
        }
        else {
            printf("Invalid input!\n");
        }
        break;
    case 3: // Update Account
        printf("Enter account number to update: ");
        if (scanf("%d", &accountNumber) == 1) {
            Update_Account(accounts, *numAccounts, accountNumber);
        }
        else {
            printf("Invalid input!\n");
        }
        break;
    case 4: // Deposit
        printf("Enter account number to deposit: ");
        if (scanf("%d", &accountNumber) == 1) {
            Deposit(accounts, *numAccounts, accountNumber);
        }
        else {
            printf("Invalid input!\n");
        }
        break;
    case 5: // Withdraw
        printf("Enter account number to withdraw: ");
        if (scanf("%d", &accountNumber) == 1) {
            Withdraw(accounts, *numAccounts, accountNumber);
        }
        else {
            printf("Invalid input!\n");
        }
        break;
    case 6: // Display Single Account
        printf("Enter account number to display: ");
        if (scanf("%d", &accountNumber) == 1) {
            Display_Single_Account(accounts, *numAccounts, accountNumber);
        }
        else {
            printf("Invalid input!\n");
        }
        break;
    case 7: // Display Accounts within Balance Range
        printf("Enter minimum balance: ");
        if (scanf("%f", &minBalance) == 1) {
            printf("Enter maximum balance: ");
            if (scanf("%f", &maxBalance) == 1) {
                Display_Range_Of_Accounts(accounts, *numAccounts, minBalance, maxBalance);
            }
            else {
                printf("Invalid input!\n");
            }
        }
        else {
            printf("Invalid input!\n");
        }
        break;
    case 8: // Display All Accounts
        Display_All_Accounts(accounts, *numAccounts);
        break;
    case 9: // Search Account by Name
        printf("Enter name to search: ");
        if (scanf("%49s", name) == 1) { // Limiting the input to avoid buffer overflow
            Search_Account(accounts, *numAccounts, name);
        }
        else {
            printf("Invalid input!\n");
        }
        break;
    case 10: // Save Accounts to File
        Save_Accounts(accounts, *numAccounts);
        break;
    case 11: // Exit
        printf("Exiting...\n");
        break;
    default:
        printf("Invalid choice. Please enter a number between 1 and 11.\n");
        break;
    }
}
