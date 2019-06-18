#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <stddef.h>


int main()
{
	wchar_t ch[] = {L'é',L'à',L'è',L'ù',L'ç'};
	int c;
	for (int index=0; index<5; index++)
	{
		c = ch[index];
		wprintf(L"caractere : %lc : %d\n", ch[index], c);

		wprintf(L"%lc\n", c);
	}
}