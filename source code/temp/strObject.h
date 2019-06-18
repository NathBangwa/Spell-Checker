#ifndef STROBJECT_H
#define STROBJECT_H

#include "object.h"

typedef struct object *String;

int slen(String chaine)
{
	// return la taille d'une String
	String tmp=chaine;
	int slen=0;
	while(tmp)
	{
		tmp = tmp->next;
		slen++;
	}
	return slen;
}


wchar_t *sgetElement(String chaine, int index)
{
	// lecture d'un element de la chaine chaine a chaine'indice index 
	String temp=chaine;
	if (index < slen(chaine) )
	{
		for(int ind=0, ln=slen(chaine); ind < ln; ind++)
		{
			if(ind == index)
			{
				return temp->data;
			}
			temp = temp->next;
		}
	}
	printf("chaine'indeice %d n'existe pas\n", index);
	return NULL;
}


String Sconcat(void *element, String Q)
{
	//puts("receive done");
	// ajoute element a la fin de la chaine Q
	String chaine, tmp=Q;

	// reservation de la memoire pour le new element
	chaine = (String)malloc(sizeof(struct object));
	chaine->data = element;
	chaine->next = NULL;
	//puts("malloc done");

	// la chaine de depart est vide [initialisation]
	if (Q == NULL) return chaine;

	//on cherche la fin de la pile
	while(tmp->next != NULL) tmp=tmp->next;

	tmp->next = chaine;
	return Q;
}

String sreset(String chaine)
{
	// supprime tous les elements
	String tmp = chaine;
	if(chaine)
	{
		free(chaine);
		while(tmp)
		{
			tmp=tmp->next;
		}
	}
	return tmp;
}

void sprint(String chaine)
{
	// affiche la chaine simple
	String tmp = chaine;
	wprintf(L"\n%lc", '\"');
	while(tmp != NULL)
	{
		//puts("done");
		wprintf(L"%ls", tmp->data);
		tmp = tmp->next;
	}
	wprintf(L"%lc\n", '\"');
	free(tmp); // libere chaine'espace tempon
}

#endif