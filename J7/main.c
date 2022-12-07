#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INDENT(n) for(int __i=0;__i<n;__i++)printf("   ")
#define NBLINES 1019
#define BUF_SIZE 100

#define NOM "input"

typedef struct file {
  int size;
  struct file* next;
}file;

typedef struct dir{
  file* fchild;
  struct dir* fdir;
  struct dir* par;
  struct dir* next;
  char name[10];
}dir;

int addfile(dir* d,file* f){
  if(d->fchild == NULL){
    d->fchild = f;
  }else{
    file* child = d->fchild;
    while(child->next) child = child->next;
    child->next = f;
  }
  f->next = NULL;
}

int adddir(dir *d, dir* n){
  if(d->fdir == NULL){
    d->fdir = n;
  }else{
    dir* child = d->fdir;
    while(child->next) child = child->next;
    child->next = n;
  }
  n->next = NULL;
  n->par = d;
}

int weight(dir* d){
  int s = 0;
  file* f = d->fchild;
  //pour les fichiers
  while(f){
    s+=f->size;
    f=f->next;
  }
  dir* e = d->fdir;
  //pour les fichiers
  while(e){
    s+=weight(e);
    e=e->next;
  }
  return s;
}

int printdir(dir* d,int ind){
  INDENT(ind);
  printf("{\"%s\":\n", d->name);
  dir* c = d->fdir;
  while(c){
    printdir(c, ind+1);
    c = c->next;
  }
  file* f = d->fchild;
  while(f){
    INDENT(ind + 1);
    printf("File %dmb\n", f->size);
    f = f->next;
  }
  INDENT(ind);
  printf("}\n");
}

int main(){
  int i = 0;
  FILE *fp = fopen(NOM,"r");
  dir* home = malloc(sizeof(dir));
  strcpy(home->name,"/");
  dir* cur;
  cur = home;
  while (i++ < NBLINES) {
    char ligne[BUF_SIZE];
    if (fgets(ligne, BUF_SIZE, fp) == NULL) break; // no more line
    for(int i = 0; i <BUF_SIZE; i++){ if (ligne[i] == '\n')ligne[i] = 0;}
    if(ligne[0] == '$'){
      if(strcmp(ligne, "$ ls")){ // cd
        char* name = (ligne + 5);
        if (strcmp(name, "..") == 0) cur = cur->par;
        else {
          dir* child = cur->fdir;
          while(child && strcmp(child->name,name)){
            child = child->next;
          }
          if(child) cur = child;
          printf("%s\n", name);
        }
      }
    }else{
      if(strncmp(ligne, "dir", 3)==0){
        char* name = (ligne + 4);
        dir* d = malloc(sizeof(dir));
        d->fdir = NULL;
        d->fchild = NULL;
        strcpy(d->name, name);
        adddir(cur, d);
      }else{
        file* f = malloc(sizeof(file));
        f->size = atoi(ligne);
        addfile(cur, f); 
      }
    }
  }
  printdir(home,0);
  printf("%i\n",weight(home));

}

