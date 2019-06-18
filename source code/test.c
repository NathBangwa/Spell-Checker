#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <stddef.h>

//#pragma comment (lib, "li.dll")

//extern int triple(int num);
//wprintf, fgetws
#include "listStr.h"

enum boolean {True=1, False=0};

struct personne
{
	char name[10];
	int age;
	
};


int main(int argc, char const *argv[])
{
	/*
	wchar_t word[5], w[50];
	puts("taper un truc");
	fgetws(w, 50, stdin);
	puts("taper un autre truc");
	fgetws(word, 50, stdin);
	wprintf(L"%ls\n", w);
	wprintf(L"%ls", word);
	
	char * file;
	file = "test.txt";
	long taille;
	printf("taille : %d\n", taille);
	//int num = triple(4);
	//num = input(L"text : ");
	
	FILE *file;

	file = fopen("a.txt", "r");
	wchar_t c;
	while(c != EOF)
	{

		c=fgetwc(file);
		wprintf(L"%lc", c);
	}
	//wprintf(L"c : %ls", c);
	fclose(file);
	puts("done");
	
	int *p;
	p = (int*)malloc(2*sizeof(int));
	*p=4;
	*(p+1)=10;
	printf("p : %d\np+1 : %d", *p, *(p+1));
	free(p);
	puts("liberation");
	printf("p : %d\np+1 : %d", *p, *(p+1));
	
	enum boolean loop = True;
	while(loop)
	{
		puts("hello");
		break;
	}
	struct personne p1 = {"nathah", 19};
	struct personne *p;
	p = &p1;
	printf("name : %s\n", p->name);
	return 0;
	*/
}