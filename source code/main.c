#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

// source files
#include "object.h"
#include "msgBox.h" // message
#include "home.h" // accueil
#include "keyBoardManag.h" // traitement du texte saisi
#include "fileGetManag.h" // traitement du fichier




int main(int argc, char const *argv[])
{
	// chargement du dictionnaire
	initDictionnary();
	short choice;
	choice = getChoice();
	printf("%d\n", choice);
	switch(choice)
	{
		case(1):
			textManag();
			break;
		case(2):
			fileManag();
			break;
		default:
			msgExit();
	}

	return 0;
}