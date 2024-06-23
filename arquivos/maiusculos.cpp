#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leitura_arquivo(char **matriz, int n);

int quantidade(const char nome_arq[]);

void salvando_no_arquivo(const char nome_arq[], char **matriz, int n);

int main(){
    char **matriz;
    int linhas = quantidade("arquivo_teste.txt");

    // alocando o vetor de ponteiros para char
    matriz = (char **) calloc(linhas, sizeof(char *));
    if(matriz == NULL){
        printf("Nao foi possivel alocar o vetor de ponteiros para char!\n");
        return -1;
    }

    for(int i = 0; i < linhas;i++){
        matriz[i] = (char *) calloc(20, sizeof(char));

        if(matriz[i] == NULL){
            printf("Nao foi possivel alocar um vetor de char!\n");
            return -1;
        }
    }

    leitura_arquivo(matriz, linhas);

    salvando_no_arquivo("letras_maisculas.txt", matriz, linhas);
}

int quantidade(const char nome_arq[]){
    FILE *pt_arq = fopen(nome_arq, "r");
    if(pt_arq == NULL){
        printf("Nao foi possivel abrir o arquivo %s!\n", nome_arq);
        return -1;
    }
    int soma = 0;
    char c;

    // enquanto eu não estiver no final do arquivo
    while((c = fgetc(pt_arq)) != EOF){

        // cheguei no final da linha
        if(c == '\n'){
            soma++;
        }
    }

    return soma;
}

void leitura_arquivo(char **matriz, int n){
    FILE *pt_arq = fopen("arquivo_teste.txt", "r");
    if(pt_arq == NULL){
        printf("Nao foi possivel abrir o arquivo de entrada!\n");
        return;
    }

    // lendo cada o nome contido em cada linha do meu arquivo de entrada
    for(int i = 0; i < n;i++){
        fscanf(pt_arq, "%s\n", matriz[i]);
    }

    fclose(pt_arq);
}

void salvando_no_arquivo(const char nome_arq[], char **matriz, int n){
    FILE *pt_arq = fopen(nome_arq, "w");
    if(pt_arq == NULL){
        printf("Nao foi possivel abrir o arquivo de saida!\n");
        return;
    }
    int letras;
    int aux;
    for(int i = 0; i < n;i++){
        
        // verificando quantas letras cada nome possui
        letras = strlen(matriz[i]);

        for(int j = 0; j < letras; j++){

            // se a letra atual for maiuscula
            if(int(matriz[i][j]) >= 65 && int(matriz[i][j]) <= 90){
                // somando +32 com base na tabela ascii para chear no numero da letra minuscula
                aux = int(matriz[i][j]) + 32;

                fprintf(pt_arq, "%c", (char) aux);
            }else{
                fprintf(pt_arq, "%c", matriz[i][j]);
            }
            
        }
        
        fprintf(pt_arq, "\n");
    }
}