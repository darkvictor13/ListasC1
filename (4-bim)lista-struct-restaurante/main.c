#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ENTRADA "consumo2.txt"
#define MAXN 51
#define MAXC 100
#define MAXCONSUMIDORES 1000

typedef struct {
  int dia, mes, ano;
}s_data;

typedef struct {
  int hora, min;
}s_hora;

typedef struct {
  char *item;
  int qnt;
  float preco;
}s_consumo;

typedef struct {
  s_hora entrada, saida;
  s_consumo *vet;
  int tam_vet;
  char *nome_g;
  int mesa, qnt_pessoas;
}s_total;

int achaCaracter (char x, char str[]) {
  for(int i = 0; str[i]; i++) {
    if (str[i] == x) {
      return 1;
    }
  }
  return 0;
}

void adicionaExtensao (char *dest, char *e) {
  for(; *dest; dest++) {
    ;
  }

  *dest = '.';
  for(dest++; *e; e++, dest++) {
    *dest = *e;
  }
  *dest = *e;
}

void lerConsumo (FILE *arch, s_consumo *v, int *t) {
  int i;
  char buffer[21];

  fscanf(arch, "%s", buffer);
  for (i = 0; strcmp(buffer, "<fim>"); i++) {
    v[i].item = (char *)malloc(strlen(buffer) + 1);
    strcpy(v[i].item, buffer);
    fscanf(arch, "%d %f%*r", &v[i].qnt, &v[i].preco);
    fscanf(arch, "%s", buffer);
  }
  fscanf(arch, "%*r");
  *t = i;
}

void ler1Struct (FILE *arch, s_total *s) {
  char buffer[MAXN];

  fscanf(arch,"%[^\n]%*r", buffer);
  s->nome_g = malloc(strlen(buffer) + 1);
  strcpy(s->nome_g, buffer);
  fscanf(arch, "%*s %d%*r", &s->mesa);
  fscanf(arch, "%d:%d", &s->entrada.hora, &s->entrada.min);
  fscanf(arch, "%d:%d%*r", &s->saida.hora, &s->saida.min);
  fscanf(arch, "%d%*r", &s->qnt_pessoas);

  s->vet = (s_consumo *)malloc(sizeof(s_consumo) * MAXC);
  lerConsumo(arch, s->vet, &s->tam_vet);
  s->vet = (s_consumo *)realloc(s->vet, sizeof(s_consumo) * s->tam_vet);
}

int leitura (s_total *consumidores, s_data *data) {
  int i;
  FILE *arch = fopen(ENTRADA, "r");
  if (arch == NULL) {
    printf("Falha na leitura do arquivo!\n");
    return 0;
  }

  fscanf(arch, "%d/%d/%d%*r", &data->dia, &data->mes, &data->ano);
  for(i = 0; !feof(arch); i++) {
  //for(i = 0; i < 2; i++) {
    ler1Struct(arch, consumidores + i);
  }
  return i;
}

void printAll (s_data data, s_total *v, int t) {
  int i, j;
  printf("Ano = (%d/%d/%d)\n", data.dia, data.mes, data.ano);

  for(i = 0; i < t; i++) {
    printf("=======================\n");
    printf("Consumo num %d\n", i + 1);
    printf("=======================\n");
    printf("Nome do garçom = (%s)\n", v[i].nome_g);
    printf("Mesa = (%d)\n", v[i].mesa);
    printf("Hora entrada = (%d:%d) | ", v[i].entrada.hora, v[i].entrada.min);
    printf("Hora saída = (%d:%d)\n", v[i].saida.hora, v[i].saida.min);
    printf("Pessoas na mesa = (%d)\n", v[i].qnt_pessoas);

    for(j = 0; j < v[i].tam_vet; j++) {
      printf("item = %s ", v[i].vet[j].item);
      printf("quantidade = %d ", v[i].vet[j].qnt);
      printf("preço = %.2f\n", v[i].vet[j].preco);
    }
  }
}

int main (int argc, char *argv[]) {
  char *nome_arch;
  if (argc <= 0 || 3 <= argc) {
    printf("Você está usando o programa de forma errada!\n");
    printf("Por favor rode:\n");
    printf("[Nome do programa] [espaço em branco] [nome do arquivo com os dados]\n");
    return 0;
  }else if (argc == 2) {
    nome_arch = (char *)malloc(strlen(argv[1]) + 1);
    strcpy(nome_arch, argv[1]);
  }else if (argc == 1) {
    nome_arch = (char *)malloc(MAXN);
    printf("Você não nos informou o nome do arquivo com os dados\n");
    printf("Por favor insira o nome aqui >> ");
    scanf("%[^\n]%*c", nome_arch);
    if (!achaCaracter('.', nome_arch)) {
      char aux[4];
      printf("Qual a extensão desse aquivo que você me passou?\n"); 
      printf("Ele é um txt? Um log? Ou o que?\n");
      printf("Entre com a extensão do arquivo -> ");
      scanf("%[^\n]%*c", aux);
      printf("Tam do aux == %d", (int)strlen(aux));
      if () { // se a string esta vazia
        adicionaExtensao(nome_arch, aux);
      }
    }
    nome_arch = realloc(nome_arch, strlen(nome_arch) + 1);
  }

  printf("O nome do arquivo para abir ficou\n>>>[%s]\n", nome_arch);
  return 0;

  s_total *vetor;
  s_data data;
  int consumidores;

  vetor = (s_total *)malloc(sizeof(s_total) * MAXCONSUMIDORES);
  consumidores = leitura(vetor, &data);
  printf("Num total de consumidores = %d\n", consumidores);
  vetor = (s_total *)realloc(vetor, sizeof(s_total) * consumidores);
  printAll(data, vetor, consumidores);
//  free()
  return 0;
}
