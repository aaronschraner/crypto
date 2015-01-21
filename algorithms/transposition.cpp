/*===================================================
Program name: Transposition
Author: Aaron Schraner
Date: 01/19/2015
Description: Transposition (en/de)cryption algorithms
=====================================================*/

#include "../algorithms.h"

void  transpositionEncrypt( const char  plaintext[], char ciphertext[], unsigned key )
{
	//fdsaf
	for(int i=0;i<MAX_MSG_SIZE;i++)
	{
		ciphertext[i]=plaintext[i];
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

