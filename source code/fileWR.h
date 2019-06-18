#ifndef FILEWR_H
#define FILEWR_H

#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <stddef.h>

#include "listStr.h"
#include "simpleStr.h"

String readFile(char fileName[])
{
	// renvoi une chaine de caractere
	FILE *flot;
	String textToFile=NULL;
	char cTemp;
	wchar_t caractere;

	flot = fopen(fileName, "r");
	if(flot == NULL)
	{
		puts("error ouverture");
		return NULL;
	}

	caractere = fgetwc(flot);
	
	
	while(cTemp != EOF){
		
		cTemp = (char)caractere;
		
		//wprintf(L"index : %d : %lc\n",index, caractere);
		textToFile = simpleCat(caractere, textToFile);
		caractere=fgetwc(flot);
	}
	if(fclose(flot) != 0) printf("\nerreur de fermeture : %s\n", fileName);
	return textToFile;
}

int writeString(char *fileName, String text)
{
	FILE *flot;
	flot = fopen(fileName, "w");
	fclose(flot);
	flot = fopen(fileName, "a");
	if(flot == NULL)
	{
		puts("error ouverture");
		return 1;
	}

	wchar_t *textToSave, caractere;
	for(int index=0, ln=simpleLen(text); index<ln; index++)
	{
		caractere = simpleGetElement(text, index);
		wprintf(L"%lc", caractere);
		fwprintf(flot, L"%lc", caractere);
	}
	//textToSave = StringToWchar(text);
	//fwprintf(flot, L"%ls", textToSave);
	
	if(fclose(flot) != 0) printf("\nerreur de fermeture : %s\n", fileName);
	return 0;
}




#endif