#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct{
    char nome[MAX];
    char cpf[12];
}MEDICO;

typedef struct {
    char nome[MAX];
    char cpf[12];
}ENFERMEIRO;

// função para saber quantas pessoas tem no meu arquivo
int quant_pessoas(char nome_arquivo[]);

// função para ler os dados do arquivo e salvar no vetor de registro de MEDICOS
void ler_medico(char nome_arquivo[], MEDICO *lista, int n);

// função para ler os dados do arquivo e salvar no vetor de registros de ENFERMEIRO
void ler_enfermeiro(char nome_arquivo[], ENFERMEIRO *lista, int n);

int ponto_medico(const char nome_arquivo[], MEDICO *lista, char nome_pessoa[], int n);

int ponto_enfermeiro(const char nome_arquivo[], ENFERMEIRO *lista, char nome_pessoa[], int n);

int main(){
    MEDICO *lista_medico;
    ENFERMEIRO *lista_enfermeiro;
    char nome_arq1[] = "medicos.txt";
    char nome_arq2[] = "enfermeiros.txt";
    char nome[MAX];
    int opc, n_medico, n_enfermeiro, aux;

    // lendo a quantidade de pessoas no arquivo dos medicos
    n_medico = quant_pessoas(nome_arq1);

    lista_medico = (MEDICO *) malloc(n_medico * sizeof(MEDICO));

    if(lista_medico == NULL){
        printf("Nao foi possivel alocar o vetor dos medicos!\n");
        return -1;
    }
    // lendo os dados dos medicos
    ler_medico(nome_arq1, lista_medico, n_medico);


    // lendo a quantidade de pessoas no arquivo dos enfermeiros
    n_enfermeiro = quant_pessoas(nome_arq2);

    lista_enfermeiro = (ENFERMEIRO *) malloc(n_enfermeiro * sizeof(ENFERMEIRO));

    if(lista_enfermeiro == NULL){
        printf("Nao foi possivel alocar o vetor dos enfermeiros!\n");
        return -1;
    }
    // lendo os dados dos enfermeiros
    ler_enfermeiro(nome_arq2, lista_enfermeiro, n_enfermeiro);

    printf("1 - Bater ponto Medicos\n2 - Bater ponto Enfermeiros\n3 - Sair\n");
    scanf("%d", &opc);
    getchar();

    while(opc != 3){

        if(opc == 1){
            printf("Informe o nome do medico:\n");
            scanf("%[^\n]", nome);
            getchar();
            
            aux = ponto_medico("pontoMedicos.txt", lista_medico , nome, n_medico);

            if(aux == -1){

                printf("Nao foi possivel abrir o arquivo!\n");

            }else if(aux == -2){

                printf("Nome %s nao foi encontrado na lista de medicos!\n", nome);

            }else if(aux == -3){

                printf("Pessoa %s ja bateu o ponto!\n", nome);

            }else{
                printf("Pessoa %s adicionada com sucesso na registro pontoMedico!\n", nome);
            }
            
        }else if(opc == 2){
            printf("Informe o nome do enfermeiro:\n");
            scanf("%[^\n]", nome);
            getchar();

            aux = ponto_enfermeiro("pontoEnfermeiros.txt", lista_enfermeiro , nome, n_enfermeiro);

            if(aux == -1){

                printf("Nao foi possivel abri o arquivo dos enfermeiros!\n");

            }else if(aux == -2){

                printf("Nome %s nao foi encontrado na lista de enfermeiros!\n", nome);

            }else if(aux == -3){

                printf("Pessoa %s ja bateu o ponto!\n", nome);

            }else{

                printf("Pessoa %s adicionada com sucesso no registro pontoEnfermeiros!\n", nome);
            }
            
        }else if(opc == 3){
            break;
        }else{
            printf("Opcao invalida!\n");
        }

        printf("1 - Bater ponto Medicos\n2 - Bater ponto Enfermeiros\n3 - Sair\n");
        scanf("%d", &opc);
        getchar();

    }
    // liberando a memoria usada pelas listas
    free(lista_medico);
    free(lista_enfermeiro);
    return 0;
}

