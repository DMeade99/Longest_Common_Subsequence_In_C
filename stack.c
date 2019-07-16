/*
 *  File: stack.c
 *  Programmer: Daryl Meade
 *  Course: Data Structures and Algorithms II
 *  Project: Project 5
 *
 *  Purpose of file: The file contains all of the function definitions necessary to implement the stack data type
 */

#include "stack.h"

struct stack
{
	List internalList;
};

Stack createStack()
{
	Stack newStack = malloc(sizeof *newStack);
	newStack->internalList = createList();

	return newStack;
}

void push(Stack currentStack, char value)
{
	prepend(currentStack->internalList, value);
}

char pop(Stack currentStack)
{
	return removeAt(currentStack->internalList, 0);
}

bool isEmpty(Stack currentStack)
{
	return getLength(currentStack->internalList) == 0;
}

void freeStack(Stack currentStack)
{
	freeList(currentStack->internalList);
	free(currentStack);
}