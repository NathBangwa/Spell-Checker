#ifndef LISTOBJECTEXTEND_H
#define LISTOBJECTEXTEND_H


struct objectExtend
{
	int data;
	struct  objectExtend *next;
};

// liste des entiers
typedef struct objectExtend *listInt;

int lenInt(listInt L)
{
	// return la taille d'une listInt
	listInt tmp=L;
	int lenInt=0;
	while(tmp)
	{
		tmp = tmp->next;
		lenInt++;
	}
	return lenInt;
}

int getElementInt(listInt L, int index)
{
	listInt temp=L;
	if (index < lenInt(L) )
	{
		for(int ind=0, ln=lenInt(L); ind < ln; ind++)
		{
			if(ind == index)
			{
				return temp->data;
			}
			temp = temp->next;
		}
	}
	printf("l'indeice %d n'existe pas\n", index);
	return 0;
}



listInt appendInt(int element, listInt Q)
{
	// ajoute element a la fin de la liste Q
	listInt L, tmp=Q;

	// reservation de la memoire pour le new element
	L = (listInt)malloc(sizeof(struct objectExtend));
	L->data = element;
	L->next = NULL;

	// la liste de depart est vide [initialisation]
	if (Q == NULL) return L;

	//on cherche la fin de la pile
	while(tmp->next != NULL) tmp=tmp->next;

	tmp->next = L;
	return Q;
}


listInt insertInt(listInt L, int index, int newElement)
{
	//insertInt un newElement a l'indice index
	listInt tmp=NULL;
	printf("index = %d\n", index);
	if (index < lenInt(L))
	{
		for(int ind=0, ln=lenInt(L); ind < ln; ind++)
		{
			if(ind==index)
			{
				tmp=appendInt(newElement, tmp);
			}
			
			tmp=appendInt(L->data, tmp);
			L = L->next;
		}
		return tmp;
	}
	printf("l'indeice %d n'existe pas\n", index);
	return L;	
}

listInt updateElementInt(listInt L, int index, int newElement)
{
	// modifie un element dans la liste
	// L : liste d'origine
	// index: indice de l'element a modifier
	// newElement : pointeur vers le new element

	listInt tmp=NULL;
	printf("index = %d\n", index);
	if (index < lenInt(L))
	{
		for(int ind=0, ln=lenInt(L); ind < ln; ind++)
		{
			if(ind==index)
			{
				tmp=appendInt(newElement, tmp);
			}
			else
			{
				tmp=appendInt(L->data, tmp);
			}
			L = L->next;
		}
		return tmp;
	}
	printf("l'indeice %d n'existe pas\n", index);
	return L;
}

listInt delElementInt(listInt L, int index)
{
	listInt tmp=NULL;
	if (index < lenInt(L))
	{
		for(int ind=0, ln=lenInt(L); ind < ln; ind++)
		{
			if(ind != index)
			{
				tmp=appendInt(L->data, tmp);
			}
			L = L->next;
		}
		return tmp;
	}
	printf("l'indeice %d n'existe pas\n", index);
	return L;
}

listInt delFirstInt(listInt L)
{
	//supprime le premier element
	listInt suivant = L;
	if(L != NULL)
	{
		suivant = L->next;
		free(L);
	}
	return suivant;
}

listInt restetInt(listInt L)
{
	// supprime tous les elements
	listInt tmp = L;
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

void printInt(listInt L)
{
	// affiche la liste en specifiant la nature de la liste
	// affiche la liste simple
	wprintf(L"%lc", '[');
	listInt tmp = L;
	while(tmp != NULL)
	{
		
		wprintf(L"%d", tmp->data);
		
		tmp = tmp->next;
		if (tmp)
		{
			wprintf(L"%lc ", ',');
		}
	}
	free(tmp); // libere l'espace tempon
	wprintf(L"%lc", ']');
}

#endif