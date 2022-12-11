#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOM "test"
#define NBLINES 5
#define BUF_SIZE 10
#define gx 5
#define gy 5

void cast(int trees[gx][gy], int vtrees[gx][gy], int x, int y, int vx, int vy){
  int m = -1;
  int c;
  while(x >= 0 && x < gx && y >= 0 && y < gy){
    c = trees[x][y];
    if(c>m){
      vtrees[x][y] = 1;
      m = c;
    }
    x += vx;
    y += vy;
  }
}

int sight(int trees[gx][gy], int x, int y, int vx, int vy){
  int height = trees[x][y];
  int c;
  int s = 0;
  while(x + vx >= 0 && x + vx < gx && y + vy >= 0 && y + vy < gy){
    x += vx;
    y += vy;
    c = trees[x][y];
    s ++;
    if (c >= height){
      break;
    }
  }
  return s;
}

int main(){
  int l = 0;
  FILE *fp = fopen(NOM,"r");
  int trees[gx][gy];

  while (1) {
    char ligne[BUF_SIZE];
    if (fgets(ligne, BUF_SIZE, fp) == NULL) break; // no more line
    for (int i = 0; i < gx; i++){
      trees[i][l] = ligne[i]-48;
    } 
    //printf("%s\n", ligne);
    l++;
  }
  printf("%d\n",l);
  for(int i=0;i<gx;i++){
    for(int j = 0; j < gy; j++){
      printf("%d",trees[i][j]);
    }
    printf("\n");
  }
  
  int vtrees[gx][gy] = {0};
  
  int m;
  int c;
  for(int i = 0; i < gx; i++){
    cast(trees, vtrees, i, 0, 0, 1);
    cast(trees, vtrees, i, gx-1, 0, -1);
  }
  for(int i = 0; i < gy; i++){
    cast(trees, vtrees, 0, i, 1, 0);
    cast(trees, vtrees, gy-1, i, -1, 0);
  }

  int result = 0;
  for(int i = 0; i < gx; i++){
    for(int j = 0; j < gy; j++){
      printf(vtrees[j][i] == 0 ? " " : "#");
      result += vtrees[j][i];
    }
    printf("\n");
  }
  printf("Q2: %d\n", result);


  int max = 0;
  for(int i = 0; i < gx; i++){
    for(int j = 0; j < gy; j++){
      int up = sight(trees, j, i, 0, -1);
      int down = sight(trees, j, i, 0, 1);
      int left = sight(trees, j, i, -1, 0);
      int right = sight(trees, j, i, 1, 0);
      int c = up*down*left*right;
      if(c > max) max = c;
      printf("%d  ", c);
    }
    printf("\n");
  }

  printf("Q1: %d\n", max);
}
