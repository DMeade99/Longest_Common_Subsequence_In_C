/*
 *  File: compare.c
 *  Programmer: Daryl Meade
 *  Course: Data Structures and Algorithms II
 *  Project: Project 5
 *
 *  Purpose of file: This file contains all of the definitions for the functions declared in compare.h, as
 *  well as the logic necessary to solve Part 2 of the project
 */

#include "compare.h"

#define file "multiStrings.txt"

FILE* fp;
int positions[20];
int totStrings = 0;
char** similarArray;

void computeLengths()
{
	char line[100];
	fp = fopen(file, "r");
	positions[0] = 0;
	fseek(fp, 0, SEEK_SET);
	fgets(line, 100, fp);
	totStrings = atoi(line);

	int a;
	for (a = 0; a < totStrings; a++)
	{
		fgets(line, 100, fp);
		line[(strlen(line) - 1)] = '\0';
		positions[a] = (strlen(line) - 1);
	}

	fclose(fp);
}

void directAccess()
{
	similarArray = createSimilarArray();
	
	
	int a, b, c, m, n;
	char line[100], str1[100], str2[100], result;	
	
	fp = fopen(file, "r");
	fscanf(fp, "%s", line); //skip first line
	
	for (a = 1; a < totStrings; a++)
	{
		fscanf(fp, "%s", line);
		strcpy(str1, line);
		m = strlen(line);
		
		for (b = a+1; b <= totStrings; b++)
		{
			fscanf(fp, "%s", line);
			strcpy(str2, line);
			n = strlen(line);
			similarArray[a][b] = compareStrings(str1, str2, m, n);
			
		}
		
		fseek(fp, 0, SEEK_SET);
		fscanf(fp, "%s", line); //Skip first line in file

		for (c = 0; c < a; c++)
		{
			fscanf(fp, "%s", line); //Skip to current line
		}

	}

}

char compareStrings(char* string1, char* string2, int m, int n)
{
	// H - High - short within 10% of longer string / LCS at least 90% of short string
	// M - Medium - short within 20%, but >10% / LCS at least 80% of short string
	// L - Low - short within 40%, but >20% / LCS at least 50% of short string
	// D - Dissimilar - none of the above
	
	char result;
	
	int a, b, lcs, shorter, longer;
	double lengthOfString, lengthOfLCS;

	int** lcsArray = malloc((m + 1) * sizeof(int*));
	for (a = 0; a < (m + 1); a++)
	{
		lcsArray[a] = malloc((n + 1) * sizeof(int));
	}

	for (a = 1; a <= m; a++)
	{
		lcsArray[a][0] = 0;
	}

	for (b = 0; b <= n; b++)
	{
		lcsArray[0][b] = 0;
	}

	for (a = 1; a <= m; a++)
	{
		for (b = 1; b <= n; b++)
		{
			if (string1[a-1] == string2[b-1])
			{
				lcsArray[a][b] = lcsArray[a - 1][b - 1] + 1;
			}
			else
			{
				if (lcsArray[a - 1][b] >= lcsArray[a][b - 1])
				{
					lcsArray[a][b] = lcsArray[a - 1][b];
				}
				else
				{
					lcsArray[a][b] = lcsArray[a][b - 1];
				}
			}
		}
	}

	lcs = lcsArray[m][n];
	
	
	if (m > n)
	{
		longer = m;
		shorter = n;
	}
	else
	{
		longer = n;
		shorter = m;
	}

	lengthOfString = (double)(shorter) / (double)(longer);
	lengthOfLCS = (double)(lcs) / (double)(shorter);
	
	if (lengthOfString > .90 && lengthOfLCS >= .90)
	{
		result = 'H';
	}
	else if (lengthOfString > .80 && lengthOfLCS >= .80)
	{
		result = 'M';
	}
	else if (lengthOfString > .60 && lengthOfLCS >= .50)
	{
		result = 'L';
	}
	else
		result = 'D';

		
	return result;
	
}

void displaySimilar()
{
	printf("Part 2 - Longest Common Subsequence 2xM Approach\n");
	computeLengths();
	directAccess();
	printSimilarArray();
}

char** createSimilarArray()
{
	int a, b, count = 1;

	char** array = malloc((totStrings + 1) * (sizeof(char*)));
	for (a = 0; a < (totStrings + 1); a++)
	{
		array[a] = malloc((totStrings + 1) * (sizeof(char)));
	}

	for (a = 1; a <= totStrings; a++)
	{
		for (b = 1; b <= totStrings; b++)
		{
			array[a][b] = '-';
		}
	}

	array[0][0] = ' ';

	for (a = 1; a <= totStrings; a++)
	{
		array[0][a] = a + '0';
		array[a][0] = a + '0';
	}

	return array;
}

void printSimilarArray()
{
	int a, b;

	for (a = 0; a < (totStrings + 1); a++)
	{
		for (b = 0; b < (totStrings + 1); b++)
		{
			printf("%c   ", similarArray[a][b]);
		}
		printf("\n");
	}
}