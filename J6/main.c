#include <stdio.h>
#include <stdlib.h>
#define LEN 4095

int main(){
  char file[LEN];
  FILE *fp = fopen("test","r");
  char c = 0;
  int count = 0;
  int t [26]= {0};
  int i=0;
  while ((c = fgetc(fp)) != EOF){
    file[i] = c;
    t[c - 'a']++;
    if (t[c - 'a'] == 1) count++;
    t[file[i-4] - 'a']--;
    if (i > 3 && (t[file[i - 4] - 'a'] != 1)) count--;
    printf("%d", count);
    if (count==4){
      printf("Fin : %d", i);
    }
    i++;
  }

}
