#include <stdio.h>
/*
    Passos:

    #Escolher um pivo(valor qualquer do vetor)
    #Definir um I(inicio do vetor = 0) e um J(final do vetor = tam-1)
    #Incrementar I enquanto vet[i] for menor que o pivo
    #Decrementar J enquanto vet[j] for maior que o pivo
    #Trocar vet[i] por vet[j] e vice-versa
    #Repetir os passos acima enquanto I for diferente de J(não se encontrarem)
    #Apos se encontrarem, retorna-se a posição I ou J(tanto faz pq se encontraram) do pivo e com isso cria-se sublistas
    #seja (x,y) = (inicio, fim) -> sublista da esquerda terá (i,posição do pivo -1)
    #Sublista da direita terá(posição do pivo +1,j)
    #Repetir todo o processo acima recursivamente para cada sublista, enquanto i >=j
    #A condição i == j garante que se a lista tiver um unico elemento, a função retorná, pois a lista já estará ordenada
    #A condição i > J garante que quando um pivo tiver uma lista vazia a direita nada será feito(caso especial)

*/
void imprime_vetor(int *vet, int tam)
{
  for(int i = 0; i < tam; i++){
    printf("%d",vet[i]);
  }
}

int calcula_pivo(int *vet, int i, int j)
{
  return (vet[ (i+j) / 2 ]);
}
int particiona(int *vet, int i, int j)
{
  int valor_pivo = calcula_pivo(vet, i, j);
  int aux;
  while(i < j){
    while(vet[i] < valor_pivo){
      i++;
    }
    while(vet[j] > valor_pivo){
      j--;
    }
    aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
  }
  return i;
}
void quick_sort(int *vet, int i, int j)
{
  if(i>=j){
    return;
  }
  int pos_pivo = particiona(vet,i,j);
  quick_sort(vet,pos_pivo+1,j);//sub_vetor da direita
  quick_sort(vet,i,pos_pivo-1);//sub_vetor da esquerda
}
int main(void)
{
  int tam;
  scanf("%d",&tam);
  int vet[tam];
  for(int i = 0; i < tam;i++){
    scanf("%d",&vet[i]);
  }
  quick_sort(vet,0,tam-1);
  imprime_vetor(vet,tam);

}
