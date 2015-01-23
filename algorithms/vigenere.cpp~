/*================================================
Program name: Vigenere
Author: Aaron Schraner
Date: 01/19/2015
Description: The French (en/de)cryption algorithms
==================================================*/

#include "../algorithms.h"

char vigenereTable(char x, char y)
{
	return (x-MIN_ASCII_VALUE+y-MIN_ASCII_VALUE)%26+MIN_ASCII_VALUE;
}
//TODO: doesn't do anything yet
void  vigenereEncrypt( const char  plaintext[], char ciphertext[], const char  key[] )
{
	//askdfgalksdhfj
	for(int i=0;i<MAX_MSG_SIZE;i++)
	{
		//ciphertext[i]=plaintext[i];
		ciphertext[i]=vigenereTable('b',i);
	}
}

void  vigenereDecrypt( const char  ciphertext[], char plaintext[], const char  key[] )
{
	//asdflkjhvkjxczljvh lkjh
	for(int i=0;i<MAX_MSG_SIZE;i++)
	{
		plaintext[i]=ciphertext[i];
	}
}
