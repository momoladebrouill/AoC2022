#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(a,b) (a<=b?a:b)

#define NOM "test"
#define NBLINES 5
#define BUF_SIZE 8

int main(){
  FILE *fp = fopen(NOM,"r");
  int heights[NBLINES][BUF_SIZE];
 
  int i = 0;
  while (i < NBLINES) {
    char ligne[BUF_SIZE + 2];
    if (fgets(ligne, BUF_SIZE + 2, fp) == NULL) break; // no more line
    int j = 0;
    while(j < BUF_SIZE){
      heights[i][j] = ligne[j];
      j++;
    }
    i++;  
  }

  int path[NBLINES][BUF_SIZE];

  for(int i = 0; i < NBLINES; i++){
    for(int j = 0; j < BUF_SIZE; j++){
      if(heights[i][j] == 'S') {
        path[i][j] = 1;
        heights[i][j] = 'a';
      } else {
        path[i][j] = 1000;
      }
    }
  }

  int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  for(int _ = 0; _ < 1000; _++){
    for(int i = 0; i < NBLINES; i ++){
      for(int j = 0; j < BUF_SIZE; j++){
        int ni, nj;
        for(int k = 0; k < 4; k++){
          ni = i + dirs[k][0];
          nj = j + dirs[k][1];
          if(ni >= 0 && ni < NBLINES && nj >= 0 && nj < BUF_SIZE){
            if(heights[i][j] - heights[ni][nj] <= 1){
              path[i][j] = min(path[i][j], path[ni][nj] + 1);
            }
          }
        }
      }
    }
  }


  for(int i=0;i<NBLINES;i++){
    for(int j = 0; j < BUF_SIZE; j++){
      printf("%c",heights[i][j]);
    }
    printf("\n");
  }
  for(int i=0;i<NBLINES;i++){
    for(int j = 0; j < BUF_SIZE; j++){
      printf("% 4d",path[i][j]);
    }
    printf("\n");
  }
  for(int i = 0; i < NBLINES; i++){
    for(int j = 0; j < BUF_SIZE; j++){
      if(heights[i][j] == 'E') {
        printf("%d\n", path[i][j-1]);
      }
    }
  } 
}
