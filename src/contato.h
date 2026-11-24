#ifndef CONTATO_H
#define CONTATO_H

typedef struct {
    char nome[100];
    char email[80];
    char telefone[20];
    char cpf[12];
} Contato;

// Avisa o compilador que o tipo Lista existe (sem precisar incluir lista.h aqui)
typedef struct lista Lista;

void InsereOrdemAlf(Lista *lista);
Contato ReceberContato();
int BuscaContatoPorNome(Lista *lista);
void RemoveContato(Lista *lista);

#endif