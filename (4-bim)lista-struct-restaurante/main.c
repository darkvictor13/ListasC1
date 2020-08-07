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
  s_data data;
  s_hora entrada, saida;
  s_consumo *vet;
  int tam_vet;
  char *nome_g;
  int mesa, qnt_pessoas;
}s_total;

void lerConsumo (FILE *arch, s_consumo *v, int *t) {
  int i;
  char buffer[21];

  fscanf(arch, "%s", buffer);
  for (i = 0; strcmp(buffer, "<fim>"); i++) {
    v[i].item = (char *)malloc(strlen(buffer) + 1);
    strcpy(v[i].item, buffer);
    //printf("compara buffer com copia [%s]-[%s]\n", buffer, v[i].item);
    fscanf(arch, "%d %f%*r", &v[i].qnt, &v[i].preco);
    printf("compara preco %f\n", v[i].preco);
    printf("compara quantidade %d\n", v[i].qnt);
    fscanf(arch, "%s", buffer);
  }
  fscanf(arch, "%*r");
  *t = i;
}

int leitura (s_total *consumidores) {
  int i;
  char buffer[MAXN];
  FILE *arch = fopen(ENTRADA, "r");
  if (arch == NULL) {
    printf("Falha na leitura do arquivo!\n");
    return 0;
  }

  for(i = 0; !feof(arch); i++) {
    fscanf(arch, "%d/%d/%d%*r", &consumidores[i].data.dia, &consumidores[i].data.mes, &consumidores[i].data.ano);
    fscanf(arch,"%[^\n]%*r", buffer);
    consumidores[i].nome_g = malloc(strlen(buffer) + 1);
    strcpy(consumidores[i].nome_g, buffer);
    fscanf(arch, "%*s %d%*r", &consumidores[i].mesa);
    fscanf(arch, "%d:%d", &consumidores[i].entrada.hora, &consumidores[i].entrada.min);
    fscanf(arch, "%d:%d%*r", &consumidores[i].saida.hora, &consumidores[i].saida.min);
    fscanf(arch, "%d%*r", &consumidores[i].qnt_pessoas);

    consumidores[i].vet = (s_consumo *)malloc(sizeof(s_consumo) * MAXC);
    lerConsumo(arch, consumidores[i].vet, &consumidores[i].tam_vet);
    //printf("numero de consumos = %d\n", consumidores[i].tam_vet);
    consumidores[i].vet = (s_consumo *)realloc(consumidores[i].vet, sizeof(s_consumo) * consumidores[i].tam_vet);
  printf("Fim da pesssoa num%d", i);
  }
  return i;
}

void printAll (s_total *v, int t) {
  int i, j;
  for(i = 0; i < t; i++) {
    printf("Ano = (%d/%d/%d)\n", v[i].data.dia, v[i].data.mes, v[i].data.ano);
    printf("Nome do garçom = (%s)\n", v[i].nome_g);
    printf("Mesa = (%d)\n", v[i].mesa);
    printf("Hora entrada = (%d:%d)\n", v[i].entrada.hora, v[i].entrada.min);
    printf("Hora saída = (%d:%d)\n", v[i].saida.hora, v[i].saida.min);
    printf("Pessoas na mesa = (%d)\n", v[i].qnt_pessoas);

    for(j = 0; j < v[i].tam_vet; j++) {
      printf("---------------\n");
      printf("item = %s\n", v[i].vet[i].item);
      printf("quantidade = %d\n", v[i].vet[i].qnt);
      printf("preço = %.2f\n", v[i].vet[i].preco);
    }
  }
}

int main (int argc, char *argv[]) {
  s_total *vetor;
  int consumidores;
  vetor = (s_total *)malloc(sizeof(s_total) * MAXCONSUMIDORES);
  printf("Num total de consumidores = %d", consumidores);
  consumidores = leitura(vetor);
  vetor = (s_total *)realloc(vetor, consumidores * sizeof(s_total));
  printAll(vetor, consumidores);
//  free()
  return 0;
}
