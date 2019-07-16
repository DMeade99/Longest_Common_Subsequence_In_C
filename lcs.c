/*
 *  File: lcs.c
 *  Programmer: Daryl Meade
 *  Course: Data Structures and Algorithms II
 *  Project: Project 5
 *
 *  Purpose of file: This file contains all of the definitions for the functions defined in lcs.h, as well
 *  as the logic necessary to compute and display the necessary information to solve Part 1 of the project
 */

#include "lcs.h"
#define SIZE 1008
#define file "twoStrings.txt"
FILE *fin;
char string1[SIZE], string2[SIZE], lcs[SIZE];
int string1Length = 0, string2Length = 0, lcsLength = 0, m, n;
int** cArray;
Stack newStack;

void displayLongest()
{
	newStack = createStack();
	processFile();
	cArray = createCArray();
	lcsLength = cArray[string1Length][string2Length];
	computeLCS();
	printResults();	
}

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;

}

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

void processFile()
{
	fin = fopen(file, "r");
	fseek(fin, 0, SEEK_SET);
	fscanf(fin, "%s", string1);
	fscanf(fin, "%s", string2);
	string1Length = strlen(string1);
	string2Length = strlen(string2);
	m = string1Length + 1;
	n = string2Length + 1;
	fclose(fin);
}

int** createCArray()
{
	int a, b;

	int** cArray = malloc(m * (sizeof(int*)));
	for (a = 0; a < m; a++)
	{
		cArray[a] = malloc(n * (sizeof(int)));
	}

	for (a = 0; a < m; a++)
	{
		for (b = 0; b < n; b++)
		{
			if ((a == 0) || (b == 0))
			{
				cArray[a][b] = 0;
			}
			else if (string1[a - 1] == string2[b - 1])
			{
				cArray[a][b] = cArray[a - 1][b - 1] + 1;
			}
			else
			{
				cArray[a][b] = max(cArray[a - 1][b], cArray[a][b - 1]);
			}
		}
	}

	return cArray;
}

void computeLCS()
{
	int currentValue = 9999999, a;
	int x = string1Length, y = string2Length;
	
	while (currentValue > 0)
	{
		if (cArray[x][y] > max(cArray[x - 1][y], cArray[x][y - 1]))
		{
			x--;
			y--;
			push(newStack, string2[y]);
		}
		else if (cArray[x][y] == cArray[x - 1][y])
		{
			x--;
		}
		else
		{
			y--;
		}

		if (cArray[x][y] == 0)
		{
			push(newStack, string2[y]);
		}

		currentValue = cArray[x][y];
	}

	for (a = 0; a <= lcsLength; a++)
	{
		lcs[a] = pop(newStack);
	}
}

void printResults()
{
	printf("Part 1 - Longest Common Subsequenc of Two Strings\n");
	printf("String 1: %s\n", string1);
	printf("String 2: %s\n", string2);
	printf("LCS: %s\n\n", lcs);
}