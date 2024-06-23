/*FILAS: o primeiro a entrar é o primiero a sair
a inserção ocorre sempre no final e a remoção sempre
no começo da fila*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *prox;
}celula;

void inserir_na_fila(int numero, celula **fila);

celula* remover_da_fila(celula **fila);

void imprimir(celula *fila);

int main(){
    celula *fila = NULL;
    celula *aux;
    int opc, numero;

    printf("\n0 - Sair\n1 - Inserir\n2 - Remover\n3 - Imprimir\n");
    scanf("%d", &opc);

    do{
        if(opc == 1){
            printf("Entre com um numero inteiro:\n");
            scanf("%d", &numero);
            
            inserir_na_fila(numero, &fila);
            
        }else if(opc == 2){
            aux = remover_da_fila(&fila);
            
            if(aux != NULL){
                printf("\nCelula removida possui %d como chave!\n", aux->chave);
            }
            
        }else if(opc == 3){
            imprimir(fila);
        }

        printf("\n0 - Sair\n1 - Inserir\n2 - Remover\n3 - Imprimir\n");
        scanf("%d", &opc);

    }while(opc != 0);

    return 0;  
}

void inserir_na_fila(int numero, celula **fila){
    // criando a minha nova celula, e ja alocando ela na memoria
    celula *nova = (celula *) malloc(sizeof(celula));

    // criando um registro auxiliar
    celula *aux;

    if(nova != NULL){
        nova->chave = numero;
        nova->prox = NULL; // NULL, pois toda inserção na fila é no final, logo o prox deve ser NULL

        // verificando se fila esta vazia
        if(*fila == NULL){

            /*sendo NULL, a fila esta vazia, ou seja, *fila já é
            o último nó da minha estrutura*/

            *fila = nova;

        }else{
            /*nesse caso, a fila não esta vazia. por isso, temos que percorrer
            toda ela para poder encontrar a ultima celula*/
            aux = *fila;

            while(aux->prox != NULL){
                /*aux->proximo != NULL e não aux != NULL
                pq se aux->proximo for NULL, significa que eu estou
                na minha ultima celula, ou seja, aux esta nesse momento no
                ultimo nó da fila*/

                aux = aux->prox;
            }

            aux->prox = nova;
        }
    }else{
        printf("Erro ao alocar memoria!\n");
        return;
    }

}

celula* remover_da_fila(celula **fila){
    // criando um ponteiro auxiliar
    celula *aux = NULL;

    // verificando se a fila não esta vazia
    if(*fila != NULL){

        // ponteiro auxiliar aponta para o primeiro elemento da fila
        aux = *fila;

        // atualiza o inicio da fila
        *fila = aux->prox;
    }else{
        printf("Fila esta vazia!!\n");
        return NULL;
    }

    // retornando a celula que foi removida
    return aux;
}

void imprimir(celula *fila){
    celula *p;

    for(p = fila; p != NULL; p = p->prox){
        printf("\n%d\n", p->chave);
    }
}