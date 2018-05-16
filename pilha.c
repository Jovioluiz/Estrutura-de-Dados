/*Inicialmente é solicitado ao usuário quantos produtos serão inseridos na pilha. Lembre-se que além
da pilha, este valor lido anteriormente deve ser passado para as funções servindo de auxílio para
teste de pilha cheia ou vazia.
O programa possui um menu para interação com o usuário com quatro opções que deve ser
apresentado até o momento em que o usuário digita 0 (zero). OPÇÕES DO MENU:
(1) Para inserir um produto na pilha.
(2) Para excluir um elemento da pilha.
(3) Para listar todos os campos dos elementos da pilha.
(0) Para finalizar o programa.*/

/*autor: Jóvio L. Giacomolli*/
/*Data 12/04/2018*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct{
  int cod;
  char nome[MAX];
  float preco;
} tp_produto;

typedef struct _pilha{
  tp_produto *info;
  int topo;
}tp_pilha;

 int cheia(tp_pilha *c, int num){ //verifica se a pilha está cheia;
   if(c->topo == num-1){
     return 1;
   } else{
     return 0;
   }
 }

 int vazia(tp_pilha *v, int num){//verifica se a pilha está vazia
   if(v->topo == -1){
     return 1;
   } else{
     return 0;
   }
 }

 void empilhar(tp_pilha *i, int valor){ //insere um elemento na pilha

  if (cheia(i, valor)){
    printf("\nPilha Cheia!\n\n");

  } else{
        i->topo++;
        printf("Digite o codigo: ");
        scanf("%d", &(i->info+i->topo)->cod);
        getchar();
        printf("Digite o nome do produto: ");
        fgets((i->info+i->topo)->nome, 50, stdin);
        printf("Digite o preço: ");
        scanf("%f", &(i->info+i->topo)->preco);
    }
 }

 int desempilhar(tp_pilha *e, int valor){//excluir um elemento da pilha

   if (vazia(e, valor)){
     printf("\nPilha Vazia!!\n\n");

   } else{
     e->topo--;
    }
 }

 void display(tp_pilha *d, int valor){//imprime os valores
   int i;
   for(i = d->topo; i >= 0; i--){
     printf("\nCod: %d\n", (d->info+i)->cod);
     printf("Nome: %s", (d->info+i)->nome);
     printf("Preço: R$ %.2f\n", (d->info+i)->preco);
   }
   printf("\n");
 }

 void cria(tp_pilha *cr, int tamanho){ //cria a pilha
   tp_produto *prod = (tp_produto *) malloc(tamanho * sizeof(tp_produto));
   cr->info = prod;
   cr->topo = -1;
 }


int main(){
   tp_pilha *p = (tp_pilha *) malloc(sizeof(tp_pilha));
   int op, num;
   printf("Quantos produtos quer cadastrar: ");
   scanf("%d", &num);

   cria(p, num);
   cheia(p, num);
   vazia(p, num);


   do {
     printf("\tOPÇÕES\n");
     printf("1 - Empilhar\n");
     printf("2 - Desempilhar\n");
     printf("3 - Mostrar\n");
     printf("0 - Sair\n");
     printf("Digite uma opção--> ");
     scanf("%d", &op);
     switch (op) {
       case 1:
       empilhar(p, num);
       break;
       case 2:
       desempilhar(p, num);
       break;
       case 3:
       display(p, num);
       break;
       case 0:
       break;
       default:
       printf("Opção Inválida!!\n");
       break;
     }
   } while(op != 0);

   free(p);
}
