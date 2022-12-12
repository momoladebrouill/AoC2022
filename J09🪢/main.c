#include <stdio.h>
#include <stdlib.h>
#define LINES 10

int main(){
    char dir;
    int times;
    int mx,my;
    int last[LINES][2] = {0}; // positions of last member
    int poses[10][2] = {0}; // list of members
    for(int line=0; line<LINES; line++){
        scanf("%c %d\n",&dir,&times);
        switch(dir){
            case 'R':
                my=0;
                mx=1;
                break;
            case 'L':
                my=0;
                mx=-1;
                break;
            case 'U':
                mx=0;
                my=1;
                break;
            case 'D':
                mx=0;
                my=-1;
                break;
            default:
                printf("Invalid move\n");
                break;
        }
        for(int _=0;_<times;_++){
            for(int i=1;i<10;i++){
                if(abs(poses[i-1][0]-poses[i][0])>=2
                        && abs(poses[i-1][1]-poses[i][1])>=2){
                    poses[i][1]=(poses[i-1][1]+poses[i][1])/2;
                    poses[i][0]=(poses[i-1][0]+poses[i][0])/2;
                }
                else if(abs(poses[i-1][0]-poses[i][0])>=2){
                    poses[i][0]=(poses[i-1][0]+poses[i][0])/2;
                    poses[i][1]=poses[i-1][1];
                }
                else if(abs(poses[i-1][1]-poses[i][1])>=2){
                    poses[i][1]=(poses[i-1][1]+poses[i][1])/2;
                    poses[i][0]=poses[i-1][0];
                }
            }
            last[line][0]=poses[9][0];
            last[line][1]=poses[9][1];
        }
    }
  for(int i=0;i<LINES;i++){
      printf("(%d,%d) ",last[i][0],last[i][1]);
  }
}
