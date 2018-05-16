/*Implementar as funções de inserção, remoção e impressão de produtos numa lista duplamente
encadeada e utilizando sentinela(cabeça de lista).*/
/*autor: Jóvio L. Giacomolli*/
/*Data 27/04/2018*/

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
  struct nodo *ant;
} tp_nodo;

typedef struct lista{//cabeça da lista
  int n_itens;
  tp_nodo *first;
  tp_nodo *last;
} tp_lista;

tp_lista* inicializa(tp_lista *l){
  l->first = NULL;
  l->last = NULL;
  l->n_itens = 0;
  return l;//opcional
}

tp_lista* insere(tp_lista* l){ //insere os produtos na lista
    tp_nodo *novo = (tp_nodo *) malloc (sizeof(tp_nodo));

    printf("Digite o código do produto: ");
    scanf("%d", &novo->produto.codigo);
    getchar();
    printf("Digite o nome do produto: ");
    fgets(novo->produto.nome, 30, stdin);
    printf("Digite o valor do produto: ");
    scanf("%f", &novo->produto.preco);

    if(l->n_itens == 0){//insere no inicio da lista quando não houver
      novo->prox = NULL;
      novo->ant = NULL;
      l->first = novo;
      l->last = novo;
      l->n_itens++;
    } else{ //insere se já possui algum elemento
      l->last->prox = novo;
      novo->ant = l->last;
      l->last = novo;
      l->n_itens++;
    }
}

tp_lista* exclui(tp_lista* l, int n){
  tp_nodo* atual = l->first; //nodo recebe first sendo este o endereço do primeiro elemento
  tp_nodo* anterior = NULL;

  while (atual != NULL && atual->produto.codigo != n) {
    anterior = atual;
    atual = atual->prox;
}
  //se não achar o código do produto
  if(atual == NULL){
    printf("\nProduto não encontrado!\n\n");
    return l;
  }
  //retira se tiver somente um produto
  else if(anterior == NULL && atual->prox == NULL){
    l->first = NULL;
    l->last = NULL;
    printf("\nÚnico Produto Excluido!\n\n");
    l->n_itens--;
    return l;
  }
  //retira o produto do inicio da lista
  else if(anterior == NULL){
    l->first = l->first->prox;
    l->first->ant = NULL;
    printf("\nPrimeiro Produto Excluído!\n\n");
    l->n_itens--;
    return l;
  }
  //retira o produto se o este for o último
  else if(atual->prox == NULL){
    l->last = l->last->ant;
    l->last->prox = NULL;
    printf("\nÚltimo Produto Excluído!\n\n");
    l->n_itens--;
    return l;
  }
  //retira o produto do meio da lista
  else{
    anterior->prox = atual->prox;
    atual = l->first;
    printf("\nProduto no meio da lista Excluído!\n\n");
    l->n_itens--;
    return l;
  }
}

tp_lista* imprime(tp_lista* l){
  tp_nodo *aux = l->first;//recebe primeiro endereço da lista

  if(aux == NULL){
    printf("\nNenhum Produto na Lista!\n");
  } else {
      while (aux != NULL) {
        printf("\nCódigo: %d\n", aux->produto.codigo);
        printf("Produto: %s", aux->produto.nome);
        printf("Preço: R$ %.2lf\n", aux->produto.preco);
        aux = aux->prox;//proximo endereço
    }
  }
  printf("\n");
}

int main(){
  tp_lista* no = (tp_lista *) malloc(sizeof(tp_lista));
  int cod_prod;
  int op;

  no = inicializa(no); //inicializa a lista

  do {
    printf("\t\tMENU\n");
    printf("1 - Inserir Produtos na Lista\n");
    printf("2 - Excluir Produtos da Lista\n");
    printf("3 - Imprimir Produtos\n");
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
      printf("\nOpção Inválida!\n\n");
      break;
    }

  } while(op != 0);

  free(no);
}
