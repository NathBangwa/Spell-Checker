#ifndef OBJECT_H
#define OBJECT_H

//liste multi-types : list
#include "listObject.h"

// liste mono-type integer : listInt
#include "listObjectExtend.h"

// chaine de caracteres : String
#include "simpleStr.h"

// convertion : list->String and String->list
#include "listStr.h"

// Ecriture et lecture
#include "fileWR.h"

#include "dictionnaire.h"


// fonction d'invite de saisie

wchar_t *input(wchar_t msg[])
{
	wchar_t text[1000];
	wchar_t *pText=text;
	wprintf(L"%ls", msg);
	//wscanf("%ls", text);
	fgetws(text, 1000, stdin);
	return pText;
}



#endif