int quant_pessoas(char nome_arquivo[]){
    FILE *pt_arq;
    int aux = 0;
    char c;
    
    pt_arq = fopen(nome_arquivo, "r");
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

    return aux / 2;
}

void ler_medico(char nome_arquivo[], MEDICO *lista, int n){
    FILE *pt_arq;
    MEDICO *p;

    pt_arq = fopen(nome_arquivo, "r");
    if(pt_arq == NULL){
        printf("Nao foi possivel abrir o arquivo %s!\n", nome_arquivo);
        return;
    }

    for(p = lista; p < lista + n; p++){
        fscanf(pt_arq, "%[^\n]\n", p->nome);
        fscanf(pt_arq, "%s\n", p->cpf);
    }

    fclose(pt_arq);
}

void ler_enfermeiro(char nome_arquivo[], ENFERMEIRO *lista, int n){
    FILE *pt_arq;
    ENFERMEIRO *p;

    pt_arq = fopen(nome_arquivo, "r");
    if(pt_arq == NULL){
        printf("Nao foi possivel abrir o arquivo %s!\n", nome_arquivo);
        return;
    }

    for(p = lista; p < lista + n; p++){
        fscanf(pt_arq, "%[^\n]\n", p->nome);
        fscanf(pt_arq, "%s\n", p->cpf);
    }

    fclose(pt_arq);
}

int ponto_medico(const char nome_arquivo[], MEDICO *lista, char nome_pessoa[], int n){
    FILE *pt_arq;
    MEDICO *p;
    int aux = 0;
    char nome_aux[MAX];

    pt_arq = fopen(nome_arquivo, "r");
    if(pt_arq == NULL){
        //printf("Nao foi possivel abrir o arquivo %s\n", nome_arquivo);
        return -1;
    }

    // verificando se o nome da pessoa esta registrado
    for(p = lista; p < lista + n;p++){
        if(strcmp(nome_pessoa, p->nome) == 0){
            aux = 1;
            break;
        }
    }

    // caso onde a pessoa em questao nao esta no registro
    if(aux == 0){
        return -2;
    }

    // verificando se a pessoa em questao ja bateu o ponto
    while(feof(pt_arq) == 0){

        // lendo o nome contido no arquivo pontoMedico
        fscanf(pt_arq, "%[^\n]\n", nome_aux);

        // se for igual, significa que a pessoa em questao ja bateu o ponto
        if(strcmp(nome_pessoa, nome_aux) == 0){
            fclose(pt_arq);
            return -3;
        }
    }
    fclose(pt_arq);

    // abrindo o arquivo para adicionar o nome da pessoa no final
    pt_arq = fopen(nome_arquivo, "a");
    
    fprintf(pt_arq, "%s\n", nome_pessoa);
    
    fclose(pt_arq);
    
    return 0;

}

int ponto_enfermeiro(const char nome_arquivo[], ENFERMEIRO *lista, char nome_pessoa[], int n){
    FILE *pt_arq;
    ENFERMEIRO *p;
    int aux = 0;
    char nome_aux[MAX];

    pt_arq = fopen(nome_arquivo, "r");
    if(pt_arq == NULL){
        return -1;
    }

    // verificando se a pessoa em questao esta na lista de enfermeiros
    for(p = lista; p < lista + n; p++){
        if(strcmp(nome_pessoa, p->nome) == 0){
            aux = 1;
            break;
        }
    }
    
    //nome da pessoa nao foi encotrado na lista dos enfermeiros
    if(aux == 0){
        return -2;
    }

    // verificando se a pessoa ja bateu o ponto
    while(feof(pt_arq) == 0){

        fscanf(pt_arq, "%[^\n]\n", nome_aux);
        
        // pessoa em questao ja bateu o ponto
        if(strcmp(nome_pessoa, nome_aux) == 0){
            fclose(pt_arq);
            return -3;
        }

    }

    fclose(pt_arq);

    // abrindo o arquivo em modo de adicionar conteudo no seu final
    pt_arq = fopen(nome_arquivo, "a");

    fprintf(pt_arq, "%s\n", nome_pessoa);

    fclose(pt_arq);

    return 0;
}