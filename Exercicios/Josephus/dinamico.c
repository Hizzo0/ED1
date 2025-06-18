#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int ch;
    struct No *proximo;
} No;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    No *cabeca = malloc(sizeof(No));
    cabeca->ch = 1;
    No *atual = cabeca;
    for (int i = 2; i <= n; i++)
    {
        atual->proximo = malloc(sizeof(No));
        atual = atual->proximo;
        atual->ch = i;
    }
    atual->proximo = cabeca; // Fecha o círculo

    for (int tamanho = n; tamanho > 0; tamanho--)
    {
        int passos = (k - 1) % tamanho;
        while (passos--)
            atual = atual->proximo;

        No *removido = atual->proximo;
        printf("%d ", removido->ch);
        atual->proximo = removido->proximo;
        free(removido);
    }
    return 0;
}