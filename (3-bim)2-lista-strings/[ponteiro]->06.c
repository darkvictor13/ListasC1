#include <stdio.h>
#include <string.h>

vai1PFrente(char dest[],char org[]) {
  int t = strlen(org);
  
  *dest = *(org + t - 1);

  for (dest++; *org; org++,dest++) {
    *dest = *org;
  }
  *(--dest) = 0;
}

int main () {
  char entrada[51],saida[51];int casos;

  for (scanf("%d%*c",&casos); casos > 0; casos--) {
    scanf("%[^\n]%*c",entrada);
    vai1PFrente(saida,entrada);
    printf("[%s]",saida);
  }
  return 0;
}