#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct{
    char primeiro_nome[MAX];
    char segundo_nome[MAX];
    char sexo, cor_olhos;
    float peso, altura;
}novo_tipo;

int quantidade(const char nome_arquivo[]);

void leitura_via_arquivo(novo_tipo *lista, const char nome_arquivo[], int n);

void separando_dados(novo_tipo *lista, int n);

void impressao(novo_tipo *lista, int n);

int main(){
    novo_tipo *vetor;
    int n;

    n = quantidade("dados.txt");
    //printf("%d\n", n);

    vetor = (novo_tipo *) malloc(n * sizeof(novo_tipo));
    if(vetor == NULL){
        printf("Nao foi possivel alocar o vetor na memoria!\n");
        return -1;
    }

    leitura_via_arquivo(vetor, "dados.txt", n);
    //impressao(vetor, n);

    separando_dados(vetor, n);

    free(vetor);

    return 0;
}

int quantidade(const char nome_arquivo[]){
    int aux = 0;
    char c;
    FILE *pt_arq = fopen(nome_arquivo, "r");

    if(pt_arq == NULL){
        printf("Nao foi possivel abrir o arquivo!\n");
        return -1;
    }

    while ((c = fgetc(pt_arq)) != EOF) {
        //printf("%c", c);
        if (c == '\n') {
            aux++;
        }
    }    

    fclose(pt_arq);
    return aux;
}

void impressao(novo_tipo *lista, int n){
    novo_tipo *p;

    for(p = lista; p < lista + n; p++){
        printf("%s %s\n", p->primeiro_nome, p->segundo_nome);
        printf("%c\n",p->sexo);
        printf("%c\n",p->cor_olhos);
        printf("%.2f\n",p->altura);
        printf("%.2f\n", p->peso);
    }
}


void leitura_via_arquivo(novo_tipo *lista, const char nome_arquivo[], int n){
    novo_tipo *p;
    FILE *pt_arq = fopen(nome_arquivo, "r");

    if(pt_arq == NULL){
        printf("Nao foi possivel abrir o arquivo!\n");
        return;
    }

    for(p = lista; p < lista + n; p++){
        fscanf(pt_arq, "%s %s %c %c %f %f\n", p->primeiro_nome, p->segundo_nome, &p->sexo, &p->cor_olhos, &p->altura, &p->peso);
    }

    fclose(pt_arq);
}

void separando_dados(novo_tipo *lista, int n){
    novo_tipo *p;
    FILE *pt_arqH = fopen("dados_homen.txt", "w");
    FILE *pt_arqM = fopen("dados_mulher.txt", "w");

    if(pt_arqH == NULL || pt_arqM == NULL){
        printf("Erro ao abrir o(s) arquivo(s)!\n");
        return;
    }

    for(p = lista; p < lista + n; p++){
        if(p->sexo == 'M'){
            fprintf(pt_arqH, "Nome: %s %s, Sexo: %c, Cor dos olhos: %c, Alura: %.2f, Peso: %.2f\n", p->primeiro_nome, p->segundo_nome, p->sexo, p->cor_olhos, p->altura, p->peso);

        }else if(p->sexo == 'F'){
            fprintf(pt_arqM, "Nome: %s %s, Sexo: %c, Cor dos olhos: %c, Alura: %.2f, Peso: %.2f\n", p->primeiro_nome, p->segundo_nome, p->sexo, p->cor_olhos, p->altura, p->peso);
        }
    }

    fclose(pt_arqH);
    fclose(pt_arqM);
}