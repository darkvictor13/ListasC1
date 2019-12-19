#include <stdio.h>
#include <string.h>

#define maxt 51

void troca(int *a,int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

void intercalaAsStr(char dest[],char org1[],char org2[]) {
  char *p;

  for (; *org1 && *org2; org1++, org2++) {
    *(dest++) = *org1;
    *(dest++) = *org2;
  }
  if (*org1) {
    p = org1;
  }else {
    p = org2;
  }
  strcpy(dest,p);
}

int main () {
  char str1[maxt],str2[maxt],fusao[101];
  int casos;

  for (scanf("%d%*c",&casos); casos > 0; casos--) {
    scanf("%s %s",str1,str2);
    intercalaAsStr(fusao,str1,str2);
    printf("[%s]\n",fusao);
  }
  return 0;
}