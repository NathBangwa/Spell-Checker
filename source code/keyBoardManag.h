#ifndef KEYBOARDMANAG_H
#define KEYBOARDMANAG_H

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <wchar.h>

#include "object.h"

void textManag()
{
	puts("textManag");
	/* traitement du text saisi*/
	wchar_t *text;

	text = input(L"Enter your text : \n");
	wprintf(L"text : %ls", text);
}
#endif