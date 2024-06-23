#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct{
    char nome[MAX], curso[MAX];
    long int rga;
}novo_tipo;

//void ler_do_arquivo(FILE *pt_arq, novo_tipo *lista, int n);

int quantidade(const char nome_arq[]);

void ler_do_arq(const char nome_arq[], novo_tipo *lista, int n);

void impressao(novo_tipo *lista, int n);

void salvar_nos_arquivos(novo_tipo *lista, int n); 

int main(){
    novo_tipo *vetor;
    int n = quantidade("nomes_cursos.txt");

    //printf("n = %d\n", n);

    vetor = (novo_tipo *) calloc(n, sizeof(novo_tipo));
    if(vetor == NULL){
        printf("Erro ao alocar o vetor!\n");
        return -1;
    }

    ler_do_arq("nomes_cursos.txt", vetor, n);
    
    //impressao(vetor, n);

    salvar_nos_arquivos(vetor, n);

    free(vetor);

    return 0;
}

int quantidade(const char nome_arq[]){
    FILE *pt_arq = fopen(nome_arq, "r");
    if(pt_arq == NULL){
        printf("Erro ao abrir o arquivo de entrada!\n");
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
    //printf("%d\n", soma);
    return soma / 3;
}

void ler_do_arq(const char nome_arq[], novo_tipo *lista, int n){
    FILE *pt_arq = fopen(nome_arq, "r");
    if(pt_arq == NULL){
        printf("Erro ao abrir o arquivo de entrada na funcao ler_do_arq!\n");
        return;
    }
    novo_tipo *p;

    for(p = lista; p < lista + n; p++){
        // lendo o nome do curso
        fscanf(pt_arq, "%[^\n]", p->curso);
        
        // lendo o nome da pessoa
        fscanf(pt_arq, "\n%[^\n]", p->nome);

        // lendo o RGA
        fscanf(pt_arq, "%ld\n", &p->rga);
    }

    fclose(pt_arq);
}

void impressao(novo_tipo *lista, int n){
    novo_tipo *p;

    for(p = lista; p < lista + n; p++){
        printf("%s\n", p->curso);
        printf("%s\n", p->nome);
        printf("%ld\n", p->rga);
    }
}

void salvar_nos_arquivos(novo_tipo *lista, int n){
    novo_tipo *p;
    FILE *pt_arq;
    char nome_arquivo[MAX];
    
    for(p = lista; p < lista + n;p++){
        strcpy(nome_arquivo, p->curso);

        //concatena a extensão .txt ao nome do arquivo
        strcat(nome_arquivo, ".txt");

        // abrindo o arquivo em modo de leitura
        pt_arq = fopen(nome_arquivo, "r");

        // verificando se o arquivo existe
        if(pt_arq != NULL){
            // fechando o arquivo, para abri-lo no modo de escrita no final
            fclose(pt_arq);

            // se ele existe, eu vou escrever no seu final

            // abrindo o arquivo em modo de escrita no final
            pt_arq = fopen(nome_arquivo, "a+");
            if(pt_arq == NULL){
                printf("Erro ao abrir o arquivo %s em modo de escrita no final!\n", nome_arquivo);
                return;
            }

            // escrevendo no arquivo
            fprintf(pt_arq, "%s\n", p->curso);
            fprintf(pt_arq, "%s\n", p->nome);
            fprintf(pt_arq, "%ld\n", p->rga);

            
        }else{
            // se o arquivo nao existe, eu vou cria-lo
            pt_arq = fopen(nome_arquivo, "w+");

            // escrevendo no arquivo
            fprintf(pt_arq, "%s\n", p->curso);
            fprintf(pt_arq, "%s\n", p->nome);
            fprintf(pt_arq, "%ld\n", p->rga);
        }

        fclose(pt_arq);
    }

}