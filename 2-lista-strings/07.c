#include <stdio.h>
#include <string.h>

int contaChar(char *str,char x) {
  int count;
  for (count = 0; *str; str++) {
    if (*str == x) {
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
    printf("%d\n",contaChar(str,parametro));
  }
  return 0;
}