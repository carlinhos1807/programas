#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "quicksort.c"
#include <stdbool.h>

#define RAM 4
#define NUM_NUMS 31
#define NUM_CAMINHOS 2

// Cria um arquivo temporario chamado nome com tam numeros aleatorios.
// Os numeros gerados sÃ£o mostrados na tela.
void cria_arq_rand(char *nome, int tam){
  FILE *arq;
  int num,j=0;
  int vet[31] = {5,28,10,40,35,7,12,2,21,11,29,27,9,38,8,49,3,15,13,30,17,46,18,36,1,4,34,16,19,22,20};


  arq = fopen(nome,"wb");

  for (int i = 0; i < tam; i++) {
    num = rand()%100;
    fwrite(&vet[i], sizeof(vet[i]), 1, arq);
    printf("%d(%d)\t",vet[i],j++);
    if (j%RAM==0)
      printf("\n");
  }
  printf("\n");
  printf("\n");
//  fflush(arq); // garante que tudo foi gravado antes de fechar
  fclose(arq);
}

// Le um aquivo com numeros inteiros e mostra-os na tela.
void le_arq(char *nome){
  FILE *arq;
  int num;
  int i=0;

  arq = fopen(nome,"rb");

  while( 1 == fread(&num,sizeof(num),1,arq)){
    printf("%d(%d) ",num,i++);
    if (i%RAM==0)
      printf("    ");
  }
  printf("\n");
  if (!feof(arq))
    printf("Houston!\n\n"); // teoricamente nunca devemos ver isso!
}

void fecha_arqs(int num, FILE **arqs){
  for (int i =0; i < num; i++){
    //fflush(arqs[i]); // garante que tudo foi gravado antes de fechar
    fclose(arqs[i]);
  }
}

void abre_arqs_temp(int inicio, int fim, char *nome_arq, FILE **arqstemp, char *como){
  char nome_arq_temp[20];
  for (int i=inicio;i<fim;i++){
    // cria nome do arq temporario e abre
    sprintf(nome_arq_temp,"%s.%d",nome_arq,i);
    arqstemp[i-inicio]=fopen(nome_arq_temp, como);
  }
}

