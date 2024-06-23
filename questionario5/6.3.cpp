#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int numero;
    struct cel *proximo;
}celula;

void insere_fim(celula **inicio, int numero);

void insere_sem_repetidos(celula **lista_repetidos, celula **lista_sem_repetidos);

int ocorrencia(celula *inicio, int numero);

void imprime(celula *lista);

int main(){
    celula *inicio =  NULL;
    celula *lista_sem_repetidos = NULL;
    int numero;

    scanf("%d", &numero);

    while(numero != 0){
        insere_fim(&inicio, numero);

        scanf("%d", &numero);
    }

    insere_sem_repetidos(&inicio, &lista_sem_repetidos);

    if(lista_sem_repetidos == NULL){
        printf("Lista vazia!\n");
    }else{
        imprime(lista_sem_repetidos);
    }


    return 0;
}

void insere_fim(celula **inicio, int numero){
    celula *aux, *nova = (celula *) calloc(1, sizeof(celula));

    if(nova == NULL){
        printf("Erro na alocacao!\n");
        return;
    }

    nova->numero = numero;
    nova->proximo = NULL;

    if(*inicio == NULL){

        *inicio = nova;

    }else{
        aux = *inicio;

        while(aux->proximo != NULL){
            aux = aux->proximo;
        }

        aux->proximo = nova;
    }
}

int ocorrencia(celula *inicio, int numero){
    celula *p;

    for(p = inicio; p != NULL; p = p->proximo){

        if(p->numero == numero){
            return 1;
        }
    }

    return 0;
}

void insere_sem_repetidos(celula **lista_repetidos, celula **lista_sem_repetidos){
    celula *p;

    for(p = *lista_repetidos; p != NULL; p = p->proximo){

        // verificando se o numero esta na lista sem repetidos, (se 0, significa que ele nao esta, entao eu posso inseri-lo)
        if(ocorrencia(*lista_sem_repetidos, p->numero) == 0){

            insere_fim(lista_sem_repetidos, p->numero);
        }
    }
}


void imprime(celula *lista){
    celula *p;

    for(p = lista; p != NULL; p = p->proximo){
        printf("%d ", p->numero);
    }
}
