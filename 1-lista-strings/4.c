#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXT 51
#define MAX1P 11

void achaPrimeiraPalavra(char dest[], char org[]) {
  while (!isalnum(*org)) {
    org++;
  }

  for (; !isspace(*org); org++, dest++) {
    *dest = *org;
  }
  *dest = '\0';
}

int contaRepeticoes(char *str, char *ref) {
  int count, tam_palavra = strlen(ref);
  char temp[tam_palavra];

  for (count = 0; *str; str++) {
    strncpy(temp, str, tam_palavra);
    if (!strcmp(temp, ref)) {
      count++;
    }
  }
  return count;
}

int main () {
  char entrada[MAXT], uma_palavra[MAX1P];
  int qnt_de_repeticoes;

  scanf("%[^\n]%*c", entrada);

  while (strcmp(entrada, "fim")) {
    achaPrimeiraPalavra(uma_palavra, entrada);
    qnt_de_repeticoes = contaRepeticoes(entrada, uma_palavra);
    printf("num de repeticoes = %d\n", qnt_de_repeticoes);
    scanf("%[^\n]%*c", entrada);
  }
  return 0;
}

