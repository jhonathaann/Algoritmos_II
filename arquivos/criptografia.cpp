#include <stdio.h>
#include <string.h>
#define MAX 20

void criptografa(FILE *arq_entrada);

void descriptografa(FILE *arq_entrada);

int main(){
    FILE *pt_arq;
    char nome_arquivo[MAX];

    printf("Informe o nome do arquivo que sera CRIPTOGRAFADO:\n");
    scanf("%s[^\n]", nome_arquivo);
    getchar();

    pt_arq = fopen(nome_arquivo, "r");
    if(pt_arq != NULL){
        criptografa(pt_arq);
        printf("Criptografia realizada com sucesso!\n");
    }else{
        printf("Nao foi possivel abrir o arquivo!\n");
    }

    printf("Informe o nome do arquivo que sera DESCRIPTOGRAFADO:\n");
    scanf("%[^\n]", nome_arquivo);
    getchar();
    pt_arq = fopen(nome_arquivo, "r");

    if(pt_arq != NULL){
        descriptografa(pt_arq);
        printf("Descriptografia realizada com sucesso!\n");
    }else{
        printf("Erro ao abrir o arquivo!\n");
    }

    return 0;
}

void criptografa(FILE *arq_entrada){
    char palavra[MAX];
    // arquivo que irá conter as strings criptografadas
    FILE *arq_saida = fopen("criptografado.txt", "w");
    
    if(arq_saida == NULL){
        printf("Nao foi possivel abrir o arquivo de saida!\n");
        return;
    }

    //feof retorna 1 quando voce chega no final di arquivo
    while(feof(arq_entrada) == 0){
        fscanf(arq_entrada, "%19[^\n]\n", palavra);
        
        for(int i = 0; palavra[i] != '\0'; i++){
            //printf("%d ", palavra[i]);
            if(i % 2 == 0){
                fprintf(arq_saida, "%c", int(palavra[i]+7));
            }else{
                fprintf(arq_saida, "%c", int(palavra[i]-8));
            }
        }
        fprintf(arq_saida, "\n");
    }

    fclose(arq_entrada);
    fclose(arq_saida);
}

void descriptografa(FILE *arq_entrada){
    char palavra[MAX];
    FILE *arq_saida = fopen("descriptografado.txt", "w");

    if(arq_saida == NULL){
        printf("Nao foi possivel abrir o arquivo de saida!\n");
        return;
    }

    while(feof(arq_entrada) == 0){
        fscanf(arq_entrada, "%19[^\n]\n", palavra);

        for(int i = 0; palavra[i] != '\0';i++){
            if(i % 2 == 0){
                fprintf(arq_saida, "%c", int(palavra[i]-7));
            }else{
                fprintf(arq_saida, "%c", int(palavra[i]+8));
            }
        }
        fprintf(arq_saida, "\n");
    }

    fclose(arq_entrada);
    fclose(arq_saida);
}