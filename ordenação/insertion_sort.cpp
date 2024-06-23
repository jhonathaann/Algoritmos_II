#include <stdio.h>
#include <stdlib.h>

void leitura(int *lista, int n);

void impressao(int *lista, int n);

void insertion_sort(int *lista, int n);

int main(){
    int *vetor, n;

    scanf("%d", &n);

    vetor = (int *) malloc(n * sizeof(int));

    if(vetor != NULL){
         printf("Entre com os valores do vetor:\n");

        leitura(vetor, n);

        insertion_sort(vetor, n);

        impressao(vetor, n);
    }else{
        printf("erro na alocacao!\n");
    }

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

void insertion_sort(int *lista, int n){
    int aux, i, j; 

    // loop para percorrer a lista a partir do segundo elemento, ja que uma lista de tamanho 1 ja esta ordenada 
    for(i = 1; i < n; i++){ 
        // armazena o elemento atual em uma variável auxiliar
        aux = lista[i]; 
        
        // loop interno para mover os elementos maiores que o elemento atual para a direita
        for(j = i - 1; j >= 0 && lista[j] > aux;  j--){ 
            
            // move o elemento para a direita se nos ainda estivermos elementos a esquerda da nossa chave (aux)
            // E se o que esta na posição j for maior que a nossa chave (aux)
            lista[j+1] = lista[j];
        }

        // insere o elemento atual na posição correta
        lista[j+1] = aux; 
    }
}

