#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *prox;
    struct cel *ant;
}celula;

void insere_apos_cursor(celula **cursor, int numero);

void insere_antes_cursor(celula **cursor, int numero);  // nao esta correta

celula* remove_apos_cursor(celula **cursor);

void imprime(celula *cursor);

void imprime_inverso(celula *cursor);

int main(){
    celula *cursor = NULL;
    celula *aux;
    int numero;

    scanf("%d", &numero);

    while(numero != 0){

        insere_apos_cursor(&cursor, numero);

        scanf("%d", &numero);
    }

    printf("Lista original:\n");
    imprime(cursor);

    //printf("\nLista impressa de traz para frente:\n");
    //imprime_inverso(cursor);

    aux = remove_apos_cursor(&cursor);
    if(aux == NULL){
        printf("A lista ja esta vazia!\n");
    }else{
        printf("\nRemocao realizada! Celula removida possui %d como chave!\n", aux->chave);
        printf("Lista apos a remocao:\n");
        imprime(cursor);

        printf("\nLista impressa de traz para frente:\n");
        imprime_inverso(cursor);
    }

    
    return 0;
}

void insere_apos_cursor(celula **cursor, int numero){
    celula *nova = (celula *) calloc(1, sizeof(celula));
    
    if(nova == NULL){
        printf("Erro ao alocar memoria na funcao insere_apos_chave!\n");
        return;
    }

    nova->chave = numero;

    // a lista esta vazia?
    if(*cursor == NULL){
        nova->prox = nova;  // é uma lista circular, que nesse momento so possui essa "nova" como celula, por isso o ant e o prox dele aponta para ela mesmo
        nova->ant = nova;
        *cursor = nova;
    }else{

        nova->prox = (*cursor)->prox;  // fazendo o prox da nova celula apontar para a celula que vem depois do cursor
        (*cursor)->prox->ant = nova;   // fazendo o campo ant da celula logo apos o cursor apontar para a nova celula
        nova->ant = *cursor;  // fazendo o campo ant da nova celula apontar para o cursor (que é a nossa referencia de inicio nesse caso)

        // atualizando o prox do cursor
        (*cursor)->prox = nova;
    }
}

void insere_antes_cursor(celula **cursor, int numero){
    celula *nova = (celula *) calloc(1, sizeof(celula));
    celula *aux;
    if(nova == NULL){
        printf("Erro ao alocar memoria na funcao insere_antes_cursor!\n");
        return;
    }

    nova->chave = numero;

    // verificando se a lista esta vazia
    if(*cursor == NULL){
        nova->prox = nova;
        nova->ant = nova;

        *cursor = nova;

    }else{
        aux = *cursor;

        while(aux->prox != *cursor){
            aux = aux->prox;
        }

        // o campo ant da nova aponta para o antigo nó que vinha antes do cursor.
        nova->ant = aux;  // antigo porque o que vem antes do cursor agora é a "nova"
        
        // aux->prox é a celula imediatamente antes do cursor
        aux->prox = nova;

        nova->prox = *cursor;
    }
}

celula* remove_apos_cursor(celula **cursor){
    celula *no_removido = NULL;

    // a lista esta vazia?
    if(*cursor == NULL){
        return no_removido;
    }

    no_removido = (*cursor)->prox;

    // veficicando se a lista possui so uma celula
    if(no_removido == *cursor){
        *cursor = NULL;
    }else{

        (*cursor)->prox = no_removido->prox;  // (*cursor)->prox = (*cursor)->prox->prox


        //fazendo a celula que esta na frente do nó que sera removido apontar para o cursor
        no_removido->prox->ant = *cursor;  // (*cursor)->prox->prox->ant = *cursor
    }

    return no_removido;
}

void imprime(celula *cursor){
    celula *aux = cursor;

    do
    {
        printf("%d ", aux->chave);
        aux = aux->prox;

    } while (aux != cursor);
    
}

void imprime_inverso(celula *cursor){
    celula *aux = cursor;

    do
    {
        printf("%d ", aux->chave);
        aux = aux->ant;

    } while (aux != cursor);
}