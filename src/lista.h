#ifndef LISTA_H
#define LISTA_H

#include "contato.h"

typedef struct no {
    Contato dados;
    struct no *ant;
    struct no *prox;
} No; 

typedef struct lista {
    No *primeiro;
    No *ultimo;
    int tamanho;
} Lista;

Lista *criaLista();
int verificaSeVazia(Lista *lista);
void exibirLista(Lista *lista);
void exibirTamanhoLista(Lista *lista);
void organizaLista(Lista *lista, Contato C);

#endif