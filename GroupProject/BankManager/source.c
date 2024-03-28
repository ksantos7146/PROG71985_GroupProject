#include "menu.h"
#include <stdio.h>
#include <stdbool.h>

//group3  - karls, madisont, adilf - prog71985 - group project - source code

int main(void) {
	bool continueProgram = true;
	while (continueProgram) {
		
		printWelcomeMenu();
		printOptions();

		char menuInput = '\0';
		menuInput = getCharInput("\nEnter menu option number:");

		switch (menuInput) {
		case '1':
			//Option to: Add a new account
			printf("Option 1\n");
			break;
		case '2':
			//Option to: Delete an existing account
			printf("Option 2\n");
			break;
		case '3':
			//Option to: Update an existing account
			printf("Option 3\n");
			break;
		case '4':
			//Option to: Display a single account
			printf("Option 4\n");
			break;
		case '5':
			//Option to: Display all customers and accounts
			printf("Option 5\n");
			break;
		case '6':
			//Option to: Search for a customer
			printf("Option 6\n");
			break;
		case '7':
			continueProgram = false;
			printf("\nQuitting program...\n");
			break;
		default:
			printf("\nInvalid option entered.\n");
			break;
		}
	}
	return 0;
}