#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define RELAT_PROD "produtos.txt"
#define PROD_ORDENADO "produtos2.txt"
#define MAXN 51
#define MAXC 100
#define MAXCONSUMIDORES 1000

/*---------------------------------
   Structs que guardam os valores
   lidos no arquivo
---------------------------------*/

// uma struct para armazenar o dia em que foi feita as entradas
typedef struct {
  int dia, mes, ano;
}s_data;

// vai ser usada para guardar a hora
//de entrada e saída dos clientes
typedef struct {
  int hora, min;
}s_hora;

// o consumo de uma mesa
typedef struct {
  char *item;
  int qnt;
  float preco;
}s_consumo;

// todas as informações sobre o consumo
typedef struct {
  s_hora entrada, saida;
  s_consumo *vet;
  int tam_vet;
  char *nome_g;
  int mesa, qnt_pessoas;
}s_entrada;

/*---------------------------------
  Structs utilizadas para
  armazenar dados úteis
  para os cálculos
---------------------------------*/

// informações sobre um produto especifico
typedef struct {
  char *nome;
  unsigned int qnt_vendida;
}s_produto;

typedef struct {
  s_produto *vet;
  int tam;
}s_vetor_produtos;

typedef struct {
  char *nome_do_garcom;
  int total_de_vendas;
}s_garcom;

typedef struct {
  s_garcom *vet;
  int tam;
}s_vetor_garcons;

int achaCaracter (char x, char str[]) {
  for(int i = 0; str[i]; i++) {
    if (str[i] == x) {
      return 1;
    }
  }
  // não encontrou o carácter que procuramos
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
  *dest = 0;
}

/*
  Funções para ler o arquivo
*/

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

