//includes e defines
//////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

#define MAX_A 1000
//////////////////////////////////

//variaveis globais
//////////////////////////////////
typedef struct {
	int *aposta;
	int acertos;
}S_aposta;

int resposta[6];

S_aposta *apostadores[MAX_A];
int num_apostadores;
//////////////////////////////////

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

int lerApostas (S_aposta *vet[MAX_A], int *tam, char *nome_arch) {
	FILE *arch = fopen(nome_arch, "r");
	int t, i, temp[10];
	char acha_fim;
	for (t = 0; !feof(arch); t++) {
		vet[t] = malloc(sizeof(S_aposta));
		for (i = 0; acha_fim == ' '; i++) {
			fscanf(arch, "%d%c", temp[i], acha_fim);
		}
		fscanf(arch, "%*r");
		vet[t]->aposta = malloc(sizeof(int) * i);
		copiaVet(vet[t]->aposta, temp, i);
	}
}

int main (int argc, char *argv[]) {
	lerVet(resposta, 6);
	lerApostas(apostadores, &num_apostadores, argv[1]);
	printf("%d\n%d\n%d\n%d\n%d\n%d\n", apostadores[0]->aposta[0], apostadores[0]->aposta[1], apostadores[0]->aposta[2], apostadores[0]->aposta[3],apostadores[0]->aposta[4],apostadores[0]->aposta[5]);
	//contaAcertos(resposta, apostadores, num_apostadores);
	//geraResposta(apostadores, num_apostadores, "Resposta.txt");
	return 0;
}
