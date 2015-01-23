/*============================================
Program name: Caesar
Author: Aaron Schraner
Date: 01/19/2015
Description: Caesar (en/de)cryption algorithms
==============================================*/

#include "../algorithms.h"
void caesarEncrypt(const char plaintext[], char ciphertext[], int key)
{
	key=26-((-key)%26);
	key=key%26;
	//encrypt using caesar
	for(int i=0;i<MAX_MSG_SIZE;i++)
	{
		if (!CHAR_OUT_OF_RANGE(plaintext[i]))
		{
			ciphertext[i]=(plaintext[i]-MIN_ASCII_VALUE + key)%26+MIN_ASCII_VALUE; //add key to value and ensure output is within range
		}
		else
		{
			ciphertext[i]=plaintext[i];
		}
	}
}

void caesarDecrypt(const char ciphertext[], char plaintext[], int key)
{
	// decrypt using caesar
	for(int i=0;i<MAX_MSG_SIZE;i++)
	{
		if (!CHAR_OUT_OF_RANGE(ciphertext[i])) 
		{
			plaintext[i]=(ciphertext[i]-MIN_ASCII_VALUE+26-key%26)%26+MIN_ASCII_VALUE; //subtract key from value and ensure output is within range
		}
		else
		{
			plaintext[i]=ciphertext[i];
		}
	}
}
