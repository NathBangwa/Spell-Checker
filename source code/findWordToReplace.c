/*
programation 11 len-1 %
==============
=	????	 = 12lettres, >=50% contigues 
==============
programme
programmation
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <stddef.h>


#include "simpleStr.h"
#include "dictionnaire.h"
#include "listObjectExtend.h"
#include "verify.h"




int thisChoice(String wordError, String goodWord)
{
	int pourcentage=0;
	int lenWordError =  simpleLen(wordError); // pourcentage
	int lengoodWord =  simpleLen(goodWord);

	int pourc50 = (lenWordError-1) / 2;
	//printf("\n pourc50 = %d\n", pourc50);

	wchar_t char1, next1, char2, next2;

	// liste qui va contenir [booleenChoiced, pourcentage]
	listInt choiced=NULL; 

	for(int index=0, indexg=0; index < lenWordError-1; index++)
	{
		char1 = simpleGetElement(wordError, index); //
		next1 = simpleGetElement(wordError, index+1);// element suivant

		if(indexg == lengoodWord-1)
		{
			break;
		}

		for(indexg;indexg < lengoodWord-1; indexg++)
		{
			char2 = simpleGetElement(goodWord, indexg); //
			next2 = simpleGetElement(goodWord, indexg+1);// element suivant

			if((char1 == char2) && (next1==next2))
			{
				//printf(" char1=%c next1=%c, char2=%c next2=%c\n", char1, next1, char2, next2);
				pourcentage++;
				break;
			}
		}
		//printf("\npourcentage %d\n", pourcentage);

	}

	return pourcentage >= pourc50 ? 1 : 0;
}

list findBestWords(list metaData)
{
	// metadata [[idDicti, w1, wn], [idDicti, w1, wn]]

	// liste [5mots] a renvoyer
	list tmp=NULL;

	return tmp;

}

void test()
{
	int age[] = {4,6, 2, 5, 1, 0};
	int ln = 6;
	int tmpa, tmpb;
	for(int index=0; index<ln; index++)
	{
		for(int next=0; next<ln; next++)
		{
			tmpa = age[index];
			tmpb = age[next];
			if(tmpa < tmpb)
			{
				age[index] = tmpb;
				age[next] = tmpa;
			}
		}
	}
	for(int nex=0; nex<ln; nex++)
	{
		printf("%d,", age[nex]);
	}
}

listInt findCorrectWords(String wordError)
{
	// renvoit [[1,2], [1,2]]
	//         dictionnaire [[Awords], [Bwords], [Cwords]....]

	simplePrint(wordError);
	int lenAllDicti; // taille du dictionnaire
	lenAllDicti = len(dictionnaire);
	
	list dictiWords=NULL; // dictionnaire tempon
	int lenWordError = simpleLen(wordError); // la taille du mot error

	// liste a renvoyer [[idFileDicti, idwor, idword], [idFileDicti, idwor, idword]]
	list allWordFind=NULL;

	// liste tampon [idFileDicti, idwor, idword]
	listInt wordFind=NULL;

	printf("\nlen wordError : %d\n", lenWordError);

	wchar_t firstChar; // la premiere lettre
	firstChar = simpleGetElement(wordError, 0);
	int indexFileDicti; // l'indice du fichier dictionnaire

	indexFileDicti = findIndexDicti(firstChar); // indice
	indexFileDicti = 0;
	printf("\nindexFileDicti : %d\n", indexFileDicti);

	// ajout de l'id dicti
	wordFind = appendInt(indexFileDicti, wordFind);
	printf("\n wordFind len : %d\n", lenInt(wordFind));

	

	int lenDicti;
	

	String good; // chargement dicti
	int lenGood;
	int responce; // la reponse d'existance

	// compteur des mots, nombre des tours[fichiers verifies]
	int wordFindCount=0, fileVerify=0; 
	for(indexFileDicti; wordFindCount < 10; indexFileDicti++, fileVerify++)
	{
		//wordFind = NULL;

		// si tous les 25 fichiers on etes verifies
		if(fileVerify == lenAllDicti) break;

		// retour a l'indice 0 : fichier a.txt
		if(indexFileDicti == lenAllDicti) indexFileDicti=0;

		dictiWords = getElement(dictionnaire, indexFileDicti); //[w1, w2, wn]
		lenDicti = len(dictiWords);
		//printf("\nlen lenDicti : %d\n", lenDicti);
		for(int index=0; (index < lenDicti) || (wordFindCount == 10); index++)
		{
			// acquisition de l'element
			good = getElementStr(dictiWords, index);
			lenGood = simpleLen(good);
			if(lenGood > (lenWordError/2))
			{
				responce = thisChoice(wordError, good);
				//printf("responce : %d\n", responce);
				if(responce)
				{
					wordFind = appendInt(index, wordFind);
					wordFindCount++;
					//break;
				}
			}

		}
	}
	return wordFind;
}


list findCorrectBigData(list bigWord, list bigIndexError)
{
	// la liste a renvoyer [[idFilew1, w1, wn], [idFilew2, w1, w2]]
	list findCorrectWords=NULL;


	return findCorrectWords;
}

int main()
{
	//test();
	//return 0;
	puts("chargement dictionnaire");
	initDictionnary();//
	puts("fin chargement");
	String chaine=NULL;

	chaine = simpleCat(L'a', chaine);
	chaine = simpleCat(L'n', chaine);
	chaine = simpleCat(L'd', chaine);
	chaine = simpleCat(L'r', chaine);
	chaine = simpleCat(L'r', chaine);

	listInt wordFindGet;
	
	wordFindGet = findCorrectWords(chaine);
	printInt(wordFindGet);
	int lenL, idWord, idFile;
	idFile = getElementInt(wordFindGet, 0);
	lenL = lenInt(wordFindGet);
	list dictiWords;
	String word;
	dictiWords = getElement(dictionnaire, idFile);

	for(int index=1; index < lenL; index++)
	{
		idWord = getElementInt(wordFindGet, index);
		word = getElementStr(dictiWords, idWord);
		puts("\n");
		simplePrint(word);
		puts("\n");

	}
	return 0;
}
