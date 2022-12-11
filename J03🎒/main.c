#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NBLINES 300
#define BUF_SIZE 100

int indice(char c){
  return ('a'<=c && c<='z') ? c-'a': c-'A' + 26;
}

int main(){
  char lignes[NBLINES][BUF_SIZE];
  int i = 0;
  FILE *fp = fopen("test","r");
  while (i < NBLINES) {
    char buf[BUF_SIZE];
    if (fgets(buf, BUF_SIZE, fp) == NULL) break; // no more line
    strcpy(lignes[i], buf);
    printf("<%s>",lignes[i]);
    i++;
  }
  
  int score = 0;
  for(int i=0;i<NBLINES;i++){
    int j = 0; // chacun des char
    int *l=calloc(26*2,sizeof(int));
    char current;

    int len = 0;
    while(lignes[i][len++]);
    
    while((current = lignes[i][j])){
      int ind = indice(current);
      printf("%i %c\n",ind,current);
      if(j < len/2){
        l[ind] = 1;
      }else if(l[ind]){
        score += ind + 1;
      }
      j++;
    }
    free(l);
  }
  printf("%d\n", score);
}
