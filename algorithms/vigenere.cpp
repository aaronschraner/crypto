/*================================================
Program name: Vigenere
Author: Aaron Schraner
Date: 01/19/2015
Description: The French (en/de)cryption algorithms
==================================================*/

#include "../algorithms.h"

char vigenereTable(char x, char y)
{
	//   a b c d
	//   _______
	//a| a b c d
	//b| b c d e
	//c| c d e f
	//d| d e f g
	// etc...
	return (x-MIN_ASCII_VALUE+y-MIN_ASCII_VALUE)%NUM_CHARACTERS+MIN_ASCII_VALUE;
}

//get the length of the key string
int keyLength(const char key[])
{
	for(int i=0;i<MAX_MSG_SIZE; i++)
	{
		if(key[i]=='\0')
			return i;
	}
	return 0;
}

//encrypt using vigenere algorithm
void  vigenereEncrypt( const char  plaintext[], char ciphertext[], const char  key[] )
{
	int len=keyLength(key); 
	//store the length of the key (so we don't need to keep checking)

	//iterate through maximum message size
	for(int i=0;i<MAX_MSG_SIZE;i++)
	{
		//if the character is in range
		if(!CHAR_OUT_OF_RANGE(plaintext[i]))
		{
			ciphertext[i]=vigenereTable(plaintext[i],key[i%len]); 
			//do the french thing
		}
		else
		{
			//otherwise, don't encrypt that character.
			ciphertext[i]=plaintext[i];
		}
	}
}

void  vigenereDecrypt( const char  ciphertext[], char plaintext[], const char  key[] )
{
	int len=keyLength(key);
	//store the length of the key

	//iterate through the maximum message size
	for(int i=0;i<MAX_MSG_SIZE;i++)
	{
		//if the char is in range
		if(!CHAR_OUT_OF_RANGE(ciphertext[i]))
		{
			// gniht hcnerf eht od
			//(do the french thing in reverse)
			plaintext[i]= ( ciphertext[i] - key[ i % len ] + NUM_CHARACTERS ) % NUM_CHARACTERS + MIN_ASCII_VALUE;
			//ciphertext[n] = plaintext[n] + key[n], 
			//therefore plaintext[n] = ciphertext[n] - key[n]
		}
		else
		{
			//if the char is out of plaintext range, don't decrypt it.
			plaintext[i]=ciphertext[i];
		}
	}
}
