#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *prox;
}celula_circular;

void insere_apos_cursor(celula_circular **cursor, int numero);

void avancar_cursor(celula_circular **cursor);

celula_circular* remover_apos_cursor(celula_circular **cursor);

void imprime(celula_circular *cursor);

int main(){
    celula_circular *cursor = NULL;
    celula_circular *aux;
    int numero;

    scanf("%d", &numero);

    while(numero != -1){

        insere_apos_cursor(&cursor, numero);

        scanf("%d", &numero);
    }

    imprime(cursor);

    //aux = remover_apos_cursor(&cursor);
    //if(aux != NULL){
        //printf("celula removida possui %d como chave!\n", aux->chave);
    //}else{
        //printf("lista esta vazia!\n");
    //}

    //imprime(cursor);
    
    return 0;
}

void insere_apos_cursor(celula_circular **cursor, int numero){
    celula_circular *nova = (celula_circular *) malloc(sizeof(celula_circular));

    if(nova == NULL){
        printf("Erro ao alocar memoria!\n");
        return;
    }
    nova->chave = numero;

    // verificando se a lista esta vazia
    if(*cursor == NULL){

        nova->prox = nova;  // isso porque a lista é circular, ou seja, se eu so tenho uma celula, o prox dela aponta para ele mesma
        *cursor = nova;   // atualizando o cursor, já que agora a lista ja nao esta mais vazia
    }else{
        nova->prox = (*cursor)->prox;

        // atualiza o proximo do cursor
        (*cursor)->prox = nova;
    }
}

celula_circular* remover_apos_cursor(celula_circular **cursor){
    celula_circular *aux;

    if(*cursor == NULL){
        // nao tem ninguem para ser removido
        return NULL;
    }else{

        aux = (*cursor)->prox;

        //verificando se a lista so possui uma celula
        // se ela so possui uma celula, o prox do cursor aponta para ele mesmo
        if(aux == *cursor){

            // cursor vai ser igual a null porque agora eu irei remover essa unica celula
            cursor = NULL;
        }else{

            (*cursor)->prox = aux->prox;   //(*cursor)->prox = (*cursor)->prox->prox
        }
    }

    // retornando a celula que foi removida
    return aux;
}

void avancar_cursor(celula_circular **cursor){

    *cursor = (*cursor)->prox;
}

void imprime(celula_circular *cursor){
    celula_circular *aux = cursor;

    do
    {
        printf("%d ", aux->chave);
        aux = aux->prox;

    } while (aux != cursor);
    
}
