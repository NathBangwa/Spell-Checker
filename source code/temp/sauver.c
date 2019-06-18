#include<stdio.h>
#include<stdlib.h>
#include<wchar.h>
#include<fcntl.h>
# include<io.h>

int main(){
 float taille;
 int fd;
 fd = open("dictionnaire/a.txt",O_RDONLY);
 taille = lseek(fd, 0, SEEK_END);
 taille= taille/1024;
 close(fd);

 printf(" LA TAILLE DE VOTRE FICHIER EST  : %f Ko \n",taille);
}
