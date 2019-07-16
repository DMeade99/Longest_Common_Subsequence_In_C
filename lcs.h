/*
 *  File: lcs.h
 *  Programmer: Daryl Meade
 *  Course: Data Structures and Algorithms II
 *  Project: Project 5
 *
 *  Purpose of file: This file contains all of the function declarations for the functions necessary
 *  to solve Part 1 of the project
 */

#ifndef LCS_H
#define LCS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "list.h"
#include "node.h"

// Function to provide a central location for the logic of finding and displaying the longest common subsequence
void displayLongest();

// Function to open a file, read its contents to specified variables and then close the file
void processFile();

// Function that compares two strings and creates an array to store the results
int** createCArray();

// Function to navigate through 'b' array and print the longest common subsequence
void computeLCS();

// Function to print the necessary informtion for the user
void printResults();

// Function to determine which of two values is greater
int max(int a, int b);

// Function to determine which of two values is lesser
int min(int a, int b);

#endif