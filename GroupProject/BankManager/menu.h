#pragma once
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

//group3 - karls, madisont, adilf - prog71985 - group project - menu interface

#ifndef MENU_LIBRARY_H
#define MENU_LIBRARY_H

#include"account.h"
#include"file_operations.h"


typedef enum {
    ADD_ACCOUNT = 1,
    DELETE_ACCOUNT,
    UPDATE_ACCOUNT,
    DEPOSIT,
    WITHDRAW,
    DISPLAY_SINGLE_ACCOUNT,
    DISPLAY_RANGE_OF_ACCOUNTS,
    DISPLAY_ALL_ACCOUNTS,
    SEARCH_ACCOUNT,
    SAVE_ACCOUNTS,
    EXIT
} MenuChoice;

void Display_Menu();
void Process_User_Choice(int choice, ACCOUNT accounts[], int* numAccounts);

#endif //MENU_LIBRARY_H