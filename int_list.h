#ifndef INT_LIST_H
#define INT_LIST_H


typedef struct IntList {
	int value;
	struct IntList *next;
} IntList;


IntList* addValue(IntList *head, int value);
void freeIntList(IntList *head);
int getLastIndex(IntList *head);
void decrementLastIndex(IntList *head);
void removeLastIndex(IntList *head);


#endif 
