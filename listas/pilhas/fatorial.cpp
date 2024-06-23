#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int valor;
    struct cel *proximo;
}celula;

celula* empilhar(celula *pilha, int num);

celula* desempilhar(celula **pilha);

void imprime(celula *pilha);

int fatorial(int numero);

int main(){
    int valor;
    
    printf("Digite um valor inteiro maior que zero: \n");
    scanf("%d", &valor);
    
    printf("Fatorial de %d eh: %d\n", valor, fatorial(valor));
    
    return 0;
}

celula* empilhar(celula *pilha, int num){
    celula *nova = (celula *) malloc(sizeof(celula));
    
    if(nova != NULL){
        nova->valor = num;
        nova->proximo = pilha;
        return nova;
        
    }else{
        printf("Nao foi possivel alocar essa estutura na memoria!\n");
        return NULL;
    }
}

celula* desempilhar(celula **pilha){
    
    if(pilha == NULL){
        printf("Pilha vazia!\n");
        return NULL;
    }else{
        celula *aux = *pilha;
        *pilha = aux->proximo;
        return aux;
        
    }
}

void imprime(celula *pilha){
    printf("\nPILHA\n");
    for(celula *p = pilha; p != NULL; p = p->proximo){
        printf("%d\n", p->valor);
    }
    printf("\n");
}

int fatorial(int numero){
    celula *pilha = NULL, *aux;
    
    while(numero > 1){
        pilha = empilhar(pilha, numero);
        numero--;
    }
    
    imprime(pilha);
    
    while(pilha != NULL){
        aux = desempilhar(&pilha);    //como ele esta desempilhando, uma hora ele termina e pilha apontara para NULL
        numero = numero * aux->valor;
        free(aux);    //como eu ja realizei a multiplicacao eu n preciso mais dessa celula
    }
    
    return numero;
}