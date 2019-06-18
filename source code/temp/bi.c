#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <wchar.h>

int triple(int num)
{
	return 3 * num;
}

short input(wchar_t msg[])
{
	short num;
	wprintf(L"%ls", msg);
	//fgetws(number, 1000, stdin);
	scanf("%d", &num);
	return num;
}

wchar_t *raw_input(wchar_t msg[])
{
	wchar_t text[1000];
	wchar_t *pText=text;
	wprintf(L"%ls", msg);
	//wscanf("%ls", text);
	fgetws(text, 1000, stdin);
	return pText;
}
