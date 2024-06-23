#include <stdio.h>
#define MAX 20

typedef struct{
    char nome[MAX];
    float nota;
}tipo_alunos;

void leitura(tipo_alunos lista[]);

float media(tipo_alunos lista[]);

void imprime(tipo_alunos lista[]);


int main(){
    tipo_alunos lista[5];
    int codigo;
    float aux;

    scanf("%d", &codigo);

    leitura(lista);

    printf("Sala: %d\n", codigo);
    imprime(lista);
    
    aux = media(lista);

    printf("Media: %.2f", aux);

    return 0;
}

void leitura(tipo_alunos lista[]){
    tipo_alunos *p;

    for(p = lista; p < lista + 5;p++){
        scanf("%s", p->nome);
        scanf("%f", &p->nota);
    }
}

float media(tipo_alunos lista[]){
    tipo_alunos *p;
    float soma = 0;

    for(p = lista; p < lista + 5;p++){
        soma += p->nota;
    }

    return soma/5;
}

void imprime(tipo_alunos lista[]){
    tipo_alunos *p;

    for(p = lista; p < lista + 5;p++){
        printf("%s %.2f\n", p->nome, p->nota);
    }
}