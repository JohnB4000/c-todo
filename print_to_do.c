#include <stdio.h>
#include <string.h>
#include "print_to_do.h"
#include "utils/widths.h"

void printList(ToDoItem *first) {
	int longestName = 4;
	int longestDue = 3;
	int longestDescription = 11;
	getWidths(first, &longestName, &longestDue, &longestDescription, 0);

	int totalWidth = longestName + longestDue + longestDescription + 4 + 6;

	printHeader(totalWidth, longestName, longestDue, longestDescription);

	ToDoItem *currentItem = first;
	int count = 1;
	while (currentItem != NULL) {
		printDivider(longestName, longestDue, longestDescription);
		printItem(currentItem, longestName, longestDue, longestDescription, 0, count++);
		printSubItems(currentItem->subItem, longestName, longestDue, longestDescription, 1);
		currentItem = currentItem->nextItem;
	}
	printLine(totalWidth);
}

void printHeader(int totalWidth, int longestName, int longestDue, int longestDescription) {
	printLine(totalWidth);
	printf("| Name ");
	printCharNTimes(' ', longestName-4);
	printf("| Due ");
	printCharNTimes(' ', longestDue-3);
	printf("| Description ");
	printCharNTimes(' ', longestDescription-11);
	printf("|\n");
}

void printLine(int width) {
	printCharNTimes('-', width);
	printf("\n");
}

void printDivider(int longestName, int longestDue, int longestDescription) {
	printf("|");
	printCharNTimes('-', longestName+2);
	printf("|");
	printCharNTimes('-', longestDue+2);
	printf("|");
	printCharNTimes('-', longestDescription+2);
	printf("|\n");
}

void printItem(ToDoItem *item, int longestName, int longestDue, int longestDescription, int depth, int count) {
	printf("| ");
	printCharNTimes(' ', depth*4);
	printf("%d. ", count);
	if (item->completed)
		printf("[x] ");
	else 
		printf("[ ] ");
	printf("%s", item->name);
	printCharNTimes(' ', longestName - (strlen(item->name) + 5 + getNumDigits(count) + (depth * 4)));
	printf("| ");
	printf("%s", item->due);
	printCharNTimes(' ', longestDue - strlen(item->due) + 1);
	printf("| ");
	printf("%s", item->description);
	printCharNTimes(' ', longestDescription - strlen(item->description));
	printf(" |\n");
}

void printSubItems(ToDoItem *item, int longestName, int longestDue, int longestDescription, int depth) {
	ToDoItem *currentItem = item;
	int count = 1;
	while (currentItem != NULL) {
		printItem(currentItem, longestName, longestDue, longestDescription, depth, count++);
		printSubItems(currentItem->subItem, longestName, longestDue, longestDescription, depth+1);
		currentItem = currentItem->nextItem;
	}
}

void printCharNTimes(char character, int count) {
	for (int i = 0; i < count; i++) {
		printf("%c", character);
	}
}
