/*===================================================
Program name: Transposition
Author: Aaron Schraner
Date: 01/19/2015
Description: Transposition (en/de)cryption algorithms
=====================================================*/

#include "../algorithms.h"
#ifdef DEBUG
#include <iostream>
#endif

//I think it works with everything now

//textLength: Length of a null-terminated string in a char array
unsigned int textLength(const char text[])
{
	for(int i=0;i<MAX_MSG_SIZE; i++) //iterate through the message
	{

		if(text[i]=='\0') 
		//once you encounter the end
			return i; 
			//return the index of it
	}

	return 0; 
	//return 0 if string is missing null terminator
}



//transpositionEncrypt: encrypt a char array of MAX_MSG_SIZE into ciphertext
//using the transposition algorithm
void  transpositionEncrypt( const char  plaintext[], char ciphertext[], unsigned key )
{
	//Constants for algorithm
	const unsigned int ptLen = textLength(plaintext); //string length
	const unsigned int xMax  = key; //columns in transposition table
	const unsigned int yMax  = (ptLen+key-1) / key ; //rows in transposition table

#ifdef DEBUG
	std::cout << "DEBUG: \nxMax = " << xMax << "\nyMax = " << yMax << "\nptLen = " << ptLen << "\n";
	//debugging output (local constant values)
#endif

	//iterate through rows
	for(unsigned y=0;y<yMax;y++)
	{
		//iterate through positions in a row
		for(unsigned x=0;x<xMax;x++)
		{

#ifdef DEBUG
			std::cout << x + xMax*y << " -> " << y+yMax * x << " ( x = " << x << ", y = " << y << " )\n";
			//show which position went to where (debug)
#endif

			ciphertext[ y + yMax * x ] = (
					( x + xMax * y < ptLen) ? //(if we are within the string length)
				   	plaintext[ x + xMax * y ] :  //use the appropriate plaintext character
					'_' ); //otherwise, fill with underscores.
			//transpose input plaintext into output ciphertext
			//(with length error checking)
		}
	}

}


//transpositionEncrypt: decrypt a char array of MAX_MSG_SIZE into plaintext
//using the transposition algorithm
void  transpositionDecrypt( const char  ciphertext[], char plaintext[], unsigned key )
{
	//Constants for algorithm
	const unsigned int ptLen = textLength(ciphertext);
	const unsigned int xMax  = key;
	const unsigned int yMax  = ptLen / key ;//+ (ptLen%key > 0 ? 1 : 2);

#ifdef DEBUG
	std::cout << "DEBUG: \nxMax = " << xMax << "\nyMax = " << yMax << "\nptLen = " << ptLen << "\n";
	//debugging output (local constant values)
#endif

	//iterate through rows
	for(unsigned y=0;y<yMax;y++)
	{
		//iterate through positions in a row
		for(unsigned x=0;x<xMax;x++)
		{

#ifdef DEBUG
			std::cout << x + xMax*y << " <- " << y+yMax * x << " ( x = " << x << ", y = " << y << " )\n";
			//show which position went to where (debug)
#endif

			plaintext[ x + xMax * y ] = ciphertext[ y + yMax * x ];
			//transpose input ciphertext into output plaintext
			//(no error checking)
		}
	}

}
