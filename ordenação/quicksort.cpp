#include <stdio.h>
#include <stdlib.h>

void leitura(int *lista, int n);

void impressao(int *lista, int n);

int separa(int p, int r, int *lista);

void quicksort(int comeco, int fim, int *lista);

int main(){
    int *vetor, n;

    scanf("%d", &n);

    vetor = (int *) malloc(n * sizeof(int));

    if(vetor != NULL){
        printf("Entre com os valores no vetor:\n");
        leitura(vetor, n);

        quicksort(0, n-1, vetor);

        impressao(vetor, n);
    }else{
        printf("erro ao alocar!\n");
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

// função para separar os elementos da lista em torno de um pivô
int separa(int comeco, int fim, int *lista) {
    int x, i, j;

    // define o pivô como o elemento no índice "comeco"
    x = *(lista + comeco);  // lista[comeco]

    // inicializa o índice 'i' antes do começo da lista
    i = comeco - 1;
    // inicializa o índice 'j' após o final da lista
    j = fim + 1;

    // loop infinito para iterar até que a separação seja concluída
    while (1) {
        
        // encontra um elemento maior ou igual ao pivô, a partir do final da lista
        do {
            j--;
        } while (*(lista + j) > x);  // lista[j]

        // encontra um elemento menor ou igual ao pivô, a partir do começo da lista
        do {
            i++;
        } while (*(lista + i) < x);  // lista[i]

        // se os índices 'i' e 'j' não se cruzarem
        if (i < j) {
            // troca os elementos nos índices 'i' e 'j'
            int aux = *(lista + i);
            *(lista + i) = *(lista + j);
            *(lista + j) = aux;
        } else {
            // retorna o índice 'j' que indica a posição do pivô
            return j;
        }
    }
}

void quicksort(int comeco, int fim, int *lista) {
    int particao;

    // se o começo é menor que o fim (ainda há elementos para ordenar)
    if (comeco < fim) {
        // realiza a partição e obtém o índice do pivô
        particao = separa(comeco, fim, lista);

        // ordena recursivamente a parte esquerda do pivô
        quicksort(comeco, particao, lista);
        // ordena recursivamente a parte direita do pivô
        quicksort(particao + 1, fim, lista);
    }
}
