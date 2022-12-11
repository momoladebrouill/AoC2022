#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOM "test"
#define NBLINES 5
#define BUF_SIZE 7

int main(){
  int len = 0;
  FILE *fp = fopen(NOM,"r");
  char *tabl=calloc(sizeof(char),NBLINES*BUF_SIZE);
  while (1) {
    char ligne[BUF_SIZE];
    if (fgets(ligne, BUF_SIZE, fp) == NULL) break; // no more line
    for(int i = 0; i <BUF_SIZE; i++){ if (ligne[i] == '\n')ligne[i] = 0;} 
    printf("%s\n",ligne);
    strcpy(tabl+len*BUF_SIZE,ligne);
    len++;
  }
  printf("%d\n",len);
  for(int i=0;i<NBLINES;i++){
    printf("%s\n",tabl+i*BUF_SIZE);
  }

}
