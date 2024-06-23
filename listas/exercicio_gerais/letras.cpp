#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    char c;
    struct cel *prox;
}celula;

void empilha(celula **topo, char digito);

void insere_fim(celula **lista, char letra);

void imprime(celula *lista);
int main(){
    celula *lista_letras = NULL;
    celula *lista_digitos = NULL;
    celula *lista_final = NULL;
    char c;
    //int digito;

    scanf("%c", &c);

    do{

        if(c >= '0' && c <= '9'){
            //  digito = c - '0'; nao vou transfomrar para int porque o registro tem apenas um campo para char
            empilha(&lista_digitos, c);
        }else{
            insere_fim(&lista_letras, c);
        }

    }while((c = getchar()) != '\n');

    printf("Lista com as letras:\n");
    imprime(lista_letras);

    printf("\nLista com os digitos:\n");
    imprime(lista_digitos);

    while(lista_letras != NULL){
        insere_fim(&lista_final, lista_letras->c);
        lista_letras = lista_letras->prox;
    }

     while(lista_digitos != NULL){
        insere_fim(&lista_final, lista_digitos->c);
        lista_digitos = lista_digitos->prox;
    }


    printf("\nLista final:\n");
    imprime(lista_final);
    
    return 0;

}

void empilha(celula **topo, char digito){
    celula *nova = (celula *) calloc(1, sizeof(celula));
    if(nova == NULL){
        printf("Erro ao alocar memoria na funcao empilha!\n");
        return;
    }

    nova->c = digito;
    nova->prox = *topo;
    *topo = nova;
}

void insere_fim(celula **lista, char letra){
    celula *nova = (celula *) calloc(1, sizeof(celula));
    celula *aux;
    if(nova == NULL){
        printf("Erro ao alocar memoria na funcao insere_fim\n");
        return;
    }
    nova->c = letra;
    nova->prox = NULL;

    if(*lista == NULL){
        *lista = nova;
    }else{
        aux = *lista;

        while(aux->prox != NULL){
            aux = aux->prox;
        }

        aux->prox = nova;
    }
}

void imprime(celula *lista){

    while(lista != NULL){
        printf("%c ", lista->c);

        lista = lista->prox;
    }
}