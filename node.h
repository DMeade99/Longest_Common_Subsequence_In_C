/*
 *  File: node.h
 *  Programmer: Daryl Meade
 *  Course: Data Structures and Algorithms II
 *  Project: Project 5
 *
 *  Purpose of file: This file contains declarations for the functions necessary to implement the node data type
 */
#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

typedef struct node *Node;

// Function to create a new node with an character value and pointer of type node
Node createNode(char value, Node next);

// Function to return the value of the node
char getValue(Node currentNode);

// Function to set the character value of a node
void setValue(Node currentNode, char newValue);

// Function that returns a pointer to the next node
Node getNext(Node currentNode);

// Function that sets the pointer of the next node
void setNext(Node currentNode, Node nextNode);

// Function to free a node from memory
void freeNode(Node currentNode);


#endif