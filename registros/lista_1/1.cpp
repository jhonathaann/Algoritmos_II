#include <stdio.h>
#define MAX 50

typedef struct novoT{
    char nome[MAX];
    int matricula;
    float n1, n2, media;
}novoT;

void cadastrar(novoT lista[], int posicao);

void imprime(novoT lista[], int n);

int main(){
    novoT lista[MAX];
    int n;

    printf("Infome o valor de N: \n");
    scanf("%d", &n);
    getchar();

    for(int i = 0; i < n; i++){
        cadastrar(lista, i);
    }

    imprime(lista, n);

    return 0;
}

void cadastrar(novoT lista[], int posicao){

    printf("Informe o nome do(a) aluno(a): \n");
    scanf("%[^\n]", lista[posicao].nome);
    getchar();

    printf("informe o codigo da matricula: \n");
    scanf("%d", &lista[posicao].matricula);
    getchar();

    printf("Informe a nota da p1: \n");
    scanf("%f", &lista[posicao].n1);

    printf("Informe a nota da p2: \n");
    scanf("%f", &lista[posicao].n2);


    getchar();

    lista[posicao].media = (lista[posicao].n1 + lista[posicao].n2) / 2;

}

void imprime(novoT lista[], int n){
    
    for(int i = 0; i < n; i++){
        printf("----------------------------------\n");
        printf("nome: %s\n", lista[i].nome);
        printf("matricula: %d\n", lista[i].matricula);
        printf("media: %.2f\n", lista[i].media);
        printf("\n");

    }
}