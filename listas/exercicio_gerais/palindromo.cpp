#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel{
    char caracter;
    struct cel *prox;
}celula;

void empilha(celula **topo, char caracter);

// funcao para eu parar na ultima celula da minha lista
celula* final_da_pilha(celula *topo);

celula* desempilha(celula **topo);

void imprime(celula *topo);

int main(){
    celula *topo = NULL;
    celula *palindromo = NULL;
    celula *aux, *p;
    char c;
    int flag = 1;
    
    scanf("%c", &c);

    // a leitura é finalozada quando o usuario digitar um enter
    while(c != '\n'){
        empilha(&topo, c);

        scanf("%c", &c);
    }
    
    p = final_da_pilha(topo);
    
    aux = desempilha(&topo);

    
    while(aux != NULL && p != NULL){
        empilha(&palindromo, aux->caracter);
        
        //printf("%c %c\n", palindromo->caracter, p->caracter);
        if(palindromo->caracter != p->caracter){
            flag = 0;
            break;
        }
        p = p->prox;
        
        aux = desempilha(&topo);
    }
    
    if(flag == 1){
        printf("O texto eh palindromo!\n");
    }else{
        printf("O texto nao eh palindromo!\n");
    }
    
    return 0;
}

void empilha(celula **topo, char caracter){
    celula *nova = (celula *) calloc(1, sizeof(celula));
    if(nova == NULL){
        printf("Erro ao alocar memoria na fucao empilha!\n");
        return;
    }
    
    nova->caracter = caracter;
    nova->prox = *topo;
    *topo = nova;
}

celula* desempilha(celula **topo){
    celula *no_removido = NULL;
    
    if(*topo == NULL){
        return no_removido;
    }else{
        
        no_removido = *topo;
        *topo = (*topo)->prox;
    }
    
    return no_removido;
}

celula* final_da_pilha(celula *topo){
    celula *aux = topo;
    
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    
    return aux;
}

void imprime(celula *topo){
    celula *p;
    
    for(p = topo; p != NULL; p = p->prox){
        printf("%c", p->caracter);
    }
}