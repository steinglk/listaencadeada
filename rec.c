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

void addfinal(List* list, DataNode data) {
    Node* node = (Node*) malloc(sizeof(Node));
    Node* pointer = list->raiz;
    node->data = data;
    node->prox = NULL;
    while (pointer->prox != NULL) {
        pointer->prox;
    }
    pointer->prox = node;

}
void printlist(List* list) {
    Node* pointer = list->raiz;
    while(pointer != NULL){
        printf(" %d \n", pointer->data.id);
        pointer = pointer->prox;
    }
}

List* exerc1a(List* list) {
    Node* pointer = list->raiz;
    // pointer para percorrer a lista
    Node* aux = pointer;
    // auxiliar para armazenar a posição 1 da lista
    list->raiz = pointer->prox; //raiz aponta pro segundo agora
    while(pointer->prox != NULL) {
        pointer = pointer->prox;
    }
    pointer->prox = aux; // ultimo elemento aponta para o primeiro elemento original
    aux->prox = NULL; // primeiro elemento aponta para NULL
    return list;
}

List* exerc1b(List* list) {
    Node* pointer = list->raiz;
    List* l2 = criarlista();
    while(pointer->prox != NULL) {
        addfinal(l2, pointer->data);
    }
    return l2;
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
    List* l2 = criarlista();
    l2 = exerc1a(l2);
    printlist(l2);


}
