#include <stdio.h>
#include <stdlib.h>

/*fila com prioridade. no caso, vou considerar a idade. aqueles com 
60 anos ou mais possuem prioridade*/

typedef struct cel{
    int idade;
    struct cel *proximo;
}celula;

void inserir_fila(int x, celula **fila);

void inserir_com_prioridade(int x, celula **fila);

celula* remover_fila(celula **fila);

void imprime(celula *fila);


int main(){
    celula *aux, *fila = NULL;
    int opc, numero;
    
     printf("\n0 - Sair\n1 - Inserir\n2 - Remover\n3 - Imprimir\n4 - Inserir com prioridade\n");
     scanf("%d", &opc);
    
    do{
        if(opc == 1){
            printf("Entre com um numero inteiro:\n");
            scanf("%d", &numero);
            
            inserir_fila(numero, &fila);
            
        }else if(opc == 2){
            aux = remover_fila(&fila);
            
            if(aux != NULL){
                printf("\nCelula removida possui %d como chave!\n", aux->idade);
            }
            
        }else if(opc == 3){

            imprime(fila);
            
        }else if(opc == 4){
            
            printf("Entre com um numero inteiro:\n");
            scanf("%d", &numero);
            
            inserir_com_prioridade(numero, &fila);
            
        }
        
        printf("\n0 - Sair\n1 - Inserir\n2 - Remover\n3 - Imprimir\n4 - Inserir com prioridade\n");
        scanf("%d", &opc);
    }while(opc != 0);
    
    return 0;
}

void inserir_fila(int x, celula **fila){
    celula *nova = (celula *) malloc(sizeof(celula));
    celula *aux;
    
    if(nova != NULL){
        nova->idade = x;
        nova->proximo = NULL;    //nulo pois toda inserção é feita no final da fila
        
        if(*fila == NULL){
            /* *fila sendo igual a NULL, significa que a fila esta vazia,
            ou seja, *fila é o ultimo nó da minha estrutura*/
            
            *fila = nova;
            
        }else{
            aux = *fila;  
            
            while(aux->proximo != NULL){
                
                aux = aux->proximo;
            }
            
            aux->proximo = nova;
        }
    }
}


celula* remover_fila(celula **fila){
    celula *aux = NULL;
    
    if(*fila != NULL){
        
        aux = *fila;  /*ponteiro auxiliar aponta para o primeiro elemento
        da fila*/  
        
        *fila = aux->proximo;  /*atualiza o incio da fila*/
    }else{
        printf("\nFila vazia!!");
    }
    
    return aux;
}

void imprime(celula *fila){
    
    printf("\n-------- FILA -------\n");
    
    while(fila != NULL){
        printf("%d\n", fila->idade);
        fila = fila->proximo;
    }
    printf("-------- FIM FILA -------\n");

}

void inserir_com_prioridade(int x, celula **fila){
    celula *nova = (celula *) malloc(sizeof(celula));
    celula *aux;
    
    if(nova != NULL){
        nova->idade = x;
        nova->proximo = NULL;    //nulo pois toda inserção é feita no final da fila
        
        if(*fila == NULL){
            /* *fila sendo igual a NULL, significa que a fila esta vazia,
            ou seja, *fila é o ultimo nó da minha estrutura*/
            
            *fila = nova;
            
        }else{
            //parte do codigo que cuida da inserçao com priorid.
            if(x > 59){
                //é a primeira prioridade?
                if((*fila)->idade < 60){
                    nova->proximo = *fila;
                    *fila = nova;
                }else{
                    //aqui, aux é prioridade
                    
                    aux = *fila;  
                    while(aux->proximo != NULL && aux->proximo->idade > 59){
                        aux = aux->proximo;
                    }
                    /*aux->proximo ou sera nulo, ou sera o primeiro no da
                    fila que não é prioridade*/
                    
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
        printf("\nErro ao alocar memoria!\n");
    }
    
}