#include <stdio.h>

#define MAX_T 100
#define MIN_T 10

int achaCaracter (char x, char str[]) {
  for(int i = 0; str[i]; i++) {
    if (str[i] == x) {
      return 1;
    }
  }
  return 0;
}

void excluiRef (char ref[], char dest[], char src[]) {
  int i, j;
  for(i = j = 0; src[i]; i++) {
    if (!achaCaracter(src[i], ref)) {
      dest[j++] = src[i];
    }
  } 
  dest[j] = '\0';
}

int main () {
  int casos;
  char ref[MIN_T], entrada[MAX_T], saida[MAX_T];
  for(scanf("%d %[^\n]%*c", &casos, ref); casos > 0; casos--) {
    scanf("%[^\n]%*c", entrada);
    excluiRef(ref, saida, entrada);
    printf("[%s]\n", saida);
  }
  return 0;
}
