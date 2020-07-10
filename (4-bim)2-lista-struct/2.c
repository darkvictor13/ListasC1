#include <stdio.h>
#include <stdlib.h>

#define MAX_A 1000


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
  int i, aux[10], tam_aux;
  char separador;
  FILE *arch = fopen(nome_arch, "r");
  if (arch == NULL) {
    return 0;
  }

  for(i = 0; !feof(arch); i++) {
    vet[i] = malloc(sizeof(S_aposta));
    separador = ' ';
    for(tam_aux = 0; separador == ' '; tam_aux++) {
      fscanf(arch, "%d%c", aux + tam_aux, &separador);
      if (separador == ' ') {
        printf("Achei um espaço\n");
      }
      if (separador == '\r') {
        printf("Achei o retorno de carro\n");  
      }
      if (separador == '\n') {
        printf("Achei o fim da linha\n");  
        fscanf(arch, "%*r");
      }
    }
//    fscanf(arch, "%c", &separador);
//    printf("Depois do n tem = [%d]", separador);
    printf("%d Aposta = ", i);
    prinVet(aux, tam_aux);
    vet[i]->aposta = malloc(tam_aux * sizeof(int));
    copiaVet(vet[i]->aposta, aux, tam_aux);
    vet[i]->tam_aposta = tam_aux;
  }

  return i;
}

int main (int argc, char *argv[]) {
  int resultado[6];

  S_aposta **apostadores;
  int num_apostadores;

  apostadores = malloc(MAX_A * sizeof(S_aposta*));
  printf("Fiz o malloc");

	lerVet(resultado, 6);
  printf("resultado = ");
  prinVet(resultado, 6);
	num_apostadores = lerApostas(apostadores, argv[1]);

  apostadores = realloc(apostadores, num_apostadores * sizeof(S_aposta*));
  printf("Fiz o realloc");

	//printf("%d\n%d\n%d\n%d\n%d\n%d\n", apostadores[0]->aposta[0], apostadores[0]->aposta[1], apostadores[0]->aposta[2], apostadores[0]->aposta[3],apostadores[0]->aposta[4],apostadores[0]->aposta[5]);

  prinVet(apostadores[0]->aposta, apostadores[0]->tam_aposta);
	return 0;
}
