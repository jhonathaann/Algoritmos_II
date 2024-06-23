#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct{
    char nome[MAX];
    float nota1, nota2, media;
}ALUNO;

void leitura(ALUNO *lista, int n);

void impressao(ALUNO *lista, int n);

void salvar_no_arquivo(ALUNO *lista, int n);

void ler_do_arquivo(ALUNO *lista, int n);

int main(){
    ALUNO *lista;
    int n, opc;

    printf("Informe a quantidade de alunos:\n");
    scanf("%d", &n);
    getchar();

    lista = (ALUNO *) malloc(n * sizeof(ALUNO));
    if(lista == NULL){
        printf("Erro na alocacao!\n");
        return 1;
    }

    printf("0 - leitura via teclado\n1 - leitura via arquivo\n2 - salvar no arquivo\n3 - impressao na tela\n4 - sair\n");
    scanf("%d", &opc);
    getchar();

    while(opc != 4){

        switch (opc){
        
            case 0:
                leitura(lista, n);
                break;

            case 1:
                ler_do_arquivo(lista, n);
                break;

            case 2:
                salvar_no_arquivo(lista, n);
                break;

            case 3:
                impressao(lista, n);
                break;    
            
            default:
                printf("Opcao invalida!\n");
                break;
        }

        printf("0 - leitura via teclado\n1 - leitura via arquivo\n2 - salvar no arquivo\n3 - impressao na tela\n4 - sair\n");
        scanf("%d", &opc);
        getchar();

    }

    return 0;
}

void leitura(ALUNO *lista, int n){
    ALUNO *p;

    for(p = lista; p < lista + n; p++){
        printf("Informe o nome do(a) aluno(a):\n");
        scanf("%[^\n]", p->nome);
        getchar();

        printf("Informe a nota da P1 e da P2 do(a) aluno(a) %s: ", p->nome);
        scanf("%f %f", &p->nota1, &p->nota2);
        getchar();

        p->media = (p->nota1 + p->nota2)/2;
    }
    
}

void impressao(ALUNO *lista, int n){
    ALUNO *p;
    float aux = 0.0;

    for(p = lista; p < lista + n; p++){
        printf("Nome: %s\n", p->nome);
        printf("P1 = %.2f || P2 = %.2f\n", p->nota1, p->nota2);
        printf("Media do(a) aluno(a) %s: %.2f\n",p->nome, p->media);

        aux += p->nota1 + p->nota2;
    }

    n = 2 * n;
    printf("Media da turma: %.2f\n", aux / n);
}

void salvar_no_arquivo(ALUNO *lista, int n){

    FILE *pt_arq = fopen("notas.txt", "w");
    ALUNO *p;
    float aux = 0.0;

    /*se o arquivo "notas.txt" não existir, essa função vai criar ele
    se ele ja existir, o "w" vai recriar todo o arquivo*/

    if(pt_arq != NULL){

        for(p = lista; p < lista + n; p++){
            fprintf(pt_arq, "Nome: %s\n", p->nome);
            fprintf(pt_arq, "P1 = %.2f  || P2 = %.2f\n", p->nota1, p->nota2);
            fprintf(pt_arq, "Media do(a) aluno(a) = %s %.2f\n",p->nome, p->media);
            fprintf(pt_arq, "-------------------------\n");
            aux += p->nota1 + p->nota2;
        }

        n = n * 2;
        fprintf(pt_arq, "Media da turma: %.2f\n", aux/n);

        fclose(pt_arq);

    }else{
        printf("Nao foi possivel abrir o arquivo!\n");
    }
}

void ler_do_arquivo(ALUNO *lista, int n){
    FILE *pt_arq = fopen("notas.txt", "r");
    ALUNO *p;

    if(pt_arq != NULL){

        for(p = lista; p < lista + n; p++){

            fscanf(pt_arq, "Nome: %19[^\n]\n", p->nome);
            fscanf(pt_arq, "P1 = %f  || P2 = %f\n", &p->nota1, &p->nota2);
            fscanf(pt_arq, "Media do(a) aluno(a) = %*s %f\n", &p->media);
            fscanf(pt_arq, "-------------------------\n");

            }

        fscanf(pt_arq, "Media da turma: %f\n", &p->media);

        fclose(pt_arq);

    }else{
        printf("Nao foi possivel abrir o arquivo!\n");
    }
}