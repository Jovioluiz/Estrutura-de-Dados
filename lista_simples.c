/*Implementar as funções de inserção, remoção e impressão de produtos numa lista simplesmente
encadeada.*/
/*O programa possui um menu para interação com o usuário com quatro opções que deve ser
apresentado até o momento em que o usuário digita 0 (zero).
OPÇÕES DO MENU:
(1) Para inserir um produto na lista.
(2) Para excluir um elemento da lista.
(3) Para listar todos os campos dos elementos da lista.
(0) Para finalizar o programa*/

/*autor: Jóvio L. Giacomolli*/
/*Data: 13/04/2018*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 30

typedef struct produto{
  int codigo;
  char nome[TAM];
  float preco;
} tp_produto;

typedef struct nodo{
  tp_produto produto;
  struct nodo *prox;
} tp_nodo;

tp_nodo* insere(tp_nodo* l){ //insere os produtos na lista
    tp_nodo *novo = (tp_nodo *) malloc (sizeof(tp_nodo));
    printf("Digite o código do produto: ");
    scanf("%d", &novo->produto.codigo);
    getchar();
    printf("Digite o nome do produto: ");
    fgets(novo->produto.nome, 30, stdin);
    printf("Digite o valor do produto: ");
    scanf("%f", &novo->produto.preco);
    novo->prox = l;
    return novo;
}

tp_nodo* exclui(tp_nodo* l, int n){
  tp_nodo* ant = NULL;
  tp_nodo* atual = l;

  while (atual != NULL && atual->produto.codigo != n) {
    ant = atual;
    atual = atual->prox;
}

  if(atual == NULL){ //se não achar o elemento
    printf("\nProduto não encontrado!\n\n");
    return l;
  }
  if(ant == NULL){//retira o produto do inicio da lista
    l = atual->prox;
    printf("\nProduto Excluido!\n\n");
    return l;
  }
  else{ //retira do meio da lista
    ant->prox = atual->prox;
    printf("\nProduto Excluido!\n\n");
    return l;
  }
}

tp_nodo* imprime(tp_nodo* l){
  tp_nodo *aux;
  for(aux = l; aux != NULL; aux = aux->prox){
    printf("\nCódigo: %d\n", aux->produto.codigo);
    printf("Produto: %s", aux->produto.nome);
    printf("Preço: %.2f\n", aux->produto.preco);
  }
}

int main(){
  tp_nodo* no = NULL;
  int cod_prod;
  int op;

  do {
    printf("\t\tMENU\n");
    printf("1 - Inserir Produtos na Lista\n");
    printf("2 - Excluir Produtos da Lista\n");
    printf("3 - Imprimir Produtos\n");
    //printf("4 - Liberar lista\n");
    printf("0 - Sair\n");
    printf("Digite sua opção--> ");
    scanf("%d", &op);
    switch (op) {
      case 1:
      no = insere(no);
      break;
      case 2:
      printf("Digite o código do produto que quer excluir: ");
      scanf("%d", &cod_prod);
      no = exclui(no, cod_prod);
      break;
      case 3:
      imprime(no);
      break;
      case 0:
      break;
      default:
      printf("Opção Inválida!\n");
      break;
    }

  } while(op != 0);

  free(no);
}
