#include <stdio.h>
#include <string.h>

#define maxt 51

void tiraEspacosDocomeco(char dest[],char org[]) {
  while (*org == ' ') {
    org++;
  }
  strcpy(dest,org);
}

int main () {
  char print[maxt],scan[maxt];

  scanf("%[^\n]%*c",scan);

  while (strcmp(scan,"fim")) {
    tiraEspacosDocomeco(print,scan);
    printf("%s\n",print);
    scanf("%[^\n]%*c",scan);
  }
  return 0;
}