/*
 *  File: client.c
 *  Programmer: Daryl Meade
 *  Course: Data Structures and Algorithms II
 *  Project: Project 5
 *
 *  Purpose of file: This file serves as the cental point to call each of the main
 *  functions within the program
 */

#include <stdio.h>
#include <stdlib.h>
#include "lcs.h"
#include "compare.h"


int main(int argc, char *argv[])
{
	displayLongest();
	displaySimilar();	

	return 0;
}