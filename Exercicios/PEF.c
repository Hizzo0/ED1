#include <stdio.h>
#include <stdlib.h>

// Estrutura para nó da lista
typedef struct no
{
    int valor;
    struct no *prox;
} No;

// Estrutura para Pilha
typedef struct
{
    No *topo;
} Pilha;

// Estrutura para Fila
typedef struct
{
    No *inicio;
    No *fim;
} Fila;

// a) O que é um tipo abstrato de dado?
// Um tipo abstrato de dado (TAD) é um modelo matemático que define um conjunto de valores
// e um conjunto de operações sobre esses valores, sem especificar como eles são implementados.
// Ele encapsula a estrutura de dados e fornece uma interface bem definida para manipulá-la.

// b) Características de uma pilha:
// - Segue o princípio LIFO (Last In, First Out)
// - Operações básicas: push (empilhar) e pop (desempilhar)
// - Acesso limitado ao elemento do topo
// - Usada em situações como: chamadas de função, avaliação de expressões, undo/redo

// c) Inserção em pilha (push)
void push(Pilha *p, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo)
    {
        novo->valor = valor;
        novo->prox = p->topo;
        p->topo = novo;
    }
}

// d) Remoção em pilha (pop)
int pop(Pilha *p)
{
    if (p->topo == NULL)
        return -1;

    No *temp = p->topo;
    int valor = temp->valor;
    p->topo = temp->prox;
    free(temp);
    return valor;
}

// e) Imprimir pilha (do topo para base)
void imprimir_pilha(Pilha *p)
{
    No *atual = p->topo;
    printf("Pilha (topo -> base): ");
    while (atual != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

// f) Características de uma fila:
// - Segue o princípio FIFO (First In, First Out)
// - Operações básicas: enqueue (enfileirar) e dequeue (desenfileirar)
// - Acesso limitado ao primeiro e último elementos
// - Usada em situações como: buffers, escalonamento de processos, impressão

// g) Inserção em fila (enqueue)
void enqueue(Fila *f, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo)
    {
        novo->valor = valor;
        novo->prox = NULL;

        if (f->inicio == NULL)
        {
            f->inicio = novo;
            f->fim = novo;
        }
        else
        {
            f->fim->prox = novo;
            f->fim = novo;
        }
    }
}

// h) Remoção em fila (dequeue)
int dequeue(Fila *f)
{
    if (f->inicio == NULL)
        return -1;

    No *temp = f->inicio;
    int valor = temp->valor;
    f->inicio = temp->prox;

    if (f->inicio == NULL)
    {
        f->fim = NULL;
    }

    free(temp);
    return valor;
}

// i) Imprimir fila
void imprimir_fila(Fila *f)
{
    No *atual = f->inicio;
    printf("Fila (início -> fim): ");
    while (atual != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

int main()
{
    Pilha p = {NULL};
    Fila f = {NULL, NULL};
    int opcao, valor;

    do
    {
        printf("\nMenu:\n");
        printf("1. Empilhar (Pilha)\n");
        printf("2. Desempilhar (Pilha)\n");
        printf("3. Imprimir Pilha\n");
        printf("4. Enfileirar (Fila)\n");
        printf("5. Desenfileirar (Fila)\n");
        printf("6. Imprimir Fila\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Valor para empilhar: ");
            scanf("%d", &valor);
            push(&p, valor);
            break;
        case 2:
            valor = pop(&p);
            if (valor != -1)
            {
                printf("Valor desempilhado: %d\n", valor);
            }
            else
            {
                printf("Pilha vazia!\n");
            }
            break;
        case 3:
            imprimir_pilha(&p);
            break;
        case 4:
            printf("Valor para enfileirar: ");
            scanf("%d", &valor);
            enqueue(&f, valor);
            break;
        case 5:
            valor = dequeue(&f);
            if (valor != -1)
            {
                printf("Valor desenfileirado: %d\n", valor);
            }
            else
            {
                printf("Fila vazia!\n");
            }
            break;
        case 6:
            imprimir_fila(&f);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}