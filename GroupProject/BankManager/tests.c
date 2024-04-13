#include "account.h"
#include "tests.h"
#include <stdio.h>
#include <string.h>

//group3 - karls, madisont, adilf prog71985 - group project - testing implementation

//Test for add account

void test_AddAccountOne() {

    ACCOUNT accounts[MAX_ACCOUNTS];
    int numAccounts = 0;

    /*Hard coding values cause its not gonna work with user input*/
    int accountNumber = 1001;
    char firstName[MAX_NAME_LENGTH] = "John";
    char lastName[MAX_NAME_LENGTH] = "Doe";
    CUSTOMER customer = { firstName, lastName };
    float balance = 1000.0;
    AccountType type = CHECKING;

    Add_Account_ToArray(accounts, &numAccounts+1, accountNumber, customer.firstName, customer.lastName, balance, type);

    /*Expected result*/
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

    /*Hard coding values cause its not gonna work with user input*/
    int accountNumber = 1002;
    char firstName[MAX_NAME_LENGTH] = "Jane";
    char lastName[MAX_NAME_LENGTH] = "Smith";
    CUSTOMER customer = { firstName, lastName };
    float balance = 2000.0;
    AccountType type = SAVINGS;

    Add_Account_ToArray(accounts, &numAccounts+1, accountNumber, customer.firstName, customer.lastName, balance, type);

    /*Expected result*/
    ACCOUNT expectedAccount = { 1002, customer, 2000.0, SAVINGS }; 

    if (memcmp(&accounts[1], &expectedAccount, sizeof(ACCOUNT)) == 0) {
        printf("Test case for Add_Account2: PASS\n");
    }
    else {
        printf("Test case for Add_Account2: FAIL\n");
    }
}

//Test for delete account

void test_DeleteAccount() {
    //Account one customer info
    CUSTOMER customer = { "John", "Doe" };

    //Account two customer info
    CUSTOMER customer2 = { "Jane", "Smith" };

    ACCOUNT accounts[MAX_ACCOUNTS] = { {1001, customer, 1000.0, CHECKING},
                                      {1002, customer2, 2000.0, SAVINGS} };
    int numAccounts = 2;

    int accountToDelete = 1001;
    Delete_Account(accounts, &numAccounts, accountToDelete);

    ACCOUNT expectedAccounts[MAX_ACCOUNTS] = { {1002, customer2, 2000.0, SAVINGS} };


    if (memcmp(accounts, expectedAccounts, sizeof(accounts)) == 0 && numAccounts == 1) {
        printf("Test case for Delete_Account: PASS\n");
    }
    else {
        printf("Test case for Delete_Account: FAIL\n");
    }
}

//Tests for update account
void test_Update_Account() {

    CUSTOMER customer = { "John", "Doe" };
    ACCOUNT accounts[] = {
        {1001, customer, 1000.0, CHECKING}
    };
    int numAccounts = 1;

    // Hardcoded values for updating the account
    char newFirstName[MAXNAME] = "Jane";
    char newLastName[MAXNAME] = "Smith";
    float newBalance = 1500.0;

    
    Update_Account(accounts, numAccounts, 1001, newFirstName, newLastName, newBalance);

    // Expected result after the update
    CUSTOMER expectedCustomer = { "Jane", "Smith" };
    ACCOUNT expectedAccount = { 1001, expectedCustomer, 1500.0, CHECKING };

    
    if (memcmp(&accounts[0], &expectedAccount, sizeof(ACCOUNT)) == 0) {
        printf("Test case for Update_Account: PASS\n");
    }
    else {
        printf("Test case for Update_Account: FAIL\n");
    }
}

//Tests for deposit

void test_AccountDeposit() {



}

//Tests for withdraw

void test_AccountWithdrawal() {



}

void test_AccountWithdraw_Insufficient() {



}