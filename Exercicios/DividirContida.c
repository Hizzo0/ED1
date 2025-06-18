No *dividir_apos(No *lista, int n)
{
    if (lista == NULL)
        return NULL;

    No *atual = lista;
    while (atual != NULL)
    {
        if (atual->ch == n)
        {
            No *nova_lista = atual->proximo; // Nova lista começa após o nó com 'n'
            atual->proximo = NULL;           // Finaliza a lista original
            return nova_lista;
        }
        atual = atual->proximo;
    }
    return NULL; // 'n' não encontrado
}

int esta_contida(No *lista1, No *lista2)
{
    if (lista2 == NULL)
        return 1; // Lista vazia está sempre contida

    while (lista1 != NULL)
    {
        No *temp1 = lista1;
        No *temp2 = lista2;
        // Compara os elementos sequencialmente
        while (temp1 != NULL && temp2 != NULL && temp1->ch == temp2->ch)
        {
            temp1 = temp1->proximo;
            temp2 = temp2->proximo;
        }
        if (temp2 == NULL)
            return 1; // Todos os elementos de lista2 foram encontrados
        lista1 = lista1->proximo;
    }
    return 0;
}