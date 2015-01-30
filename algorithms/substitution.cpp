/*==================================================
Program name: Substitution
Author: Aaron Schraner
Date: 01/19/2015
Description: Substitution (en/de)cryption algorithms
====================================================*/


#include <iostream>
#include <cstring>
#include "../algorithms.h"
void substitutionEncrypt(const char plaintext[], char ciphertext[], const char key[])
{
	//substitution
	//iterate through maximum message size
	for(unsigned int i=0;i<strlen(plaintext);i++)
	{
		if(!CHAR_OUT_OF_RANGE(plaintext[i])) 
		//if the character is within defined range
		{
			ciphertext[i]=key[plaintext[i]-MIN_ASCII_VALUE]; 
			//use the encrypted char
		}
		else
		{
			ciphertext[i]=plaintext[i]; 
			//use the plaintext char
		}
	}
	ciphertext[strlen(plaintext)]='\0';
}

//generate a reverse lookup table for use with the decryption algorithm
void genReverseTable(const char table[], char output[])
{
	for(int i=0;i<=NUM_CHARACTERS;i++)
	{
		output[table[i]-MIN_ASCII_VALUE]=i+MIN_ASCII_VALUE;
	}
}


//using a reverse lookup table is more efficient and clean than parsing the entire string
//to find the lookup values for each character.
void substitutionDecrypt(const char ciphertext[], char plaintext[], const char key[])
{
	char reversekey[NUM_CHARACTERS]; 
	//reverse lookup table 
	//instead of C[x]=P[key[x]]
	//           C[reversekey[x]]=P[x]
	
	genReverseTable(key,reversekey); 
	//populate the reverse lookup table
	
	substitutionEncrypt(ciphertext,plaintext,(const char*)reversekey); 
	//reuse the encryption algorithm with the reverse key to decrypt
}

