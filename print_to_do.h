#ifndef PRINT_TO_DO_H
#define PRINT_TO_DO_H


#include "to_do_item.h"

void printList(ToDoItem *first);
void printDivider(int longestName, int longestDue, int longestDescription);
void printHeader(int totalWidth, int longestName, int longestDue, int longestDescription);
void printLine(int width);
void printItem(ToDoItem *item, int longestName, int longestDue, int longestDescription, int depth, int count);
void printSubItems(ToDoItem *item, int longestName, int longestDue, int longestDescription, int depth);
void printCharNTimes(char character, int count);


#endif
