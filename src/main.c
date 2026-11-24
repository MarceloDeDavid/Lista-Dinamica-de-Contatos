#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contato.h"
#include "lista.h"

void mostrarMenu(Lista *lista) {
    int opcao = 0;
    
    while (opcao != 4) {
        
        if (!verificaSeVazia(lista)) {
            
            printf("\n--------------------------\n");
            printf("Lista atual: \n");
            exibirLista(lista);
            printf("\n--------------------------");
        } 
        
        printf("\n=== MENU ===\n");
        printf("1. Inserir\n");
        printf("2. Remover\n");
        printf("3. Buscar por nome\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                InsereOrdemAlf(lista);
                break;
            case 2:
                RemoveContato(lista);
                break;
            case 3:
                BuscaContatoPorNome(lista);
                break;
            case 4:
                printf("Saindo do programa\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } 
}


int main()
{
    Lista *l1 = criaLista();
    
    mostrarMenu(l1);

    return 0;
}