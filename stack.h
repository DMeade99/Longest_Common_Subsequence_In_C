/*
 *  File: stack.h
 *  Programmer: Daryl Meade
 *  Course: Data Structures and Algorithms II
 *  Project: Project 5
 *
 *  Purpose of file: This file contains the function declarations necessary to implement a stack data type
 */

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

typedef struct stack *Stack;

// Function to create a new stack
Stack createStack();

// Function to add an item to the stack
void push(Stack currentStack, char value);

// Function to remove an item from the stack and return the value of the removed item
char pop(Stack currentStack);

// Function to identify whether a stack is empty
bool isEmpty(Stack currentStack);

// Function to free the stack from memory
void freeStack(Stack currentStack);



#endif