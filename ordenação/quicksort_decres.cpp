#include <stdio.h>
#include <stdlib.h>

void leitura(int *lista, int n);

void impressao(int *lista, int n);

int separa(int comeco, int fim, int *lista);

void quicksort(int comeco, int fim, int *lista);

int main(){
    int *vetor, n;

    scanf("%d", &n);

    vetor = (int *) malloc(n * sizeof(int));
    if(vetor == NULL){
        printf("Nao foi possivel alocar o vetor!\n");
        return 1;
    }

    leitura(vetor, n);

    quicksort(0, n-1, vetor);

    impressao(vetor, n);

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

int separa(int comeco, int fim, int *lista){
    int pivo, i, j;

    pivo = *(lista+comeco);
    i = comeco-1;
    j = fim+1;

    while(1){
        do{
            j--;
        }while(*(lista+j) < pivo);  // alteraçao na comparação, para que a ordenação seja decrescente

        do{
            i++;
        }while(*(lista+i) > pivo);  // alteraçao na comparação, para que a ordenação seja decrescente

        if(i < j){

            int aux = *(lista+i);
            *(lista+i) = *(lista+j);
            *(lista+j) =  aux;

        }else{
            return j;
        }
    }
}

void quicksort(int comeco, int fim, int *lista){
    int particao;

    if(comeco < fim){
        particao = separa(comeco, fim, lista);

        quicksort(comeco, particao, lista);
        quicksort(particao+1, fim, lista);
    }
}