#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char nome[50];
    Data data;
}Pessoa;

typedef struct cel{
    Pessoa p;
    struct cel *proximo;
}celula;

Pessoa ler_pessoa();

void imprimir_pessoa(Pessoa p);

celula* empilhar(celula *pilha);

celula* desempilhar(celula **pilha);

void imprime(celula *pilha);

int main(){
    celula *celula_removida, *topo = NULL;
    int opcao;
    
    printf("\n0 - Sair\n1 - Empilhar\n2 - Desemepilhar\n3 - Imprimir\n");
    scanf("%d", &opcao);
    getchar();
    
    do{
        if(opcao == 1){
             
             topo = empilhar(topo);
             
        }else if(opcao == 2){
            
            celula_removida = desempilhar(&topo);
            
            if(celula_removida != NULL){
                printf("\nRemocao realizada!");
                imprimir_pessoa(celula_removida->p);

                free(celula_removida);       //liberando da memoria a celula que foi desempilhada
                
            }else{
                printf("\nPilha vazia!!\n");
            }
        
        }else if(opcao == 3){
        
            imprime(topo);
            
        }else{
            printf("\nOpcao invalida!\n");
        }
        
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desemepilhar\n3 - Imprimir\n");
        scanf("%d", &opcao);
        getchar();
    }while(opcao != 0);
    
    return 0;
}

Pessoa ler_pessoa(){
    Pessoa p;
    
    printf("Digite o nome e a data de nascimento: dia/mes/ano\n");
    scanf("%49[^\n]", p.nome);
    getchar();
    scanf("%d/%d/%d", &p.data.dia, &p.data.mes, &p.data.ano);

    return p;
}

void imprimir_pessoa(Pessoa p){
    
    printf("\nNome: %s\nData: %2d/%2d/%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

celula* empilhar(celula *pilha){
    celula *nova = (celula *) malloc(sizeof(celula));
    
    if(nova != NULL){
        nova->p = ler_pessoa();       //insere um novo dado
        nova->proximo = pilha;        //atualiza o topo da pilha, que passa a ser "nova"
        return nova;                  //retorna o novo topo
  
    }else{
        printf("\nNao foi possivel alocar na memoria essa estrutura!!\n");
    }
    
    return NULL;          //caso eu n tenha conseguido alocar a memoria
}

celula* desempilhar(celula **pilha){
    if(*pilha != NULL){
        celula *aux = *pilha;       //pomteiro para o topo
        *pilha = aux->proximo;     //atualizei o topo da pilha (useu aux por opcao)
        return aux;          //retorna a chave removida
        
    }else{
        printf("\nPilha vazia!\n");
    }
    
    return NULL;          //caso a pilha esteja vazia desde o inicio
}

void imprime(celula *pilha){
    
    printf("\n--------------- PILHA -------------------\n");
    while(pilha != NULL){
        imprimir_pessoa(pilha->p);
        pilha = pilha->proximo;
    }
    printf("\n--------------- FIM PILHA -------------------\n");
}