#include <stdio.h>

#define MAXT 100

int contaChar (char str[], char x) {
  int resposta, i;

  for(i = resposta = 0; str[i]; i++) {
    if (str[i] == x) {
      resposta++;
    }
  } 
  return resposta;
}

int verificaTodos (char ref[], char src[]) {
  int ocorrencias = 0;
  for(int i = 0; ref[i]; i++) {
    ocorrencias += contaChar(src, ref[i]);
  } 
  return ocorrencias;
}

int main () {
  int casos;
  char ref[MAXT], str[MAXT];
  for(scanf("%d %[^\n]%*c", &casos, ref); casos > 0; casos--) {
    scanf("%[^\n]%*c", str);
    printf("%d\n", verificaTodos(ref, str));
  }
  return 0;
}
