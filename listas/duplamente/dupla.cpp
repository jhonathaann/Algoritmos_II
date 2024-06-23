#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *prox;
    struct cel *ant;
}celula;

void insere_inicio(celula **lista, int numero);

void insere_fim(celula **lista, int numero);

celula* remove_na_chave(celula **lista, int numero);

void imprime(celula *lista);


int main(){
    celula *lista = NULL;
    celula *aux;
    int numero;

    scanf("%d", &numero);
    while(numero != -1){

        insere_fim(&lista, numero);

        scanf("%d", &numero);
    }

    imprime(lista);

    aux = remove_na_chave(&lista, 5);
    if(aux != NULL){
        printf("\nCelula que foi removida possui %d como chave!\n",  aux->chave);
    }

    printf("\n");
    imprime(lista);

    return 0;

}

void insere_inicio(celula **lista, int numero){
    celula *nova = (celula *) calloc(1, sizeof(celula));

    if(nova == NULL){
        printf("Erro na alocacao!\n");
        return;
    }

    nova->chave = numero;

    nova->prox = *lista;

    // como essa nova celual sera a primera, oq vem antes dela deve ser sempre nuloi
    nova->ant = NULL;

    // lista não esta vazia?
    if(*lista != NULL){
        // se não estiver vazia, a celula anterior da lista recebe a nova celula
        (*lista)->ant = nova;
    }

    // atualiza o inicio da lista
    *lista = nova;
}

void insere_fim(celula **lista, int numero){
    celula *nova = (celula *) malloc(sizeof(celula));
    celula *aux;

    if(nova == NULL){
        printf("Erro na alocacao!\n");
        return;
    }
    nova->chave = numero;
    nova->prox = NULL;

    // verificando se a lista esta vazia
    if(*lista == NULL){
        *lista = nova;  //lista estando vazia, esse nova celula sera a unica celula da minha lista
        nova->ant = NULL;

    }else{
        aux = *lista;

        while(aux->prox != NULL){
            aux = aux->prox;
        }

        // esse laço saiu quando o aux->prox == NULL. como a inserção aqui é no final, aux->prox tem que receber essa nova celula
        aux->prox = nova;
        
        //como é duplamente encadeada, o ant da nova celula tem que receber esse aux, que agora é p penultimo elemento da lista
        nova->ant = aux;
    }
}

celula* remove_na_chave(celula **lista, int numero){
    celula *aux = NULL;

    aux = *lista;
    while(aux != NULL && aux->chave != numero){
        aux = aux->prox;
    }

    if(aux == NULL){
        printf("Chave %d nao encontrada na lista!\n", numero);
        return NULL;
    }else{

        // a celula a ser removida é a primeira?
        if(aux->ant == NULL){
            // avança o ponteiro do inicio da lista
            *lista = (*lista)->prox;

            // se a lista não ficar nulla, signifca que a lista inicialmente tinha mais de um elemento. como eu removi o primeiro
            // o anterior agora deve ser nulo
            if(*lista != NULL){
                (*lista)->ant = NULL;
            }
        }else{

            aux->ant->prox = aux->prox;  // (aux->ant)->prox = aux->prox

            // se a celula a ser removida não for a ultima
            if(aux->prox != NULL){
                aux->prox->ant = aux->ant;  // (aux->prox)->ant = aux->ant
            }
        }
        
    }

    return aux;
}

void imprime(celula *lista){

    while(lista != NULL){
        printf("%d ", lista->chave);
        lista = lista->prox;
    }
}