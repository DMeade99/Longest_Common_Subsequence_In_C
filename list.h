/*
 *  File: list.h
 *  Programmer: Daryl Meade
 *  Course: Data Structures and Algorithms II
 *  Project: Project 5
 *
 *  Purpose of file:  This file contains definitions for functions necessary to implement a list data type
 */

#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "node.h"

typedef struct list *List;

// Function to create a new list
List createList();

// Function to add an item to the end of the list
void append(List currentList, char value);

// Function to add an item to the beginning of the list
void prepend(List currentList, char value);

// Function to insert an item into a specific position within a list
void insert(List currentList, int position, char value);

// Function that removes an item from the list and returns the value that was removed
char removeAt(List currentList, int position);

// Function to return the length of the current list
int getLength(List currentList);

// Function to print the contents of a list
void print(List currentList);

// Function to free the list from memory
void freeList(List currentList);



#endif