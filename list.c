/*
 *  File: list.c
 *  Programmer: Daryl Meade
 *  Course: Data Structures and Algorithms II
 *  Project: Project 5
 *
 *  Purpose of file: This file contains the definitions for the functions necessary to implement a list data type
 */

#include "list.h"

struct list {
	Node head;
	Node tail;
	int size;
};

List createList()
{
	List newList = malloc(sizeof *newList);
	newList->head = NULL;
	newList->tail = NULL;
	newList->size = 0;

	return newList;
}

void append(List currentList, char value)
{
	Node newNode = createNode(value, NULL);
	currentList->size += 1;

	if (currentList->tail == NULL)
	{
		currentList->head = newNode;
		currentList->tail = newNode;
		return;
	}

	setNext(currentList->tail, newNode);
	currentList->tail = newNode;
}

void prepend(List currentList, char value)
{
	Node newNode = createNode(value, NULL);

	if (currentList->tail == NULL)
		currentList->tail = newNode;

	setNext(newNode, currentList->head);
	currentList->head = newNode;
	currentList->size += 1;
}

void insert(List currentList, int position, char value)
{
	if (position == 0)
	{
		prepend(currentList, value);
		return;
	}
	if (position == (currentList->size) - 1)
	{
		append(currentList, value);
		return;
	}
	if ((position < 0) || (position >= currentList->size))
		return;

	Node currentNode = currentList->head;
	int currentPosition = 0;

	while (currentPosition != position - 1)
	{
		currentNode = getNext(currentNode);
		currentPosition++;
	}
	Node newNode = createNode(value, NULL);
	setNext(newNode, getNext(currentNode));
	setNext(currentNode, newNode);

	currentList->size += 1;
}

char removeAt(List currentList, int position)
{
	if (!(currentList->size > 0) || (position < 0) || (position > (currentList->size - 1)))
	{
		printf("Cannot do removal at this position.");
		exit(1);
	}

	currentList->size -= 1;
	if (position == 0)
	{
		Node tempNode = currentList->head;
		currentList->head = getNext(currentList->head);
		int removedValue = getValue(tempNode);
		freeNode(tempNode);

		if (position == currentList->size)
			currentList->tail = NULL;

		return removedValue;
	}

	Node currentNode = currentList->head;
	int currentPosition = 0;

	while (currentPosition < (position - 1))
	{
		currentPosition++;
		currentNode = getNext(currentNode);
	}

	Node tempNode = getNext(currentNode);
	setNext(currentNode, getNext(tempNode));
	int removedValue = getValue(tempNode);
	freeNode(tempNode);

	if (position == currentList->size)
		currentList->tail = currentNode;

	return removedValue;
}

int getLength(List currentList)
{
	return currentList->size;
}

void print(List currentList)
{
	Node currentNode = currentList->head;
	while (currentNode != NULL)
	{
		//processing on a linked list
		printf("%c\n", getValue(currentNode));
		currentNode = getNext(currentNode);
	}
}

void freeList(List currentList)
{
	Node currentNode = currentList->head;
	while (currentNode != NULL)
	{
		//processing on a linked list
		Node nextNode = getNext(currentNode);
		free(currentNode);
		currentNode = nextNode;
	}

	free(currentList);
}