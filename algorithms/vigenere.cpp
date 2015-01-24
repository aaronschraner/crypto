/*================================================
Program name: Vigenere
Author: Aaron Schraner
Date: 01/19/2015
Description: The French (en/de)cryption algorithms
==================================================*/

#include "../algorithms.h"

char vigenereTable(char x, char y)
{
	//(x+y)%26
	//ct=(key+pt)%26
	//(ct-key+26)%26=pt
	return (x-MIN_ASCII_VALUE+y-MIN_ASCII_VALUE)%NUM_CHARACTERS+MIN_ASCII_VALUE;
}

int keyLength(const char key[])
{
	for(int i=0;i<MAX_MSG_SIZE; i++)
	{
		if(key[i]=='\0')
			return i;
	}
	return 0;
}

void  vigenereEncrypt( const char  plaintext[], char ciphertext[], const char  key[] )
{
	int len=keyLength(key);

	for(int i=0;i<MAX_MSG_SIZE;i++)
	{
		//ciphertext[i]=plaintext[i];
		if(!CHAR_OUT_OF_RANGE(plaintext[i]))
		{
			ciphertext[i]=vigenereTable(plaintext[i],key[i%len]);
		}
		else
		{
			ciphertext[i]=plaintext[i];
		}
	}
}

void  vigenereDecrypt( const char  ciphertext[], char plaintext[], const char  key[] )
{
	int len=keyLength(key);

	for(int i=0;i<MAX_MSG_SIZE;i++)
	{
		//plaintext[i]=ciphertext[i];
		if(!CHAR_OUT_OF_RANGE(ciphertext[i]))
		{
			plaintext[i]=(ciphertext[i]-key[i%len]+NUM_CHARACTERS)%NUM_CHARACTERS+MIN_ASCII_VALUE;
		}
		else
		{
			plaintext[i]=ciphertext[i];
		}
	}
}
