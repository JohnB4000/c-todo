#include <stdlib.h>
#include "int_list.h"


IntList* addValue(IntList *head, int value) {
	IntList *newNode = (IntList*) malloc(sizeof(IntList));
	newNode->value = value;
	IntList *currentNode = head;
	if (currentNode == NULL)
		return newNode;
	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
	}
	currentNode->next = newNode;
	return head;
}


void freeIntList(IntList *head) {
	IntList *currentNode = head;
	IntList *nextNode = NULL;
	while (currentNode != NULL) {
		nextNode = currentNode->next;
		free(currentNode);
		currentNode = nextNode;
	}
}


int getLastIndex(IntList *head) {
	while (head->next != NULL) {
		head = head->next;
	}
	return head->value;
}


void decrementLastIndex(IntList *head) {
	while (head->next != NULL) {
		head = head->next;
	}
	head->value = head->value - 1;
}

void removeLastIndex(IntList *head) {
	IntList *previous;
	while (head->next != NULL) {
		previous = head;
		head = head->next;
	}
	free(head);
	previous->next = NULL;
}
