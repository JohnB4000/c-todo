#ifndef TO_DO_ITEM_H 
#define TO_DO_ITEM_H 

#include "int_list.h"

typedef struct ToDoItem {
	char name[50];
	int completed;
	char due[50];
	char description[50];
	struct ToDoItem *nextItem;
	struct ToDoItem *subItem;
} ToDoItem;


ToDoItem* addNewToDoItem(ToDoItem *head, char *name, char *due, char *description);
ToDoItem* createNewToDoItem(char *name, char *due, char *description);
void freeToDoList(ToDoItem *item);
ToDoItem* getNthItem(ToDoItem *headItem, IntList *headList);
void updateColumn(ToDoItem *item, char *columnName, char *newValue);
ToDoItem* deleteToDoItem(ToDoItem *head, IntList *indexListHead);
	
#endif
