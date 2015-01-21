/*==================================================
Program name: Substitution
Author: Aaron Schraner
Date: 01/19/2015
Description: Substitution (en/de)cryption algorithms
====================================================*/


//TODO: weird bug where only decrypts first 8 chars, rest are key values
#include <iostream>
#include "../algorithms.h"
void substitutionEncrypt(const char plaintext[], char ciphertext[], const char key[])
{
	//substitution
	for(int i=0;i<MAX_MSG_SIZE;i++)
	{
		if(!CHAR_OUT_OF_RANGE(plaintext[i]))
		{
			ciphertext[i]=key[plaintext[i]-MIN_ASCII_VALUE];
		}
		else
		{
			ciphertext[i]=plaintext[i];
		}
	}
}
void genReverseTable(const char table[], char output[])
{
	for(int i=0;i<=NUM_CHARACTERS;i++)
	{
		output[table[i]-MIN_ASCII_VALUE]=i+MIN_ASCII_VALUE;
	}
}


void substitutionDecrypt(const char ciphertext[], char plaintext[], const char key[])
{
	char reversekey[NUM_CHARACTERS];
	genReverseTable(key,reversekey);
	//substitution
	for(int i=0;i<MAX_MSG_SIZE;i++)
	{
		if(!CHAR_OUT_OF_RANGE(ciphertext[i]))
		{
			plaintext[i]=reversekey[ciphertext[i]-MIN_ASCII_VALUE];
		}
		else
		{
			plaintext[i]=ciphertext[i];
		}
	}
}

