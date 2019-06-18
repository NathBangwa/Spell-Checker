#ifndef WORDFILEPATH_H
#define WORDFILEPATH_H
/*contient des constante : chemin vers les fichier*/

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

#endif