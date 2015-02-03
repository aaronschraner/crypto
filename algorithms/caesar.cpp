/*============================================
Program name: Caesar
Author: Aaron Schraner
Date: 01/19/2015
Description: Caesar (en/de)cryption algorithms
==============================================*/

#include <cstring>
#include "../algorithms.h"
void caesarEncrypt(const char plaintext[], char ciphertext[], int key)
{
	key=NUM_CHARACTERS-((-key)%NUM_CHARACTERS); //Ensure key is greater than -26
	key=key%NUM_CHARACTERS; //ensure key is less than 26

	//encrypt using caesar
	//iterate through message size
	for(unsigned int i=0;i<strlen(plaintext);i++)
	{
		if (!CHAR_OUT_OF_RANGE(plaintext[i]))
		{
			ciphertext[i]=(plaintext[i]-MIN_ASCII_VALUE + key)%NUM_CHARACTERS+MIN_ASCII_VALUE; 
			//add key to value and ensure output is within range
		}
		else //if the plaintext character is out of range
		{
			ciphertext[i]=plaintext[i]; //just use that character
		}
	}
	ciphertext[strlen(plaintext)]=0;
}

void caesarDecrypt(const char ciphertext[], char plaintext[], int key)
{

	key=NUM_CHARACTERS-((-key)%NUM_CHARACTERS); 
	key=key%NUM_CHARACTERS;
	//ensure -26 < key < 26
	
	// decrypt using caesar
	// iterate through message size
	for(unsigned int i=0;i<strlen(ciphertext);i++)
	{
		if (!CHAR_OUT_OF_RANGE(ciphertext[i])) 
		{
			plaintext[i]=(ciphertext[i]-MIN_ASCII_VALUE+NUM_CHARACTERS-key%NUM_CHARACTERS)%NUM_CHARACTERS+MIN_ASCII_VALUE; 
			//subtract key from value and ensure output is within range
		}
		else 
		//again if plaintext is out of range use the character without encrypting it
		{
			plaintext[i]=ciphertext[i];
		}
	}
	plaintext[strlen(ciphertext)]=0;
}
