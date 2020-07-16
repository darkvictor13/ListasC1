#include <stdio.h>
#include <string.h>

int contaParenteses (char str[]) {
  int aux, i;

  if (str[0] == ')') {
    return 0;
  }

  for(i = 0, aux = 1; str[i]; i++) {
    if(str[i] == '(') {
      aux++;
    }else {
      aux--;
    }
  } 

  if (aux == 1) return 1;
  return 0;
}

int main () {
  char str[101];

  scanf("%[^\n]%*c", str);
  while (strcmp(str,"fim")) {
    if(contaParenteses(str)) {
      printf("sim\n");
    }else {
      printf("nao\n");
    }
    scanf("%[^\n]%*c",str);
  }
  return 0;
}
