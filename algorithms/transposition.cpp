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


//
//
// 0 1 2 3 4 5 6 7 8 9
//   x--->
//
// y 0 1 2
// | 3 4 5
// | 6 7 8
// V 9 _ _
//
// 0 3 6 9 1 4 7 _ 2 5 8 _
//
// test case:
// for plaintext length of 10 (0123456789)
// and key=3
//  x->
//
//y 0 1 2
//| 3 4 5
//V 6 7 8
//  9 _ _
//
// --> 
// y ->
// x 0 3 6 9
// | 1 4 7 _
// V 2 5 8 _
// 0 1 2 3 4 5 6 7 8 9 A B
// 0 3 6 9 1 4 7 A 2 5 8 B
//
// inpos -> outpos
// 0 -> 0
// 1 -> 4
// 2 -> 8
// 3 -> 1
// 4 -> 5
// 5 -> 9
// 6 -> 2
// 7 -> 6
// 8 -> 
//
// yMax=4
// xMax=3
//
// outpos -> inpos
// 0 -> 0
// 1 -> 3
// 2 -> 6
// 3 -> 9
// 4 -> 1
// 5 -> 4
// 6 -> 7
// 7 -> A
// 8 -> 2
// 9 -> 5
// X => 8
// 1 => B
//
// (o%4)*3 + o/4
void  transpositionEncrypt( const char  plaintext[], char ciphertext[], unsigned key )
{
	//fdsaf
	const unsigned int ptLen = textLength(plaintext);
	const unsigned int xMax  = key;
	const unsigned int yMax  = ptLen / key + ( ptLen%key > 0 ? 1 : 0);

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
	unsigned int ptLen = textLength(plaintext);
	unsigned int xMax  = key;
	unsigned int yMax  = ptLen / key + ( ptLen%key > 0 ? 1 : 0);

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

