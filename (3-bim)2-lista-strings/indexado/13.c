#include <stdio.h>
#include <string.h>

#define MAXT 51

void copiaReferencia (char dest[], char ref[]) {
  for(int i = 0; ref[i]; i++) {
    dest[i] = ref[i];
  } 
}

void colocaReferencia (char dest[], char src[], char ref[]) {
  int i, j, aux, tam_ref = strlen(ref);

  for(i = j = aux = 0; src[i]; i++) {
    if (src[i] != '>') {
      dest[j++] = src[i];
    }else {
      aux = 1;
      copiaReferencia(dest + j, ref);
      j += tam_ref;
    }
  }

  if (!aux) {
    j += tam_ref;
    copiaReferencia(dest + j, ref);
  }

  dest[j] = 0;
}

int main () {
  
  char referencia[MAXT],entrada[MAXT],print[MAXT];

  scanf("%[^\n]%*c",referencia);
  scanf("%[^\n]%*c",entrada);

  while (strcmp (entrada,"fim")) {
    colocaReferencia(print,entrada,referencia);
    printf("[%s]\n",print);
    scanf("%[^\n]%*c",entrada);
  }
  return 0;
}
