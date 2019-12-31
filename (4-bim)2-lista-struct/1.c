#include <stdio.h>
#include <stdlib.h>

#define MAXN 10
#define MAXA 1000

typedef struct {
  int *vet;
  int tam;
  int acerto;
}apostador;

typedef struct {
  apostador *v;
  int t;
}vet_apostadores;

void lerDadosArquivo(FILE *a,apostador *p) {
  int i;
  char aux;

  fscanf(a, "%d%c", &p->vet[i], &aux);
  for (i = 0; aux == ' ' && !feof(a); i++) {
    fscanf(a, "%d%c", &p->vet[i], &aux);
  }
  p->tam = i;
}

int lerTodasAsApostas (char *nome, vet_apostadores *vet) {
  int i;
  apostador aux;
  FILE *arch;

  aux.vet = malloc(10 * sizeof(int));

  if (arch = fopen(nome, "r") == EOF){ 
    printf("falhou ao abrir\n");
    return 0;
  }
  printf("entrei no for\n");
  for (i = 0; !feof(arch); i++) {
    lerDadosArquivo(arch, &aux);
    printf("consegui ler %d", i);
    vet->v = malloc(aux.tam * sizeof(int));
    *(vet->v) = aux;
    printf("consegui salvar o dado %d\n", i);
  }
  vet->t = i;
  free (aux.vet);
  fclose(arch);
  return 1;
}

int main () {
  vet_apostadores vetor;
  vetor.v = malloc (MAXA * sizeof(apostador));
  if (!lerTodasAsApostas("aposta.txt", &vetor)) return 0;
  vetor.v = realloc(vetor.v, vetor.t * sizeof(apostador));
  return 0;
}