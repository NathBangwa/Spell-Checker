#ifndef LISTSTR_H
#define LISTSTR_H

#include <wchar.h>
#include "listObject.h"
#include "simpleStr.h"

int countElementSplit(String text, wchar_t separator)
{
	/*
		comteur d'element apres split
	*/
	int idWord=0;
	wchar_t element;
	for(int index=0,taille=simpleLen(text); index < taille; index++)
	{
		element = simpleGetElement(text, index);
		if(element == separator || index == (taille-1))
		{
			idWord++;
		}
	}
	return idWord;
}

list split(String text, wchar_t separator)
{
	//on decoupe un text suivant le caractere
	int countElement=countElementSplit(text, separator);

	list words=NULL; // liste a retourner

	// caractere de split non trouvee
	if(countElement == 1)
	{
		words = append(text, words);
		return words;
	}

	// initialisation de la liste d'element
	String listWords[countElement];
	String word=NULL, wordTmp; // chaine de caractere tempon
	wchar_t element; // element de text

	for(int index=0, idWord=0, taille=simpleLen(text); index < taille; index++)
	{
		element = (wchar_t)simpleGetElement(text, index);
		if(element == separator || index==(taille-1))
		{
			if(index==(taille-1) && (element!=separator))
			{
				word = simpleCat(element, word);
			} 
			//String wordTmp;
			wordTmp = NULL;
			wordTmp = simpleCopy(wordTmp, word);
			listWords[idWord] = word;
			//listWords[idWord] = simpleCopy(wordTmp, word);
			//puts("copy done");
			words = append(listWords[idWord], words);
			idWord++;
			word = NULL;

		}
		else
		{
			word = simpleCat(element, word);
		}
	}
	free(word);
	return words;

}


list splitText(list tabFollowing)
{
	// decoupe une liste des phrases en une liste des mots des phrases
	// renvoi [[w, w], []]
	list tabFollowingWords=NULL;
	String tmp=NULL;
	list splitTemp; // liste des mots
	for(int index=0, ln=len(tabFollowing); index < ln; index++)
	{
		tmp = getElementStr(tabFollowing, index);
		//simplePrint(tmp);
		splitTemp = split(tmp, L' ');
		tabFollowingWords = append(splitTemp, tabFollowingWords);
		//puts("\n");
	}
	return tabFollowingWords;
}

String join(list words, wchar_t caractere)
{
	/*
		concatene les element du tableau
		["hello", "word"]
		return "hello(caractere)word"
	*/
	String text=NULL, tmp=NULL;
	if(words)
	{
		if(sizeof(getElementStr(words, 0)) != sizeof(String))
		{
			puts("error : string required");
			return NULL;
		}
		if(len(words) == 1)
		{
			text = getElementStr(words, 0);
			return text;
		}

		for(int index=0, lenList=len(words); index < lenList; index++)
		{
			// recuperation des elements
			tmp = getElementStr(words, index);
			if(index != (lenList-1))
			{
				tmp = simpleCat(caractere, tmp);
			}
			// copie
			text = simpleCopy(text, tmp);

		}
	}
	return text;
}

list joinList(list listXDimension, wchar_t caractere)
{
	// listXDimension = [[w,w], [z,z]]
	//return [wcarw, zcarz]
	list listWords=NULL; // wcarw, zcarz
	list tmp=NULL;
	String wordTmp;
	for(int indeXDim=0, lenXDim=len(listXDimension); indeXDim < lenXDim; indeXDim++)
	{
		// recuperation de la liste
		tmp = getElement(listXDimension, indeXDim);
		// jointure
		wordTmp = join(tmp, caractere);
		// ajout a la liste
		listWords = append(wordTmp, listWords);
	}
	return listWords;
}

wchar_t *StringToWchar(String text)
{
	// change le type String en wchar_t
	int taille = simpleLen(text);
	wchar_t textW[taille+5];
	wchar_t *pTextW = textW;
	for(int index=0; index < taille; index++)
	{
		textW[index] = simpleGetElement(text, index);
	}
	return pTextW;
}

#endif