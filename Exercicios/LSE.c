#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *prox;
} No;

// a) Criar um novo nó
No *criar_no(int chave)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo)
    {
        novo->valor = chave;
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

// c) Inserir no início
void inserir_inicio(No **lista, int chave)
{
    No *novo = criar_no(chave);
    if (novo)
    {
        novo->prox = *lista;
        *lista = novo;
    }
}

// d) Inserir no final
void inserir_final(No **lista, int chave)
{
    No *novo = criar_no(chave);
    if (novo)
    {
        if (*lista == NULL)
        {
            *lista = novo;
        }
        else
        {
            No *atual = *lista;
            while (atual->prox != NULL)
            {
                atual = atual->prox;
            }
            atual->prox = novo;
        }
    }
}

// e) Remover duplicatas
void remover_duplicatas(No **lista)
{
    No *atual = *lista;
    while (atual != NULL && atual->prox != NULL)
    {
        No *comparador = atual;
        while (comparador->prox != NULL)
        {
            if (comparador->prox->valor == atual->valor)
            {
                No *temp = comparador->prox;
                comparador->prox = temp->prox;
                free(temp);
            }
            else
            {
                comparador = comparador->prox;
            }
        }
        atual = atual->prox;
    }
}

// f) Contar ocorrências
int contar_ocorrencias(No *lista, int numero)
{
    int count = 0;
    No *atual = lista;
    while (atual != NULL)
    {
        if (atual->valor == numero)
        {
            count++;
        }
        atual = atual->prox;
    }
    return count;
}

// g) Multiplicar por 10
void multiplicar_por_10(No *lista)
{
    No *atual = lista;
    while (atual != NULL)
    {
        atual->valor *= 10;
        atual = atual->prox;
    }
}

// h) Verificar se está ordenada
int esta_ordenada(No *lista)
{
    if (lista == NULL || lista->prox == NULL)
    {
        return 1;
    }
    No *atual = lista;
    while (atual->prox != NULL)
    {
        if (atual->valor > atual->prox->valor)
        {
            return 0;
        }
        atual = atual->prox;
    }
    return 1;
}

// i) Intercalar listas ordenadas
No *intercalar_listas_ordenadas(No *l1, No *l2)
{
    No dummy;
    No *cauda = &dummy;
    dummy.prox = NULL;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->valor <= l2->valor)
        {
            cauda->prox = l1;
            l1 = l1->prox;
        }
        else
        {
            cauda->prox = l2;
            l2 = l2->prox;
        }
        cauda = cauda->prox;
    }

    if (l1 != NULL)
    {
        cauda->prox = l1;
    }
    else
    {
        cauda->prox = l2;
    }

    return dummy.prox;
}

// j) Complexidade da função de intercalar
// A função tem complexidade O(n + m), onde n e m são os tamanhos das duas listas.
// Como percorremos cada lista apenas uma vez, a complexidade é linear.

int main()
{
    // Teste das funções
    No *lista = NULL;

    inserir_final(&lista, 1);
    inserir_final(&lista, 2);
    inserir_final(&lista, 2);
    inserir_final(&lista, 3);

    printf("Lista original: ");
    imprimir_lista(lista);

    printf("Está ordenada? %s\n", esta_ordenada(lista) ? "Sim" : "Não");

    remover_duplicatas(&lista);
    printf("Lista sem duplicatas: ");
    imprimir_lista(lista);

    multiplicar_por_10(lista);
    printf("Lista multiplicada por 10: ");
    imprimir_lista(lista);

    return 0;
}