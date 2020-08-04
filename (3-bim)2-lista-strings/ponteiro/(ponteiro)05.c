#include <stdio.h>
#include <string.h>

void vaiUmPFrente (char *dest, char *org) {
  char guarda_1_char = *org;

  for (org++; *org; org++, dest++) {
    *dest = *org;
  }
  *dest = guarda_1_char;
  *(dest + 1) = '\0';
}

int main () {
  char str1[50], str2[50];
  int casos;

  for (scanf("%d%*c", &casos); casos > 0; casos--) {
    scanf("%[^\n]%*c", str1);
    vaiUmPFrente(str2, str1);
    printf("[%s]",  str2);
  }

  scanf("%[^\n]%*c", str1);
  printf("[%s]\n", str1);

  vaiUmPFrente(str2, str1);
  printf("[%s]\n", str2);
  return 0;
}
