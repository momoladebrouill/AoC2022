#include <stdio.h>
#include <stdlib.h>

#define N 14

int main()
{
  char file[N + 1];
  FILE *fp = fopen("input", "r");
  char c = 0;
  int count = 0;
  int t[26] = {0};
  int i = 0;

  while ( (c = fgetc(fp)) != EOF && count != N){
    file[i%(N+1)] = c;

    int *a = t + c - 'a';
    (*a)++;

    if ((*a) == 1) count++;
    if ((*a) == 2) count--;

    if (i > N - 1){
      int *b = t + file[(i + 1)%(N + 1)] - 'a';
      (*b)--;
      if ((*b) == 0) count--;
      if ((*b) == 1) count++;
    }
    i++;
  }
  printf("Fin : %d\n",i);

}
