#ifndef OTHERS_H
#define OTHERS_H

#include<stdio.h>
#include<stdlib.h>
#include<wchar.h>
#include<fcntl.h>
#include<io.h>



float findSizeFile(char fileName[])
{
	// calcul et return la size d'un fichier en Ko
	float size;
	int flot;
	flot = open(fileName,O_RDONLY);
	size = lseek(flot, 0, SEEK_END);
	size= size/1024;
	close(flot);
	printf("file : %f\n", size);
	return size;
}

int traiter(char fileName[])
{
	printf("fileName :  %s\n", fileName);
	float size;
	size = findSizeFile(fileName);

	// la taille du fichier ne doit depasser 10Ko
	return size<=10 ? 1 : 0;
}


#endif