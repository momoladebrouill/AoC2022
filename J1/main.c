#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NBLINES 2237
#define BUF_SIZE 20
#define L 5


#define PRINT printf("Maxis : ");for(int i=0;i<L;i++)printf("%i ",max[i]); printf("\nSum : %i\n",sum);


int main(){
  char lignes[NBLINES][BUF_SIZE];
  int nelves = 0;

  FILE *fp = fopen("input","r");

  while (nelves < NBLINES) {
    char buf[BUF_SIZE];
    if (fgets(buf, BUF_SIZE, fp) == NULL) break; // no more line
    strcpy(lignes[nelves], buf);
    nelves++;
  }

  int sum=0;
  int max[L]={0};

  char vide[]="\n";

  for(int i=0;i<nelves;i++){
    if(lignes[i][0]=='\n'){
      
      int k=0;
      while(max[k]>sum && k<L){
        k++;
      }
      for(int j=L-1;j>k;j--){
        max[j]=max[j-1];
      }
      if(k<L)max[k]=sum;
      sum=0;
    }else{
      printf("La ligne  : \"%s\"\n",lignes[i]); 
      sum+=atoi(lignes[i]);
    }
    PRINT;
  }
  return 0;
}
