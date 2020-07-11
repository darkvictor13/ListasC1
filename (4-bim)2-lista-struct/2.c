#include <stdio.h>
#include <stdlib.h>

#define MAX_A 1000
#define MAX_NUMS 10
#define TAM_R 6


typedef struct {
	int *aposta;
  int tam_aposta;
	int acertos;
}S_aposta;

void lerVet(int *v, int tam) {
	for(int i = 0; i < tam; i++) {
		scanf("%d", v + i);
	}
}

void copiaVet(int *v1, int *v2, int t) {
	for(int i = 0; i < t; i++) {
		v1[i] = v2[i];
	}
}

void prinVet (int *vet, int tam) {
  for(int i = 0; i < tam; i++) {
    printf("%d ", vet[i]);
  }
  printf("\n");
}

int lerApostas (S_aposta **vet, char *nome_arch) {
  int i, aux[MAX_NUMS], tam_aux;
  char separador;
  FILE *arch = fopen(nome_arch, "r");
  if (arch == NULL) {
    return 0;
  }

  for(i = 0; !feof(arch); i++) {
    vet[i] = malloc(sizeof(S_aposta));
    
    for(tam_aux = 0, separador = ' '; separador == ' '; tam_aux++) {
      fscanf(arch, "%d%c", aux + tam_aux, &separador);
    }
    fscanf(arch, "%*r");

    vet[i]->aposta = malloc(tam_aux * sizeof(int));
    copiaVet(vet[i]->aposta, aux, tam_aux);
    vet[i]->tam_aposta = tam_aux;
  }

  return i;
}

int numerosIguais(int *v1, int *v2, int tam_v1, int tam_v2) {
  int i, j, resposta;
  for(i = resposta = 0; i < tam_v1; i++) {
    for(j = 0; j < tam_v2; j++) {
      if (v1[i] == v2[j]) {
        resposta++;
        break;
      }
    }
  }
  return resposta;
}

void verificaAcertos (S_aposta **matriz, int *r, int tam_m) {
  int i_matriz;
  for(i_matriz = 0; i_matriz < tam_m; i_matriz++) {
    matriz[i_matriz]->acertos = numerosIguais(r, matriz[i_matriz]->aposta, TAM_R, matriz[i_matriz]->tam_aposta);
  }
}

void escreveVetNoArq (FILE *arch, int *vet, int tam) {
  int i;
  fprintf(arch, "{");
  for(i = 0, tam--; i < tam; i++) {
    fprintf(arch, "%02d ", vet[i]);
  }
  fprintf(arch, "%02d}", vet[i]);
}

void pulaLinhaRelat(FILE *arch) {
  fprintf(arch, "|");
  for(int i = 0; i < 58; i++) {
    fprintf(arch, "-");
  }
  fprintf(arch, "|\n");
}

void printaEspaco (FILE *arch, int n) {
  for(int i = 0; i < n; i++) {
    fprintf(arch, " ");
  }
}

void cabecalho (FILE *arch, int *r) {
  pulaLinhaRelat(arch);
  fprintf(arch, "|RESULTADO = ");
  escreveVetNoArq(arch, r, TAM_R);
  printaEspaco(arch, 27);
  fprintf(arch, "|\n");
  pulaLinhaRelat(arch);
  fprintf(arch, "|%10s|%37s|%9s|\n", "", "", "");
  fprintf(arch, "|%-10s|%-38s|%-9s|\n", "CANDIDATO", "NÚMEROS DA APOSTA", "ACERTOS");
  fprintf(arch, "|%10s|%37s|%9s|\n", "", "", "");
  pulaLinhaRelat(arch);
}

void EscreveRelat (char *nome_arch, int *r, S_aposta **m, int tam_m) {
  FILE *arch = fopen(nome_arch, "w");

  cabecalho(arch, r);

  for(int i = 0; i < tam_m; i++) {
    fprintf(arch, "|%3s%04d%3s|", "", i + 1, "");
    escreveVetNoArq(arch, m[i]->aposta, m[i]->tam_aposta);
    printaEspaco(arch, 36 - (m[i]->tam_aposta * 3));
    fprintf(arch, "|%4s%d%4s|\n", "", m[i]->acertos, "");
  }
}

void liberaMemoria (S_aposta **m, int t) {
  for(int i = 0; i < t; i++) {
    free(m[i]->aposta);
  }
  free(m);
}

int main (int argc, char *argv[]) {
  if (argc != 2) {
    printf("Você está usando o programa de forma errada!\n");
    printf("Por favor rode:\n");
    printf("[Nome do programa] [espaço em branco] [nome do arquivo]\n");
    return 0;
  }

  int resultado[TAM_R];
  S_aposta **apostadores;
  int num_apostadores;

  printf("Por favor entre com o resultado do concurso\n");
	lerVet(resultado, TAM_R);

  apostadores = malloc(MAX_A * sizeof(S_aposta*));
	num_apostadores = lerApostas(apostadores, argv[1]);
  apostadores = realloc(apostadores, num_apostadores * sizeof(S_aposta*));

  verificaAcertos(apostadores, resultado, num_apostadores);
  EscreveRelat("saida.txt", resultado, apostadores, num_apostadores);

  liberaMemoria(apostadores, num_apostadores);
	return 0;
}
