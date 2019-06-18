#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <stddef.h>

#define A "a.txt"
#include "fileWR.h"
//#include "strObject.h"
#include "simpleStr.h"
#include "dictionnaire.h"
#include "listObjectExtend.h"
#include "verify.h"
#include "msgBox.h"

int main(int argc, char const *argv[])
{
	/*
	
	list text = NULL, l1, l2, l3;
	l1 = append(L"m", NULL);
	l2 = append(L"je", NULL);
	l3 = append(L"nde", NULL);
	text = append(l1, text);
	text = append(l2, text);
	text = append(l3, text);
	l1 = append(L"femme", l1);
	l2 = append(L"good", l2);
	puts("donneee");
	print(text, 0);
	printf("len : %d\n", len(text));
	return 0;

	//text = delFirst(text);
	//text = reset(text);
	//append(l, L"to get");
	text = updateElement(text, 2, l2);
	list thirtelement = getElement(text, 2);
	thirtelement = updateElement(thirtelement, 1, L"Sais");
	text = updateElement(text, 2, thirtelement);
	print(text, 0);
	text = delElement(text, 1);
	print(text, 0);
	text = insert(text, 0, l1);
	print(text, 0);
	printf("len : %d\n", len(text));

	void *tex;
	tex = getElement(text, 0);
	//void *tx = join(tex);
	
	//puts("\nread done");
	*/
	
	String chaine=NULL, chaine1=NULL;
	//chaine = sreset(chaine);
	chaine = simpleCat(L'd', chaine);
	chaine = simpleCat(L'a', chaine);
	chaine = simpleCat(L'n', chaine);
	chaine1 = simpleCat(L'c', chaine1);
	chaine1 = simpleCat(L' ', chaine1);
	chaine1 = simpleCat(L'd', chaine1);
	/*
	puts("begin copy");
	simplePrint(chaine);
	simplePrint(chaine1);
	chaine = simpleCopy(chaine, chaine1);
	chaine1 = NULL;
	chaine1 = chaine1 = simpleCat(L's', chaine1);
	simplePrint(chaine);
	chaine = simpleCopy(chaine, chaine1);
	simplePrint(chaine);
	puts("fin test copy");
	*/

	
	puts("\nlecture Textofile");
	
	String textTofile = NULL;
	//lecture des donnees
	textTofile= readFile(A);

	printf("\nlen textTofile: %d\n", simpleLen(textTofile));
	simplePrint(textTofile);
	puts("\n lecture end textTofile\n ");

	puts("\ndecoupage line tabFollowing");
	list tabFollowing = NULL;
	//tabFollowing = append(chaine, tabFollowing);
	//tabFollowing = append(chaine1, tabFollowing);
	//printf("tabFollowing : %d\n", len(tabFollowing));
	tabFollowing = split(textTofile, L'\n');
	printSimpleList(tabFollowing);
	puts("\nend decoupage line tabFollowing\n");

	puts("decoupage fw");
	list fw;
	fw = splitText(tabFollowing);
	printf("len fw : %d\n", len(fw));
	print(fw, 0);
	puts("\nend decoupage fw\n");

	puts("\nverification\n");
	list indexError=NULL;
	indexError = verifyBigData(fw);

	puts("\nend verification\n");

	puts("\naffichage\n");
	displayErrorFound(indexError, fw);
	puts("\nend affichage\n");

	
	puts("\nreplace dans fw\n");
	list fe;
	fe = getElement(fw, 0);
	fe = updateElement(fe, 1, chaine);
	fw = updateElement(fw, 0, fe);
	puts("\nend replace dans fw\n");


	puts("\njointure fw xdim\n");
	list j;
	j = joinList(fw, L' ');
	print(j, 1);
	puts("\nend jointure fw xdim\n");

	puts("\njointure text\n");
	String txt;
	txt = join(j, L'\n');
	simplePrint(txt);
	puts("\nend jointure text\n");
	puts("\ntanstype text\n");
	wchar_t *t;
	/*
	t = StringToWchar(txt);
	wprintf(L"%ls", t);
	puts("\nend tanstype text\n");
	*/
	puts("save text");
	writeString("atemp.txt", txt);
	puts("\nend save test\n");
	/*
	String element=NULL;
	puts("\n");
	printSimpleList(tabFollowing);
	printf("\nlen tabFollowing: %d\n", len(tabFollowing));

	String firstText;
	firstText = join(tabFollowing, '\n');
	simplePrint(firstText);
	printf("len firstText: %d\n", simpleLen(textTofile));

	wchar_t *t;
	t = StringToWchar(firstText);
	wprintf(L"%ls", t);
	/*ttest sauvegarde
	*/
	//initDictionnary();
	//initDictionnary();
	//printf("\n len dicti : %d\n", len(dictionnaire));

	/*
	// listInt
	listInt l=NULL;
	l = appendInt(1, l);
	l = appendInt(2, l);
	printf("taille int : %d\n", lenInt(l));
	printInt(l);
	*/
	wchar_t tab[] = {L'A', L'Z'};
	wprintf(L"\nA : %d, Z : %d", tab[0], tab[1]);
	return 0;

}