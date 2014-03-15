
/*
* @file			task3_7.cpp
* @brief		Program delete words with defined numbers. For now it's delete 2 and 5 words

* Copyright 2014 by Yuliia Lyubchik Inc.,
*
* This software is the confidential and proprietary information
* of Yuliia Lyubchik. ("Confidential Information").  You
* shall not disclose such Confidential Information and shall use
* it only with permission from Yuliia.
*
*/


#include "stdafx.h"
#include "task3_7.h"	 /*defines prototypes of used in this file functions*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const unsigned char ERROR = 0;
const unsigned char SUCCESS = 1;
const unsigned int MAIN_SUCCESS = 0;

/*number of words needed to be deleted in string*/
const unsigned int NUM1 = 2;
const unsigned int NUM2 = 5;


int main( )
{
	Interface();

	char* riadok = NULL;
	unsigned char retCode;
	char* censorship = NULL;	/*string after deleting words*/
	unsigned int count = 0;		/*the quantity of deleted words*/

	retCode = Input(&riadok);
	if (retCode == ERROR)
	{
		printf("Error occurs while trying to input string.\n");
		return (int)ERROR;
	}
	
	if (riadok != NULL && strlen(riadok) != 0)
	{
		censorship = (char*)malloc(strlen(riadok) * sizeof(char));
		strcpy(censorship, riadok);
	}


	retCode = Delete_bad_word(censorship, NUM1);
	if (retCode == ERROR)
	{
		printf("Can not delete word number %u.\n", NUM1);
		printf("String after censoring: %s\n", censorship);
	}
	else
	{
		printf("String after censoring word number %u: %s\n", NUM1, censorship);
	}
	++count; 

	retCode = Delete_bad_word(censorship, NUM2 - count);
	if (retCode == ERROR)
	{
		printf("Can not delete word number %u.\n", NUM2);
		printf("String after censoring: %s\n", censorship);
	}
	else
	{
		printf("String after censoring words number %u and %u: %s\n", NUM1, NUM2,censorship);
	}

	free(riadok);
	system("pause");
	return MAIN_SUCCESS;

}

void Interface(void)
{
	printf("------------------------------------------------------------------\n");
	printf("Hi! Welcome to the brilliant word censor.\n");
	printf("Enter sentences and program will delete for you 2 and 5 word. \n");
	printf("Program made by Yuliia Lyubchik.\n");
	printf("------------------------------------------------------------------\n\n");
}

unsigned char Input(char** riadok)
{
	do
	{
		char temp;
		int count = 0;
		printf("Please enter sentence: ");
		do
		{
			scanf("%c", &temp);
			++count;
			*riadok = (char*)realloc(*riadok, count * sizeof(char));
			if (*riadok != NULL) 
			{
				*(*riadok + count - 1) = temp;
			}
			else 
			{
				free(riadok);
				puts("Error (re)allocating memory. \n");
				return ERROR;
			}

		} 
		while (temp != '\n' && temp != EOF);
		fflush(stdin);
		*(*riadok + count - 1) = '\0';
	} 
	while (riadok == NULL || strlen(*riadok) == 0);

	return SUCCESS;
}

unsigned char Delete_bad_word(char* censorship, unsigned int number)
{
	if (censorship == NULL)
	{
		printf("Can not get access to memory. \n");
		return ERROR;
	}
	char* temp; 
	temp = (char*)malloc(strlen(censorship) * sizeof(char));
	temp[0] = '\0';

	char* begin = NULL;
	char* end = NULL;
	char* token;
	unsigned int count = 1;

	const char delimiters[] = { ' ', ',', '-', '.', ':', ';', '(', ')', '[', ']', '!', '?' };

	token  = strpbrk(censorship, delimiters);
	++count;

	while (token != NULL)
	{
		if (count == number)
		{
			begin = token;
		}
		else if (count == (number + 1))
		{
			end = token;
		}
		token = strpbrk(token + 1, delimiters);
		++count;
	}

	if (count < number)
	{
		printf("Sorry but there is no word with such number.\n");
		return ERROR;
	}

	if (begin == NULL)
	{
		printf("Sorry but there is no word with such number.\n");
		return ERROR;
	}
	unsigned int n = begin - censorship;
	
	strncpy(temp, censorship, begin - censorship);
	temp[n] = '\0';
	 
	if (end == NULL)
	{
		end = censorship + strlen(censorship);
	}
	n = end - censorship;
	strcat(temp, censorship + n);
	strcpy(censorship, temp);
	
	return SUCCESS;
}

