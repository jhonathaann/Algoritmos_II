#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct cel{
    char nome[MAX];
    int capacidade;
    struct cel *prox;
}celula;

void insere_fim(celula **lista, char nome[], int capacidade);

celula* remove_primero(celula **lista);

void imprime(celula *lista);

int main(){
    celula *fila_espera = NULL, *aux;
    int opc, capacidade, quant = 0;
    char nome[MAX];

    printf("\n1 - Listar o numero de avioes agurdando na fila de decolagem\n2 - Autorizar a decolagem do primeiro aviao da fila de decolagem\n3 - Adicionar um aviao a fila de decolagem\n4 - Listar todos os avioes na fila de decolagem\n5 - Listar todas as caracteristica do primeiro aviao da fila de decolagem\n6 - Sair\n");
    scanf("%d", &opc);
    getchar();

    while(opc != 6){
        if(opc == 1){
            printf("Numero de avioes na fila de decolagem: %d\n", quant);
        }else if(opc == 2){
            aux = remove_primero(&fila_espera);

            if(aux == NULL){
                printf("Lista de decolagem esta vazia!\n");
            }else{
                printf("\nAviao %s decolou!\n", aux->nome);
                quant--;
            }
        }else if(opc == 3){

            printf("Informe o nome do aviao:\n");
            scanf("%[^\n]", nome);
            getchar();

            printf("Informe a capacidade do aviao %s:\n", nome);
            scanf("%d", &capacidade);
            getchar();

            insere_fim(&fila_espera, nome, capacidade);
            quant++;
        }else if(opc == 4){
            printf("Todos os avioes na lista de espera:\n");
            imprime(fila_espera);
            
        }else if(opc == 5){

            if(fila_espera == NULL){
                printf("Nenhum aviao esta na fila de decolagem nesse momento!\n");
            }
            printf("Caracteristicas do primeiro aviao da fila:\n");
            printf("Nome: %s, Capacidade: %d\n", fila_espera->nome, fila_espera->capacidade);
        }
        printf("\n1 - Listar o numero de avioes agurdando na fila de decolagem\n2 - Autorizar a decolagem do primeiro aviao da fila de decolagem\n3 - Adicionar um aviao a fila de espera\n4 - Listar todos os avioes na fila de espera\n5 - Listar todas as caracteristica do primeiro aviao da fila de decolagem\n6 - Sair\n");
        scanf("%d", &opc);
        getchar();
    }
}

void imprime(celula *lista){
    
    while(lista != NULL){
        printf("Nome: %s, Capacidade: %d\n", lista->nome, lista->capacidade);
        lista = lista->prox;
    }
}

void insere_fim(celula **lista, char nome[], int capacidade){
    celula *nova = (celula *) calloc(1, sizeof(celula));
    celula *aux;
    if(nova == NULL){
        printf("Erro ao alocar memoria na funcao insere_fim!\n");
        return;
    }

    strcpy(nova->nome, nome);
    nova->capacidade =  capacidade;
    nova->prox = NULL;  // porque toda insercao eh no fim

    if(*lista == NULL){
        *lista = nova;
    }else{
        aux = *lista;

        while(aux->prox != NULL){
            aux = aux->prox;
        }

        aux->prox = nova;
    }
    
}

celula* remove_primero(celula **lista){
    celula *no_removido = NULL;

    if(*lista == NULL){
        // nao ha ninguem a ser removido
        return NULL;
    }

    no_removido =  *lista;
    (*lista) = (*lista)->prox;

    return no_removido;
}