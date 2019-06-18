#ifndef SIMPLESTR_H
#define SIMPLESTR_H

//chaine de caractere simple
struct simpleStr 
{
	wchar_t data;
	struct simpleStr *next;
};


typedef struct simpleStr *String;

int simpleLen(String chaine)
{
	// return la taille d'une String
	String tmp=chaine;
	int simpleLen=0;
	while(tmp)
	{
		tmp = tmp->next;
		simpleLen++;
	}
	return simpleLen;
}


wchar_t simpleGetElement(String chaine, int index)
{
	// lecture d'un element de la chaine chaine a chaine'indice index 
	String temp=chaine;
	if (index < simpleLen(chaine) )
	{
		for(int ind=0, ln=simpleLen(chaine); ind < ln; ind++)
		{
			if(ind == index)
			{
				return temp->data;
			}
			temp = temp->next;
		}
	}
	printf("chaine'indeice %d n'existe pas\n", index);
	return L' ';
}


String simpleCat(wchar_t element, String Q)
{
	//puts("receive done");
	// ajoute element a la fin de la chaine Q
	String chaine, tmp=Q;

	// reservation de la memoire pour le new element
	chaine = (String)malloc(sizeof(struct simpleStr));
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

String simpleCopy(String chaine, String chaine1)
{
	/*copie les elements de chaine1 dans chaine*/
	wchar_t element;
	for (int index = 0, ln=simpleLen(chaine1); index < ln; index++)
	{
		// recuperation de l'element de chaine1
		element = simpleGetElement(chaine1, index);

		// ajout de l'element a chaine 
		chaine = simpleCat(element, chaine);
	}
	return chaine;
}

int aEqualb(String word1, String word2)
{
	// verifie l'egalite de deux chaine de caractere
	int len1, len2;
	len1 = simpleLen(word1);
	len2 = simpleLen(word2);
	wchar_t c1, c2;
	int ci1, ci2;
	if(len1 == len2)
	{
		for(int index=0; index < len1; index++)
		{
			c1 = simpleGetElement(word1, index);
			c2 = simpleGetElement(word2, index);
			ci1 = c1;
			ci2 = c2;
			if (ci1 != ci2)
			{
				return 0;
			}
		}
		return 1;
	}
	else return 0;
	return 1;
}


String simpleReset(String chaine)
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

void simplePrint(String chaine)
{
	// affiche la chaine simple
	String tmp = chaine;
	wprintf(L"%lc", '\"');
	while(tmp != NULL)
	{
		//puts("done");
		wprintf(L"%lc", tmp->data);
		tmp = tmp->next;
	}
	wprintf(L"%lc", '\"');
	free(tmp); // libere chaine'espace tempon
}

#endif