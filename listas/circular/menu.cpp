#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int chave;
    struct cel *proximo;
}celula;

typedef struct{
    celula *inicio;
    celula *fim;
    int tam;
}Lista;

void criar_lista(Lista *lista);

void imprime(Lista lista);

void insere_inicio(Lista *lista, int numero);

void insere_fim(Lista *lista, int numero);

void insere_ordenado(Lista *lista, int numero);

//void insere_apos_chave(Lista *lista, int numero, int chave);

celula* remover(Lista *lista, int chave);

celula* busca(Lista *lista, int chave);

int main(){
    Lista lista;
    int opc, numero, chave;
    celula *aux;
    
    criar_lista(&lista);
    do{
        printf("\n\n0 - SAIR\n1 - IMPRIME\n2 - INSERIR NO INICIO\n3 - INSERIR NO FIM\n4 - INSERIR ORDENADO\n5 - REMOVER DA LISTA\n6 - BUSCAR NA LISTA\n");
        scanf("%d", &opc);
        
        if(opc == 1){
            imprime(lista);
        }else if(opc == 2){
            printf("Entre com um numero inteiro:\n");
            scanf("%d", &numero);
            
            insere_inicio(&lista, numero);
        }else if(opc == 3){
            printf("Entre com um numero inteiro:\n");
            scanf("%d", &numero);
            
            insere_fim(&lista, numero);
        }else if(opc == 4){
            printf("Entre com um numero inteiro:\n");
            scanf("%d", &numero);
            
            insere_ordenado(&lista, numero);
        }else if(opc == 5){
            printf("Entre com um inteiro para ser removida da lista:\n");
            scanf("%d", &numero);
            
            aux = remover(&lista, numero);
            if(aux == NULL){
                printf("Remocao nao foi realizada pois o numero %d nao foi encontrado na lista!\n", numero);
            }else{
                printf("Remoçao realizada com sucesso!!\n");
            }
        }else if(opc == 6){
            printf("Entre com um numero para ser buscado na lista:\n");
            scanf("%d", &numero);
            
            aux = busca(&lista, numero);
            if(aux == NULL){
                printf("O numero %d NAO esta na lista!!\n", numero);
            }else{
                printf("0 numero %d ESTA na lista!!\n", numero);
            }
        }
    }while(opc != 0);
    
    return 0;
    
}

void criar_lista(Lista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

void imprime(Lista lista){
    celula *aux = lista.inicio;
    
    printf("\n------ LISTA: %d -------\n", lista.tam);
    if(aux != NULL){
        do{
            printf("%d\n", aux->chave);
            aux = aux->proximo;
        }while(aux != lista.inicio);
    }
    
    printf("\n------ FIM LISTA -------\n");
}

void insere_inicio(Lista *lista, int numero){
    celula *nova = (celula *) malloc(sizeof(celula));
    
    if(nova !=  NULL){
        nova->chave = numero;
        nova->proximo = lista->inicio; 
        lista->inicio = nova;  //atualiza o inicio
        
        if(lista->fim == NULL){ //esse if sera vrdd apenas na primeira inserçao
            lista->fim = nova;
        }
        lista->fim->proximo = lista->inicio;  //ultima celula aponta para a celula que acaba de ser inserida na lista
        
        lista->tam++;
    }else{
        printf("Erro na alocaçao de memoria!\n");
    }
}

void insere_fim(Lista *lista, int numero){
    celula *aux, *nova = (celula *) malloc(sizeof(celula));
    
    if(nova != NULL){
        nova->chave = numero;
        
        if(lista->inicio == NULL){//lista esta vazia?
            lista->inicio = nova;
            lista->fim = nova;
            lista->fim->proximo = lista->inicio;
        }else{
            lista->fim->proximo = nova;   //nova eh a ultima celula da lista
            lista->fim = nova;
            //lista->fim->proximo = lista->inicio;
            nova->proximo = lista->inicio;
        }
        lista->tam++;
    }else{
        printf("Erro ao alocar memoria!\n");
    }
}

/*void insere_apos_chave(Lista *lista, int numero, int chave){
    celula *aux, *nova = malloc(sizeof(celula));
    
    if(nova != NULL){
        nova->chave = numero;
        //caso seja o primeiro:
        if(lista->inicio == NULL){
            nova->proximo = NULL;
            lista->inicio = nova;  //atualiza o inicio da lista
        }else{
            
            aux = lista->inicio;
            while(aux->chave != chave && aux->proximo != NULL){
                aux = aux->proximo;
            }
            nova->proximo = aux->proximo;
            aux->proximo = nova;
        }
        lista->tam++;
    }else{
        printf("Erro ao alocar memoria!\n");
    }
}*/

void insere_ordenado(Lista *lista, int numero){
    celula *aux, *nova = (celula *) malloc(sizeof(celula));
    
    if(nova != NULL){
        nova->chave = numero;
        
        if(lista->inicio == NULL){  //lista vazia
            insere_inicio(lista, numero);
        }else if(nova->chave < lista->inicio->chave){  //valor q eu quero inserir eh o menor da lista
            insere_inicio(lista, numero);
        }else{
            aux = lista->inicio;
            while(aux->proximo != lista->inicio && nova->chave > aux->proximo->chave){
                aux = aux->proximo;
            }
            
            if(aux->proximo == lista->inicio){
                insere_fim(lista, numero);
            }else{
                nova->proximo = aux->proximo;
                aux->proximo = nova;
                lista->tam++;
            }
        }
    }else{
        printf("Erro ao alocar memoria!!\n");
    }
}

celula* remover(Lista *lista, int chave){
    celula *aux, *celula_removida = NULL;
    
    if(lista->inicio != NULL){
        /*esse primeiro if trata apenas do caso onde a lista contem apenas
        uma celula e o elemento que eu quero remover esta contido nessa
        chave*/
        if(lista->inicio == lista->fim && lista->inicio->chave == chave){
            celula_removida = lista->inicio;
            lista->inicio = NULL;
            lista->fim = NULL;
            lista->tam--;
            
        }else if(lista->inicio->chave == chave){
            celula_removida = lista->inicio;
            lista->inicio = celula_removida->proximo;  //atualiza o inicio
            lista->fim->proximo = lista->inicio;  //faz o final apontar para o inicio
            lista->tam--;
            
        }else{
            aux = lista->inicio;
            while(aux->proximo != lista->inicio && aux->proximo->chave != chave){
                aux = aux->proximo;
            }
            
            if(aux->proximo->chave == chave){
                //remocao na ultima celula:
                if(lista->fim == aux->proximo){
                    celula_removida = aux->proximo;
                    aux->proximo = celula_removida->proximo;
                    lista->fim = aux;
                    
                    //remocao no meio:
                }else{
                    celula_removida = aux->proximo;
                    aux->proximo = celula_removida->proximo;
                }
                lista->tam--;
            }
        }
    }
    
    return celula_removida;
}

celula* busca(Lista *lista, int chave){
    celula *aux = lista->inicio;
    
    if(aux != NULL){
        do{
            if(aux->chave == chave){
                return aux;
            }
            aux = aux->proximo;
        }while(aux != lista->inicio);
    }
    
    return NULL;
}