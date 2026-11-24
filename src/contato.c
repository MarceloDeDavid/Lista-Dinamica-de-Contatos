#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contato.h"
#include "lista.h"

Contato ReceberContato(){ /// A ideia é receber o contato a ser inserido para depois inserir
    
    Contato NovoContato;
    printf("Digite o nome: ");
    fgets(NovoContato.nome, sizeof(NovoContato.nome), stdin);
    NovoContato.nome[strcspn(NovoContato.nome, "\n")] = '\0';
    
    for (int i = 0; NovoContato.nome[i] != '\0'; i++) {
        NovoContato.nome[i] = tolower((unsigned char)NovoContato.nome[i]);
    }
    
    printf("Digite o e-mail: ");
    fgets(NovoContato.email,sizeof(NovoContato.email), stdin);
    NovoContato.email[strcspn(NovoContato.email, "\n")] = '\0';
    
    printf("Digite o telefone: ");
    fgets(NovoContato.telefone,sizeof(NovoContato.telefone), stdin);
    NovoContato.telefone[strcspn(NovoContato.telefone, "\n")] = '\0';
    
    printf("Digite o CPF: ");
    fgets(NovoContato.cpf, sizeof(NovoContato.cpf), stdin);
    NovoContato.cpf[strcspn(NovoContato.cpf, "\n")] = '\0';
    
    return NovoContato;
}

void RemoveContato(Lista *lista) {
    printf("Função ainda não implementada.\n");
}

void InsereOrdemAlf(Lista *lista){

    if(verificaSeVazia(lista)){

        No *novoNo = malloc(sizeof(No));

        if(novoNo == NULL){
            printf("Erro ao alocar memória!\n");
            return;
        }

        novoNo->dados = ReceberContato();
        novoNo->prox = NULL;
        novoNo->ant = NULL;

        lista->primeiro = novoNo;
        lista->ultimo = novoNo;
        lista->tamanho++;

        return;

    } else {

        Contato C = ReceberContato();
        organizaLista(lista, C);
    }
}

int BuscaContatoPorNome(Lista *lista){
    
    if(verificaSeVazia(lista)){
        printf("A lista está vazia!\n");
        return 0;
    }
    
    int qtde = 0;
    int posicao = 1;
    char nomeBusca[100];
    
    printf("Digite o nome que deseja buscar: ");
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';
    
    for (int i = 0; nomeBusca[i] != '\0'; i++) {
        nomeBusca[i] = tolower((unsigned char)nomeBusca[i]);
    }
    
    No *aux = lista->primeiro;
    
    while(aux!=NULL){
        
        if(strcmp(nomeBusca, aux->dados.nome)==0){
            
            qtde++;
            printf("Contato encontrado!\n");
            printf("\nNome: %s", aux->dados.nome);
            printf("\nE-mail: %s", aux->dados.email);
            printf("\nTelefone: %s", aux->dados.telefone);
            printf("\nCPF: %s", aux->dados.cpf);
            printf("\nPosição: %d\n", posicao);
            printf("--------------------------\n");
            
        }
        
        aux = aux->prox;
        posicao++;
        
    }
    
    if(qtde==0){
        printf("Nenhum contato encontrado com esse nome...");
        return 0;
    }
    
    return qtde;
    
}