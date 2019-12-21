#include <stdio.h>

void todas_consoantes () {
  int i;
  for (i = 'b'; i <= 'z'; i++) {
    if (i == 'e' || i == 'i' || i == 'o' || i == 'u') {
      i ++;
      printf("%c\n", i);
    }else
    printf("%c\n", i);
    }
}

int main () {
  int x;
  todas_consoantes ();
  return 0;
}
