/*===================================================
Program name: Transposition
Author: Aaron Schraner
Date: 01/19/2015
Description: Transposition (en/de)cryption algorithms
=====================================================*/

//TODO: you don't need to padd it with z's
#include "../algorithms.h"
//TODO: doesn't currently encrypt or decrypt anything
unsigned int textLength(const char text[])
{
	for(int i=0;i<MAX_MSG_SIZE; i++)
	{
		if(text[i]=='\0')
			return i;
	}
	return 0;
}
void  transpositionEncrypt( const char  plaintext[], char ciphertext[], unsigned key )
{
	//fdsaf
	int ptLen=textLength(plaintext);
	for(int i=0;i<MAX_MSG_SIZE;i++)
	{
		//ciphertext[i]=plaintext[i];
		ciphertext[i]=(i<ptLen?plaintext[(i%key)*key+(i/key)]): //probably doesn't work
	}
}

void  transpositionDecrypt( const char  ciphertext[], char plaintext[], unsigned key )
{
	//fdlkhjsgj
	for(int i=0;i<MAX_MSG_SIZE;i++)
	{
		plaintext[i]=ciphertext[i];
	}
}

