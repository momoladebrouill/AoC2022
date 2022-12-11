#include <stdio.h>
#include <stdlib.h>

#define L 9
#define BUF_SIZE 50

typedef struct node{
  struct node* prec;
  char val;
} node;

node* push(node* s, char v){
  node* new;
  new->prec = s;
  new->val = v;
  return new;
}

node* pop(node* s){
  node* nh= s->prec;
  free(s);
  return nh;
}

int main(){

  char array[8][9];
  int l = 0;

  FILE *fp = fopen("input.txt","r");

  while (l < 8) {
    char buf[BUF_SIZE];
    if (fgets(buf, BUF_SIZE, fp) == NULL) break; // no more line
    for(int j = 0; j < 9; j ++){
      array[l][j] = buf[j*4+1];
    }
    l++;
  }

  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 9; j++){
      printf("%c",array[i][j]);
    }
    printf("\n");
  }

  node* stack[9] = {NULL};
  for(int i = 9; i >= 0; i--){
    for(int j = 0; j < 8; j++){
      printf("%d, %d\n", j, i);
      stack[j] = push(stack[j], array[j][i]);
      printf("done");
    }
  }
  /*for(int i = 0; i < 9; i++){
    int j = 0;
    node* c = stack[i];
    while(c){ 
      c = c->prec;
      j++;
    }
    printf("%d", j);
  }*/
}
