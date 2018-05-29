
//Programa que ordena os vetores em ordem crescente através de ponteiros
/*autor: Jóvio L. Giacomolli*/
/*Data 29/05/2018*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int tam;
	int *vetor;
	int aux = 0;
	
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &tam);

	vetor = (int *) malloc(tam * sizeof(int));

	if(vetor == NULL){
		printf("Memória excedida!!\n");
         break;
	}


	for(int i = 0; i < tam; i++){
		printf("Digite um numero: ");
		scanf("%d", vetor+i);		
	}

	for(int i = 0; i < tam; i++){
		for(int j = 0; j < tam; j++){
			if(*(vetor+i) < (*(vetor+j))){
				aux = *(vetor+i);
				*(vetor+i) = *(vetor+j);
				*(vetor+j) = aux;
			}
		}
	}

	for (int i = 0; i < tam; i++){
		printf("%d\n", *(vetor+i));

	}

		free(vetor);
		vetor = NULL;
}
