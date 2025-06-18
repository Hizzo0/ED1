DNo *intercalar_listas(DNo *lista1, DNo *lista2)
{
    if (lista1 == NULL)
        return lista2;
    if (lista2 == NULL)
        return lista1;

    DNo *cabeca = NULL;
    DNo *cauda = NULL;

    while (lista1 != NULL && lista2 != NULL)
    {
        if (lista1->ch <= lista2->ch)
        {
            if (cabeca == NULL)
                cabeca = lista1;
            if (cauda != NULL)
                cauda->proximo = lista1;
            lista1->anterior = cauda;
            cauda = lista1;
            lista1 = lista1->proximo;
        }
        else
        {
            if (cabeca == NULL)
                cabeca = lista2;
            if (cauda != NULL)
                cauda->proximo = lista2;
            lista2->anterior = cauda;
            cauda = lista2;
            lista2 = lista2->proximo;
        }
    }

    // Adiciona os elementos restantes
    if (lista1 != NULL)
    {
        cauda->proximo = lista1;
        lista1->anterior = cauda;
    }
    if (lista2 != NULL)
    {
        cauda->proximo = lista2;
        lista2->anterior = cauda;
    }

    return cabeca;
}