

#include <stdio.h>
#include <stdlib.h>

int* uniao(int *v1, int n1, int *v2, int n2){//une dois vetores em um terceiro vetor

	int soma = n1 + n2;
	int i=0, j=0;
	int *v3 = (int *) malloc(soma * sizeof(int));


	for(i = 0; i < n1; i++){
		*(v3+i) = *(v1+i);
	}
	for(i = n1, j=0; i < soma; i++, j++){
		*(v3+i) = *(v2+j);
	}

	return v3;
}

int main(){
	const int n1 = 3; //alterar este valor altera o tamanho do vetor
	const int n2 = 3; //alterar este valor altera o tamanho do vetor

	int v1[n1], v2[n2];
	int *v3 = 0;
	int cont = n1+n2;//para imprimir os valores


	for(int i=0; i<n1; i++){
		printf("Digite os valores para o vetor 1: ");
		scanf("%d", (v1+i));
	}

	for(int i=0; i<n2; i++){
		printf("Digite os valores para o vetor 2: ");
		scanf("%d", (v2+i));
	}

	v3 = uniao(v1, n1, v2, n2);

	for(int i=0; i<cont; i++){
		printf("Valor: %d\n", *(v3+i));
		printf("Indice: %d\n", i);
		printf("Endereço de memória: %p\n", v3+i);
	}

	free(v3);

}
