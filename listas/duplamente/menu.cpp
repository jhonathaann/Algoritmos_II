//varias funcoes em uma lista duplamente encadeada

#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *proximo, *anterior;
}celula;

void imprime(celula *lista);

void insere_inicio(celula **lista, int numero);

void insere_final(celula **lista, int numero);

void insere_apos_chave(celula **lista, int numero, int chave);

void insere_ordenado(celula **lista, int numero);

celula* busca(celula **lista, int chave);

celula* remover(celula **lista, int chave);

celula* ultima_celula(celula **lista);  //retorna o ponteiro para a ultima celula

void imprime_contrario(celula *lista); //recebe um pont para o final da lista

int main(){
    celula *lista = NULL, *celula_removida, *aux;
    int opc, chave, numero;
    
    printf("\n\n0 - Sair\n1 - Inserir no Inicio\n2 - Insererir no Final\n3 - Inserir na Chave\n4 - Inserir Ordenado\n5 - Buscar na lista\n6 - Remover da lista\n7 - Imprimir a Lista\n8 - Imprimir ao contrario\n\n");
    
    scanf("%d", &opc);
    
    while(opc != 0){
        if(opc == 1){
            printf("Entre com um numero:\n");
            scanf("%d", &numero);
            
            insere_inicio(&lista, numero);
        }else if(opc == 2){
            printf("Entre com um numero:\n");
            scanf("%d", &numero);
            
            insere_final(&lista, numero);
        }else if(opc == 3){
            printf("Entre com um numero:\n");
            scanf("%d", &numero);
            
            printf("Digite uma chave:\n");
            scanf("%d", &chave);
            
            insere_apos_chave(&lista, numero, chave);
        }else if(opc == 4){
            printf("Entre com um numero:\n");
            scanf("%d", &numero);
            
            insere_ordenado(&lista, numero);
        }else if(opc == 5){
            printf("Digite uma chave para ser buscada na lista:\n");
            scanf("%d", &chave);
            
            aux = busca(&lista, chave);
            if(aux == NULL){
                printf("A chave %d NAO foi encontrada na lista!!\n", chave);
            }else{
                printf("A chave %d foi encontrada na lista!!!\n", chave);
            }
        }else if(opc == 6){
            printf("Entre com uma chave para ser removida da lista:\n");
            scanf("%d", &chave);
            
            celula_removida = remover(&lista, chave);
            if(celula_removida == NULL){
                printf("Chave %d nao foi encontrada na lista!\n", chave);
            }else{
                printf("Chave %d removida com sucesso!!\n", chave);
            }
        }else if(opc == 7){
            imprime(lista);
        }else if(opc == 8){
            aux = ultima_celula(&lista);
            imprime_contrario(aux);
        }
        
         printf("\n\n0 - Sair\n1 - Inserir no Inicio\n2 - Insererir no Final\n3 - Inserir na Chave\n4 - Inserir Ordenado\n5 - Buscar na lista\n6 - Remover da lista\n7 - Imprimir a Lista\n8 - Imprimir ao contrario\n\n");
    
        scanf("%d", &opc);
    }
    
    return 0;
}

void imprime(celula *lista){
    
    printf("\n----- LISTA -----\n");
    while(lista != NULL){
        printf("%d\n", lista->chave);
        lista = lista->proximo;
    }
    printf("\n\n");
}

void insere_inicio(celula **lista, int numero){
    celula *nova = (celula *) malloc(sizeof(celula));
    
    if(nova != NULL){
        nova->chave = numero;
        nova->proximo = *lista;
        nova->anterior = NULL;
        
        if(*lista != NULL){
            (*lista)->anterior = nova;
        }
        *lista = nova;
    }else{
        printf("Erro na alocaçao de memoria!!\n");
    }
}

void insere_final(celula **lista, int numero){
    celula *aux, *nova = (celula *) malloc(sizeof(celula));
    
    if(nova != NULL){
        nova->chave = numero;
        nova->proximo = NULL;
        
        if(*lista == NULL){
            *lista = nova;
            nova->anterior = NULL;
            
        }else{
            aux = *lista;
            while(aux->proximo != NULL){
                aux = aux->proximo;
            }
            aux->proximo = nova;
            nova->anterior = aux;
        }
    }else{
        printf("Erro na alocaçao de memoria!\n");
    }
}

void insere_apos_chave(celula **lista, int numero, int chave){
    celula *aux, *nova = (celula *) malloc(sizeof(celula));
    
    if(nova != NULL){
        nova->chave = numero;
        
        if(*lista == NULL){
            nova->proximo = NULL;
            nova->anterior = NULL;
            *lista = nova;
        }else{
            aux = *lista;
            
            while(aux->chave != chave && aux->proximo != NULL){
                aux = aux->proximo;
            }
            nova->proximo = aux->proximo;
            aux->proximo->anterior = nova;
            nova->anterior = aux;
            aux->proximo = nova;
        }
    }else{
        printf("Erro na alocaçao de memoria!\n");
    }
}

void insere_ordenado(celula **lista, int numero){
    celula *aux, *nova = (celula *) malloc(sizeof(celula));
    
    if(nova != NULL){
        nova->chave = numero;
        
        if(*lista == NULL){
            nova->proximo = NULL;
            nova->anterior = NULL;
            *lista = nova;
        }else if(nova->chave < (*lista)->chave){
            nova->proximo = *lista;
            (*lista)->anterior = nova;
            *lista = nova;
        }else{
            aux = *lista;
            while(aux->proximo != NULL && nova->chave > aux->proximo->chave){
                aux = aux->proximo;
            }
            nova->proximo = aux->proximo;
            aux->proximo->anterior = nova;
            nova->anterior = aux;
            aux->proximo = nova;
        }
    }else{
        printf("Erro ao alocar memoria!!\n");
    }
}

celula* busca(celula **lista, int chave){
    celula *aux, *chave_buscada = NULL;
    
    aux = *lista;
    while(aux != NULL && aux->chave != chave){
        aux = aux->proximo;
    }
    
    if(aux != NULL){
        chave_buscada = aux;
    }
    
    return chave_buscada;
}

celula* remover(celula **lista, int chave){
    celula *aux, *remover = NULL;
    
    if(*lista != NULL){
        if((*lista)->chave == chave){
            remover = *lista;
            *lista = remover->proximo;
            
            if(*lista != NULL){
                (*lista)->anterior = NULL;
            }
        }else{
            aux = *lista;
            while(aux->proximo != NULL && aux->proximo->chave != chave){
                aux = aux->proximo;
            }
            if(aux->proximo != NULL){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                
                if(aux->proximo != NULL){
                    aux->proximo->anterior = aux;
                }
            }
        }
    }
    
    return remover;
}

celula* ultima_celula(celula **lista){
    celula *aux = *lista;
    
    while(aux->proximo != NULL){
        aux = aux->proximo;
    }
    
    return aux;
}

void imprime_contrario(celula *lista){
    
    printf("\n----- LISTA AO CONTRARIO -----\n");
    while(lista != NULL){
        printf("%d\n", lista->chave);
        lista = lista->anterior;
    }
    printf("\n\n");
}