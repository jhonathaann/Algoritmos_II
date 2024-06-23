#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int numero;
    struct cel *proximo;
}celula;

void insere_inicio(celula **inicio, int numero);

double media(celula *inicio);


int main(){
    celula *inicio = NULL;
    int numero;

    scanf("%d", &numero);

    while(numero >= 0){
        insere_inicio(&inicio, numero);

        scanf("%d", &numero);
    }

    printf("%.2f\n", media(inicio));

    return 0;
}

void insere_inicio(celula **inicio, int numero){
    celula *nova = (celula *) calloc(1, sizeof(celula));

    if(nova == NULL){
        printf("Erro na alocacao de memoria!\n");
        return;
    }

    nova->numero = numero;
    nova->proximo = *inicio;
    *inicio = nova;
}

double media(celula *inicio){
    celula *p;
    double soma = 0.0;
    double quant = 0.0;

    for(p = inicio; p != NULL; p = p->proximo){
        soma += p->numero;
        quant++;
    }

    return soma/quant;
}