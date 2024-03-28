#define MAXCHAR 3
#include "menu.h"

//group3  - karls, madisont, adilf - prog71985 - group project - menu implementation

//Added Welcome Menu print function
void printWelcomeMenu() {
	printf("\n *********************** \n");
	printf("**   Welcome to Bank   **\n");
	printf("**  Management System  **\n");
	printf(" *********************** \n");
}

//Added Welcome Menu Options print function
void printOptions() {
	printf("\nTo choose a function, enter its label:\n");
	printf("1) Add a new account\n");
	printf("2) Delete an existing account\n");
	printf("3) Update an existing account\n");
	printf("4) Display a single account\n");
	printf("5) Display all customers and accounts\n");
	printf("6) Search for a customer\n");
	printf("7) Quit\n");
}

//Added Menu Input function
char getCharInput(char message[]) {
	char menuInput[MAXCHAR];
	printf("%s\n", message);
	scanf_s("%s", menuInput, MAXCHAR);
	return menuInput[0];
}