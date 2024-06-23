#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct{
    char nome[MAX], estado_civil[MAX];
    int idade;
}novo_tipo;

void leitura(novo_tipo *lista, FILE *pt_arq, int n, int *casados, int *solteiros);

void separa(novo_tipo *lista, int n, int *casados, int *solteiros);


int main(){
    FILE *pt_arq = fopen("dados1.txt", "r");
    if(pt_arq == NULL){
        printf("Nao foi possivel abrir o arquivo de entrada!\n");
        return -1;
    }
    
    novo_tipo *vetor;
    int n, casados = 0, solteiros = 0;

    // lendo do arquivo a quantidade de pessoas
    fscanf(pt_arq, "%d\n", &n);

    // alocando o vetor

    vetor = (novo_tipo *) calloc(n, sizeof(novo_tipo));
    if(vetor == NULL){
        printf("Nao foi possivel alocar o arquivo!\n");
        return -1;
    }

    leitura(vetor,pt_arq, n, &casados, &solteiros);

    separa(vetor, n, &casados, &solteiros);


    fclose(pt_arq);
    free(vetor);
    return 0;
}

void leitura(novo_tipo *lista, FILE *pt_arq, int n, int *casados, int*solteiros){
    novo_tipo *p;

    for(p = lista; p < lista + n; p++){
        fscanf(pt_arq, "%s ", p->estado_civil);
        fscanf(pt_arq, "%d ", &p->idade);
        fscanf(pt_arq, "%[^\n]\n", p->nome);

        if(strcmp(p->estado_civil, "Casado") == 0){
            *casados = *casados + 1;
        }else{
            *solteiros = *solteiros + 1;
        }
    }
}

void separa(novo_tipo *lista, int n, int *casados, int *solteiros){
    FILE *pt_arq1, *pt_arq2;
    novo_tipo *p;
    // abrindo os dois arquivos em modo de escrita
    pt_arq1 = fopen("casados.txt", "w");
    pt_arq2 = fopen("solteiros.txt", "w");

    if(pt_arq1 == NULL || pt_arq2 == NULL){
        printf("Erro ao abrir o(s) arquivo(s) de escrita!\n");
        return;
    }
    // escrevendo nos dois arquivos a quantidade de cada um na primeira linha
    fprintf(pt_arq1, "%d\n", *casados);
    fprintf(pt_arq2, "%d\n", *solteiros);

    for(p = lista; p < lista + n; p++){
        if(strcmp(p->estado_civil, "Casado") == 0){
            fprintf(pt_arq1, "Nome: %s, Idade: %d\n", p->nome, p->idade);
        }else{
            fprintf(pt_arq2, "Nome: %s, Idade: %d\n", p->nome, p->idade);
        }
    }

    fclose(pt_arq1);
    fclose(pt_arq2);

}