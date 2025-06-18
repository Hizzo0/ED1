#include <stdio.h>
#define MAX 200000

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int proximo[MAX];
    for (int i = 0; i < n; i++)
        proximo[i] = (i + 1) % n; // Cria um círculo

    int atual = 0;
    for (int tamanho = n; tamanho > 0; tamanho--)
    {
        int passos = (k - 1) % tamanho;
        while (passos--)
            atual = proximo[atual];

        printf("%d ", atual + 1);                 // Imprime a criança removida
        proximo[atual] = proximo[proximo[atual]]; // Remove do círculo
        atual = proximo[atual];
    }
    return 0;
}