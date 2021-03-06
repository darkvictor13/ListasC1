#include <stdio.h>
#include <ctype.h>

#define MAXT 100

int contaChar (char str[], char x) {
  int resposta, i;
  char aux;

  if(isupper(x)) {
    aux = tolower(x);
  }else {
    aux = toupper(x);
  }

  for(i = resposta = 0; str[i]; i++) {
    if (str[i] == x || str[i] == aux) {
      resposta++;
    }
  } 
  return resposta;
}

int main () {
  int casos;
  char ref, str[MAXT];
  for(scanf("%d %c%*c", &casos, &ref); casos > 0; casos--) {
    scanf("%[^\n]%*c", str);
    printf("%d\n", contaChar(str, ref));
  }
  return 0;
}
