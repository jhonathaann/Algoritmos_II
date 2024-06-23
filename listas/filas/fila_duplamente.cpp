#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int numero;
    struct cel *prox;
    struct cel *ant;
}celula;

// na fila, a inserção é sempre no final
void insere_final(celula **inicio, celula **final, int numero);

//remoção na fila é sempre no primeiro nó
celula* remove_da_fila(celula **inicio, celula **final);

void imprime(celula *inicio);

void imprime_inverso(celula *final);

int main(){
    celula *inicio = NULL, *final = NULL;
    celula *aux;
    int numero;

    scanf("%d", &numero);

    while(numero != 0){

        insere_final(&inicio, &final, numero);

        scanf("%d", &numero);
    }

    printf("original:\n");
    imprime(inicio);
    printf("\ninverso:\n");
    imprime_inverso(final);

    aux = remove_da_fila(&inicio,  &final);
    if(aux == NULL){
        printf("Fila ja esta vazia!\n");
    }else{
        printf("A primeira celula da fila foi removida! a sua chave era: %d\n", aux->numero);
    }

    printf("original:\n");
    imprime(inicio);
    printf("\ninverso:\n");
    imprime_inverso(final);

    return 0;
}

void insere_final(celula **inicio, celula **final, int numero){
    celula *nova = (celula *) malloc(sizeof(celula));
    if(nova == NULL){
        printf("Erro ao alocar memoria!\n");
        return;
    }

    nova->numero = numero;
    nova->prox = NULL;

    // verificando se a lista esta vazia
    if(*inicio == NULL){

        nova->ant = NULL;

        *inicio = nova;
        *final = nova;
    }else{

        // a nova celula vai ficar na ultima posicao. portanto, a antiga ultima celula deve ficar antes da nova
        nova->ant = *final;

        (*final)->prox = nova;
        *final = nova;
    }
}

celula* remove_da_fila(celula **inicio, celula **final){
    celula *celula_removida;

    // verificando se a fila esta vazia
    if(*inicio == NULL){
        return NULL;
    }

    // a celula que vai ser removida é a primeira
    celula_removida = *inicio;

    // andei com o ponteiro do inicio
    *inicio = (*inicio)->prox;
    (*inicio)->ant = NULL;

    // se depois de eu andar com o inicio ele ficar NULL, é porque a fila so tinha uma celula
    if(*inicio == NULL){
        *final = NULL;
    }

    return celula_removida;
}

void imprime(celula *inicio){
    celula *p;

    for(p = inicio; p != NULL; p = p->prox){
        printf("%d ", p->numero);
    }
}

void imprime_inverso(celula *final){
    celula *p;

    for(p = final; p != NULL; p = p->ant){
        printf("%d ", p->numero);
    }
}