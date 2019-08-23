#include <stdio.h>

int main(void)
{
  int tam;
  scanf("%d",&tam);
  int vet[tam];
  int i, j, aux;
  int chave;
  for(i = 0; i < tam; i++){
    scanf("%d",&vet[i]);
  }
  int intervalo = tam / 2;
  while(intervalo > 0){
      for(i = intervalo; i < tam;i++){
        j = i;
        while(vet[j] < vet[j-intervalo] && (j > 0)){
          aux = vet[j-intervalo];
          vet[j-intervalo] = vet[j];
          vet[j] = aux;
          j = j - intervalo;
        }
      }
      intervalo = intervalo / 2;
  }
  for(i = 0; i < tam; i++){
    printf(" %d",vet[i]);
  }
}
