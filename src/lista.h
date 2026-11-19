typedef struct nodo {
    Contato dados;
    struct nodo *ant;
    struct nodo *prox;
} Nodo;

typedef struct lista {
    Nodo *primeiro;
    Nodo *ultimo;
    int tamanho;
} Lista;