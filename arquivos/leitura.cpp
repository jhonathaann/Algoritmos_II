#include <stdio.h>
#include <stdlib.h>

void leitura(int *lista, int n, FILE *pt_arq);

void impressao(int *lista, int n);

int main(){
    int *vetor, n;
    char nome_arquivo[15];
    FILE *pt_arq; // ponteiro para o arquivo

    printf("Digite o nome do arquivo:\n");
    scanf("%s", nome_arquivo);

    // abrindo o arquivo no modo de leitura e atribuindo ao ponteiro o endereco
    pt_arq = fopen(nome_arquivo, "r");

    if(pt_arq != NULL){

        // lendo a dimensao do vetor contida na primeira linha do arquivo
        fscanf(pt_arq, "%d", &n);

        vetor = (int *) malloc(n * sizeof(int));
        if(vetor != NULL){

            leitura(vetor, n, pt_arq);

            printf("valores lidos do arquivo de entrada:\n");
            impressao(vetor, n);

        }else{
            printf("Erro ao alocar o vetor na memoria!\n");
        }

    }else{
        printf("Erro ao abrir o arquivo!\n");
    }

}

void leitura(int *lista, int n, FILE *pt_arq){
    int *p;

    for(p = lista; p < lista + n; p++){

        // lendo os valores contidos na segunda linha do arquivo
        fscanf(pt_arq, "%d", p);
    }
}

void impressao(int *lista, int n){
    int *p;

    for(p = lista; p < lista + n; p++){
        printf("%d ", *p);
    }
}
