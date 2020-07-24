#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define max_tam 51

void inverteStr(char dest[],char org[]) {
  int tam = strlen(org);
  
  dest += tam;
  *dest = '\0';
  dest--;

  for (; *org; org++,dest--) {
    *dest = *org;
  }
}

int main () {
  char origem[max_tam],destino[max_tam];
  int casos;

  for (scanf("%d%*c",&casos); casos > 0; casos--) {
    scanf("%[^\n]%*c",origem);
    inverteStr(destino,origem);
    printf("[%s]\n",destino);
  }

  return 0;
}
