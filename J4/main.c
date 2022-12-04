#include <stdio.h>
#define LINES 1000

int main(){
  int p1=0,p2=0;
  int a1,a2,b1,b2;
  for(int i=0; i<LINES; i++){
    scanf("%d-%d,%d-%d\n",&a1,&a2,&b1,&b2);

    p1 += ((a1<=b1 && b2<=a2) // B C A
        ||(b1<=a1 && a2<=b2));// A C B

    p2 += ((a1<=b1 && b1<=a2) // b1 E A
        ||(a1<=b2 && b2<=a2)// b2 E A
        ||(b1<=a1 && a1<=b2)// a1 E B
        ||(b1<=a2 && a2<=b2));// a2 E B
  }
  printf("Partie 1 : %d  Partie 2 : %d\n",p1,p2);
}
