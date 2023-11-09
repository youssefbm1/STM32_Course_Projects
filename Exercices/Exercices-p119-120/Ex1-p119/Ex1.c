#include<stdio.h>
#include<stdlib.h>

int BSS = 0;
int DATA = 1;
const int RODATA = 20;



void pile(int n){
  if (n>10){
    return;
  }
  printf("numero de l'appel de fonction %d et l'Adresse de l'argument est: %p\n",n,&n);
  pile(n+1);
  return;
}


int main(){
  int* HEAP = (int*) malloc(sizeof(int));
  int* HEAP2 = (int*) malloc(sizeof(int));

  printf(" L'adresse de TEXT est: %p\n", main);
  printf(" L'adresse de RODATA est: %p\n", &RODATA);
  printf(" L'adresse de DATA   est: %p\n", &DATA);
  printf(" L'adresse de BSS    est: %p\n", &BSS);
  printf(" L'adresse de HEAP   est: %p\n", HEAP);
  printf(" L'adresse de HEAP2  est: %p\n", HEAP2);
  
  pile(1);
}
