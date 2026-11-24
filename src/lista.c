#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lista.h"
#include "contato.h"

Lista *criaLista(){
    
    Lista *ListaNova = malloc(sizeof(Lista));
    if(ListaNova !=NULL){
        ListaNova->primeiro = NULL;
        ListaNova->ultimo = NULL;
        ListaNova->tamanho = 0;
    }
    else {
        
        printf("Erro ao alocar memória!");
    }
    
    return ListaNova;
}

int verificaSeVazia(Lista *lista){
    if(lista->tamanho ==0)return 1;
    return 0;
}

void exibirTamanhoLista(Lista *lista){
    printf("A lista tem: %d", lista->tamanho);
}

void exibirLista(Lista *lista){

    if(verificaSeVazia(lista)){
        printf("A lista está vazia!\n");
        return;
    }

    No *aux = lista->primeiro;

    while(aux != NULL){

        printf("\nNome: %s | ", aux->dados.nome);
        printf("E-mail: %s | ", aux->dados.email);
        printf("Telefone: %s | ", aux->dados.telefone);
        printf("CPF: %s; ", aux->dados.cpf);

        aux = aux->prox; // avança para o próximo nó
    }
}

void organizaLista(Lista *lista, Contato C){
    
    No *aux = lista->primeiro;
    
    while(aux!=NULL){
        
        if(strcmp(C.nome,aux->dados.nome) < 0) {
            
            No *novoNo = malloc(sizeof(No));
             if(novoNo == NULL){
                printf("Erro ao alocar memória!\n");
                return;
            }
            
            novoNo->dados = C;
            novoNo->prox = aux;
            novoNo->ant = aux->ant;
            
            if(aux->ant != NULL) {  /// se for o primeiro nó da lista
                aux->ant->prox = novoNo;
            } 
            else {
                lista->primeiro = novoNo;
            }
            
            aux->ant = novoNo;
            
            lista->tamanho++;
            return;
            
            
        } else if(strcmp(C.nome,aux->dados.nome) == 0){
            
            
            No *novoNo = malloc(sizeof(No));
            if(novoNo == NULL){
                printf("Erro ao alocar memória!\n");
                return;
            }
            novoNo->dados = C;
            novoNo->ant = aux;
            novoNo->prox = aux->prox;
            
            if(aux->prox != NULL) {  /// se for o primeiro nó da lista
                aux->prox->ant = novoNo;
            } 
            else {
                lista->ultimo = novoNo;
            }
            
            aux->prox = novoNo;
            
            lista->tamanho++;
            return;
        }
        
        else {
            aux = aux->prox;
        }
            
    }
    
    //o while anterior percorre a lista enquanto aux!=NULL
    //mas se o nome que eu quiser inserir vier no final da lista
    // o aux será null e não entrara no while, por isso tive que tratar
    // esse caso nas linhas a seguir separadas do while
    
    No *novoNo = malloc(sizeof(No));

    if(novoNo == NULL){
    printf("Erro ao alocar memória!\n");
    return;
    }

    novoNo->dados = C;
    novoNo->ant = lista->ultimo;
    novoNo->prox = NULL;

    lista->ultimo->prox = novoNo;
    lista->ultimo = novoNo;

    lista->tamanho++;
}