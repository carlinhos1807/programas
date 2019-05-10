#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "quicksort.c"
#include <stdbool.h>
#include <math.h>

#define RAM 4
#define NUM_NUMS 31
#define NUM_CAMINHOS 6
struct fitas{
  FILE *arq;
  bool pode_avancar;
  bool ativa;
};
typedef struct fitas Fitas;
// Cria um arquivo temporario chamado nome com tam numeros aleatorios.
// Os numeros gerados sÃ£o mostrados na tela.
void cria_arq_rand(char *nome, int tam){
  FILE *arq;
  int num,j=0;
  int vet[42] = {5,28,10,40,35,7,12,2,21,11,29,27,9,38,8,49,3,15,13,30,17,46,18,36,1,4,34,16,19,22,20,80,81,82,83,84,85,86,87,88,89,90};


  arq = fopen(nome,"wb");

  for (int i = 0; i < tam; i++) {
    num = rand()%100;
    fwrite(&vet[i], sizeof(vet[i]), 1, arq);
    printf("%d\t",vet[i],j++);
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
    printf(" %d ",num,i++);

    if (i%RAM==0)
      printf("");
  }
  printf("\n");
  if (!feof(arq))
    printf("Houston!\n\n"); // teoricamente nunca devemos ver isso!
}

void fecha_arqs(int num, Fitas *fitas){
  for (int i =0; i < num; i++){
    //fflush(arqs[i]); // garante que tudo foi gravado antes de fechar
    fclose(fitas[i].arq);
  }
}
void abre_arqs_temp(int inicio, int fim, char *nome_arq,Fitas *fitas,char *como){
  char nome_arq_temp[20];
  for (int i=inicio;i<fim;i++){
    // cria nome do arq temporario e abre
    sprintf(nome_arq_temp,"%s.%d",nome_arq,i);
    fitas[i].arq = fopen(nome_arq_temp, como);
  }
}
void le_arq2()
{
  FILE *arq = fopen("teste.arq.2","r");
  int buffer = 0, i, t;
  fseek(arq,8*sizeof(int),SEEK_SET);
  fread(&buffer,sizeof(int),1,arq);
  if(feof(arq)){
  printf("gg");
}


}
void verifica_fitas_inativas(Fitas *fitas, int *leitura_fitas, int tam, int tamanho_conjunto)
{
    for(int i = 0; i < tam;i++){
      if(leitura_fitas[i] > tamanho_conjunto || feof(fitas[i].arq)){
        fitas[i].ativa = false;
        fitas[i].pode_avancar = false;
      }
    }
}
void zera_valores(int *leitura_fitas, int tam)
{
  for(int i = 0; i < tam;i++){
    leitura_fitas[i] = 0;
  }
}
int verifica_menor(int *vet, Fitas *fitas, int tam)
{
  int i, menor, ind_menor = 0;
  menor = 800;
  for(i = 0; i < tam;i++){
    if(vet[i] < menor && fitas[i].ativa){
      menor = vet[i];
      ind_menor = i;
    }
  }
  for(i = 0; i < tam;i++){
    if(i == ind_menor){
      fitas[i].pode_avancar = true;
    }else{
      fitas[i].pode_avancar = false;
    }
  }
  //printf("%d e %d = %d\n",vet[0],vet[1],menor);
  return menor;
}
bool verifica_fim(Fitas *fitas, int tam)
{
  int i, inativas = 0;
  for(i = 0; i < tam;i++){
    if(!fitas[i].ativa){
      inativas++;
    }
  }
  if(inativas == tam){
    return true;
  }
  return false;
}
void zera_fitas(Fitas *fitas, int tam)
{
  for(int i = 0; i < tam;i++){
    fitas[i].pode_avancar = true;
    fitas[i].ativa = true;
  }
}
void distribui(int num_caminhos, char *nome_arq, Fitas *fitas){
  FILE *arq = fopen(nome_arq,"rb");
  int buffer[RAM], i=0, lidos;
  abre_arqs_temp(0,num_caminhos,nome_arq,fitas,"wb+"); //abre args temporarios

  while( RAM == (lidos = fread(&buffer, sizeof(int), RAM, arq))){ // le o arquivo de entrada para a RAM
    quick_sort(buffer,RAM); // ordena
    fwrite(buffer, sizeof(int)*RAM, 1, fitas[i].arq); // escreve para o arquivo temporario atual
    i++;
    i %= num_caminhos; // incrementa o arquivo temporario
  }
  // trata os ultimos numeros do arquivo
  quick_sort(buffer,lidos); // ordena
  fwrite(buffer, sizeof(int)*lidos, 1, fitas[i].arq); // escreve para o arquivo temporario atual
  fecha_arqs(num_caminhos, fitas);



}
void redistribui(Fitas *fitas,int conjunto,char *nome_arq,int *vet,int tam)
{

  int buffer[conjunto], i=0, lidos;
  abre_arqs_temp(NUM_CAMINHOS,NUM_CAMINHOS+1,nome_arq,fitas,"wb");
  for(i = 0; i < tam;i++){
    fwrite(&vet[i],sizeof(int),1,fitas[NUM_CAMINHOS].arq);
    //printf(" %d",vet[i]);
  }
  fecha_arqs(NUM_CAMINHOS+1,fitas);
  abre_arqs_temp(0,NUM_CAMINHOS,nome_arq,fitas,"wb");
  abre_arqs_temp(NUM_CAMINHOS,NUM_CAMINHOS+1,nome_arq,fitas,"rb");
  i = 0;
  while( conjunto == (lidos = fread(&buffer, sizeof(int), conjunto, fitas[NUM_CAMINHOS].arq))){ // le o arquivo de entrada para a RAM
    fwrite(buffer, sizeof(int)*conjunto, 1, fitas[i].arq); // escreve para o arquivo temporario atual
    i++;
    i %= NUM_CAMINHOS; // incrementa o arquivo temporario
  }
  fwrite(buffer, sizeof(int)*lidos, 1, fitas[i].arq); // escreve para o arquivo temporario atual
  fecha_arqs(NUM_CAMINHOS+1,fitas);


}
int conta_fim = 0;
void intercalacao_balanceada(Fitas *fitas, char *nome_arq, int tamanho_conjunto, int *vet,int tam2, int passadas)
{
  conta_fim++;
  if(conta_fim == passadas+1){
    return;
  }
  int i = 0, j, buffer, menor, contador_escrita = 0, cont = 0, z;
  int val_fitas[NUM_CAMINHOS];
  int leitura_fitas[NUM_CAMINHOS];
  float tam_aux;
  zera_valores(leitura_fitas,NUM_CAMINHOS+1);
  bool fim = false, calcula = true;
  abre_arqs_temp(0,NUM_CAMINHOS,nome_arq,fitas,"rb+");
  zera_fitas(fitas,NUM_CAMINHOS+1);
  for(i =0; i < tam2;i++){
    zera_valores(leitura_fitas,NUM_CAMINHOS+1);
    zera_fitas(fitas,NUM_CAMINHOS+1);
    fim = false;
    for(z = 0; z < NUM_CAMINHOS;z++){

        fseek(fitas[z].arq,tamanho_conjunto*i*sizeof(int),SEEK_SET);
        fread(&buffer,sizeof(int),1,fitas[z].arq);
        if(feof(fitas[z].arq)){
          fitas[z].ativa = false;
          fitas[z].pode_avancar = false;
        }
        fseek(fitas[z].arq,tamanho_conjunto*i*sizeof(int),SEEK_SET);

    }
    while(!fim){
      for(j = 0; j < NUM_CAMINHOS;j++){
        if(fitas[j].pode_avancar && fitas[j].ativa && !feof(fitas[j].arq)){
          leitura_fitas[j]++;
          if(leitura_fitas[j] <= tamanho_conjunto){
            fread(&val_fitas[j],sizeof(int),1,fitas[j].arq);
         }
       }
      }
      verifica_fitas_inativas(fitas,leitura_fitas,NUM_CAMINHOS,tamanho_conjunto);
      menor = verifica_menor(val_fitas,fitas,NUM_CAMINHOS);
      fim = verifica_fim(fitas,NUM_CAMINHOS);
      if(!fim){
        vet[cont] = menor;
        cont++;
      }

    }
}
  fecha_arqs(NUM_CAMINHOS+1,fitas);
  redistribui(fitas,NUM_CAMINHOS*tamanho_conjunto,nome_arq,vet,NUM_NUMS);
  tam_aux = tam2 / 2.0;
  tam_aux = ceil(tam_aux);
  int tam3 = tam_aux;
  intercalacao_balanceada(fitas,nome_arq,NUM_CAMINHOS*tamanho_conjunto,vet,tam3,passadas);


}
void inicializa_fitas(Fitas *fitas, int tam)
{
  for(int i = 0; i < tam;i++){
    fitas[i].arq = NULL;
    fitas[i].pode_avancar = true;
    fitas[i].ativa = true;
  }
}
void intercalacao_multi_ways(Fitas *fitas, char *nome_arq,int tamanho_conjunto, int passadas)
{
    int vet[NUM_NUMS], cont = 0, i, j;
    float valor = (float)NUM_NUMS / (RAM*NUM_CAMINHOS);
    valor = ceil(valor);
    int valor2 = valor;
    intercalacao_balanceada(fitas,nome_arq,RAM,vet,valor2,passadas);
    fecha_arqs(NUM_CAMINHOS+1, fitas);
}
int main(){
  //srand(time(NULL));
  char nome_arq[]="teste.arq";
  char *nome_arq_temp = malloc(sizeof(char)*strlen(nome_arq)+3); // suporta ate .99 arquivos
  cria_arq_rand(nome_arq, NUM_NUMS);
  Fitas *fitas = (Fitas*)malloc(sizeof(Fitas) * (NUM_CAMINHOS+1));
  inicializa_fitas(fitas,NUM_CAMINHOS+1);
  distribui(NUM_CAMINHOS, nome_arq,fitas);
  float v1 = (float)NUM_NUMS / RAM;
  float passadas_aux = log10(v1) / log10(NUM_CAMINHOS);
  passadas_aux = ceil(passadas_aux);
  int passadas = passadas_aux;
  printf("-------- ANTES DE ORDENAR(depois de feita a distribuicao) ---------\n");
  for (int i=0; i<NUM_CAMINHOS; i++){
    sprintf(nome_arq_temp, "%s.%d", nome_arq, i);
    printf("------- %s:\n", nome_arq_temp);
    le_arq(nome_arq_temp);
  }
  printf("\n");
  intercalacao_multi_ways(fitas,nome_arq,RAM,passadas);



  //le_arq2();
  printf("-------- DEPOIS DE ORDENAR ---------\n");
    sprintf(nome_arq_temp, "%s.%d", nome_arq, 0);
    printf("------- %s:\n", nome_arq_temp);
    le_arq(nome_arq_temp);


}
