#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
 
typedef struct dataNode {
    int id;
} DataNode;
 
typedef struct node{
    DataNode data;
    struct node* prox;
} Node;
 
typedef struct list {
    int size;
    Node* raiz;
} List;
 
List* criarlista();
void push(List* list, DataNode data);
void pop(List* list);
void printlist(List* list);
bool isEmpty(List* list);
 
// Função que Cria a lista
List* criarlista() {
    List* list = (List*) malloc(sizeof(List));
 
    list->size = 0;
    list->raiz = NULL;
 
    return list;
}
 
void push(List* list, DataNode data) {
    Node* node = (Node*) malloc(sizeof(Node));
 
    node->data = data;
    node->prox = list->raiz;
    list->raiz = node;
    list->size++;
 
}

void pop(List* list) {
    if(list->size == 0){
        printf("LISTA VAZIA\n");
        return;
    }
    else {
      
        Node* pointer = list->raiz;
        list->raiz = pointer->prox;
        free(pointer);
    }
}

void printlist(List* list) {
    Node* pointer = list->raiz;
    while(pointer != NULL){
        printf(" %d \n", pointer->data.id);
        pointer = pointer->prox;
    }
}
int main(){
    List* lista = criarlista();
    DataNode data;
    int i = 0, ind = 0;
    while (ind < 10000) {
      printf("\n 1 - Para adicionar um item na fila: \n");
      printf("\n 2 - Para remover um item na fila: \n");
      printf("\n 9 - Para Sair \n");
      scanf("%d", &i);
      if ( i == 1) {
          printf("\nDigite o numero do id: \n");
          scanf("%d", &ind);
          data.id = ind;
          push(lista, data);
      }
      if(i == 2){
          pop(lista);
      }
      if (i == 9)
        break;
      printlist(lista);
    }
  }
