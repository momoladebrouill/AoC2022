#include <stdio.h>
#define LINES 2000

int main(){
  char dir;
  int times;

  int poses[10][2] = {500};
  for(int i=0; i<LINES; i++){
    scanf("%c %d\n",&a1,&a2);

    p1 += ((a1<=b1 && b2<=a2) // B C A
        ||(b1<=a1 && a2<=b2));// A C B

    p2 += (!(a2<b1 || a1>b2));
  }
  printf("Partie 1 : %d  Partie 2 : %d\n",p1,p2);
}
