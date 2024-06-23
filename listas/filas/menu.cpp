#include <stdio.h>
#include <stdlib.h>

/*FILAS: o primeiro a entrar eh o primeiro a sair
na pilha, a inserção era sempre no topo, ou seja, todo novo nó
inserido era o topo/inicio da pilha. na fila, a inserção ocorre sempre
no final*/

typedef struct cel{
    int dado;
    struct cel *proximo;
}celula;

void inserir_fila(int x, celula **fila);

celula* remover_fila(celula **fila);

void imprime(celula *fila);


int main(){
    celula *aux, *fila = NULL;
    int opc, numero;
    
     printf("\n0 - Sair\n1 - Inserir\n2 - Remover\n3 - Imprimir\n");
     scanf("%d", &opc);
    
    do{
        if(opc == 1){
            printf("Entre com um numero inteiro:\n");
            scanf("%d", &numero);
            
            inserir_fila(numero, &fila);
            
        }else if(opc == 2){
            aux = remover_fila(&fila);
            
            if(aux != NULL){
                printf("\nCelula removida possui %d como chave!\n", aux->dado);
            }
            
        }else if(opc == 3){
            imprime(fila);
        }
        
        printf("\n0 - Sair\n1 - Inserir\n2 - Remover\n3 - Imprimir\n");
        scanf("%d", &opc);
    }while(opc != 0);
    
    return 0;
}

void inserir_fila(int x, celula **fila){
    celula *nova = (celula *) malloc(sizeof(celula));
    celula *aux;
    
    if(nova != NULL){
        nova->dado = x;
        nova->proximo = NULL;    //nulo pois toda inserção é feita no final da fila
        
        if(*fila == NULL){
            /* *fila sendo igual a NULL, significa que a fila esta vazia,
            ou seja, *fila é o ultimo nó da minha estrutura*/
            
            *fila = nova;
            
        }else{
            aux = *fila;  
            
            while(aux->proximo != NULL){
                /*aux->proximo != NULL e não aux != NULL
                pq se aux->proximo for NULL, significa que eu estou
                na minha ultima celula, ou seja, aux esta nesse momento no
                ultimo nó da fila*/
                
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
        printf("%d\n", fila->dado);
        fila = fila->proximo;
    }
    printf("-------- FIM FILA -------\n");

    /*aqui eu estou utilizando o proprio ponteiro para percorrer a fila
    pq essa funcao n recebe o endereço dessa variavel, e sim o conteudo, que eh o ponteiro para o 
    primeiro no*/
}