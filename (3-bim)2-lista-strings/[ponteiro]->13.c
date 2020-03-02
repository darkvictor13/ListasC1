#include <stdio.h>
#include <string.h>

void colocaReferencia (char dest[],char org[],char ref[]) {
  int tam = strlen(ref),aux = 0;

  for (; *org; org++) {
    if (*org != '>') {
      
      *(dest++) = *org;
    }else {
      aux = 1;
      strncpy(dest,ref,tam);
      dest += tam;
    }
  }
  if (!aux) {
    strncpy(dest,ref,tam);
    dest += tam;
  }
  *dest = '\0';
}

int main () {
  char referencia[51],entrada[51],print[51];

  scanf("%[^\n]%*c",referencia);
  scanf("%[^\n]%*c",entrada);

  while (strcmp (entrada,"fim")) {
    colocaReferencia(print,entrada,referencia);
    printf("[%s]\n",print);
    scanf("%[^\n]%*c",entrada);
  }
  return 0;
}