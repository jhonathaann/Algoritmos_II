/*invertendo a ordem das letras de uma frase, mas
mantendo a ordem das palavras na frase*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    char caracter;
    struct cel *proximo;
}celula;

celula* empilhar(char x, celula *pilha);

celula* desempilhar(celula **pilha);

void inverter_palavra(char x[]);

int main(){
    char frase[100];
    
    printf("Informe uma frase:\n");
    scanf("%99[^\n]s", frase);
    
    inverter_palavra(frase);
    
    return 0;
}

celula* empilhar(char x, celula *pilha){
    celula *nova = (celula *) malloc(sizeof(celula));
    
    if(nova != NULL){
        nova->caracter = x;    //insere o dado na pilha
        nova->proximo = pilha;  //atualiza o topo da pilha
        return nova;            //retorna o novo topo
    }else{
        printf("Nao foi possivel alocar essa estrutura!\n");
        return NULL;
    }
}

celula* desempilhar(celula **pilha){
    celula *aux = NULL;
    
    if(*pilha != NULL){
        aux = *pilha;
        *pilha = aux->proximo;
        return aux;
    }else{
        printf("Pilha vazia!!\n");
        return aux;
    }
}

void inverter_palavra(char x[]){
    int i = 0;
    celula *pilha = NULL, *aux;
    
    while(x[i] != '\0'){
        
        if(x[i] != ' '){
            pilha = empilhar(x[i], pilha);
        }else{
            while(pilha != NULL){
                aux = desempilhar(&pilha);
                printf("%c", aux->caracter);
                free(aux);
            }
            
            printf(" ");
        }
        
        i++;
    }
    
    while(pilha != NULL){
        aux = desempilhar(&pilha);
        printf("%c", aux->caracter);
        free(aux);
    }
    
    printf("\n");
}