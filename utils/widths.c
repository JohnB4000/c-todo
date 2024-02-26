#include <string.h>
#include "widths.h"

void getWidths(ToDoItem *first, int *longestName, int *longestDue, int *longestDescription, int depth) {
	ToDoItem *currentItem = first;
	int count = 1;
	while(currentItem != NULL) {
		updateWidths(currentItem, longestName, longestDue, longestDescription, depth, count++);
		getWidths(currentItem->subItem, longestName, longestDue, longestDescription, depth+1);
		currentItem = currentItem->nextItem;
	}
}

int getNumDigits(int number) {
	int numDigits = 1;
	while (number > 9) {
		numDigits++;
		number /= 10;
	}
	return numDigits;
}

void updateWidths(ToDoItem *item, int *longestName, int *longestDue, int *longestDescription, int depth, int count) {
	int currentLength = strlen(item->name) + 4 + 2 + getNumDigits(count) + (depth * 4);
	if (currentLength > *longestName)
		*longestName = currentLength;
	if (strlen(item->due) > *longestDue) 
		*longestDue = strlen(item->due);
	if (strlen(item->description) > *longestDescription)
		*longestDescription = strlen(item->description);
}
