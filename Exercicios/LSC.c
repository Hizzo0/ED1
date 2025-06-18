#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *prox;
} No;

// a) Inserir no início
void inserir_inicio(No **lista, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo)
    {
        novo->valor = valor;
        if (*lista == NULL)
        {
            novo->prox = novo;
            *lista = novo;
        }
        else
        {
            No *ultimo = *lista;
            while (ultimo->prox != *lista)
            {
                ultimo = ultimo->prox;
            }
            novo->prox = *lista;
            ultimo->prox = novo;
            *lista = novo;
        }
    }
}

// b) Remover primeiro elemento
void remover_inicio(No **lista)
{
    if (*lista == NULL)
        return;

    if ((*lista)->prox == *lista)
    {
        free(*lista);
        *lista = NULL;
    }
    else
    {
        No *ultimo = *lista;
        while (ultimo->prox != *lista)
        {
            ultimo = ultimo->prox;
        }
        No *temp = *lista;
        *lista = (*lista)->prox;
        ultimo->prox = *lista;
        free(temp);
    }
}

// c) Inserir no final
void inserir_final(No **lista, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo)
    {
        novo->valor = valor;
        if (*lista == NULL)
        {
            novo->prox = novo;
            *lista = novo;
        }
        else
        {
            No *ultimo = *lista;
            while (ultimo->prox != *lista)
            {
                ultimo = ultimo->prox;
            }
            novo->prox = *lista;
            ultimo->prox = novo;
        }
    }
}

// d) Remover último elemento
void remover_final(No **lista)
{
    if (*lista == NULL)
        return;

    if ((*lista)->prox == *lista)
    {
        free(*lista);
        *lista = NULL;
    }
    else
    {
        No *penultimo = NULL;
        No *ultimo = *lista;
        while (ultimo->prox != *lista)
        {
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }
        penultimo->prox = *lista;
        free(ultimo);
    }
}

// e) Remover chave específica
void remover_chave(No **lista, int chave)
{
    if (*lista == NULL)
        return;

    No *atual = *lista;
    No *anterior = NULL;

    do
    {
        if (atual->valor == chave)
        {
            if (anterior == NULL)
            { // Primeiro nó
                remover_inicio(lista);
                atual = *lista;
            }
            else
            {
                anterior->prox = atual->prox;
                No *temp = atual;
                atual = atual->prox;
                free(temp);
            }
        }
        else
        {
            anterior = atual;
            atual = atual->prox;
        }
    } while (atual != *lista);
}

// f) Imprimir lista
void imprimir_lista(No *lista)
{
    if (lista == NULL)
    {
        printf("Lista vazia\n");
        return;
    }

    No *atual = lista;
    do
    {
        printf("%d ", atual->valor);
        atual = atual->prox;
    } while (atual != lista);
    printf("\n");
}

int main()
{
    No *lista = NULL;

    inserir_final(&lista, 1);
    inserir_final(&lista, 2);
    inserir_final(&lista, 3);
    inserir_inicio(&lista, 0);

    printf("Lista: ");
    imprimir_lista(lista);

    remover_chave(&lista, 2);
    printf("Lista após remover 2: ");
    imprimir_lista(lista);

    remover_inicio(&lista);
    printf("Lista após remover início: ");
    imprimir_lista(lista);

    remover_final(&lista);
    printf("Lista após remover final: ");
    imprimir_lista(lista);

    return 0;
}