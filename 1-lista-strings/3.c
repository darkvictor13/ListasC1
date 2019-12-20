#include <stdio.h>
#include <string.h>
#include <ctype.h>

void achaPrimeiraPalavra(char dest[], char org[]) {
  while (!isalnum(*org)) {
    org++;
  }

  for (; !isspace(*org); org++, dest++) { //*org != ' '
    *dest = *org;
  }
  *dest = '\0';
}

int main () {
  char str[51], palavra[11];

  printf("Entre com uma palavra : ");
  scanf("%[^\n]%*c", str);

  while (strcmp(str, "fim")) {
    achaPrimeiraPalavra(palavra, str);
    printf("A primeira palavra eh = [%s]\n", palavra);
    printf("Entre com uma palavra (fim mata o programa): ");
    scanf("%[^\n]%*c", str);
  }
  return 0;
}