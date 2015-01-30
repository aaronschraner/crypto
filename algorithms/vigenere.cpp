/*================================================
Program name: Vigenere
Author: Aaron Schraner
Date: 01/19/2015
Description: The French (en/de)cryption algorithms
==================================================*/

#include "../algorithms.h"
#include <cstring>

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

//encrypt using vigenere algorithm
void  vigenereEncrypt( const char  plaintext[], char ciphertext[], const char  key[] )
{
	unsigned int len=strlen(key); 
	//store the length of the key (so we don't need to keep checking)

	//iterate through maximum message size
	for(unsigned int i=0;i<strlen(plaintext);i++)
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
	unsigned int len=strlen(key);
	//store the length of the key

	//iterate through the maximum message size
	for(unsigned int i=0;i<strlen(ciphertext);i++)
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
