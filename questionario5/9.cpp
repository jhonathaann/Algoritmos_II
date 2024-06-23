#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int numero;
    struct cel *proximo;
}celula;

void insere_fim(celula **inicio, celula **final, int numero);

celula* remove_na_chave(celula **inicio, int chave);

void removendo_pares(celula **inicio);

void imprime(celula *inicio);


int main(){
    celula *inicio = NULL;
    celula *final = NULL;
    int numero;

    scanf("%d", &numero);
    while(numero != 0){
        insere_fim(&inicio, &final, numero);

        scanf("%d", &numero);
    }

    removendo_pares(&inicio);

    imprime(inicio);

    return 0;
}

void insere_fim(celula **inicio, celula **final, int numero){
    celula *nova = (celula *) calloc(1, sizeof(celula));

    if(nova == NULL){
        printf("Erro ao alocar memoria!\n");
        return;
    }

    nova->numero = numero;
    nova->proximo = NULL;

    if(*inicio == NULL){
        *inicio = nova;
        *final = nova;
    }else{
        (*final)->proximo = nova;
        *final = nova;
    }
}

void imprime(celula *inicio){

    while(inicio != NULL){
        printf("%d ", inicio->numero);

        inicio = inicio->proximo;
    }
}

celula* remove_na_chave(celula **inicio, int chave){
    celula *aux, *no_removido = NULL;

    // verificando se a lista não esta vazia
    if(*inicio != NULL){

        if((*inicio)->numero == chave){
            no_removido = *inicio;
            *inicio = no_removido->proximo;
    
        }else{
            aux = *inicio;
            while(aux->proximo != NULL && aux->proximo->numero != chave){
                aux = aux->proximo;
            }

            if(aux->proximo != NULL){
                no_removido = aux->proximo;
                aux->proximo = no_removido->proximo;
            }
        }
    }

    return no_removido;
}

void removendo_pares(celula **inicio){
    celula *p;

    for(p = *inicio; p != NULL; p = p->proximo){
        if(p->numero % 2 == 0){
            remove_na_chave(inicio, p->numero);
        }
    }
}