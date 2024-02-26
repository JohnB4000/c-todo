#ifndef UTILS_H 
#define UTILS_H

#include "../to_do_item.h"

int getNumDigits(int number);
void getWidths(ToDoItem *first, int *longestName, int *longestDue, int *longestDescription, int depth);
void updateWidths(ToDoItem *item, int *longestName, int *longestDue, int *longestDescription, int depth, int count);


#endif
