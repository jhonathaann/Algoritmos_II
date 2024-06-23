#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    char caracter;
    struct cel *proximo;
}celula;

celula* empilhar(char simbolo, celula *pilha);

celula* desempilhar(celula **pilha);

void imprime(celula *pilha);

int verifica_expressao(char x[]);

int forma_par(char empilhado, char desempilhado);

int main(){
    char expressao[100];
    
    printf("Digite uma expressao matematica: \n");
    scanf("%49[^\n]s", expressao);
    
    printf("Retorno: %d\n", verifica_expressao(expressao));
    
    return 0;
}

celula* empilhar(char simbolo, celula *pilha){
    celula *nova = (celula *) malloc(sizeof(celula));
    
    if(nova == NULL){
        printf("Nao foi possivel alocar na memoria essa estrutura!\n");
        return NULL;
    }else{
        nova->caracter = simbolo;      //insere o dado na pilha
        nova->proximo = pilha;        //atualiza o topo da pilha
        return nova;                  //retorna o topo da pilha
    }
}

celula* desempilhar(celula **pilha){
    if(*pilha == NULL){
        printf("Pilha vazia!\n");
        return NULL;
    }else{
        celula *aux = *pilha;       //cria um ponteiro auxiliar e faz ele apontar para o topo inical da pilha
        *pilha = aux->proximo;     //atualiza o topo da pilha
        return aux;             //retorna a pilha a ser desempilhada
    }
}

void imprime(celula *pilha){
    
    printf("\nPILHA\n");
    for(celula *p = pilha; p != NULL; p = p->proximo){
        printf("%c\n", p->caracter);
    }
    printf("\nFIM PILHA\n");
}

int verifica_expressao(char x[]){
    int i = 0;
    celula *pilha = NULL, *aux = NULL;
    
    while(x[i] != '\0'){     //percorrendo a string de caracteres
        
        if(x[i] == '(' || x[i] == '{' || x[i] == '['){
            
            pilha = empilhar(x[i], pilha);
            
            imprime(pilha);
            
        }else if(x[i] == ')' || x[i] == '}' || x[i] == ']'){
            aux = desempilhar(&pilha);
            
            if(aux == NULL){
                printf("Expressao mal formulada, ja que faltou a abertura de pelo menos uma simbolo matematico!!\n");
                return 0;
            }
            if(forma_par(x[i], aux->caracter) == 0){
                printf("Expressao mal formulada, ja que foi encontrado dois simbolos que nao formaram um par!!\n");
                return 0;  //expressao mal formulada
            }
            
            free(aux);
        }
        i++;
    }
    
    imprime(pilha);
    if(pilha != NULL){ 
        printf("Expressao mal formulada, pois sobrou elementos na pilha!!\n");
        return 0; 
    }else{
        printf("Expressao bem formulada!!\n");
        return 1;
    }
}

/*se forma_par retorna 0, significa que foi encontrado pelo menos um par de simbolos que nao formaram um par, 
logo a expressao nao esta bem formulada */

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
}