#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int ch;
    struct no *prox, *ant;
} No;

typedef struct lista
{
    No *inicio, *fim;
} Lista;

// a) Criar lista vazia
Lista *criar_lista()
{
    Lista *nova = (Lista *)malloc(sizeof(Lista));
    if (nova)
    {
        nova->inicio = NULL;
        nova->fim = NULL;
    }
    return nova;
}

// b) Inserir no início
void inserir_inicio(Lista *lista, int chave)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo)
    {
        novo->ch = chave;
        novo->ant = NULL;
        novo->prox = lista->inicio;

        if (lista->inicio == NULL)
        {
            lista->fim = novo;
        }
        else
        {
            lista->inicio->ant = novo;
        }

        lista->inicio = novo;
    }
}

// c) Inserir no final
void inserir_final(Lista *lista, int chave)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo)
    {
        novo->ch = chave;
        novo->prox = NULL;
        novo->ant = lista->fim;

        if (lista->fim == NULL)
        {
            lista->inicio = novo;
        }
        else
        {
            lista->fim->prox = novo;
        }

        lista->fim = novo;
    }
}

// d) Remover chave
void remover_chave(Lista *lista, int chave)
{
    No *atual = lista->inicio;
    while (atual != NULL)
    {
        if (atual->ch == chave)
        {
            if (atual->ant != NULL)
            {
                atual->ant->prox = atual->prox;
            }
            else
            {
                lista->inicio = atual->prox;
            }

            if (atual->prox != NULL)
            {
                atual->prox->ant = atual->ant;
            }
            else
            {
                lista->fim = atual->ant;
            }

            No *temp = atual;
            atual = atual->prox;
            free(temp);
        }
        else
        {
            atual = atual->prox;
        }
    }
}

// e) Trocar chaves entre listas
void trocar_chaves(Lista *L1, Lista *L2, int c1, int c2)
{
    No *no1 = NULL, *no2 = NULL;
    No *pos1 = NULL, *pos2 = NULL;

    // Buscar c1 em L1
    No *atual = L1->inicio;
    while (atual != NULL && no1 == NULL)
    {
        if (atual->ch == c1)
        {
            no1 = atual;
            pos1 = atual->ant; // Guarda a posição anterior
        }
        atual = atual->prox;
    }

    // Buscar c2 em L2
    atual = L2->inicio;
    while (atual != NULL && no2 == NULL)
    {
        if (atual->ch == c2)
        {
            no2 = atual;
            pos2 = atual->ant; // Guarda a posição anterior
        }
        atual = atual->prox;
    }

    if (no1 != NULL && no2 != NULL)
    {
        // Remover no1 de L1
        if (no1->ant != NULL)
        {
            no1->ant->prox = no1->prox;
        }
        else
        {
            L1->inicio = no1->prox;
        }
        if (no1->prox != NULL)
        {
            no1->prox->ant = no1->ant;
        }
        else
        {
            L1->fim = no1->ant;
        }

        // Remover no2 de L2
        if (no2->ant != NULL)
        {
            no2->ant->prox = no2->prox;
        }
        else
        {
            L2->inicio = no2->prox;
        }
        if (no2->prox != NULL)
        {
            no2->prox->ant = no2->ant;
        }
        else
        {
            L2->fim = no2->ant;
        }

        // Inserir no2 em L1 na posição de no1
        no2->ant = pos1;
        no2->prox = (pos1 == NULL) ? L1->inicio : pos1->prox;

        if (pos1 == NULL)
        {
            if (L1->inicio != NULL)
            {
                L1->inicio->ant = no2;
            }
            L1->inicio = no2;
        }
        else
        {
            pos1->prox = no2;
            if (no2->prox != NULL)
            {
                no2->prox->ant = no2;
            }
            else
            {
                L1->fim = no2;
            }
        }

        // Inserir no1 em L2 na posição de no2
        no1->ant = pos2;
        no1->prox = (pos2 == NULL) ? L2->inicio : pos2->prox;

        if (pos2 == NULL)
        {
            if (L2->inicio != NULL)
            {
                L2->inicio->ant = no1;
            }
            L2->inicio = no1;
        }
        else
        {
            pos2->prox = no1;
            if (no1->prox != NULL)
            {
                no1->prox->ant = no1;
            }
            else
            {
                L2->fim = no1;
            }
        }
    }
}

// f) Complexidade da função de troca
// A função tem complexidade O(n + m), onde n e m são os tamanhos de L1 e L2.
// Isso porque percorremos cada lista uma vez para buscar os elementos.
// A notação assimétrica é Θ(n + m).

int main()
{
    Lista *L1 = criar_lista();
    Lista *L2 = criar_lista();

    inserir_final(L1, 1);
    inserir_final(L1, 2);
    inserir_final(L1, 3);

    inserir_final(L2, 4);
    inserir_final(L2, 5);
    inserir_final(L2, 6);

    printf("L1 antes: ");
    for (No *atual = L1->inicio; atual != NULL; atual = atual->prox)
    {
        printf("%d ", atual->ch);
    }
    printf("\nL2 antes: ");
    for (No *atual = L2->inicio; atual != NULL; atual = atual->prox)
    {
        printf("%d ", atual->ch);
    }

    trocar_chaves(L1, L2, 2, 5);

    printf("\nL1 depois: ");
    for (No *atual = L1->inicio; atual != NULL; atual = atual->prox)
    {
        printf("%d ", atual->ch);
    }
    printf("\nL2 depois: ");
    for (No *atual = L2->inicio; atual != NULL; atual = atual->prox)
    {
        printf("%d ", atual->ch);
    }

    return 0;
}