#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LETRAS 20

int quantidade(const char nome_arq[]);

void lendo_do_arquivo(const char nome_arq[], char **nomes, int n);

void intercala(char **nomes1, char **nomes2, int quant1, int quant2);

void impressao(char **nomes, int n);

int main(){
    char **nomes1;
    char **nomes2;
    int quant1, quant2;  // variaveis que vao guardar quantos nomes cada arquivo possui

    quant1 = quantidade("arquivo1.txt");
    quant2 = quantidade("arquivo2.txt");

    // alocando a matriz que ira guardar todos os nomes lidos do primeiro arquivo
    // alocando o vetor que ira para ponteiros do tipo do char
    nomes1 = (char **) calloc(quant1, sizeof(char *));

    if(nomes1 == NULL){
        printf("Nao foi possivel alocar o primeiro vetor de ponteiros!\n");
        return 1;
    }
    for(int i = 0; i < quant1; i++){
        nomes1[i] = (char *) calloc(LETRAS, sizeof(char));
        if(nomes1[i] == NULL){
            printf("Nao foi possivel alocar o vetor de char!\n");
            return -1;
        }
    }

    // alocando a matriz que ira guardar todos os nomes lidos do segundo arquivo
    nomes2 = (char **) calloc(quant2, sizeof(char *));
    if(nomes2 == NULL){
        printf("Nao foi possivel alocar o segundo vetor de ponteiros!\n");
        return -1;
    }
    for(int i = 0; i < quant2; i++){
        nomes2[i] = (char *) calloc(LETRAS, sizeof(char));
        if(nomes2[i] == NULL){
            printf("Nao foi possivel alocar o vetor de char!\n");
            return -1;
        }
    }

    lendo_do_arquivo("arquivo1.txt", nomes1, quant1);
    lendo_do_arquivo("arquivo2.txt", nomes2, quant2);

    //impressao(nomes1, quant1);
    //impressao(nomes2, quant2);
    //printf("%d %d", quant1, quant2);

    intercala(nomes1, nomes2, quant1, quant2);

    for(int i = 0; i < quant1; i++){
        free(nomes1[i]);
    }
    free(nomes1);

    for(int i = 0; i < quant2;i++){
        free(nomes2[i]);
    }
    free(nomes2);

    return 0;
}

int quantidade(const char nome_arq[]){
    int aux = 0;
    char c;
    FILE *pt_arq = fopen(nome_arq, "r");
    if(pt_arq == NULL){
        printf("Nao foi possivel abrir o arquivo!\n");
        return -1;
    }

    while((c = fgetc(pt_arq)) != EOF){

        if(c == '\n'){
            aux++;
        }
    }

    fclose(pt_arq);

    return aux;
}

void impressao(char **nomes, int n){

    for(int i = 0; i < n; i++){
        printf("%s\n", nomes[i]);
    }
}

void lendo_do_arquivo(const char nome_arq[], char **nomes, int n){
    FILE *pt_arq = fopen(nome_arq, "r");
    if(pt_arq == NULL){
        printf("Nao foi possivel abrir o arquivo!\n");
        return;
    }
    // n = numero de linhas, ou seja, a quantidade de nomes que eu tenho no meu arquivo em questao
    //printf("%d ", n);
    for(int i = 0; i < n; i++){
        fscanf(pt_arq, "%s\n", nomes[i]);
        
    }

    fclose(pt_arq);
}

void intercala(char **nomes1, char **nomes2, int quant1, int quant2){
    FILE *pt_arq = fopen("arquivo_saida.txt", "w");
    if(pt_arq == NULL){
        printf("Nao foi possivel abrir o arquivo para a escrita!\n");
        return;
    }
    int i = 0;
    int j = 0;

    while(i < quant1 && j < quant2){
        
        if(strcmp(nomes1[i], nomes2[j]) < 0){
            fprintf(pt_arq, "%s\n", nomes1[i]);
            //printf("%s\n", nomes1[i]);
            i++;

        }else{
            fprintf(pt_arq,"%s\n", nomes2[j]);
            //printf("%s\n", nomes2[j]);
            j++;
        }
        
    }
    
    // sobrou nomes no primeiro arquivo
    while(i < quant1){
        fprintf(pt_arq, "%s\n", nomes1[i]);
        //printf("%s\n", nomes1[i]);
        i++;
    }

    // sobrou nomes no segundo arquivo
    while(j < quant2){
        fprintf(pt_arq, "%s\n", nomes2[j]);
        //printf("%s\n", nomes2[j]);
        j++;
    }
    
    fclose(pt_arq);

}
