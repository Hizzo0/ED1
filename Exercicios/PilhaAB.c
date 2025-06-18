#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 10

typedef struct
{
    int dados[TAMANHO_MAX];
    int inicio;
    int fim;
    int tamanho;
} FilaCircular;

// a) Criar fila vazia
FilaCircular *criar_fila()
{
    FilaCircular *f = (FilaCircular *)malloc(sizeof(FilaCircular));
    if (f)
    {
        f->inicio = 0;
        f->fim = 0;
        f->tamanho = 0;
    }
    return f;
}

int esta_vazia(FilaCircular *f)
{
    return f->tamanho == 0;
}

int esta_cheia(FilaCircular *f)
{
    return f->tamanho == TAMANHO_MAX;
}

void enqueue(FilaCircular *f, int valor)
{
    if (esta_cheia(f))
    {
        printf("Fila cheia!\n");
        return;
    }

    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % TAMANHO_MAX;
    f->tamanho++;
}

int dequeue(FilaCircular *f)
{
    if (esta_vazia(f))
    {
        printf("Fila vazia!\n");
        return -1;
    }

    int valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % TAMANHO_MAX;
    f->tamanho--;
    return valor;
}

void imprimir(FilaCircular *f)
{
    if (esta_vazia(f))
    {
        printf("Fila vazia\n");
        return;
    }

    printf("Fila: ");
    int i = f->inicio;
    int contador = 0;
    while (contador < f->tamanho)
    {
        printf("%d ", f->dados[i]);
        i = (i + 1) % TAMANHO_MAX;
        contador++;
    }
    printf("\n");
}

int main()
{
    FilaCircular *f = criar_fila();
    int opcao, valor;

    do
    {
        printf("\nMenu:\n");
        printf("1. Enfileirar\n");
        printf("2. Desenfileirar\n");
        printf("3. Imprimir Fila\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Valor: ");
            scanf("%d", &valor);
            enqueue(f, valor);
            break;
        case 2:
            valor = dequeue(f);
            if (valor != -1)
            {
                printf("Valor desenfileirado: %d\n", valor);
            }
            break;
        case 3:
            imprimir(f);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    free(f);
    return 0;
}