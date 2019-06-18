#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H

//#include "wordFilePath.h"
#include "listObject.h"
#include "fileWR.h"
/*
	contient les liste des elements du disctionnaires
*/
#include "simpleStr.h"
#include "listObjectExtend.h"
#include "fileWR.h"

char fileA[]="dictionnaire/a.txt";
char fileB[]="dictionnaire/b.txt";
char fileC[]="dictionnaire/c.txt";
char fileD[]="dictionnaire/d.txt";
char fileE[]="dictionnaire/e.txt";
char fileF[]="dictionnaire/f.txt";
char fileG[]="dictionnaire/g.txt";
char fileH[]="dictionnaire/h.txt";
char fileI[]="dictionnaire/i.txt";
char fileJ[]="dictionnaire/j.txt";
char fileK[]="dictionnaire/k.txt";
char fileL[]="dictionnaire/l.txt";
char fileM[]="dictionnaire/m.txt";
char fileN[]="dictionnaire/n.txt";
char fileO[]="dictionnaire/o.txt";
char fileP[]="dictionnaire/p.txt";
char fileQ[]="dictionnaire/q.txt";
char fileR[]="dictionnaire/r.txt";
char fileS[]="dictionnaire/s.txt";
char fileT[]="dictionnaire/t.txt";
char fileU[]="dictionnaire/u.txt";
char fileV[]="dictionnaire/v.txt";
char fileW[]="dictionnaire/w.txt";
char fileX[]="dictionnaire/x.txt";
char fileY[]="dictionnaire/y.txt";
char fileZ[]="dictionnaire/z.txt";

list initData(char filename[])
{
	String textTofile = NULL;
	//lecture des donnees
	textTofile= readFile(filename);
	list tabFollowing = NULL;
	//tabFollowing = append(chaine, tabFollowing);
	//tabFollowing = append(chaine1, tabFollowing);
	//printf("tabFollowing : %d\n", len(tabFollowing));
	tabFollowing = split(textTofile, L'\n');
	return tabFollowing;
}

int init = 0;
list dictionnaire=NULL;

void initDictionnary(){
	if(init==0)
	{
		puts("Dictionnary Loading. . .");
		dictionnaire = append(initData(fileA), dictionnaire);
		printf("%s", "A..");
		dictionnaire = append(initData(fileB), dictionnaire);
		printf("%s", "B..");
		dictionnaire = append(initData(fileC), dictionnaire);
		printf("%s", "C..");
		dictionnaire = append(initData(fileD), dictionnaire);
		printf("%s", "D..");
		dictionnaire = append(initData(fileE), dictionnaire);
		printf("%s", "E..");
		dictionnaire = append(initData(fileF), dictionnaire);
		printf("%s", "F..");
		dictionnaire = append(initData(fileG), dictionnaire);
		printf("%s", "G..");
		dictionnaire = append(initData(fileH), dictionnaire);
		printf("%s", "H..");
		dictionnaire = append(initData(fileI), dictionnaire);
		printf("%s", "I..");
		dictionnaire = append(initData(fileJ), dictionnaire);
		printf("%s", "J..");
		dictionnaire = append(initData(fileK), dictionnaire);
		printf("%s", "K..");
		dictionnaire = append(initData(fileL), dictionnaire);
		printf("%s", "L..");
		dictionnaire = append(initData(fileM), dictionnaire);
		printf("%s", "M..");
		dictionnaire = append(initData(fileN), dictionnaire);
		printf("%s", "N..");
		dictionnaire = append(initData(fileO), dictionnaire);
		printf("%s", "O..");
		dictionnaire = append(initData(fileP), dictionnaire);
		printf("%s", "P..");
		dictionnaire = append(initData(fileQ), dictionnaire);
		printf("%s", "Q..");
		dictionnaire = append(initData(fileR), dictionnaire);
		printf("%s", "R..");
		dictionnaire = append(initData(fileS), dictionnaire);
		printf("%s", "S..");
		dictionnaire = append(initData(fileT), dictionnaire);
		printf("%s", "T..");
		dictionnaire = append(initData(fileU), dictionnaire);
		printf("%s", "U..");
		dictionnaire = append(initData(fileV), dictionnaire);
		printf("%s", "V..");
		dictionnaire = append(initData(fileW), dictionnaire);
		printf("%s", "W..");
		dictionnaire = append(initData(fileX), dictionnaire);
		printf("%s", "X..");
		dictionnaire = append(initData(fileY), dictionnaire);
		printf("%s", "Y..");
		dictionnaire = append(initData(fileZ), dictionnaire);
		printf("%s", "Z..");
		puts("\n");
		init = 1;
	}
}
#endif