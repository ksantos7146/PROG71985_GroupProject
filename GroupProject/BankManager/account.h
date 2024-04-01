#ifndef ACCOUNT_H
#define ACCOUNT_H

/*Macros*/
#define MAX_ACCOUNTS 100
#define MAX_NAME_LENGTH 50

/*NGL I had to watch 2 hour videos on ENUM alone and after learning it I feel stupid cause it was such a simple concept*/


/*Structs and Enum*/
typedef enum {
    CHECKING,
    SAVINGS
} AccountType;

/*This is our bread and butter the account struct*/
typedef struct {
    int account_number;
    char name[MAX_NAME_LENGTH];
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

#endif /* ACCOUNT_H */
