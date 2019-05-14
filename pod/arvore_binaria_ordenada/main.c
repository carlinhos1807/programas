#include "stdlib.h"
#include "stdio.h"
#include "arvore.h"

int quant_maiores(No * no, int v);
int gera_vetor_maiores(No * no, int v, int ** vetor);

int calcula_altura(No * no);
int balanceada(No * no);

void imprime_asc(No * no){
    if (no==NULL)
        return;

    imprime_asc(arv_busca_filho(no,0));
    printf("%d, ",arv_busca_valor(no) );
    imprime_asc(arv_busca_filho(no,1));

}


int calcula_altura(No * no){

    return 0;
}

int balanceada(No * no)
{
    return 0;
}



int quant_maiores(No * no, int v)
{
    return 0;
}

int gera_vetor_maiores(No * no, int v, int ** vetor){

    return 0;
}




int main()
{

   printf("\n\n******************* TESTE 1 ******************************");
   Arvore * arv = arv_cria();

   arv_insere_no(arv, 1);
   arv_insere_no(arv, 2);
   arv_insere_no(arv, 3);
   arv_insere_no(arv, 4);
   arv_insere_no(arv, 5);
   arv_insere_no(arv, 6);
   arv_insere_no(arv, 7);

   printf("\n");
   int bal = balanceada(arv_busca_raiz(arv));
   if (bal)
        printf("\nBalanceada");
    else printf("\nNao Balanceada");


   printf("\n\n******************* TESTE 2 ******************************");
   Arvore * arv1 = arv_cria();

   arv_insere_no(arv1, 4);
   arv_insere_no(arv1, 6);
   arv_insere_no(arv1, 2);
   arv_insere_no(arv1, 5);
   arv_insere_no(arv1, 1);
   arv_insere_no(arv1, 7);
   arv_insere_no(arv1, 3);

   printf("\n");
    bal = balanceada(arv_busca_raiz(arv1));
   if (bal)
        printf("\nBalanceada");
    else printf("\nNao Balanceada");


   int * vetor;
   int tam = gera_vetor_maiores(arv_busca_raiz(arv1), 3, &vetor);

   printf("\n\nvetor gerado: ");
   int x;
   for(x=0;x<tam;x++){
       printf("%d ", vetor[x]);
   }
   printf("\n");


   return 0;
}
