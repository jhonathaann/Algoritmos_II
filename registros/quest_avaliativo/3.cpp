#include <stdio.h>
#include <string.h>
#define MAX 30

typedef struct{
    char nome[MAX];
    char curso[MAX];
    int codigo;
}tipo_alunos;

void cadastra(tipo_alunos lista[]);

void busca(tipo_alunos lista[], char curso[]);


int main(){
    tipo_alunos lista[5];
    char aux[MAX];

    cadastra(lista);

    scanf("%[^\n]", aux);
    getchar();
    busca(lista, aux);

    return 0;

}

void cadastra(tipo_alunos lista[]){
    tipo_alunos *p;

    for(p = lista; p < lista + 5; p++){
        scanf("%d", &p->codigo);
        getchar();

        scanf("%[^\n]", p->nome);
        getchar();

        scanf("%[^\n]", p->curso);
        getchar();
    }
}

void busca(tipo_alunos lista[], char curso[]){
    tipo_alunos *p;
    int aux;

    for(p = lista; p < lista + 5; p++){
        aux = strcmp(p->curso, curso);
        if(aux == 0){
            printf("%d %s\n", p->codigo, p->nome);
        }
    }
}