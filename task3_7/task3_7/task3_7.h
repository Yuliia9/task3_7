#ifndef TASK3_7_H_
#define TASK3_7_H_

/*
*@file		task3_7.h
*@brief		header file that defines prototypes of functions used in file task3_7.cpp
*/

#include "stdafx.h"


/**
* @brief				This function displays general information about program to users
* @param	void
* @return	void
*/
void Interface(void);


/*
* @brief					Function for inputing string
* @param	[in/out]		char** riadok - a pointer to null pointer to string for sentences
*
*@return	unsigned char	Return ERROR if error occurs while trying to allocate memory for string
							Return SUCCESS if string was inputed
*/
unsigned char Input(char** riadok);


/*
* @brief					Function for deleting defined by number word in string
* @param	[in/out]		char* censorship - a pointer to string for deleting words.
			[in]			unsigned int number - number of word in sentence needed to be deleted
*
*@return	unsigned char	Return ERROR if error occurs while trying to get access to string
							Return SUCCESS if word in string censorship was deleted 
*/
unsigned char Delete_bad_word( char* censorship, unsigned int number);

#endif







