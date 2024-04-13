#include "account.h"
#include "tests.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//group3 - karls, madisont, adilf prog71985 - group project - testing implementation

//Tests for add account
void test_AddAccountOne() {

    ACCOUNT accounts[MAX_ACCOUNTS];
    int numAccounts = 0;

    //Hard coding values cause its not gonna work with user input
    int accountNumber = 1001;
    char firstName[MAX_NAME_LENGTH] = "John";
    char lastName[MAX_NAME_LENGTH] = "Doe";
    CUSTOMER customer = { firstName, lastName };
    float balance = 1000.0;
    AccountType type = CHECKING;

    Add_Account_ToArray(accounts, &numAccounts+1, accountNumber, customer.firstName, customer.lastName, balance, type);

    //Expected result
    ACCOUNT expectedAccount = { 1001, customer, 1000.0, CHECKING };


    if (memcmp(&accounts[0], &expectedAccount, sizeof(ACCOUNT)) == 0) {
        printf("Test case for Add_Account1: PASS\n");
    }
    else {
        printf("Test case for Add_Account1: FAIL\n");
    }
}

void test_AddAccountTwo() {

    ACCOUNT accounts[MAX_ACCOUNTS];
    int numAccounts = 1;

    //Hard coding values cause its not gonna work with user input
    int accountNumber = 1002;
    char firstName[MAX_NAME_LENGTH] = "Jane";
    char lastName[MAX_NAME_LENGTH] = "Smith";
    CUSTOMER customer = { firstName, lastName };
    float balance = 2000.0;
    AccountType type = SAVINGS;

    Add_Account_ToArray(accounts, &numAccounts+1, accountNumber, customer.firstName, customer.lastName, balance, type);

    //Expected result
    ACCOUNT expectedAccount = { 1002, customer, 2000.0, SAVINGS }; 

    if (memcmp(&accounts[1], &expectedAccount, sizeof(ACCOUNT)) == 0) {
        printf("Test case for Add_Account2: PASS\n");
    }
    else {
        printf("Test case for Add_Account2: FAIL\n");
    }
}

//Test for delete account
void test_DeleteAccountOne() {
    //Account one customer info
    CUSTOMER customer = { "John", "Doe" };

    //Account two customer info
    CUSTOMER customer2 = { "Jane", "Smith" };

    //Allocate memory for accounts arrays on the heap
    ACCOUNT* accounts = (ACCOUNT*)malloc(MAX_ACCOUNTS * sizeof(ACCOUNT));
    ACCOUNT* expectedAccounts = (ACCOUNT*)malloc(MAX_ACCOUNTS * sizeof(ACCOUNT));

    //Check if memory allocation succeeded
    if (accounts == NULL || expectedAccounts == NULL) {
        printf("Memory allocation failed. Exiting test.\n");
        return;
    }

    //Initialize accounts
    accounts[0] = (ACCOUNT){ 1001, customer, 1000.0, CHECKING };
    accounts[1] = (ACCOUNT){ 1002, customer2, 2000.0, SAVINGS };
    int numAccounts = 2;

    int accountToDelete = 1001;
    Delete_Account(accounts, &numAccounts, accountToDelete);

    expectedAccounts[0] = (ACCOUNT){ 1002, customer2, 2000.0, SAVINGS };

    //Compare the actual accounts with the expected accounts
    if (memcmp(accounts, expectedAccounts, MAX_ACCOUNTS * sizeof(ACCOUNT)) == 0 && numAccounts == 1) {
        printf("Test case for Delete_Account: PASS\n");
    }
    else {
        printf("Test case for Delete_Account: FAIL\n");
    }

    //Free dynamically allocated memory
    free(accounts);
    free(expectedAccounts);
}

//Test for update account
void test_UpdateAccount() {

    CUSTOMER customer1 = { "John", "Doe" };
    CUSTOMER customer2 = { "Jane", "Smith" };
    ACCOUNT accounts[] = {
        {1001, customer1, 1000.0, CHECKING},
        {1002, customer2, 2000.0, SAVINGS}
    };
    int numAccounts = 2;

    //Hardcoded values for updating the account
    int accountNumberToUpdate = 1001;
    char newFirstName[MAXNAME] = "Joe";
    char newLastName[MAXNAME] = "Johnson";
    float newBalance = 1500.0;


    Update_Account(accounts, numAccounts, accountNumberToUpdate, newFirstName, newLastName, newBalance);

    //Expected result after the update
    CUSTOMER expectedCustomer1 = { "Joe", "Johnson" };
    CUSTOMER expectedCustomer2 = { "Jane", "Smith" };
    ACCOUNT expectedAccounts[] = {
        {1001, expectedCustomer1, 1500.0, CHECKING},
        {1002, expectedCustomer2, 2000.0, SAVINGS}
    };


    if (memcmp(accounts, expectedAccounts, numAccounts * sizeof(ACCOUNT)) == 0) {
        printf("Test case for Update_Account: PASS\n");
    }
    else {
        printf("Test case for Update_Account: FAIL\n");
    }
}


//Test for deposit
void test_AccountDeposit() {
    CUSTOMER customer = { "John", "Johnson" };
    ACCOUNT accounts[MAX_ACCOUNTS] = { {1001, customer, 1500.0, CHECKING} };
    int numAccounts = 1;
    int accountToDeposit = 1001;
    float depositAmount = 500.0;

    Deposit(accounts, numAccounts, accountToDeposit, depositAmount);

    ACCOUNT expectedAccount = { 1001, customer, 2000.0, CHECKING };

    if (memcmp(&accounts[0], &expectedAccount, sizeof(ACCOUNT)) == 0) {
        printf("Test case for Deposit: PASS\n");
    }
    else {
        printf("Test case for Deposit: FAIL\n");
    }
}

//Test for withdraw
void test_AccountWithdrawal() {
    CUSTOMER customer = { "John", "Johnson" };
    ACCOUNT accounts[MAX_ACCOUNTS] = { {1001, customer, 2000.0, CHECKING} };
    int numAccounts = 1;
    int accountToWithdraw = 1001;
    float withdrawalAmount = 500.0;

    Deposit(accounts, numAccounts, accountToWithdraw, withdrawalAmount);

    ACCOUNT expectedAccount = { 1001, customer, 1500.0, CHECKING };

    if (memcmp(&accounts[0], &expectedAccount, sizeof(ACCOUNT)) == 0) {
        printf("Test case for Withdrawal: PASS\n");
    }
    else {
        printf("Test case for Withdrawal: FAIL\n");
    }
}