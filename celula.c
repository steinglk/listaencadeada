#include <stdio.h>
#include <stdlib.h>

//Estrutura base do nó.
struct Node
{
    int valor;
    struct Node *prox;
};

typedef struct Node node;

//Função pra printar o nó na tela.
void displayLL(node *p)
{
    p = p->prox;
    printf("Mostrando a lista:\n");
    if(p)
    {
        do
        {
            printf(" %d", p->valor);
            p = p->prox;
        }
        while(p);
        printf("\n\n");

    }
    else
        printf("Lista vazia.\n\n");
}

// Função para inserir nó no inicio
void insere_no_inicio(node *raiz, int info){
    node *novo = (node *) malloc(sizeof(node *));
    novo->valor = info;
    novo->prox = raiz->prox;
    raiz->prox = novo;
}

// Função para inserir nó no final
void insere_no_final(node *raiz, int info){
    node *novo = NULL;
    novo = (node *)malloc(sizeof(node *));
    novo->valor = info;
    novo->prox = NULL;

    node *ultimo = raiz->prox;
    while (ultimo->prox)
    {
        ultimo = ultimo->prox;
    }

    ultimo->prox = novo;
    novo->prox = NULL;
}

void exc1(node *raiz) {
    node *pointer = raiz;
    node *aux = pointer;
    raiz->prox = raiz->prox->prox;
    while (pointer) {
        pointer->prox;
    }
    pointer->prox = aux;
    aux->prox = NULL;

}
int main(void)
{
    printf("\n\n\n");
    node *raiz = NULL;
    raiz = (node *)malloc(sizeof(node *));
    raiz->valor = 0;
    raiz->prox = NULL;

    //Mostrando a lista.
    //if (raiz)
      // -o teste  displayLL(raiz);

    insere_no_inicio(raiz, 1);
    insere_no_inicio(raiz, 2);
    insere_no_inicio(raiz, 3);
    insere_no_inicio(raiz, 4);

    if (raiz)
        displayLL(raiz);

    exc1(raiz);
    if (raiz)
        displayLL(raiz);
}
