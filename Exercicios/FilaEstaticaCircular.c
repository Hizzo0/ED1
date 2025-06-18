#define MAX 100

typedef struct
{
    int dados[MAX];
    int inicio, fim, tamanho;
} Fila;

void inicializar(Fila *f)
{
    f->inicio = f->fim = f->tamanho = 0;
}

int enfileirar(Fila *f, int valor)
{
    if (f->tamanho == MAX)
        return 0;

    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX;
    f->tamanho++;
    return 1;
}

int desenfileirar(Fila *f, int *valor)
{
    if (f->tamanho == 0)
        return 0;

    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    return 1;
}
