#ifndef FILEGETMANAG_H
#define FILEGETMANAG_H

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <wchar.h>

#include "object.h"
#include "others.h"

#define fileName "myFile.txt"

void fileManag()
{
	/*traitement du fichier*/
	// recuperation du nom du fichier
	wchar_t *filename;
	//char filename[20];
	//fileName = "a.txt";
	puts("Ctrl + c : quit\n");
	int isDone; // variable de verification
	
	while(1)
	{
		filename = input(L"Enter the file name : ");
		//filename = (char)fileName;
		//
		//printf("filename : %s\n", filename);
		isDone = traiter(fileName);
		if(isDone)
		{
			break;
		}
		else puts("Error : la taille de votre fichier ne doit pas depasser 10Ko\n");
	}
	
	//lecture des donnees
	String textTofile = NULL;
	textTofile= readFile(fileName);

	// decoupage du texte en phrases [ph1, ph2]
	list tabFollowing = NULL;
	tabFollowing = split(textTofile, L'\n');

	//decoupage des phrase en mots [[w1, w2], [w1, w2]]
	list followingWords;
	followingWords = splitText(tabFollowing);

	// verification [[idWord1, idWord2], [], [idWord]]
	list indexError=NULL;
	indexError = verifyBigData(followingWords);

	// detection des mots

	// affichage des erreurs ET RECUPERATION DES POSSIBILITES
	// [[w1, w2]]
	list wordToReplace=NULL;
	wordToReplace = displayErrorFound(indexError, followingWords);

	int ln;
	ln = len(wordToReplace);
	list tmp=NULL;
	for(int index=0; index < ln; index++)
	{
		tmp = getElement(wordToReplace, index);
		print(tmp, 1);
	}

	/* correction des erreurs*/
		//1. trouver les mots de remplacement
	// [[w1, w2, w5], [w1, w2, w5]]
	list goodWords=NULL;
	//goodWords = findCorrectBigData(indexError, followingWords);




}

#endif