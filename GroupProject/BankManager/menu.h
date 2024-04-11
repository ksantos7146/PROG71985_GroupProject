#pragma once
#include <stdio.h>

//group3 - karls, madisont, adilf - prog71985 - group project - menu interface

#ifndef MENU_LIBRARY_H
#define MENU_LIBRARY_H

#include"account.h"

#include"file_operations.h"

void Display_Menu();
void Process_User_Choice(int choice, ACCOUNT accounts[], int* numAccounts);

#endif //MENU_LIBRARY_H