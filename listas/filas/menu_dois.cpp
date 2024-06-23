#include <stdio.h>
#include <stdlib.h>


typedef struct cel{
    int dado;
    struct cel *proximo;
}celula;

typedef struct{
    int tam;
    celula *inicio;
    celula *fim;
}Fila;

void criar_fila(Fila *fila);

void inserir_fila(int x, Fila *fila);

celula* remover_fila(Fila *fila);

void imprime(Fila *fila);


int main(){
    celula *aux;
    Fila fila;
    int opc, numero;
    
    criar_fila(&fila);
    
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
            imprime(&fila);
        }
        
        printf("\n0 - Sair\n1 - Inserir\n2 - Remover\n3 - Imprimir\n");
        scanf("%d", &opc);
    }while(opc != 0);
    
    return 0;
}

/*procedimento que inicializa a estrutura fila*/
void criar_fila(Fila *fila){
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tam = 0;
}


void inserir_fila(int x, Fila *fila){
    celula *aux, *nova = (celula *) malloc(sizeof(celula));
    
    if(nova != NULL){
        nova->dado = x;
        nova->proximo = NULL;    //nulo pois toda inserção é feita no final da fila
        
        if(fila->inicio == NULL){
            /* se o primeiro no da fila for nulo, entao
            nossa fila esta vazia*/
            
            fila->inicio = nova;
            fila->fim = nova;
            
            /*nesse momento, o primeiro e o ultimo sao exatamente iguais,
            isso pq nesse momento nos temos apenas um no*/
            
        }else{
            fila->fim->proximo = nova;  /*faz a linkagem do final da fila
            com o novo no que foi criado*/
            fila->fim = nova;  /*o fim eh o novo que acaba de ser criado.
            isso pq na fila, toda inserçao ocorre no final*/
        }
        fila->tam++;
        
        /*o fila aumenta de tamanho tanto se o if for verdadeiro ou se o else for verdadeiro. por isso eu coloquei o fila->tam++ fora
        */
    }
    
}

celula* remover_fila(Fila *fila){
    celula *aux = NULL;
    
    if(fila->inicio != NULL){
        
        aux = fila->inicio;  /*ponteiro auxiliar aponta para o primeiro elemento
        da fila*/  
        
        fila->inicio = aux->proximo;  /*atualiza o incio da fila*/
        fila->tam--;
        
    }else{
        printf("\nFila vazia!!");
    }
    
    return aux;
}

void imprime(Fila *fila){
    celula *aux = fila->inicio;
    
    printf("\n-------- FILA: %d -------\n", fila->tam);
    
    while(aux != NULL){
        printf("%d\n", aux->dado);
        aux = aux->proximo;
    }
    printf("-------- FIM FILA -------\n");
}