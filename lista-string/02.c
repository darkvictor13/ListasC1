#include <stdio.h>
#include <ctype.h>

#define max_tam 100

void maiuscMinusc (char *dest,char *org) {
  int count;

  for (count = 0; *org; org++,dest++,count++) {
    while (*org == ' ') {
      *dest = ' ';
      dest++;
      org++;
    }

    if (count % 2) {
      *dest = tolower (*org);
    }else {
      *dest = toupper (*org);
    }
  }
}

int main () {
  char entrada[max_tam],sentenca_dancante[max_tam];
  int casos;

  for (scanf("%d%*c",&casos); casos > 0; casos--) {
    scanf("%[^\n]%*c",entrada);
    maiuscMinusc(sentenca_dancante,entrada);
    printf("%s\n",sentenca_dancante);
  }
  return 0;
}