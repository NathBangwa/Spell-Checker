#ifndef LISTOBJECT_H
#define LISTOBJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <stddef.h>
#include "simpleStr.h"
#include "listObjectExtend.h"

// liste chainee
struct object
{
	void *data;
	struct object *next;
};

typedef struct object *list;


int len(list L)
{
	// return la taille d'une list
	list tmp=L;
	int len=0;
	while(tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return len;
}

String getElementStr(list L, int index)
{
	list temp=L;
	if (index < len(L) )
	{
		for(int ind=0, ln=len(L); ind < ln; ind++)
		{
			if(ind == index)
			{
				return temp->data;
			}
			temp = temp->next;
		}
	}
	printf("l'indeice %d n'existe pas\n", index);
	return NULL;
}

list getElement(list L, int index)
{
	// lecture d'un element de la liste L a l'indice index 
	list temp=L;
	if (index < len(L) )
	{
		for(int ind=0, ln=len(L); ind < ln; ind++)
		{
			if(ind == index)
			{
				return temp->data;
			}
			temp = temp->next;
		}
	}
	printf("l'indeice %d n'existe pas\n", index);
	return NULL;
}
listInt getElementListInt(list L, int index)
{
	// lecture d'un element de la liste L a l'indice index 
	list temp=L;
	if (index < len(L) )
	{
		for(int ind=0, ln=len(L); ind < ln; ind++)
		{
			if(ind == index)
			{
				return temp->data;
			}
			temp = temp->next;
		}
	}
	printf("l'indeice %d n'existe pas\n", index);
	return NULL;
}


list append(void *element, list Q)
{
	// ajoute element a la fin de la liste Q
	list L, tmp=Q;

	// reservation de la memoire pour le new element
	L = (list)malloc(sizeof(struct object));
	L->data = element;
	L->next = NULL;

	// la liste de depart est vide [initialisation]
	if (Q == NULL) return L;

	//on cherche la fin de la pile
	while(tmp->next != NULL) tmp=tmp->next;

	tmp->next = L;
	return Q;
}

list appendStr(String element, list Q)
{
	// ajoute element a la fin de la liste Q
	list L, tmp=Q;

	// reservation de la memoire pour le new element
	L = (list)malloc(sizeof(struct object));
	L->data = element;
	L->next = NULL;

	// la liste de depart est vide [initialisation]
	if (Q == NULL) return L;

	//on cherche la fin de la pile
	while(tmp->next != NULL) tmp=tmp->next;

	tmp->next = L;
	return Q;
}

list insert(list L, int index, void *newElement)
{
	//insert un newElement a l'indice index
	list tmp=NULL;
	printf("index = %d\n", index);
	if (index < len(L))
	{
		for(int ind=0, ln=len(L); ind < ln; ind++)
		{
			if(ind==index)
			{
				tmp=append(newElement, tmp);
			}
			
			tmp=append(L->data, tmp);
			L = L->next;
		}
		return tmp;
	}
	printf("l'indeice %d n'existe pas\n", index);
	return L;	
}

list updateElement(list L, int index, void *newElement)
{
	// modifie un element dans la liste
	// L : liste d'origine
	// index: indice de l'element a modifier
	// newElement : pointeur vers le new element

	list tmp=NULL;
	printf("index = %d\n", index);
	if (index < len(L))
	{
		for(int ind=0, ln=len(L); ind < ln; ind++)
		{
			if(ind==index)
			{
				tmp=append(newElement, tmp);
			}
			else
			{
				tmp=append(L->data, tmp);
			}
			L = L->next;
		}
		return tmp;
	}
	printf("l'indeice %d n'existe pas\n", index);
	return L;
}

list delElement(list L, int index)
{
	list tmp=NULL;
	if (index < len(L))
	{
		for(int ind=0, ln=len(L); ind < ln; ind++)
		{
			if(ind != index)
			{
				tmp=append(L->data, tmp);
			}
			L = L->next;
		}
		return tmp;
	}
	printf("l'indeice %d n'existe pas\n", index);
	return L;
}

list delFirst(list L)
{
	//supprime le premier element
	list suivant = L;
	if(L != NULL)
	{
		suivant = L->next;
		free(L);
	}
	return suivant;
}

list reset(list L)
{
	// supprime tous les elements
	list tmp = L;
	if(L)
	{
		free(L);
		while(tmp)
		{
			tmp=tmp->next;
		}
	}
	return tmp;

}
void printSimpleList(list L)
{
	// affiche la liste simple
	wprintf(L"%lc", '[');
	list tmp = L;
	while(tmp != NULL)
	{
		if(sizeof(tmp->data) == sizeof(String))
		{
			simplePrint(tmp->data);
		}
		else if(sizeof(tmp->data) == sizeof(wchar_t))
		{
			wprintf(L"%ls", tmp->data);
		}
		tmp = tmp->next;
		if (tmp)
		{
			wprintf(L"%lc ", ',');
		}
	}
	free(tmp); // libere l'espace tempon
	wprintf(L"%lc", ']');
}

void printList(list L)
{
	// affiche la liste a n dimension
	list temp = L;
	wprintf(L"%lc", '[');
	for(int index=0, ln=len(L); index < ln; index++){
		printSimpleList(temp->data);
		if (index+1 < ln) wprintf(L"%lc ", ',');
		temp = temp->next;
	}
	wprintf(L"%lc", ']');
}
void print(list L, short simple)
{
	// affiche la liste en specifiant la nature de la liste
	if(simple) printSimpleList(L);
	else printList(L);
	puts("\n");
}
#endif