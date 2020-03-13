#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 20
#define MAXC 100

typedef struct {
	float *ipva;
	double preco;
	char *categoria;
	char *modelo;
}veiculo;

void lerAliquotas (float *a[], int *ta) {
	int i, j;
	char resposta;
	printf("Insira as aliquotas de IPVA dessa maneira\n");
	printf("1 coluna carros\n2 coluna Onibus\n");
	printf("3 coluna Motos\n4 Coluna Caminhonetes\n\n");

	printf("Entendido?\nSe deseja prosseguir digite (Y) : ");
	scanf("%c", &resposta);
	
	if (resposta == 'Y' || resposta == 'y') {
		printf("Por favor insira o numero de Estados que serao analisados : ");
		scanf("%d", ta);
		for (i = 0; i < (*ta); i++) {
			printf("Entre com as 4 aliquotas do estado num %d : ", (i + 1));
			a[i] = malloc(4 * sizeof(float));
			for (j = 0; j < 4; j++) {
				scanf("%f", &a[i][j]);
			}
		}	
	}
}

void printaMatriz(float *a[], int ta) {
	int i, j;
	for(i = 0; i < ta; i++) {
		for (j = 0; j < 3; j++) {
			printf("%f ", a[i][j]);
		}
		printf("%f\n", a[i][j]);
	}
}

int load (char *nome_arq, veiculo *v[], int *tv) {
	char temp[MAXN];
	int i;
	FILE *arch = fopen(nome_arq, "r");
	if (arch == NULL) return 0;

	for (i = 0; !feof(arch); i++) {
		v[i] = malloc(sizeof(veiculo));

		fscanf(arch, "%[^\n]%*r", temp);
		v[i]->modelo = malloc(strlen(temp));
		strcpy(v[i]->modelo, temp);

		fscanf(arch, "%[^\n]%*r", temp);
		v[i]->categoria = malloc(strlen(temp));
		strcpy(v[i]->categoria, temp);

		fscanf(arch, "%lf%*r", &v[i]->preco);
	}
	fclose(arch);
	*tv = i;
	return 1;
}

int descobreColuna(char *str) {
	if (strcmp(str, "CARRO")) return 0;
	else if (strcmp(str, "ONIBUS")) return 1;
	else if (strcmp(str, "MOTOCICLETA")) return 2;
	else if (strcmp(str, "CAMINHONETE")) return 3;
	else return -1;
}

void geraIpva(veiculo *v[], int tv, float *a[], int ta) {
	int count, i, j;
	for (count = 0; count < tv; count++) {
		j = descobreColuna(v[count]->categoria);
		v[count]->ipva = malloc(sizeof(float) * ta);
		for (i = 0; i < ta; i++) {
			v[count]->ipva[i] = (a[i][j] * v[count]->preco) / 100;
		}
	}
}

void printaDados(veiculo *v[], int t) {
	for (int i = 0; i < t; i++) {
		printf("Veiculo num (%d)\n", (i + 1));
		printf("Modelo : [%s]\n", v[i]->modelo);
		printf("Categoria : [%s]\n", v[i]->categoria);
		printf("Preco : [%.2lf]R$\n", v[i]->preco);
	}
}

void printaNCaracteres(FILE *a, char ch, int n) {
	for (int i = 0; i < n; i++) {
		fprintf(a, "%c", ch);
	}
}

void printaEstados(FILE *a,int n) {
	for(int i = 0; i < n; i++) {
		fprintf(a, "   Estado%d", i+1);
	}
}

void cabecalho(FILE *a, int tam_aliq) {
	printaNCaracteres(a, ' ', 15);
	fprintf(a, "TABELA DE IPVA POR ESTADO\n");
	printaNCaracteres(a, ' ', 20);
	printaEstados(a, tam_aliq);
	fprintf(a, "\n");
}

void printaIpva(FILE *a, veiculo x, int tam_aliq) {
	for(int i = 0; i < tam_aliq; i++) {
		fprintf(a, "%.2f ", x.ipva[i]);
	}
	fprintf(a, "\n");
}

void relat (char *nome_arq, veiculo *v[], int tv, int tam_aliq) {
	FILE *a = fopen(nome_arq, "w");

	cabecalho(a, tam_aliq);

	for(int i = 0; i < tv; i++) {
		fprintf(a, "%-23s", v[i]->modelo);
		printaIpva(a, *v[i], tam_aliq);
	}
}

int main (int argc, char *argv[]) {
	veiculo *vetor[MAXC];
	float *aliquotas[4];
	int na, nv;
	lerAliquotas(aliquotas, &na);
	//printaMatriz(aliquotas, na);
	if (!load(argv[1], vetor, &nv)) {
		printf("Nao foi possivel ler o arquivo!");
	}
	//printaDados(vetor, nv);
	relat(argv[2], vetor, nv, na);
	
	return 0;
}
