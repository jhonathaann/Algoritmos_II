#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 25

typedef struct{
    char nome[MAX];
    float p1, p2;
}novo_tipo;

int quantidade(char nome_arq[]);

void ler_do_arquivo(char nome_arq[], novo_tipo *lista, int n);

//void impressao(novo_tipo *lista, int n);

void salvar_no_arquivo(novo_tipo *lista, int n);

int main(int argc, char *argv[]){
    novo_tipo *vetor;
    char nome_arq[MAX];
    int n;

    // copiando o nome do arquivo que foi informado via linha de comando
    // considerando que o nome do arquivo foi informado logo apos o nome do executavel
    strcpy(nome_arq, argv[1]);

    n = quantidade(nome_arq);
    vetor = (novo_tipo *) calloc(n, sizeof(novo_tipo));
    if(vetor == NULL){
        printf("Nao foi possivel alocar o vetor na memoria!\n");
        return - 1;
    }

    ler_do_arquivo(nome_arq, vetor, n);

    //impressao(vetor, n);

    salvar_no_arquivo(vetor, n);

    free(vetor);

    return 0;
}

// funcao para saber quantas linhas o arquivo possui
int quantidade(char nome_arq[]){
    FILE *pt_arq = fopen(nome_arq, "r");
    if(pt_arq == NULL){
        printf("Nao foi possivel abrir o arquivo com nome %s na funcao quantidade!\n", nome_arq);
        return -1;
    }

    int soma = 0;
    char c;

    while((c = (fgetc(pt_arq))) != EOF){

        if(c == '\n'){
            soma++;
        }
    }

    fclose(pt_arq);
    printf("%d\n", soma);
    return soma;
}

void ler_do_arquivo(char nome_arq[], novo_tipo *lista, int n){
    FILE *pt_arq = fopen(nome_arq, "r");
    if(pt_arq == NULL){
        printf("Nao foi possivel abrir o arquivo com nome %s na funcao ler_do_arquivo!\n", nome_arq);
        return;
    }
    novo_tipo *p;

    for(p = lista; p < lista + n; p++){
        fscanf(pt_arq, "%s %f %f", p->nome, &p->p1, &p->p2);
    }

    fclose(pt_arq);
}

void impressao(novo_tipo *lista, int n){
    novo_tipo *p;

    for(p = lista; p < lista + n; p++){
        printf("%s %.2f %.2f\n", p->nome, p->p1, p->p2);
    }
}

void salvar_no_arquivo(novo_tipo *lista, int n){
    FILE *pt_arq = fopen("teste_saida.txt", "w");
    if(pt_arq == NULL){
        printf("Nao foi possivel criar o arquivo teste_saida.txt na funcao salvar_no_arquivo!\n");
        return;
    }
    novo_tipo *p;
    float aux;
    for(p = lista; p < lista + n; p++){
        aux = (p->p1 + p->p2)/2;

        fprintf(pt_arq, "Nome: %s   P1 = %.2f, P2 = %.2f    Media = %.2f\n", p->nome, p->p1, p->p2, aux);
    }

    fclose(pt_arq);
}