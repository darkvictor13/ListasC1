#include <stdio.h>
#include <string.h>

void vaiUmPFrente(char *dest,char *org) {
  char *p_dest = dest;
  char guarda_1_char = *org;

  org++;

  for (; *org; org++,dest++) {
    *dest = *org ;
  }
  *dest = guarda_1_char;
  dest++;
  *dest = '\0';
}

int main () {
  char str1[50],str2[50];

  scanf("%[^\n]%*c",str1);
  printf("[%s]\n",str1);

  vaiUmPFrente(str2,str1);
  printf("[%s]\n",str2);
  return 0;
}