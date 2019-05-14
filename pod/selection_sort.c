#include <stdio.h>
/*
    #Encontre o menor elemento do vetor e troque com a primeira posição
    #Encontre o segundo menor elemento do vetor e troque com a segunda posição, e assim por diante
*/
int main(void)
{
  int tam;
  scanf("%d",&tam);
  int vet[tam];
  int i, j;
  for(i = 0; i < tam;i++){
    scanf("%d",&vet[i]);
  }
  for(i = 0; i < tam-1;i++){
    for(j = i+1; j < tam;j++){
      if(vet[i] < vet[j]){
        int aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
      }
    }
  }
  for(i = 0; i < tam;i++){
    printf(" %d",vet[i]);
  }

}
