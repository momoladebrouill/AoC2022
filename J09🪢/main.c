#include <stdio.h>
#define LINES 10

int main(){
  char dir;
  int times;

  int poses[10][2] = {500};
  for(int i=0; i<LINES; i++){
    scanf("%c %d\n",&dir,&times);

    printf("%c  %d\n",dir, times);
  }
}
