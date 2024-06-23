#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa{
    char nome[30];
    int idade;
    struct pessoa *proximo;
}pessoa;

void inserir_com_prioridade(char nome[], int idade, pessoa **fila);

void imprimir(pessoa *fila);

int main(){
    pessoa *fila = NULL;
    char nome[30];
    int quant, idade;

    scanf("%d", &quant);

    for(int i = 0; i < quant; i++){
        scanf("%s %d", nome, &idade);
        //printf("%s %d\n", nome, idade);

        inserir_com_prioridade(nome, idade, &fila);
    }

    imprimir(fila);

    return 0;
}

void inserir_com_prioridade(char nome[], int idade, pessoa **fila){
    pessoa *aux, *nova = (pessoa *) malloc(sizeof(pessoa));

    if(nova != NULL){

        strcpy(nova->nome, nome);
        nova->idade = idade;
        nova->proximo = NULL;  // nullo pois toda inserção é feita no final da fila

        if(*fila == NULL){

            /* *fila sendo igual a NULL, significa que a fila esta vazia,
            ou seja, *fila é o ultimo nó da minha estrutura*/

            *fila = nova;

        }else{
            // parte do codigo que cuida da inserção com prioridade

            if(idade > 70){
                // é a primeira prioridade?
                if((*fila)->idade < 71){
                    nova->proximo =  *fila;
                    *fila = nova;
                }else{

                    // aqui, aux é a prioridade
                    aux = *fila;

                    while(aux->proximo != NULL && aux->proximo->idade > 70){

                        aux = aux->proximo;
                    }

                    /*aux->proximo sera NULL ou sera o primeiro nó da fila que não é prioridade*/

                    nova->proximo = aux->proximo;
                    aux->proximo = nova;

                }

            }else{
                aux = *fila;

                while(aux->proximo != NULL){
                    aux = aux->proximo;
                }

                aux->proximo = nova;
            }

        }
    }else{
        printf("Erro ao alocar memoria!\n");
        return;
    }
}

void imprimir(pessoa *fila){
    pessoa *p;

    for(p = fila; p != NULL; p = p->proximo){
        printf("%s ", p->nome);
    }
}
