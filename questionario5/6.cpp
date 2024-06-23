#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int valor;
    struct cel *proximo;
}celula;

void insere_fim(celula **inicio, celula **final, int numero);

celula* remove_na_chave(celula **inicio, int numero);

int ocorrencia(celula *inicio, int numero);

void removendo_repetidos(celula **inicio);

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

    removendo_repetidos(&inicio);

    imprime(inicio);

    return 0;
}


void insere_fim(celula **inicio, celula **final, int numero){
    celula *nova = (celula *) calloc(1, sizeof(celula));

    if(nova == NULL){
        printf("Erro ao alocar memoria!\n");
        return;
    }

    nova->valor = numero;
    nova->proximo = NULL;

    // verificando se a lista esta vazia
    if(*inicio == NULL){
        *inicio = nova;
        *final = nova;
    }else{

        (*final)->proximo = nova;
        *final = nova;
    }
}

celula* remove_na_chave(celula **inicio, int numero){
    celula *aux, *removida = NULL;

    // lista nao esta vazia?
    if(*inicio != NULL){

        // verificando se o numero a ser removido esta na primeira celula
        if((*inicio)->valor == numero){

            // faz o ponteiro "removida" apontar para o inicio da lista
            removida = *inicio;

            // atualiza o inicio da lista, que a agr começa na celula seguinte da celula que contem o numero
            *inicio = (*inicio)->proximo;

        }else{  // o numero a ser removido nao esta na primeira celula da lista
            aux = *inicio;

            while(aux->proximo != NULL && aux->proximo->valor != numero){
                aux = aux->proximo;
            }

            // verificando se o proximo existe. se sim, a numero da proxima celula é o numero a ser removido
            if(aux->proximo != NULL){
                removida = aux->proximo;
                aux->proximo = removida->proximo;
            }
        }
    }

    return removida;
}

void removendo_repetidos(celula **inicio){
    celula *p;

    for(p = *inicio; p != NULL; p = p->proximo){

        // se for 1, eu tenho que remover a celula que contem o p->valor
        if(ocorrencia(p, p->valor) == 1){
            //printf("tESTE\n");
            remove_na_chave(inicio, p->valor);
        }
    }
    
}

int ocorrencia(celula *inicio, int numero){
    int count = 0;

    while(inicio != NULL){

        if(inicio->valor == numero){
            count++;
        }

        if(count == 2){
            // o numero ocorre em mais de uma vez
            return 1;
        }

        inicio = inicio->proximo;
    }

    // o numero nao ocorre em mais de uma vez na lista
    return 0;
}

void imprime(celula *inicio){

    while(inicio != NULL){
        printf("%d ", inicio->valor);

        inicio = inicio->proximo;
    }
}