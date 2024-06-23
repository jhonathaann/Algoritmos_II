#include <stdio.h>
#include <stdlib.h>

void leitura(int *lista, int n);

void impressao(int *lista, int n);

void selection_sort(int *lista, int n);

int main(){
    int *vetor, n;

    scanf("%d", &n);

    vetor = (int *) malloc(n * sizeof(int));

    if(vetor != NULL){
        printf("Entre com os valores do vetor:\n");

        leitura(vetor, n);

        selection_sort(vetor, n);

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

void selection_sort(int *lista, int n){ 
    int min, aux; // Declaração de variáveis para armazenar o índice mínimo e uma variável auxiliar para troca de elementos

    // loop mais externo, que percorrerá ate a penultima posiçao da lista
    for(int i = 0; i < n-1; i++){

        // define que o indice onde se encontra o menor da minha lista é o meu indice atual

        min = i;
        // loop para encontrar qual é de fato o indice do menor elemento disponivel na lista

        for(int j = i+1; j < n; j++){ 

            // se o elemento atual for menor que o mínimo atual
            if(lista[j] < lista[min]){

                // atualiza o indice do mínimo
                min = j; 
            }
        }
        // guarda o elemento atual em uma variavel auxiliar
        aux = lista[i]; 
        // substitui o elemento atual pelo mínimo encontrado
        lista[i] = lista[min];
        // substitui o mínimo encontrado pelo elemento atual da lista
        lista[min] = aux;
    }
}
