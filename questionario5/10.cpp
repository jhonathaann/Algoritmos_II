#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel{
    char nome[20];
    char site[20];
    struct cel *prox;
}celula;

void insere_fim(celula **lista, char nome[], char site[]);

void insere_inicio(celula **lista, char nome[], char site[]);

celula* remove_na_chave(celula **lista, char nome[]);

void imprime(celula *lista);


int main(){
    celula *lista = NULL;
    celula *aux;
    char nome[20];
    char site[50];
    char nome_aux[20];

    scanf("%s", nome);

    while(strcmp(nome, "0") != 0){

        scanf(" %s", site);

        insere_fim(&lista, nome, site);

        scanf(" %s", nome);
        
    }

    scanf("%s", nome_aux);

    //printf("\nANTES DA REMOCAO\n");
    //imprime(lista);

    aux = remove_na_chave(&lista, nome_aux);
    if(aux != NULL){
        //printf("celula que foi removida possui %s como nome\n", aux->nome);

        insere_inicio(&lista, aux->nome, aux->site);
    }else{
        //printf("Nenhuma celula que foi removida!\n");
    }

    //printf("\nDEPOIS DA REMOCAO\n");
    imprime(lista);

    return 0;

}

void insere_inicio(celula **lista, char nome[], char site[]){
    celula *nova = (celula *) calloc(1, sizeof(celula));
    if(nova == NULL){
        printf("Erro ao alocar memoria na funcao insere_inicio!\n");
        return;
    }

    strcpy(nova->nome, nome);
    strcpy(nova->site, site);

    nova->prox = *lista;
    *lista = nova;

}

void insere_fim(celula **lista, char nome[], char site[]){
    celula *nova = (celula *) calloc(1, sizeof(celula));
    celula *aux;

    if(nova != NULL){
        strcpy(nova->nome, nome);
        strcpy(nova->site, site);
        nova->prox = NULL;

        //  verificando se a lista é NULL
        if(*lista == NULL){
            *lista = nova;

        }else{

            // achando a ultima celula
            aux = *lista;
            while(aux->prox != NULL){
                aux = aux->prox;
            }

            aux->prox = nova;
        }
    }else{

        printf("Erro ao alocar memoria na funcao insere_fim!\n");
    }
    

}

celula* remove_na_chave(celula **lista, char nome[]){
    celula *aux, *no_removido = NULL;

    // verificando se a lista nao esta vazia
    if(*lista != NULL){

        // vericicando se o no a ser removido é o primeiro
        if(strcmp((*lista)->nome, nome) == 0){
            no_removido = *lista;

            // atualizando o inicio da lista
            *lista = no_removido->prox;  // *lista = (*lista)->prox

        }else{
            aux = *lista;

            // strcmp((*lista)->prox->nome, nome) pelo visto nao funcionou.
            while(aux->prox != NULL && strcmp(aux->prox->nome, nome) != 0){
                aux = aux->prox;
            }

            // se o proximo nao for null, significa que eu achei qual celula contem a chave a ser removida
            if(aux->prox != NULL){
                no_removido = aux->prox;
                aux->prox = no_removido->prox;  // aux->prox = aux->prox->prox
            }
        }
    }

    return no_removido;
}

void imprime(celula *lista){
    celula *p;

    for(p = lista; p != NULL; p = p->prox){
        printf("%s %s\n", p->nome, p->site);
    }
}