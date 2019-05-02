#include <stdio.h>

/*
    Algoritmo:

*/
void insertion_sort1()
{
  int vet[9] = {2,53,0,34,31,65,11,-1,120};
  int i, j, aux, chave;
  for(i = 1; i < 9;i++){
    j = i;//define a chave. Começa a partir do segundo elemento do vetor.
    while((vet[j] < vet[j-1]) && j > 0){//enquanto a chave for menor ou maior que os elementos anterioes, troca.
      aux = vet[j];
      vet[j] = vet[j-1];
      vet[j-1] = aux;
      j--;
    }
  }
  for(i = 0; i < 9;i++){
    printf(" %d",vet[i]);
  }
}
void insertion_sort2()
{
  int vet[9] = {2,53,0,34,31,65,11,-1,120};
  int i, j, aux, chave;
  for(i = 1; i < 9;i++){
    chave = vet[i];//define a chave. Começa a partir do segundo elemento do vetor.
    j = i;
    while((chave < vet[j-1]) && j > 0){//enquanto a chave for menor ou maior que os elementos anterioes, troca.
      vet[j] = vet[j-1];
      j--;
    }
    vet[j] = chave;
  }
  for(i = 0; i < 9;i++){
    printf(" %d",vet[i]);
  }
}
int main(void)
{
    insertion_sort2();
    insertion_sort1();
}
