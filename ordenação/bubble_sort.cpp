#include <stdio.h>
#include <stdlib.h>

void leitura(int *lista, int n);

void impressao(int *lista, int n);

void bubble_sort(int *lista, int n);

int main(){
    int *vetor, n;

    scanf("%d", &n);

    vetor = (int *) malloc(n * sizeof(int));

    if(vetor != NULL){
        printf("Entre com os dados do vetor:\n");
        leitura(vetor, n);

        bubble_sort(vetor, n);

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

void bubble_sort(int *lista, int n){ 
    int aux; 
    // loop externo para percorrer toda a lista (vamos ate a penultima posicao)
    for(int i = n - 1; i > 0; i--){

        // loop interno para percorrer a lista até a posição atual de i
        for(int j = 0; j < i; j++){

            // se o elemento atual for maior que o seu sucessor
            if(lista[j] > lista[j+1]){
                
                // trocamos os dois de posicão
                aux = lista[j]; 
                lista[j] = lista[j+1]; 
                lista[j+1] = aux; 
            }
        }
    }
}
