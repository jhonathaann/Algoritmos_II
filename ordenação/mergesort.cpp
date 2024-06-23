#include <stdio.h>
#include <stdlib.h>

void leitura(int *lista, int n);

void impressao(int *lista, int n);

void intercala(int *lista, int inicio, int meio, int fim);

void mergesort(int *lista, int comeco, int fim);

int main(){
    int *vetor, n;

    scanf("%d", &n);

    vetor = (int *) malloc(n * sizeof(int));
    if(vetor != NULL){
        printf("Entre com os numeros no vetor:\n");
        leitura(vetor, n);

        mergesort(vetor, 0, n);

        impressao(vetor, n);
    }else{
        printf("erro na alocacao!\n");
    }

    free(vetor);

    return 0;
}

void leitura(int *lista, int n){
    int *p;

    for(p = lista; p < lista + n; p++){
        scanf("%d", p);
    }
}

void impressao(int *lista, int n){
    int *p;

    for(p = lista; p < lista + n; p++){
        printf("%d ", *p);
    }
}

void intercala(int *lista, int inicio, int meio, int fim){
    int i, j, k, W[fim];

    i = inicio;
    j = meio;
    k = 0;

    // enquanto ainda houver elementos nas duas metades da lista
    while(i < meio && j < fim){

        // se o elemento na primeira metade for menor que o elemento na segunda metade
        if(*(lista + i) < *(lista + j)){

            // coloca o elemento na posição correta em W
            *(W + k) = *(lista + i);
            i++;
        }else{
             // coloca o elemento na posição correta em W
            *(W + k) = *(lista + j);
            j++;
        }
        k++;
    }

    // sobraram valores na primeira parte do vetor
    while(i < meio){

        // coloca os elementos restantes na posição correta em W
        *(W + k) = *(lista + i);
        i++;
        k++;
    }

    // sobraram valores na segunda parte do vetor
    while(j < fim){

        // coloca os elementos restantes na posição correta em W
        *(W + k) = *(lista + j);
        j++;
        k++;
    }

    // copia o auxiliar (W) para o vetor original
    for(i = inicio; i < fim; i++){
        *(lista + i) = *(W+i-inicio);
    }
}

void mergesort(int *lista, int comeco, int fim){

    int particao;

    // verifica se a lista tem mais de um elemento
    if(comeco < fim -1){
        particao = (comeco + fim) / 2;

        // ordena a primeira metade da lista
        mergesort(lista, comeco, particao);
        // ordena a segunda metade da lista
        mergesort(lista, particao, fim);

        // combina a duas metades ordenadas
        intercala(lista, comeco, particao, fim);
    }   

}