void ler1Struct (FILE *arch, s_entrada *s) {
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

int leitura (s_entrada *consumidores, s_data *data, char *fn) {
  int i;
  FILE *arch = fopen(fn, "r");
  if (arch == NULL) {
    printf("Falha na leitura do arquivo!\n");
    printf("Você deve ter passado o nome errado chefia\n");
    return 0;
  }

  fscanf(arch, "%d/%d/%d%*r", &data->dia, &data->mes, &data->ano);
  for(i = 0; !feof(arch); i++) {
    ler1Struct(arch, consumidores + i);
  }
  return i;
}

void liberaMemoriaDaEntrada (s_entrada *v, int tam) {
  for(int i = 0; i < tam; i++) {
    
  }
}

void printAll (s_data data, s_entrada *v, int t) {
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

int itemApareceu (s_vetor_produtos *p, char *nome_item) {
  for(int i = 0; i < p->tam; i++) {
    if (!strcmp(nome_item, p->vet[i].nome)) {
      //retorna o índice em que apareceu o item igual;
      return i;
    }
  }
  // -1 indica que não encontrou o item nesse vetor;
  return -1;
}

void estatisticaProdutos (s_entrada *v, int tam, s_vetor_produtos *p) {
  // i_entrada esta relacionado ao vetor de entradas
  // i_produto esta relacionado ao vetor de produtos
  // i_apareceu indica o índice em que um item apareceu no vetor de produtos
  int i_entrada, i_produto, i_apareceu;

  // zera p tamanho do vetor de todos os produtos
  p->tam = 0;

  for(i_entrada = 0; i_entrada < tam; i_entrada++) {
    for(i_produto = 0; i_produto < v[i_entrada].tam_vet; i_produto++) {
      i_apareceu = itemApareceu(p, v[i_entrada].vet[i_produto].item);
      if (i_apareceu == -1) {
        p->vet[p->tam].nome = malloc(strlen(v[i_entrada].vet[i_produto].item));
        p->vet[p->tam].qnt_vendida = v[i_entrada].vet[i_produto].qnt;
        strcpy(p->vet[p->tam].nome, v[i_entrada].vet[i_produto].item);
        p->tam++;
      }else {
        p->vet[i_apareceu].qnt_vendida += v[i_entrada].vet[i_produto].qnt;
      }
    }
  }
}

s_produto* localDoMaiorProduto (s_produto *inicio, s_produto *fim) {
  s_produto *maior = inicio;

  for(inicio++; inicio <= fim; inicio++) {
    if (maior->qnt_vendida < inicio->qnt_vendida) {
      maior = inicio;
    }
  }

  return maior;
}

void trocaProdutos (s_produto *a, s_produto *b) {
  s_produto aux;
  aux = *a;
  *a = *b;
  *b = aux;
}

void printNaTelaProdutos (s_vetor_produtos *p) {
  for(int i = 0; i < p->tam; i++) {
    printf("Produto num %d\n", i + 1);
    printf("==========================\n");
    printf("Produto = %s\n", p->vet[i].nome);
    printf("Quantidade vendida = %d\n", p->vet[i].qnt_vendida);
    printf("==========================\n\n");
  }
}

void ordenaProdutos (s_vetor_produtos *p) {
  int i;
  for(i = 0; i < p->tam; i++) {
    trocaProdutos(p->vet+i, localDoMaiorProduto(p->vet + i, p->vet + p->tam - 1));
    //printNaTelaProdutos(p);
  }
}

void estatiticaGarcons (s_entrada *vet, int tam_vet, s_vetor_garcons *g) {
  //to do
}

/*------------------------------------
  Seção de funções que facilitam para
  Escrever nos arquivos
------------------------------------*/

void separador (FILE *a, int n, char caracter) {
  // n = numero de caracteres que deseja usar para separar 
  for(int i = 0; i < n; i++) {
    fprintf(a, "%c", caracter);
  }
  fprintf(a, "\n");
}

void relatProdutos (s_vetor_produtos *p) {
  FILE *arch = fopen(RELAT_PROD, "w");
  for(int i = 0; i < p->tam; i++) {
    fprintf(arch, "Produto num %d\n", i + 1);
    separador(arch, 26, '=');
    fprintf(arch, "Produto = %s\n", p->vet[i].nome);
    fprintf(arch, "Quantidade vendida = %d\n", p->vet[i].qnt_vendida);
    separador(arch, 26, '=');
    fprintf(arch, "\n");
  }
}

void relatProdutosOrdenado (s_vetor_produtos *p) {
  FILE *arch = fopen(PROD_ORDENADO , "w");
  for(int i = 0; i < p->tam; i++) {
    fprintf(arch, "Produto num %d\n", i + 1);
    separador(arch, 26, '=');
    fprintf(arch, "Produto = %s\n", p->vet[i].nome);
    fprintf(arch, "Quantidade vendida = %d\n", p->vet[i].qnt_vendida);
    separador(arch, 26, '=');
    fprintf(arch, "\n");
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
    printf("Por favor insira o nome aqui -> ");
    scanf("%[^\n]%*c", nome_arch);
    if (!achaCaracter('.', nome_arch)) {
      char aux[4];
      aux[1] = 0;
      printf("Qual a extensão desse aquivo que você me passou?\n"); 
      printf("Ele é um txt? Um log? Ou o que?\n");
      printf("Entre com a extensão do arquivo -> ");
      scanf("%[^\n]%*c", aux);
      if (aux[0] != '\n') {
        if(aux[0] == '.') {
          strcat(nome_arch, aux);
        }else {
          adicionaExtensao(nome_arch, aux);
        }
      }
    }
    nome_arch = realloc(nome_arch, strlen(nome_arch) + 1);
  }

  s_entrada *vetor;
  int consumidores;

  s_data data;
  s_vetor_produtos p;
  s_vetor_garcons g;

  vetor = (s_entrada *)malloc(sizeof(s_entrada) * MAXCONSUMIDORES);
  consumidores = leitura(vetor, &data, nome_arch);

  free(nome_arch);

  vetor = (s_entrada *)realloc(vetor, sizeof(s_entrada) * consumidores);
  p.vet = (s_produto *)malloc(sizeof(s_produto) * MAXN);
  estatisticaProdutos(vetor, consumidores, &p);
  p.vet = (s_produto *)realloc(p.vet, sizeof(s_produto) * p.tam);

  relatProdutos(&p);
  ordenaProdutos(&p);
  relatProdutosOrdenado(&p);

  g.vet = (s_garcom *)malloc(sizeof(s_garcom) * MAXN);
  estatiticaGarcons(vetor, consumidores, &g);
  g.vet = (s_garcom *)realloc(g.vet, sizeof(s_garcom) * g.tam);
  return 0;
}
