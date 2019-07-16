/*
 *  File: compare.h
 *  Programmer: Daryl Meade
 *  Course: Data Structures and Algorithms II
 *  Project: Project 5
 *
 *  Purpose of file: This file contains the function declarations for all functions
 *  used to solve Part 2 of the project
 */

#ifndef COMPARE_H
#define COMPARE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Function to compute the lengths of all strings within the file and save them to an array
void computeLengths();

// Handler function to serve as a central location for calling all necessary functions to display a solution
void displaySimilar();

// Function to sequentially read strings from a file and check them against each other
void directAccess();

// Function to build 'b' array and compare the two passed strings, returning a measure of similarity
char compareStrings(char* string1, char* string2, int m, int n);

// Function to create an empty array to display measures of similarity
char** createSimilarArray();

// Function to print the array showing calculated measures of similiarity
void printSimilarArray();


#endif