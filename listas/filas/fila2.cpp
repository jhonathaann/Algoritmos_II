/*Implementando a estrutura fila, mas realizando as operações
de inserção e remoção de forma diferente*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *prox;
}celula;

void inserir_na_fila(int numero, celula **inicio, celula **final);

int remover_da_fila(celula **inicio, celula **final);

void imprimir(celula *inicio);


int main(){

    // usando um ponteiro para ser o inicio da fila
    // e um outro pnteiro para ser o final de fila
    celula *inicio = NULL;
    celula *final = NULL;
    int opc, numero, aux;

    printf("\n0 - Sair\n1 - Inserir\n2 - Remover\n3 - Imprimir\n");
    scanf("%d", &opc);

    do{
        if(opc == 1){
            printf("Entre com um numero inteiro:\n");
            scanf("%d", &numero);
            
            inserir_na_fila(numero, &inicio, &final);
            
        }else if(opc == 2){
            aux = remover_da_fila(&inicio, &final);
            
            if(aux != -1){
                printf("\nCelula removida possui %d como chave!\n", aux);
            }
            
        }else if(opc == 3){
            imprimir(inicio);
        }

        printf("\n0 - Sair\n1 - Inserir\n2 - Remover\n3 - Imprimir\n");
        scanf("%d", &opc);

    }while(opc != 0);

    return 0;  
}

void inserir_na_fila(int numero, celula **inicio, celula **final){
    // criando uma celula nova, e ja alocando ela na memoria
    celula *nova = (celula *) malloc(sizeof(celula));

    if(nova == NULL){
        printf("Erro na alocacao!!\n");
        return;
    }

    nova->chave = numero;
    nova->prox = NULL;
    /*como a inserção de uma nova celula é sempre no final, o proximo
    dessa nova celula deve ser NULL. ja que essa nova celula vai estar na ultima
    posição*/

    //verificando se a fila esta vazia
    if(*inicio == NULL){
        //nesse caso, o inicio e o final vao ser os mesmos
        *inicio = nova;
        *final = nova;

    }else{

        (*final)->prox = nova;
        *final = nova;
    }

}

int remover_da_fila(celula **inicio, celula **final){
    // criando um ponteiro auxiliar
    celula *aux;
    int numero;

    // verificando se a fila ja esta vazia
    if(*inicio == NULL){
        // se sim, não tem ninguem para ser removido
        return -1;        
    }

    numero = (*inicio)->chave;
    aux = *inicio;

    *inicio = aux->prox;
    if(*inicio == NULL){
        *final = NULL;
    }

    free(aux);
    return numero;
}

void imprimir(celula *inicio){
    celula *p;
    printf("----------FILA------------\n");
    for(p = inicio; p != NULL; p = p->prox){
        printf("%d ", p->chave);
    }
}

