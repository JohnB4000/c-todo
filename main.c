#include <stdio.h>
#include <string.h>
#include "main.h"
#include "print_to_do.h"
#include "to_do_item.h"
#include "int_list.h"
#include "utils/index_sequence.h"


void printWelcome();

int main(int argc, char *argv[]) {
	ToDoItem *head = NULL;

	int userOption = 1;
	char userInput[500];

	char nameBuffer[50] = "";
	char dueBuffer[50] = "";
	char descriptionBuffer[50] = "";

	printWelcome();
	while (userOption != 0) {
		printList(head);
		printf("\n\n>>> ");
		scanf(" %[^\n]", userInput);
		if (strncmp(userInput, "exit", 4) == 0) {
			userOption = 0;
		} else if (strncmp(userInput, "addsub", 6) == 0) { 
			int bytesRead;
			IntList *indexListHead = getIndexSequenceAndOffset(userInput, 7, &bytesRead);
			sscanf(userInput + bytesRead, " \"%49[^\"]\" \"%49[^\"]\" \"%49[^\"]\"", nameBuffer, dueBuffer, descriptionBuffer);
			ToDoItem *parent = getNthItem(head, indexListHead);
			if (parent->subItem == NULL)
				parent->subItem = createNewToDoItem(nameBuffer, dueBuffer, descriptionBuffer);
			else 
				addNewToDoItem(parent->subItem, nameBuffer, dueBuffer, descriptionBuffer);
			freeIntList(indexListHead);
			strcpy(nameBuffer, "");
			strcpy(dueBuffer, "");
			strcpy(descriptionBuffer, "");
		} else if (strncmp(userInput, "add", 3) == 0) {
			sscanf(userInput, "add \"%49[^\"]\" \"%49[^\"]\" \"%49[^\"]\"", nameBuffer, dueBuffer, descriptionBuffer);
			head = addNewToDoItem(head, nameBuffer, dueBuffer, descriptionBuffer);
			strcpy(nameBuffer, "");
			strcpy(dueBuffer, "");
			strcpy(descriptionBuffer, "");
		} else if (strncmp(userInput, "check", 5) == 0) {
			IntList *indexListHead = getIndexSequence(userInput, 6);
			getNthItem(head, indexListHead)->completed = 1;
			freeIntList(indexListHead);
		} else if (strncmp(userInput, "uncheck", 7) == 0) {
			IntList *indexListHead = getIndexSequence(userInput, 8);
			getNthItem(head, indexListHead)->completed = 0;
			freeIntList(indexListHead);
		} else if (strncmp(userInput, "update", 6) == 0) {
			int bytesRead;
			char columnName[50], newValue[50];
			IntList *indexListHead = getIndexSequenceAndOffset(userInput, 7, &bytesRead);
			sscanf(userInput + bytesRead, " %s \"%49[^\"]\"", columnName, newValue);
			ToDoItem *itemToUpdate = getNthItem(head, indexListHead);
			updateColumn(itemToUpdate, columnName, newValue);
			freeIntList(indexListHead);
		} else if(strncmp(userInput, "delete", 6) == 0) {
			IntList *indexListHead = getIndexSequence(userInput, 7);
			head = deleteToDoItem(head, indexListHead);
		} else {
			printf("Invalid Command\n");
		}
	}
	freeToDoList(head);
	return 0;
}


void printWelcome() {
	printf("Welcome to To Do App.\n");
}
