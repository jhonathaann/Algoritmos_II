#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int valor;
    struct cel *proximo;
}celula;

void insere_fim(celula **inicio, int numero, int flag);

int ocorrencia(celula *inicio, int numero);

void removendo_repetidos(celula **lista_repetidos, celula **lista_sem_repetidos);

void imprime(celula *inicio);

int main(){
    celula *lista_original = NULL;
    celula *lista_sem_repetidos = NULL;
    int numero;

    scanf("%d", &numero);

    while(numero != 0){
        
        insere_fim(&lista_original, numero, 0);

        scanf("%d", &numero);
    }

    removendo_repetidos(&lista_original, &lista_sem_repetidos);

    imprime(lista_sem_repetidos);

    return 0;
}

void insere_fim(celula **inicio, int numero, int flag){
    celula *aux, *nova = (celula *) calloc(1, sizeof(celula));

    if(nova == NULL){
        printf("Erro na alocacao de memoria!\n");
        return;
    }

    // se essa flag for 1, é porque eu estou chamando essa funçao depois de ter criado a minha lista original
    if(flag == 1){

        printf("kkk\n");
        // verificando se o numero ja esta na nova lista
        // se 1, é porque ele ja esta
        if(ocorrencia(*inicio, (*inicio)->valor) == 1){

            printf("olaa\n");
            return;
        }else{
            printf("hduwdbwu\n");
        }
    }
   
    nova->valor = numero;
    nova->proximo = NULL;

    // verificando se a lista esta vazia
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


void removendo_repetidos(celula **lista_repetidos, celula **lista_sem_repetidos){
    celula *p;
    
    for(p = *lista_repetidos; p != NULL; p = p->proximo){

        printf("teste\n");
        insere_fim(lista_sem_repetidos, p->valor, 1);
           
        
    }
    
}

int ocorrencia(celula *inicio, int numero){

    printf("%d\n", inicio->valor);
    while(inicio != NULL){

        // verificando se o numero ja esta na lista
        if(inicio->valor == numero){
            return 1;
        }

        inicio = inicio->proximo;
    }

    // o numero nao esta na lista
    return 0;
}

void imprime(celula *inicio){

    while(inicio != NULL){
        printf("%d ", inicio->valor);

        inicio = inicio->proximo;
    }
}