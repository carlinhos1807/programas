#include <stdio.h>
#include<stdbool.h>
/*
  Algoritmo que compara elementos adjacentes, ex:
  [5,2,7,9,11]
  compara o prim com o segundo, o segundo com o terceiro.... e assim vai, trocando quando for necessário.
  esse processo se repete varias vezes(vetor percorrido varias vezes), e para quando em uma iteração nenhuma troca foi realizada,
  ou seja, quando o vetor já estiver ordenado.
*/
void imprime_vetor(int *vet, int tam)
{
  for(int i = 0; i < tam; i++){
    printf("%d",vet[i]);
  }
}
void bubble_sort(int *vet, int tam)
{
  int i, aux;
  bool trocou;
  do{
    trocou = false;
    for(i = 0; i < tam-1;i++){
      if(vet[i] > vet[i+1]){
        aux = vet[i];
        vet[i] = vet[i+1];
        vet[i+1] = aux;
        trocou = true;
      }
    }
  }while(trocou);
}
int main(void)
{
  int tam;
  scanf("%d",&tam);
  int vet[tam];
  for(int i = 0; i < tam;i++){
    scanf("%d",&vet[i]);
  }
  bubble_sort(vet,tam);
  imprime_vetor(vet,tam);

}
