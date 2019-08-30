#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>
void merge(int arr[], int l, int m, int r, int *iv)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            *iv = *iv + (n1-i);
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r, int *i)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        mergeSort(arr, l, m,i);
        mergeSort(arr, m+1, r,i);

        merge(arr, l, m, r,i);
    }
}
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
bool identifica_soma(int *vet, int tam, int x)
{
    for(int i = 0; i < tam;i++){
        int valor = x - vet[i];

        if(pesquisa_binaria(vet,tam,valor)){

            return true;
        }
    }
    return false;
}
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n\n");
}
int main()
{
    int arr[] = {5,4,3,2};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int inversoes = 0;

    printf("Array:\n\n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1,&inversoes);
    int x = 5;
    printf("Numero de inversoes = %d\n\n",inversoes);
    printf("Pares que somados sao = %d\n\n",x);
    if(identifica_soma(arr,arr_size,x)){
        printf("Existem 2 numeros somados que dao = %d\n",x);
    }else{
        printf("Nao existem 2 numeros somados que dao = %d\n",x);
    }

    return 0;
}
