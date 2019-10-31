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

void addinicio(List* list, DataNode data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->prox = list->raiz;
    list->raiz = node;
    list->size++;
}
void printlist(List* list) {
    Node* pointer = list->raiz;
    while(pointer != NULL){
        printf(" %d \n", pointer->data.id);
        pointer = pointer->prox;
    }
}

List* exerc1(List* list) {
    Node* pointer = list->raiz;
    Node* aux = pointer;
    list->raiz = pointer->prox;
    while(pointer != NULL) {
        pointer = pointer->prox;
    }
    pointer->prox = aux;
    aux->prox = NULL;
    return list;
}

int main(){
    List* l = criarlista();
    DataNode data;
    data.id = 10;
    addinicio(l, data);
    data.id = 20;
    addinicio(l, data);
    data.id = 30;
    addinicio(l, data);
    data.id = 40;
    addinicio(l, data);
    data.id = 50;
    addinicio(l, data);
    printlist(l);
    List* l2 = exerc1(l);
    printlist(l2);


}
