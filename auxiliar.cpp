celula* remover_celula(celula **lista, int chave){
    celula *aux, *remover = NULL;
    
    //lista nao é vazia?
    if(*lista != NULL){
        if((*lista)->chave == chave){ //chave esta na 1° celula
            remover = *lista; //faz remover apontar para o inicio da lista
            *lista = remover->proximo; //atualiza o inicio da lista
        }else{ //chave nao esta na 1° celula da lista
            aux = *lista;
            while(aux->proximo != NULL && aux->proximo->chave != chave){
                aux = aux->proximo;
            }
            //o proximo existe?se sim, a chave da proxima celula eh a chave a ser removida
            if(aux->proximo != NULL){
                remover = aux->proximo;
                aux->proximo = remover->proximo; //faz o aux->proximo ser o que vem logo a pos a celula que foi removida
            }
        }
    }
    
    return remover;
}