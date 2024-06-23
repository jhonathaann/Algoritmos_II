#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[20];
    int quantidade;
}novo_tipo;

void leitura(novo_tipo *lista, int n);

void impressao(novo_tipo *lista, int n);

void insertion_sort(novo_tipo *lista, int n);

int main(){
    novo_tipo *vetor;
    int n;

    scanf("%d", &n);
    getchar();

    vetor = (novo_tipo *) malloc(n * sizeof(novo_tipo));
    if(vetor == NULL){
        printf("Nao foi possivel alocar o vetor na memoria!\n");
        return 1;
    }

    leitura(vetor, n);
    //impressao(vetor, n);

    insertion_sort(vetor, n);
    //printf("\n");
    impressao(vetor, n);

    free(vetor);
    return 0;
}

void leitura(novo_tipo *lista, int n){
    novo_tipo *p;

    for(p = lista; p < lista + n; p++){
        scanf("%s %d", p->nome, &p->quantidade);
        getchar();

    }
}

void impressao(novo_tipo *lista, int n){
    novo_tipo *p;

    for(p = lista; p < lista + n; p++){
        printf("%s ", p->nome);
    }
}

// insertion_sort de forma decrescente
void insertion_sort(novo_tipo *lista, int n){
    int aux, i, j;
    char nome_aux[20];

    for(i = 1; i < n; i++){
        aux = lista[i].quantidade;
        strcpy(nome_aux, lista[i].nome);

        for(j = i - 1; j >= 0 && lista[j].quantidade < aux;  j--){
            lista[j+1].quantidade = lista[j].quantidade;
           
        }

        lista[j+1].quantidade = aux;
        strcpy(lista[i].nome, lista[j+1].nome);
        strcpy(lista[j+1].nome, nome_aux);
    }
}