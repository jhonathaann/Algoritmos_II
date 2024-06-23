#include <stdio.h>
#include <stdlib.h>

void leitura_arq(float **M, int linhas, int colunas, FILE *pt_arq);

void impressao(float **M, int linhas, int colunas);

void transposta(float **M, int linhas, int colunas);

int main(){
    FILE *pt_arq = fopen("matriz.txt", "r");
    if(pt_arq == NULL){
        printf("Nao foi possivel abrir o arquivo!\n");
        return 1;
    }
    float **matriz;
    int l, c;

    // lendo do arquivo as dimensões do arquivo
    fscanf(pt_arq, "%d %d", &l, &c);
    
    // alocando a matriz na memoria (alocando o vetor de ponteiros para float)
    matriz = (float **) calloc(l, sizeof(float *));

    if(matriz == NULL){
        printf("Nao foi possivel alocar a matriz na memoria!\n");
        return -1;
    }
     // alocando cada uma das linha da matriz (alocando os vetores de float)
    for(int i = 0; i < l; i++){
        matriz[i] = (float *) calloc(c, sizeof(float));
        
        if(matriz[i] == NULL){
            printf("Nao foi possivel alocar a linha %d da matriz\n", i);
            return -1;
        }
    }

    leitura_arq(matriz, l, c, pt_arq);

    //impressao(matriz, l, c);

    transposta(matriz, l, c);

    for(int i = 0; i < l; i++){
        free(matriz[i]);
    }
    free(matriz);
    fclose(pt_arq);

    return 0;
}

// função para ler do arquivo os valores da matriz
void leitura_arq(float **M, int linhas, int colunas, FILE *pt_arq){

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            fscanf(pt_arq, "%f", &M[i][j]);
        }
    }

    fclose(pt_arq);
}

void impressao(float **M, int linhas, int colunas){

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%.2f ", M[i][j]);
        }
        printf("\n");
    }
}

// calcula a transposta da matriz contida no arquivo "matriz.txt"
void transposta(float **M, int linhas, int colunas){
    FILE *pt_arq = fopen("matriz_transposta.txt", "w");
    if(pt_arq == NULL){
        printf("Nao foi possivel abrir/criar o arquivo de saida!\n");
        return;
    }

    fprintf(pt_arq, "Matriz Transposta\n");
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            fprintf(pt_arq, "%.2f ", M[j][i]);
        }
        fprintf(pt_arq, "\n");
    }


}