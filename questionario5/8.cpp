#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int numero;
    struct cel *proximo;
}celula;

void insere_fim(celula **inicio, int numero);

void remove_k_esimo(celula **inicio, int indice);

void imprime(celula *inicio);

int main(){
    celula *inicio = NULL;
    int n, numero, indice;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &numero);

        insere_fim(&inicio, numero);
    }

    // lendo o indice para a remoção
    scanf("%d", &indice);

    remove_k_esimo(&inicio, indice);

    if(inicio == NULL){
        printf("Lista vazia!\n");
    }else{
        imprime(inicio);
    }


    return 0;
}

void insere_fim(celula **inicio, int numero){
    celula *nova = (celula *) calloc(1, sizeof(celula));
    celula *aux;
    
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

void remove_k_esimo(celula **inicio, int indice){
    celula *p = *inicio;
    int contador = 1;

    // vericicando se a lista esta vazia (lembrando que p = *inicio)
    if(*inicio == NULL){
        return;
    }

    // verificando se o indice é 1 (nesse caso eu tenho que remover a primeira celula)
    if(indice == 1){

        // verificando se a lista so contem uma celula
        if(p->proximo == NULL){

            // nesse caso, a lista vai ficar vazia
            *inicio = NULL;
            return;

        }else{

            // aqui, como eu vou remover a primeira celula, e a lista nao tem so uma celula, eu atualizo o inicio da lista para a celula seguinte
            *inicio = p->proximo;
            free(p);
            return;
        }

    }else{

        // aqui nao vai ser a primeira celula que eu vou remover

        celula *anterior = NULL;

        while(p != NULL && contador < indice){

            anterior = p;  // anterior passa a ser o p
            p = p->proximo;
            contador++;
        }

        // encontrei o k-esimo elemento
        if(p != NULL){

            /*o p esta apontando justamente para o registro que contem o k-esimo elemento*/
            anterior->proximo = p->proximo;

            free(p);
        }
    }
}



void imprime(celula *inicio){
    celula *p;

    for(p = inicio; p!= NULL; p = p->proximo){
        printf("%d ", p->numero);
    }
}