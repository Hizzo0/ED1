#include <stdio.h>
#include <stdlib.h>

typedef struct NoPolinomio
{
    int coef;
    int exp;
    struct NoPolinomio *anterior;
    struct NoPolinomio *proximo;
} NoPolinomio;

typedef struct
{
    NoPolinomio *cabeca; // Nó cabeça (dummy)
} Polinomio;

NoPolinomio *criar_no_polinomio(int coef, int exp)
{
    NoPolinomio *novo = malloc(sizeof(NoPolinomio));
    novo->coef = coef;
    novo->exp = exp;
    novo->anterior = novo->proximo = NULL;
    return novo;
}

Polinomio *somar_polinomios(Polinomio *A, Polinomio *B)
{
    Polinomio *C = malloc(sizeof(Polinomio));
    C->cabeca = malloc(sizeof(NoPolinomio));              // Nó cabeça
    C->cabeca->proximo = C->cabeca->anterior = C->cabeca; // Lista vazia

    NoPolinomio *a = A->cabeca->proximo;
    NoPolinomio *b = B->cabeca->proximo;

    while (a != A->cabeca && b != B->cabeca)
    {
        if (a->exp > b->exp)
        {
            NoPolinomio *novo = criar_no_polinomio(a->coef, a->exp);
            // Insere no final da lista C
            novo->proximo = C->cabeca;
            novo->anterior = C->cabeca->anterior;
            C->cabeca->anterior->proximo = novo;
            C->cabeca->anterior = novo;
            a = a->proximo;
        }
        else if (b->exp > a->exp)
        {
            NoPolinomio *novo = criar_no_polinomio(b->coef, b->exp);
            novo->proximo = C->cabeca;
            novo->anterior = C->cabeca->anterior;
            C->cabeca->anterior->proximo = novo;
            C->cabeca->anterior = novo;
            b = b->proximo;
        }
        else
        {
            int soma = a->coef + b->coef;
            if (soma != 0)
            {
                NoPolinomio *novo = criar_no_polinomio(soma, a->exp);
                novo->proximo = C->cabeca;
                novo->anterior = C->cabeca->anterior;
                C->cabeca->anterior->proximo = novo;
                C->cabeca->anterior = novo;
            }
            a = a->proximo;
            b = b->proximo;
        }
    }

    // Adiciona os termos restantes de A ou B
    while (a != A->cabeca)
    {
        NoPolinomio *novo = criar_no_polinomio(a->coef, a->exp);
        novo->proximo = C->cabeca;
        novo->anterior = C->cabeca->anterior;
        C->cabeca->anterior->proximo = novo;
        C->cabeca->anterior = novo;
        a = a->proximo;
    }

    while (b != B->cabeca)
    {
        NoPolinomio *novo = criar_no_polinomio(b->coef, b->exp);
        novo->proximo = C->cabeca;
        novo->anterior = C->cabeca->anterior;
        C->cabeca->anterior->proximo = novo;
        C->cabeca->anterior = novo;
        b = b->proximo;
    }

    return C;
}