#include <stdio.h>
#include <string.h>

#define maxt 51

int conta_parenteses (char *str) {
  int abre,fecha;

  if (*(str++) == ')') {
    return 0;
  }

  for (abre = 1,fecha = 0; *str; str++) {
    if (*str == ')') {
      fecha++;
    }else {
      abre++;
    }
  }

  return abre == fecha;
}

int main () {
  char str[maxt];

  scanf("%[^\n]%*c",str);

  while (strcmp(str,"fim")) {
    if(conta_parenteses(str)) {
      printf("sim\n");
    }else {
      printf("nao\n");
    }
    
    scanf("%[^\n]%*c",str);
  }
  return 0;
}