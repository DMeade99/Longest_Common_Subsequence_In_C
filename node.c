/*
 *  File: node.c
 *  Programmer: Daryl Meade
 *  Course: Data Structures and Algorithms II
 *  Project: Project 5
 *
 *  Purpose of file: This file contains definitions for all of the functions necessary to implement a node data type
 */

#include "node.h"

struct node {
	char value;
	Node next;
};

Node createNode(char value, Node next)
{
	Node newNode = malloc(sizeof *newNode);
	newNode->value = value;
	newNode->next = next;

	return newNode;
}


char getValue(Node currentNode)
{
	return currentNode->value;
}


void setValue(Node currentNode, char newValue)
{
	currentNode->value = newValue;
}


Node getNext(Node currentNode)
{
	return currentNode->next;
}


void setNext(Node currentNode, Node nextNode)
{
	currentNode->next = nextNode;
}


void freeNode(Node currentNode)
{
	free(currentNode);
}