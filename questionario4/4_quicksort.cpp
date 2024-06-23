#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[20];
    int quantidade;
}novo_tipo;

void leitura(novo_tipo *lista, int n);

void impressao(novo_tipo *lista, int n);

int sepera(int comeco, int fim, novo_tipo *lista);

void quicksort(int comeco, int fim, novo_tipo *lista);


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

    //printf("\n");
    quicksort(0, n-1, vetor);

    impressao(vetor, n);
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

int sepera(int comeco, int fim, novo_tipo *lista){
    int pivo, i, j;

    pivo = lista[comeco].quantidade;
    i = comeco - 1;
    j = fim + 1;

    while(1){
        
        do{
            j--;
        }while(lista[j].quantidade < pivo);

        do{
            i++;
        }while(lista[i].quantidade > pivo);

        if(i < j){

            int aux = lista[i].quantidade;
            lista[i].quantidade = lista[j].quantidade;
            lista[j].quantidade = aux;

            char nome_aux[20];
            strcpy(nome_aux, lista[i].nome);
            strcpy(lista[i].nome, lista[j].nome);
            strcpy(lista[j].nome, nome_aux);

        }else{
            return j;
        }
    }
}

void quicksort(int comeco, int fim, novo_tipo *lista){
    int particao;

    if(comeco < fim){
        particao = sepera(comeco, fim, lista);

        quicksort(comeco, particao, lista);
        quicksort(comeco+1, fim,lista);
    }
}