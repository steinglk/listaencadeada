#include <stdio.h>
#include <stdlib.h>

//Estrutura base do nó.
struct Node
{
    int valor;
    struct Node *proximo;
};

typedef struct Node node;

//Função pra printar o nó na tela.
void displayLL(node *p)
{
    p = p->proximo;
    printf("Mostrando a lista:\n");
    if(p)
    {
        do
        {
            printf(" %d", p->valor);
            p = p->proximo;
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
    novo->proximo = raiz->proximo;
    raiz->proximo = novo;
}

// Função para inserir nó no final
void insere_no_final(node *raiz, int info){
    node *novo = NULL;
    novo = (node *)malloc(sizeof(node *));
    novo->valor = info;
    novo->proximo = NULL;

    node *ultimo = raiz->proximo;
    while (ultimo->proximo)
    {
        ultimo = ultimo->proximo;
    }

    ultimo->proximo = novo;
    novo->proximo = NULL;
}

int main(void)
{
    printf("\n\n\n");
    node *raiz = NULL;
    raiz = (node *)malloc(sizeof(node *));
    raiz->valor = NULL;
    raiz->proximo = NULL;

    //Mostrando a lista.
    if (raiz)
        displayLL(raiz);

    insere_no_inicio(raiz, 1);
    insere_no_inicio(raiz, 2);
    insere_no_inicio(raiz, 3);
    insere_no_inicio(raiz, 4);

    if (raiz)
        displayLL(raiz);
