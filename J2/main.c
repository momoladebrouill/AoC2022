#include <stdio.h>
#define LEN 2500


int amIwinning (char adv, char me)
{
  return (me - adv - (88 - 65) + 3) % 3;
}

int main (){
  int p1 = 0;
  int p2 = 0;
  char lut, me;
  for (int i = 0; i < LEN; i++){
    scanf ("%c %c\n", &lut, &me);
    p1 += me - 87;
    switch (amIwinning (lut, me)){
      case 0://tie
        p1 += 3;
        break;
      case 1://win
        p1 += 6;
        break;
      case 2://loose
        break;
      default:
        printf ("ERREUR BOB");
        break;
    }
    switch(me){
      case 'X'://loose
        p2+=(lut-65+2)%3+1;
        break;
      case 'Y'://draw
        p2+=lut-65+1+3;
        break;
      case 'Z'://win
        p2+=(lut-65+1)%3+1+6;
        break;
      default:
        printf("ERREUR JEAN");
        break;
    }

  }
  printf ("p1: %i\np2: %i\n", p1,p2);
}
