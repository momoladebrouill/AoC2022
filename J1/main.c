#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NBLINES 10
//2263
#define L 5
#define PRINT printf("Maxis : ");for(int i=0;i<L;i++)printf("%i ",max[i]); printf("\nSum : %i\n",sum);

int main(){
  char lignes[NBLINES][10];
  fflush( stdout );
  for(int i=0;i<NBLINES;i++){
    scanf("%[^\n]\n",lignes[i]);
    fgetc( stdin );
  }
  int sum=0;
  int max[L]={0};
  char vide[]="";
  for(int i=0;i<NBLINES;i++){
    if(strcmp(lignes[i],vide)==0){
      int k=0;
      while(max[k]>sum && k<L){
        k++;
      }
      for(int j=L-1;j>k;j--){
        max[j]=max[j-1];
      }
      if(k<L)max[k]=sum;
      PRINT;
      sum=0;
    }else{
      printf("La ligne  : \"%s\"%i\n",lignes[i],lignes[i]); 
      sum+=atoi(lignes[i]);
    }
  }
  printf("Max : %i\nMaxes : ",max[0]);
  for(int i=0;i<L;i++)printf("%i ",max[i]);
  printf("\n");
  return 0;
}
