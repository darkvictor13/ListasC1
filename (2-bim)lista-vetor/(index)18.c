#include <stdio.h>

#define MAXT 100

void lerVetCompleto(int v[], int *t) {
  int i;
  scanf("%d", t);
  for(i = 0; i < (*t); i++) {
    scanf("%d", &v[i]);
  }
}

void intercalaVets(int v1[], int v2[], int r[], int t_menor) {
  int i;

  for(i = 0; i < t_menor; i++) {
    r[(i * 2)] = v1[i];
    r[(i * 2) + 1] = v2[i];
  }
}

void completaVet(int v[],int t_maior, int t_menor, int r[]) {
  int i_vet = t_menor;
  int i_resp = (t_menor * 2);

  while (i_vet < t_maior) {
    r[i_resp] = v[i_vet];
    i_resp++;
    i_vet++;
  }
  //tudo pode ser escrito em um for, mas fiz assim p ficar mais visivel
}

void printVet(int v[], int t) {
  for (int i = 0; i < t; i++) {
    printf("%d\n", v[i]);
  }
}

int main () {
  int src1[MAXT], src2[MAXT], resposta[MAXT * 2], tam1, tam2, tam_r;

  lerVetCompleto(src1, &tam1);
  lerVetCompleto(src2, &tam2);
  tam_r = tam1 + tam2;

  if (tam1 == tam2) {
    intercalaVets(src1, src2, resposta, tam2);//pode usar tam1 tanto faz
  }else if (tam1 > tam2) {
    intercalaVets(src1, src2, resposta, tam2);
    completaVet(src1, tam1, tam2, resposta);
  }else {
    intercalaVets(src1, src2, resposta, tam1);
    completaVet(src2, tam2, tam1, resposta);
  }

  printVet(resposta, tam_r);

  return 0;
}