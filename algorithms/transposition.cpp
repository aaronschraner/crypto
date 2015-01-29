/*===================================================
Program name: Transposition
Author: Aaron Schraner
Date: 01/19/2015
Description: Transposition (en/de)cryption algorithms
=====================================================*/

//TODO: you don't need to padd it with z's
#include "../algorithms.h"
#ifdef DEBUG
#include <iostream>
#endif
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



//doesn't work in some cases for some reason

void  transpositionEncrypt( const char  plaintext[], char ciphertext[], unsigned key )
{
	//fdsaf
	const unsigned int ptLen = textLength(plaintext);
	
	const unsigned int xMax  = key;
	const unsigned int yMax  = (ptLen+key-1) / key ;//+ (ptLen%key > 0 ? 1 : 2);

#ifdef DEBUG
	std::cout << "DEBUG: \nxMax = " << xMax << "\nyMax = " << yMax << "\nptLen = " << ptLen << "\n";
#endif
	for(unsigned y=0;y<yMax;y++)
	{
		for(unsigned x=0;x<xMax;x++)
		{
#ifdef DEBUG
			std::cout << x + xMax*y << " -> " << y+yMax * x << " ( x = " << x << ", y = " << y << " )\n";
#endif
			ciphertext[ y + yMax * x ] = ( x + xMax * y < ptLen ? plaintext[ x + xMax * y ] : '_' );
		}
	}

}

void  transpositionDecrypt( const char  ciphertext[], char plaintext[], unsigned key )
{
	//fdsaf
	const unsigned int ptLen = textLength(ciphertext);
	
	const unsigned int xMax  = key;
	const unsigned int yMax  = ptLen / key ;//+ (ptLen%key > 0 ? 1 : 2);

#ifdef DEBUG
	std::cout << "DEBUG: \nxMax = " << xMax << "\nyMax = " << yMax << "\nptLen = " << ptLen << "\n";
#endif
	for(unsigned y=0;y<yMax;y++)
	{
		for(unsigned x=0;x<xMax;x++)
		{
#ifdef DEBUG
			std::cout << x + xMax*y << " <- " << y+yMax * x << " ( x = " << x << ", y = " << y << " )\n";
#endif
			plaintext[ x + xMax * y ] = ciphertext[ y + yMax * x ];
		}
	}

}
