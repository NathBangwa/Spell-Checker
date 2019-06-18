// accueil : demande a l'utilisateur de choisir un mode d'usage

#ifndef HOME_H
#define HOME_H
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <wchar.h>

// fichier 
#include "object.h"


short getChoice()
{
	homePage();
	short *get, choice;
	while (1)
	{
		get = input(L"Your choice Here : ");
		choice = get[0];
		switch(choice)
		{
			case('1'):
				return 1;
			case('2'):
				return 2;
			case('3'): // exit
				return 10;
			default:
				puts("Erreur : choice between 1 and 3 !");
		}
	}
	return 0;

}
#endif