#define _CRT_SECURE_NO_WARNINGS
#define MAXCHAR 3
#include "main.h"

//group3  - karls, madisont, adilf - prog71985 - group project - menu implementation


/*

Bank Management System:

1) Has the ability to add checkings and savings accounts so that's good
2) Has the ability to withdraw as well as deposit money to any account so that's down
3) Has all the basic stuff and banking management we needed.

Issues to be worked on (you guys can read and add stuff to this as well)

1) Lots of input validation and I mean A LOT . We need to make sure the data is always the type it's for for example the account number being always int and unique
2) We can certainly make the code hella cleaner cause this is scuffed . Lets make it so that the main has 20-30 lines at max.
3) We need to check each functions and their capability . I take blame for this this is hella scuffed coding so I had to clean input buffer here and there.
4) We should also add more capabilities if we have time . for example interest system , pin code for each account ? , mobile number for each account ? Employee key to access to account information?
5) Other than that the file handling is a bit eh as well so we can work on that. If I write "ADIL FARID" as account name it shows only ADIL on the file so anyone pls fix it tytyty :D


*/


/*This is the main with the most hatefull coding you ever seen*/
int main() {
    ACCOUNT accounts[MAX_ACCOUNTS];
    int numAccounts = 0;
    int choice;

    Load_Accounts(accounts, &numAccounts);

    do {
        /*Displaying main menu : Lowkey not a fan of the way it's looking so lets work on the looks */
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

        if (scanf("%d", &choice) != 1) {
            printf("Invalid Option Selected. Try Again\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
        case 1:
            Add_Account(accounts, &numAccounts);
            break;
        case 2: {
            int accountNumber;
            printf("Enter account number to delete: ");
            if (scanf("%d", &accountNumber) == 1) {
                Delete_Account(accounts, &numAccounts, accountNumber);
            }
            else {
                printf("Invalid input!\n");
            }
            break;
        }
        case 3: {
            int accountNumber;
            printf("Enter account number to update: ");
            if (scanf("%d", &accountNumber) == 1) {
                Update_Account(accounts, numAccounts, accountNumber);
            }
            else {
                printf("Invalid input!\n");
            }
            break;
        }
        case 4: {
            int accountNumber;
            printf("Enter account number to deposit: ");
            if (scanf("%d", &accountNumber) == 1) {
                Deposit(accounts, numAccounts, accountNumber);
            }
            else {
                printf("Invalid input!\n");
            }
            break;
        }
        case 5: {
            int accountNumber;
            printf("Enter account number to withdraw: ");
            if (scanf("%d", &accountNumber) == 1) {
                Withdraw(accounts, numAccounts, accountNumber);
            }
            else {
                printf("Invalid input!\n");
            }
            break;
        }
        case 6: {
            int accountNumber;
            printf("Enter account number to display: ");
            if (scanf("%d", &accountNumber) == 1) {
                Display_Single_Account(accounts, numAccounts, accountNumber);
            }
            else {
                printf("Invalid input!\n");
            }
            break;
        }
        case 7: {
            float minBalance, maxBalance;
            printf("Enter minimum balance: ");
            if (scanf("%f", &minBalance) == 1) {
                printf("Enter maximum balance: ");
                if (scanf("%f", &maxBalance) == 1) {
                    Display_Range_Of_Accounts(accounts, numAccounts, minBalance, maxBalance);
                }
                else {
                    printf("Invalid input!\n");
                }
            }
            else {
                printf("Invalid input!\n");
            }
            break;
        }
        case 8:
            Display_All_Accounts(accounts, numAccounts);
            break;
        case 9: {
            char name[50];
            printf("Enter name to search: ");
            if (scanf("%s", name) == 1) {
                Search_Account(accounts, numAccounts, name);
            }
            else {
                printf("Invalid input!\n");
            }
            break;
        }
        case 10:
            Save_Accounts(accounts, numAccounts);
            break;
        case 11:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 11.\n");
        }

        clearInputBuffer();
    } while (choice != 11);

    return 0;
}
