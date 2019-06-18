#ifndef MSGBOX_H
#define MSGBOX_H

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <wchar.h>

#define m1 "temp/1.txt"
#define m2 "temp/2.txt"
#define m3 "temp/3.txt"
#define m4 "temp/4.txt"
#define m5 "temp/5.txt"

#include "object.h"
#include "fileWR.h"

#include "dictionnaire.h"

#include "verify.h"
#include "findWordToReplace.h"

list find(int word)
{
	String textTofile = NULL;
	switch(word)
	{
		case(1):
			textTofile= readFile(m1);
			break;
		case(2):
			textTofile= readFile(m2);
			break;
		case(3):
			textTofile= readFile(m3);
			break;
		case(4):
			textTofile= readFile(m4);
			break;
		case(5):
			textTofile= readFile(m5);
			break;

	}
	//lecture des donnees

	// decoupage du texte en phrases [ph1, ph2]
	list tabFollowing = NULL;
	tabFollowing = split(textTofile, L'\n');
	return tabFollowing;
}

void msgExit()
{
	puts("Fermeture du programme");
}

void homePage()
{
	//affiche un menu
	 puts("User Mode  \n1. KeyBoard\n2. file .txt\n3. Exit");

}

int calculateError(list bigData)
{
	// bigData = [[int, int], [int, int]]
	listInt listError=NULL;
	int error=0;
	for(int indexList=0, ln = len(bigData); indexList<ln; indexList++)
	{
		// acquisition de l'element
		listError = getElementListInt(bigData, indexList);
		error += lenInt(listError);
	}
	return error;
}
list displayErrorFound(list bigData, list bigDataWord)
{
	// affiche et trouve les mots de remplacement
	// renvoit [[element0:liste des mots propose'], [element1]]
	list allWordToReplace=NULL;

	// liste tempon des propositions
	list wordToReplace=NULL;

	// bigData = [[int, int], [int, int]]
	listInt listError=NULL; // [int, int]
	// liste temporaire des mots down
	list listWordError;
	int countError;
	// calcul des fautes
	countError = calculateError(bigData);
	// erreur par ligne
	String wordError=NULL;
	//affichage
	int indexInbigData;
	wprintf(L"il y a %d Erreur dans votre fichier\n", countError);

	// numero de l'erreur
	int numError=1;

	for(int indexList=0, ln = len(bigData); indexList<ln; indexList++)
	{
		// liste des erreur [int, int]
		listError = getElementListInt(bigData, indexList);
		//erreur
		countError = lenInt(listError);
		if(countError)// s'il ya erreur
		{
			for (int index = 0; index < countError; index++)
			{
				wordToReplace = NULL;
				/* code */
				// aquisition de l'indice du big data
				indexInbigData = getElementInt(listError, index);

				// acquisition de la liste concernee
				listWordError = getElement(bigDataWord, indexList);

				// qcquisition de l'element concernee
				wordError = getElementStr(listWordError, indexInbigData);
				wprintf(L"(%d)", numError); // affichage du numero
				simplePrint(wordError); // affichage du mot


				wprintf(L" : %d ligne, %deme mot\n", indexList+1, indexInbigData+1);
				numError++;

				/* detection des mots a proposer*/
				wordToReplace = findCorrectWords(wordError);
				wordToReplace = find(numError);

				allWordToReplace = append(wordToReplace, allWordToReplace);
			}
		}
	}
	return allWordToReplace;
}
#endif