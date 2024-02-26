#include <stdlib.h>
#include <string.h>
#include "to_do_item.h"
#include "int_list.h"

ToDoItem* addNewToDoItem(ToDoItem *head, char *name, char *due, char *description) {
	ToDoItem *newToDoItem = createNewToDoItem(name, due, description);
	if (head == NULL) {
		return newToDoItem;
	}

	ToDoItem *currentItem = head;
	while (currentItem->nextItem != NULL) {
		currentItem = currentItem->nextItem;
	}
	currentItem->nextItem = newToDoItem;
	return head;
}


ToDoItem* createNewToDoItem(char *name, char *due, char *description) {
	ToDoItem *newToDoItem = (ToDoItem*) malloc(sizeof(ToDoItem));
	strcpy(newToDoItem->name, name);
	strcpy(newToDoItem->due, due);
	strcpy(newToDoItem->description, description);
	newToDoItem->completed = 0;
	newToDoItem->subItem = NULL;
	newToDoItem->nextItem = NULL;
	return newToDoItem;
}

void freeToDoList(ToDoItem *item) {
	if (item == NULL)
		return;
	if (item->nextItem != NULL)
		freeToDoList(item->nextItem);
	if (item->subItem != NULL)
		freeToDoList(item->subItem);
	free(item);
}

ToDoItem* getNthItem(ToDoItem *headItem, IntList *headList) {
	ToDoItem *currentItem = headItem;
	IntList *currentNode = headList;
	while(currentNode != NULL) {
		for (int i = 0; i < currentNode->value; i++) {
			if (currentItem != NULL)
				currentItem = currentItem->nextItem;
		}
		currentNode = currentNode->next;
		if (currentNode != NULL)
			currentItem = currentItem->subItem;
	}
	return currentItem;
}

void updateColumn(ToDoItem *item, char *columnName, char *newValue) {
	if (strcmp(columnName, "Name") == 0)
		strcpy(item->name, newValue);
	else if (strcmp(columnName, "Due") == 0)
		strcpy(item->due, newValue);
	else if (strcmp(columnName, "Description") == 0)
		strcpy(item->description, newValue);
}

ToDoItem* deleteToDoItem(ToDoItem *head, IntList *indexListHead) {
	ToDoItem *item = getNthItem(head, indexListHead);
	if (indexListHead->value == 0 && indexListHead->next == NULL) {
		ToDoItem *newHead = head->nextItem;
		head->nextItem = NULL;
		if (head->subItem != NULL)
			free(head->subItem);
		free(head);
		return newHead;
	} else if (getLastIndex(indexListHead) == 0 ) {
		removeLastIndex(indexListHead);
		ToDoItem *parent = getNthItem(head, indexListHead);
		parent->subItem = item->nextItem;
	} else {
		decrementLastIndex(indexListHead);
		ToDoItem *previousItem = getNthItem(head, indexListHead);
		previousItem->nextItem = item->nextItem;
		freeToDoList(item->subItem);
		free(item);
	}
	return head;
}
