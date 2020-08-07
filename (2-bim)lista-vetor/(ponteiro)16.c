#include <stdio.h>


void le2VetsAoMesmoTempo(int *v1, int *v2, int *t) {
  int *fim;
  scanf("%d", t);
  
  for (fim = (v1 + (*t)); v1 < fim; v1++, v2++) {
    scanf("%d %d", v1, v2);
  }
}

void intercalandoVets(int *dest, int *v1, int *v2, int t) {
	for(int *fim = (v1 + t); v1 < fim; v1++, v2++){
		*dest++ = *v1;
		*dest++ = *v2;
	}
}

void printVet(int v[], int t) {
  for (int *fim = (v + t); v < fim; v++) {
    printf("%d\n", *v);
  }
}

int main (){
	
	return 0;
}
