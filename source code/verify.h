#ifndef VERIFY_H
#define VERIFY_H

#include <wchar.h>
#include "dictionnaire.h"
#include "listObjectExtend.h"
#include "simpleStr.h"

#define AMAJ 65
#define ZMAJ 90
#define AMIN 97

short isMaj(wchar_t caractere)
{
	int c = caractere;
	if (c >= AMAJ && c <= ZMAJ)
	{
		return 1;
	}
	return 0;
}


int findIndexDicti(wchar_t caractere)
{
	// renvoi l'indice du fichier dictionnaire si caractere = A
	// index = 65-65
	int index = caractere;
	//wprintf(L"\nfirstLetter : %lc, findIndexDicti : %d\n",caractere, index-AMIN);
	return index-AMIN;
}

short wordIndictionnary(String word)
{
	wchar_t firstLetter;
	// recuperation dupremier element
	firstLetter = simpleGetElement(word, 0);
	int equal;
	// si cest un majuscule par defaut il existe
	if(isMaj(firstLetter))
	{
		return 1;
	}
	else
	{
		// initialisation du dictionnaire
		initDictionnary();
		// indice du fichier dictionnaire
		int indexDicti = findIndexDicti(firstLetter);
		//printf("\nindexDicti : %d : lendictionnary = %d\n", indexDicti, len(dictionnaire));
		list fileDictionnary=NULL;
		String wordTmp=NULL;

		// recuperation du fichier concernee
		fileDictionnary = getElement(dictionnaire, indexDicti);
		if(fileDictionnary) 
		{
			//printf("\n fileDictionnary get done : len = %d\n", len(fileDictionnary));
		}

		for(int index=0, ln=len(fileDictionnary); index < ln; index++)
		{
			// recuperation du (index)eme mot du fichier concerne
			wordTmp = getElementStr(fileDictionnary, index);
			// verification
			equal = aEqualb(word, wordTmp);
			if(equal)
			{
				return 1; // mot existe
			}
		}

	}
	return 0; // le mot n'existe pas
}

list verifyBigData(list bigData)
{
	// renvoi [[x, y], [], [x,z]] indice des mots incorrect String
	list bigDataNoExist=NULL;
	// [x, y], [], [x,z] String x,y
	listInt DataNoExistTmp=NULL;

	// liste temporaire bigData[x,y] - [] - [x,z] . x,w,z word
	list dataTmp=NULL;

	// LE MOT X-Y-ZZ
	String wordTmp;

	int exist;// booleen d'existance

	for(int indexBig=0, lenBig=len(bigData); indexBig < lenBig; indexBig++)
	{
		// reinitialisation de la liste des indices errones
		DataNoExistTmp = NULL;

		// acquisition de la (indexBig)eme liste[w1,w2,w3]
		dataTmp = getElement(bigData, indexBig);
		for(int indexDataTmp=0, lenDataTmp=len(dataTmp); indexDataTmp<lenDataTmp; indexDataTmp++)
		{
			// recuperation du mot
			wordTmp = getElementStr(dataTmp, indexDataTmp);

			// verification de l'existance
			exist = wordIndictionnary(wordTmp);
			if(exist){}
			else
			{
				// si le mot n'existe pas
				// ajout de l'indice
				DataNoExistTmp = appendInt(indexDataTmp, DataNoExistTmp);

			}

		}
		// ajout de la liste d'indice a la big data
		bigDataNoExist = append(DataNoExistTmp, bigDataNoExist);

	} 
	return bigDataNoExist;
}

list findStringWord(list bigData, list bigDataWord)
{
	list tmp=NULL;
	return tmp;
}

#endif