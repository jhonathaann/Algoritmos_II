#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel{
    char nome[31];
    struct cel *proximo;
}celula;

void insere_na_lista(celula **lista, char nome[]);

celula* interseccao(celula *lista1, celula *lista2);

int busca(celula *lista, char nome[]);

void imprime(celula *lista);

int main(){
    celula *lista1, *lista2, *lista3;
    lista1 = NULL;
    lista2 = NULL;

    char nome[31];

    scanf("%s", nome);

    while(strcmp(nome, "FIM") != 0){
        
        insere_na_lista(&lista1, nome);

        scanf("%s", nome);

    }

    scanf("%s", nome);

    while(strcmp(nome, "FIM") != 0){
        
        insere_na_lista(&lista2, nome);

        scanf("%s", nome);

    }

    lista3 = interseccao(lista1, lista2);

    if(lista3 == NULL){
        printf("VAZIA\n");
    }else{
        imprime(lista3);
    }   

    //imprime(lista1);
    //imprime(lista2);


    return 0;

}

celula* interseccao(celula *lista1, celula *lista2){
    celula *lista_aux = NULL;
    celula *p;

    for(p = lista1; p != NULL; p = p->proximo){

        // se for 1, significa que o nome que eu peguei na lista1 "p->nome" esta na lista2
        if(busca(lista2, p->nome) == 1){
            insere_na_lista(&lista_aux, p->nome);
        }
    }

    return lista_aux;

}

int busca(celula *lista, char nome[]){
    celula *p;

    for(p = lista; p != NULL; p = p->proximo){

        if(strcmp(p->nome, nome) == 0){
            return 1;
        }
    }

    // não achei nenhum nome da lista igual ao nome que eu recebi como parametro na função
    return 0;
}

// fazendo inserção no final da fila
void insere_na_lista(celula **lista, char nome[]){
    celula *nova = (celula *) malloc(sizeof(celula));
    celula *aux;

    if(nova == NULL){
        printf("Erro ao alocar memoria!\n");
        return;
    }

    strcpy(nova->nome, nome);
    nova->proximo = NULL;  //null, pois toda inserção na fila é no final

    // verificando se a lista esta vazia
    if(*lista == NULL){

        *lista = nova;
    }else{

        aux = *lista;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }

        aux->proximo = nova;
    }
    
}

void imprime(celula *lista){
    celula *p;

    for(p = lista; p != NULL; p = p->proximo){
        printf("%s ", p->nome);
    }
}

