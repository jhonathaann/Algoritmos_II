#include <stdio.h>
#include <stdlib.h>

#include "funcoes.h"

// inserção será realiza no fim.
void inserirMarca(Marcas **marca, int codigo, float nota){
    Marcas *nova = (Marcas *) calloc(1, sizeof(Marcas));
    Marcas *aux;
    if(nova == NULL){
        printf("Erro ao alocar memoria na funcao inserirMarca!\n");
        return;
    }

    nova->codigo = codigo;
    nova->nota = nota;
    nova->prox = NULL;  // toda inserção é no fim, por isso o prox da nova celula deve ser NULL

    // verificando se a lista esta vazia
    if(*marca == NULL){

        nova->ant = NULL;
        *marca = nova;
    }else{
        aux = *marca;

        while(aux->prox != NULL){
            aux = aux->prox;
        }

        // ao sair do while, o aux estava na minha ultima celula
        // mas a "nova" agora deve ser a ultima
        aux->prox = nova;
        nova->ant = aux;  // como é duplamente encadeada, o campo ant da ultima celula deve apontar para a penultima celula
    }
}

float buscaMarca(Marcas *marca, int codigo){

    while(marca != NULL){
        if(marca->codigo == codigo){
            return marca->nota;
        }
        marca = marca->prox;
    }

    // codigo da marca nao foi encontrado
    return 0.0;
}

// a inserção aqui é para ser realizada no inicio da lista
void inserirCarro(Carros **carro, char *modelo, int ano, int codigo){
    Carros *nova = (Carros *) calloc(1, sizeof(Carros));
    if(nova == NULL){
        printf("Erro ao alocar memoria na funcao inserirCarro!\n");
        return;
    }

    nova->ano = ano;
    nova->codigomarca = codigo;
    strcpy(nova->modelo, modelo);

    nova->prox = *carro;
    *carro = nova;
}

void listagem(Marcas *marca, Carros *carro){

    Carros *p = carro;

    while(p != NULL){

        float nota = buscaMarca(marca, p->codigomarca);

        if(nota == 0.0){
            printf("Codigo da marca %d nao encontrado!\n", p->codigomarca);
        }else{

             printf("%s %d %.1f\n", p->modelo, p->ano, nota);
            p = p->prox;
        }
    }
}


// função que verifica se uma marca possui pelo menos um carro associado a ela
int marcaTemcarro(Carros *carro, int codigo){

    Carros *p;

    for(p = carro; p != NULL; p = p->prox){

        if(p->codigomarca == codigo){
            return 1;
        }
    }
    
    // marca nao possui nenhum carro associado a ela
    return 0;
}

void removerMarca(Marcas **marca, Carros *carro, int codigo){

    // verificando se a marca possui pelo menos um carro associado a ela
    if(marcaTemcarro(carro, codigo) == 1){
        printf("A marca possui um carro associado a ela, portanto ela nao pode ser removida!\n");
    }else{

        Marcas *no_removida = *marca;

        while(no_removida != NULL && no_removida->codigo != codigo){
            no_removida = no_removida->prox;
        }

        // verificando se é o primeiro no
        if(no_removida->ant == NULL){
            
            // avançando o ponteiro *marca, para o segundo no da lista (que vai passar a ser o primeiro)
            *marca = (*marca)->prox;

            // verificando se, depois que o ponteiro *marca avançou ele ficou NULL
            //ou seje, se ele ficou null, a minha lista so tinha um elemento, que sera removido
            if(*marca != NULL){
                (*marca)->ant = NULL;  // como agora o segundo sera o primeiro, o ant dele deve ser NULL
            }

            free(no_removida);
           
        }else{

            // verificando se o no que sera removido nao é o ultimo
            if(no_removida->prox != NULL){

                // eu so posso fazer no_removido->prox se esse no nao for o ultimo, porque se ele for, o prox nao existe, ja que é nullo
                no_removida->prox->ant = no_removida->ant;
            }

            no_removida->ant->prox = no_removida->prox;
            free(no_removida);
        }
        printf("Marca de codigo %d foi removida com sucesso!\n", codigo);
    }
}

void imprime(Marcas *marca){

    while(marca != NULL){
        printf("codigo: %d, nota: %.1f\n", marca->codigo, marca->nota);
        marca = marca->prox;
    }
}