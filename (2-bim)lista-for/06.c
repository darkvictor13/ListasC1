#include <stdio.h>

void todasAsConsoantes () {
  char i;
  for (i = 'b'; i <= 'z'; i++) {
    if (i == 'e' || i == 'i' || i == 'o' || i == 'u') {
      i++;
    }
    printf("%c\n", i);
  }
}

int main () {
  todasAsConsoantes();
  return 0;
}
