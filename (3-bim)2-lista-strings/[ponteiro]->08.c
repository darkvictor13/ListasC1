#include <stdio.h>
#include <string.h>

int contaCharMaiuscEMinusc(char *str,char x) {
  int count;
  char parametro;

  if (islower(x)) {
    parametro = toupper(x);
  }else {
    parametro = tolower(x);
  }

  for (count = 0; *str; str++) {
    if (*str == x || *str == parametro) {
      count++;
    }
  }
  return count;
}

int main () {
  char str[50],parametro;
  int i;

  for (scanf("%d %c%*c",&i,&parametro); i > 0; i--) {
    gets(str);
    printf("%d\n",contaCharMaiuscEMinusc(str,parametro));
  }
  return 0;
}