void mostra_arquivos(char *nome, int num_arquivo)
{
  char *nome_arq_temp = malloc(sizeof(char)*strlen(nome)+3);
  sprintf(nome_arq_temp, "%s.%d", nome,num_arquivo);
  printf("\n");
  printf("------- %s:\n", nome_arq_temp);
  le_arq(nome_arq_temp);
}
int verifica_menor(bool *avanca,int*fitas, int tam,bool *ativa, int*leitura_fitas,bool *compara, int flag)
{
  int menor = 800, i, indice_menor;

  for(i = 0; i < tam;i++){
    if(i == 0 && compara[i] == true){
      menor = fitas[i];
      indice_menor = i;
    }else if(fitas[i] <= menor && compara[i] == true){
      menor = fitas[i];
      indice_menor = i;

    }
  }
  for(i = 0; i < tam;i++){
    if(i != indice_menor){
      avanca[i] = false;
    }else{

       avanca[i] = true;
    }

  }

  if(leitura_fitas[indice_menor] == RAM){
    compara[indice_menor] = false;
  }


  if(flag){
  printf("%d(%d)(%d)(%d) e %d(%d)(%d)(%d) = %d(%d)\n",fitas[0],leitura_fitas[0],ativa[0],compara[0],fitas[1],leitura_fitas[1],ativa[1],compara[1],menor,indice_menor);
}

  return menor;

}
bool verifica_fim(bool *vet, int tam, bool *compara){
  int i, terminou = 0;
  for(i = 0; i < tam;i++){
    if(!vet[i] && compara[i] == false){
      terminou++;
    }
  }
  if(terminou == tam){
    return true;
  }
  return false;
}
void verifica_ativos(bool *ativos,int*leitura_fitas, int tam, bool *avanca, int*fitas, bool *compara)
{
  int i, menor;
  for(i = 0; i < tam;i++){
    if(leitura_fitas[i] == RAM){
      ativos[i] = false;


    }
  }
}
bool esta_no_vetor(int *vet,int menor,int tam)
{
  int i;
  for(i = 0; i < tam;i++){
    if(vet[i] == menor){
      return true;
    }
  }
  return false;
}
void merge(int *vet_aux, FILE **arqstemp)
{
  int i,j, menor, cont = 0, nao_terminou;
  bool fita_ativa[NUM_CAMINHOS];
  bool avanca[NUM_CAMINHOS];
  bool compara[NUM_CAMINHOS];
  int fitas[NUM_CAMINHOS];
  int leitura_fitas[NUM_CAMINHOS];
  bool todas_terminaram = false;
  fseek(arqstemp[0],8*sizeof(int),SEEK_SET);
  fseek(arqstemp[1],8*sizeof(int),SEEK_SET);
  for(i = 0; i < NUM_CAMINHOS; i++){
    fita_ativa[i] = true;
    avanca[i] = true;
    leitura_fitas[i] = 0;
    compara[i] = true;
  }
  while(!todas_terminaram){
    for(j = 0; j < NUM_CAMINHOS; j++){
      if(avanca[j] && fita_ativa[j]){
        fread(&fitas[j],sizeof(int),1,arqstemp[j]);
        leitura_fitas[j]++;
     }

   }
   verifica_ativos(fita_ativa,leitura_fitas,NUM_CAMINHOS,avanca,fitas,compara);
   menor = verifica_menor(avanca,fitas,NUM_CAMINHOS,fita_ativa,leitura_fitas,compara,1);
   todas_terminaram = verifica_fim(fita_ativa,NUM_CAMINHOS,compara);

      vet_aux[cont] = menor;
      cont++;

 }
}
void intercalacao_balanceada_2_caminhos(char *nome_arq)
{
    FILE **arqstemp = malloc(sizeof(FILE *) * NUM_CAMINHOS);
    abre_arqs_temp(0,NUM_CAMINHOS,nome_arq,arqstemp,"rb");
    int vet[8];
    int valor, lido, vet_aux[NUM_CAMINHOS*RAM];
    merge(vet_aux,arqstemp);
    for(int i = 0; i < NUM_CAMINHOS*RAM;i++){
      printf(" %d",vet_aux[i]);
    }







}
void distribui(int num_caminhos, char *nome_arq){
  FILE *arq = fopen(nome_arq,"rb");
  FILE **arqstemp = malloc(sizeof(FILE *) * num_caminhos);
  int buffer[RAM], i=0, lidos;
  abre_arqs_temp(0,num_caminhos,nome_arq,arqstemp,"wb"); //abre args temporarios

  while( RAM == (lidos = fread(&buffer, sizeof(int), RAM, arq))){ // le o arquivo de entrada para a RAM
    quick_sort(buffer,RAM); // ordena
    fwrite(buffer, sizeof(int)*RAM, 1, arqstemp[i]); // escreve para o arquivo temporario atual
    i++;
    i %= num_caminhos; // incrementa o arquivo temporario
  }
  // trata os ultimos numeros do arquivo
  quick_sort(buffer,lidos); // ordena
  fwrite(buffer, sizeof(int)*lidos, 1, arqstemp[i]); // escreve para o arquivo temporario atual
  fecha_arqs(num_caminhos, arqstemp);
  intercalacao_balanceada_2_caminhos(nome_arq);



}

int main(){
  //srand(time(NULL));
  char nome_arq[]="teste.arq";
  char *nome_arq_temp = malloc(sizeof(char)*strlen(nome_arq)+3); // suporta ate .99 arquivos
  cria_arq_rand(nome_arq, NUM_NUMS);
  distribui(NUM_CAMINHOS, nome_arq);

  for (int i=0; i<NUM_CAMINHOS; i++){
    sprintf(nome_arq_temp, "%s.%d", nome_arq, i);
    printf("------- %s:\n", nome_arq_temp);
    le_arq(nome_arq_temp);
  }

}
