#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *ant;
    struct no *prox;
} No;

// a) Criar novo nó
No *criar_no(int chave)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo)
    {
        novo->valor = chave;
        novo->ant = NULL;
        novo->prox = NULL;
    }
    return novo;
}

// b) Imprimir lista
void imprimir_lista(No *lista)
{
    No *atual = lista;
    while (atual != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

// c) Inserir em lista ordenada
void inserir_ordenado(No **lista, int chave)
{
    No *novo = criar_no(chave);
    if (*lista == NULL)
    {
        *lista = novo;
        return;
    }

    No *atual = *lista;
    No *anterior = NULL;

    while (atual != NULL && atual->valor < chave)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == NULL)
    { // Inserir no início
        novo->prox = *lista;
        (*lista)->ant = novo;
        *lista = novo;
    }
    else if (atual == NULL)
    { // Inserir no final
        anterior->prox = novo;
        novo->ant = anterior;
    }
    else
    { // Inserir no meio
        anterior->prox = novo;
        novo->ant = anterior;
        novo->prox = atual;
        atual->ant = novo;
    }
}

// d) Remover duplicatas
void remover_duplicatas(No **lista)
{
    No *atual = *lista;
    while (atual != NULL && atual->prox != NULL)
    {
        No *comparador = atual->prox;
        while (comparador != NULL)
        {
            No *proximo = comparador->prox;
            if (comparador->valor == atual->valor)
            {
                if (comparador->ant != NULL)
                {
                    comparador->ant->prox = comparador->prox;
                }
                if (comparador->prox != NULL)
                {
                    comparador->prox->ant = comparador->ant;
                }
                free(comparador);
            }
            comparador = proximo;
        }
        atual = atual->prox;
    }
}

// e) Intercalar listas ordenadas
No *intercalar_listas_ordenadas(No *l1, No *l2)
{
    No dummy;
    No *cauda = &dummy;
    dummy.prox = NULL;
    dummy.ant = NULL;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->valor <= l2->valor)
        {
            cauda->prox = l1;
            l1->ant = cauda;
            l1 = l1->prox;
        }
        else
        {
            cauda->prox = l2;
            l2->ant = cauda;
            l2 = l2->prox;
        }
        cauda = cauda->prox;
    }

    if (l1 != NULL)
    {
        cauda->prox = l1;
        l1->ant = cauda;
    }
    else
    {
        cauda->prox = l2;
        if (l2 != NULL)
        {
            l2->ant = cauda;
        }
    }

    if (dummy.prox != NULL)
    {
        dummy.prox->ant = NULL;
    }

    return dummy.prox;
}

// f) Complexidade da função de intercalar
// A função tem complexidade O(n + m), onde n e m são os tamanhos das duas listas.
// Como percorremos cada lista apenas uma vez, a complexidade é linear, representada como Θ(n + m).

int main()
{
    No *lista1 = NULL;
    No *lista2 = NULL;

    inserir_ordenado(&lista1, 3);
    inserir_ordenado(&lista1, 1);
    inserir_ordenado(&lista1, 2);
    inserir_ordenado(&lista1, 2);

    inserir_ordenado(&lista2, 5);
    inserir_ordenado(&lista2, 4);
    inserir_ordenado(&lista2, 6);

    printf("Lista 1: ");
    imprimir_lista(lista1);

    printf("Lista 2: ");
    imprimir_lista(lista2);

    No *lista_intercalada = intercalar_listas_ordenadas(lista1, lista2);
    printf("Listas intercaladas: ");
    imprimir_lista(lista_intercalada);

    return 0;
}