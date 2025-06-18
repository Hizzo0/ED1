#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 10

typedef struct
{
    int dados[TAMANHO_MAX];
    int inicio;
    int fim;
    int tamanho;
} ListaCircular;

void inicializar(ListaCircular *lista)
{
    lista->inicio = 0;
    lista->fim = 0;
    lista->tamanho = 0;
}

int esta_vazia(ListaCircular *lista)
{
    return lista->tamanho == 0;
}

int esta_cheia(ListaCircular *lista)
{
    return lista->tamanho == TAMANHO_MAX;
}

void inserir_inicio(ListaCircular *lista, int valor)
{
    if (esta_cheia(lista))
        return;

    if (!esta_vazia(lista))
    {
        lista->inicio = (lista->inicio - 1 + TAMANHO_MAX) % TAMANHO_MAX;
    }
    lista->dados[lista->inicio] = valor;
    lista->tamanho++;
}

void inserir_final(ListaCircular *lista, int valor)
{
    if (esta_cheia(lista))
        return;

    if (!esta_vazia(lista))
    {
        lista->fim = (lista->fim + 1) % TAMANHO_MAX;
    }
    lista->dados[lista->fim] = valor;
    lista->tamanho++;
}

int remover_inicio(ListaCircular *lista)
{
    if (esta_vazia(lista))
        return -1;

    int valor = lista->dados[lista->inicio];
    if (lista->tamanho > 1)
    {
        lista->inicio = (lista->inicio + 1) % TAMANHO_MAX;
    }
    lista->tamanho--;
    return valor;
}

int remover_final(ListaCircular *lista)
{
    if (esta_vazia(lista))
        return -1;

    int valor = lista->dados[lista->fim];
    if (lista->tamanho > 1)
    {
        lista->fim = (lista->fim - 1 + TAMANHO_MAX) % TAMANHO_MAX;
    }
    lista->tamanho--;
    return valor;
}

void imprimir(ListaCircular *lista)
{
    if (esta_vazia(lista))
    {
        printf("Lista vazia\n");
        return;
    }

    int i = lista->inicio;
    int contador = 0;
    while (contador < lista->tamanho)
    {
        printf("%d ", lista->dados[i]);
        i = (i + 1) % TAMANHO_MAX;
        contador++;
    }
    printf("\n");
}

int main()
{
    ListaCircular lista;
    inicializar(&lista);

    inserir_inicio(&lista, 1);
    inserir_inicio(&lista, 0);
    inserir_final(&lista, 2);
    inserir_final(&lista, 3);

    printf("Lista: ");
    imprimir(&lista);

    printf("Removido do início: %d\n", remover_inicio(&lista));
    printf("Removido do final: %d\n", remover_final(&lista));

    printf("Lista após remoções: ");
    imprimir(&lista);

    return 0;
}