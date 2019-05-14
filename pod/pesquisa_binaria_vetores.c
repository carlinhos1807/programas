#include <stdio.h>
#include <stdbool.h>

bool pesquisa_binaria(int *vet, int tam, int valor)
{
  bool achou = false;
  int inicio = 0;
  int fim = tam-1;
  int meio;

  while(!achou && inicio <=fim){
    meio = (inicio + fim) / 2;
    if(valor == vet[meio]){
      achou = true;
      break;
    }else if(valor < vet[meio]){
      fim = meio -1;
    }else{
      inicio = meio +1;
    }
  }
  return achou;
}
bool pesquisa_binaria_recursiva(int *vet, int tam, int valor, int inicio, int fim)
{
  if(inicio > fim){
    return false;
  }
  int meio = (inicio + fim) / 2;
  if(valor == vet[meio]){
    return true;
  }else if(valor < vet[meio]){
    pesquisa_binaria_recursiva(vet,tam,valor,inicio,meio-1);
  }else{
    pesquisa_binaria_recursiva(vet,tam,valor,meio+1,fim);
  }

}
int main(void)
{
    int tam;
    scanf("%d",&tam);
    int vetor[tam];
    int i, valor = -1;
    for(i = 0; i < tam;i++){
      scanf("%d",&vetor[i]);
    }
    if(pesquisa_binaria_recursiva(vetor,tam,valor,0,tam-1)){
      printf("achou\n");
    }else{
      printf("nao achou\n");
    }
    return 0;
}
