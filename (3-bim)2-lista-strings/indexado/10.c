#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXT 100

int caracterEspecial (char x) {
  char ref[] = "@#$%&−+<> ";

  for(int i = 0; ref[i]; i++) {
    if (x == ref[i]) {
      return 1;
    }
  } 
  return 0;
}

int segurancaDaSenha (char s[]) {
  int tam, maiusc, minusc, num, especial = 0;

  if(7 < strlen(s)) {
    tam = 20;
  }

  for(int i = 0; s[i]; i++) {
    if (islower(s[i])) {
      minusc = 20;
    }else if (isupper(s[i])) {
      maiusc = 20;
    }else if (isdigit(s[i])) {
      num = 20;
    }else if (caracterEspecial(s[i])) {
      especial = 20;
    }
  } 
  return tam + maiusc + minusc + num + especial;
}

int main () {
  char senha[MAXT];
  int casos;
  for (scanf("%d ",&casos); casos > 0; casos--) {
    scanf("%[^\n]%*c",senha);
    printf("%d\n",segurancaDaSenha(senha));
  }
  return 0;
}
