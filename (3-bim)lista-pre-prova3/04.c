#include <stdio.h>

#define MAXT 70

void fazPadrao (int m[][MAXT], int tam) {
  int i, j;
  for(i = 0; i < tam; i++) {
    for(j = 0; j < tam; j++) {
      m[i][j] = 3;
    }
    m[i][i] = 1; 
    m[i][tam - i - 1] = 2;
  }
}

void printaMatriz (int m[][MAXT],int t) {
  int i,j;

  for (i = 0; i < t; i++) {
    for (j = 0; j < t; j++) {
      printf ("%d",m[i][j]);
    }
    printf ("\n");
  }
}

int main () {
  int tam, matriz[MAXT][MAXT];
  while (scanf("%d", &tam) != EOF) {
    fazPadrao(matriz, tam);
    printaMatriz(matriz, tam);
  }
  return 0;
}
