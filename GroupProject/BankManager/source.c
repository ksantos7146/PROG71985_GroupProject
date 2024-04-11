#define _CRT_SECURE_NO_WARNINGS
#define MAXCHAR 3
#include "menu.h"

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
        Display_Menu();

        if (scanf("%d", &choice) != 1) {
            printf("Invalid Option Selected. Try Again\n");
            clearInputBuffer();
            continue;
        }
        Process_User_Choice(choice, accounts, &numAccounts);
        clearInputBuffer();

    } while (choice != 11);

    return 0;
}
