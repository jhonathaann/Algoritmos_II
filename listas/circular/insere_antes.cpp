#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *prox;
}celula;

void insere_antes_cursor(celula **cursor, int numero);

celula* remove_na_chave(celula **cursor, int numero);

void avancar_cursor(celula **cursor);

void imprime(celula *cursor);


int main(){
    celula *cursor = NULL;
    celula *aux;
    int numero;

    scanf("%d", &numero);

    while(numero != 0){

        insere_antes_cursor(&cursor, numero);

        scanf("%d", &numero);
    }

    printf("Lista inicial:\n");
    imprime(cursor);

    printf("Entre com a chave a ser removida:\n");
    scanf("%d", &numero);

    aux = remove_na_chave(&cursor, numero);
    if(aux == NULL){
        printf("Celula com chave %d nao foi encontrada na lista!\n", numero);
    }else{
        printf("Remocao realizada com sucesso!\n");
    }

    printf("Lista depois da remocao da chave %d:\n", aux->chave);
    imprime(cursor);


    return 0;
}

void insere_antes_cursor(celula **cursor, int numero){
    celula *nova = (celula *) calloc(1, sizeof(celula));
    celula *aux;
    if(nova == NULL){
        printf("Erro ao alocar memoria na funcao insere_ante_cursor!\n");
        return;
    }

    nova->chave = numero;

    // verificando se a lista esta vazia
    if(*cursor == NULL){
        nova->prox = nova;  // isso porque a lista é circular, e nesse caso eu so tenho uma celula
        *cursor = nova;
    }else{
        aux = *cursor;

        // achando o no que vem antes do cursor
        while(aux->prox != *cursor){
            aux = aux->prox;
        }

        aux->prox = nova;
        nova->prox = *cursor;
    }
}

celula* remove_na_chave(celula **cursor, int numero){
    celula *aux, *no_removido = NULL;

    if(*cursor == NULL){

        // não há ninguem para ser removido
        return no_removido;
    }

    if((*cursor)->chave == numero){
        no_removido = *cursor;

        *cursor = no_removido->prox;  // avançando o cursor *cursor = (*cursor)->prox
    }else{

        aux = *cursor;

        while(aux->prox != *cursor && aux->prox->chave != numero){
            aux = aux->prox;
        }

        if(aux->prox != *cursor){
            // se eu entrar nessa condição, aux->prox é a minha celula atual. e é a celula a ser removida
            no_removido = aux->prox;
            aux->prox = no_removido->prox; // avançando o ponteiro. aux->prox = aux->prox->prox
        }
        
    }

    return no_removido;
}

void avancar_cursor(celula **cursor){

    *cursor = (*cursor)->prox;
}

void imprime(celula *cursor){
    celula *aux = cursor;

    do{
        printf("%d\n", aux->chave);
        aux = aux->prox;

    }while(aux != cursor);
}