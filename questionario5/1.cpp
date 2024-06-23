#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    char caracter;
    struct cel *proximo;
}celula;

celula* empilhar(char simbolo, celula *topo);

celula* desempilhar(celula **topo);

int verifica_expressao(char c[]);

int forma_par(char empilhado, char desempilhado);

int main(){
    char expressao[100];
    
    scanf("%s", expressao);

    if(verifica_expressao(expressao) == 0){
        printf("Parênteses incorretos");
    }else{
        printf("Parênteses corretos");
    }

    return 0;
    
    
}

celula* empilhar(char simbolo, celula *topo){
    celula *nova = (celula *) malloc(sizeof(celula));
    
    if(nova == NULL){
        return NULL;
    }
    
    nova->caracter = simbolo;
    nova->proximo = topo;
    
    return nova;
}

celula* desempilhar(celula **topo){
    
    if(*topo == NULL){
        return NULL;
    }
    
    celula *aux = *topo;   // cria um ponteiro auxiliar e faz ele apontar para o topo inical da pilha
    *topo = aux->proximo;  // atualiza o topo da pilha
    
    return aux;  // retorna a celula que vai se removida
}

int verifica_expressao(char c[]){
    int i = 0;
    celula *pilha = NULL, *aux = NULL;
    
    // percorrendo a string de caracteres
    while(c[i] != '\0'){
        
        if(c[i] == '(' || c[i] == '[' || c[i] == '{'){
            
            pilha = empilhar(c[i], pilha);
            
        }else if(c[i] == ')' || c[i] == ']' || c[i] == '}'){
            
            aux = desempilhar(&pilha);
            
            if(aux == NULL){
                return 0;  // expressao mal formulada, ja que faltou a abertura de pelo menos um parenteses
            }
            
            if(forma_par(c[i], aux->caracter) == 0){
                
                return 0; // mal formulada, ja que foram encontrados dois simbolos que nao formaram um par
            }
            
            free(aux);
            
        }
        
        i++;
    }
    
    if(pilha != NULL){
        
        // mal formulada pois sobrou elementos na pilha
        return 0;
    }else{
        
        // expressao bem formulada
        return 1;
    }
    
}

int forma_par(char empilhado, char desempilhado){
    
    switch(empilhado){
        case ')':
            if(desempilhado == '('){
                return 1;
            }else{
                return 0;
            }
            
            break;
        
        case ']':
            if(desempilhado == '['){
                return 1;
            }else{
                return 0;
            }
            
            break;
            
        case '}':
            if(desempilhado == '{'){
                return 1;
            }else{
                return 0;
            }
            
            break;
    }
    
    return 0;
            
}