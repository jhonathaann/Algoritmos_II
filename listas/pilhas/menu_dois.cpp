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

typedef struct{
    celula *topo;    //agr temos explicitamente um tipo pilha, que tem um ponteiro para o topo
    int tam;      //variavel que vai guarda o tamanho da pilha
}Pilha;

void criar_pilha(Pilha *p);

Pessoa ler_pessoa();

void imprimir_pessoa(Pessoa p);

void empilhar(Pilha *p);

celula* desempilhar(Pilha *p);

void imprime(Pilha *p);

int main(){
    celula *celula_removida;
    Pilha p;
    int opcao;
    
    criar_pilha(&p);     //criando a pilha
    
    printf("\n0 - Sair\n1 - Empilhar\n2 - Desemepilhar\n3 - Imprimir\n");
    scanf("%d", &opcao);
    getchar();
    
    do{
        if(opcao == 1){
             
            empilhar(&p);
             
        }else if(opcao == 2){
            
            celula_removida = desempilhar(&p);
            
            if(celula_removida != NULL){
                printf("\nRemocao realizada!");
                imprimir_pessoa(celula_removida->p);

                free(celula_removida);       //liberando da memoria a celula que foi desempilhada
                
            }else{
                printf("\nPilha vazia!!\n");
            }
        
        }else if(opcao == 3){
        
            imprime(&p);
            
        }else{
            printf("\nOpcao invalida!\n");
        }
        
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desemepilhar\n3 - Imprimir\n");
        scanf("%d", &opcao);
        getchar();
    }while(opcao != 0);
    
    return 0;
}

void criar_pilha(Pilha *p){
    p->topo = NULL;
    p->tam = 0;
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

void empilhar(Pilha *p){
    celula *nova = (celula *) malloc(sizeof(celula));
    
    if(nova != NULL){
        nova->p = ler_pessoa();       //insere um novo dado
        nova->proximo = p->topo;      //n->prox aponta pro topo atual
        p->topo = nova;             //atualizei o topo da pilha
        p->tam++;
        
    }else{
        printf("\nNao foi possivel alocar na memoria essa estrutura!!\n");
    }
    
    
}

celula* desempilhar(Pilha *p){
    if(p->topo != NULL){
        celula *aux = p->topo;       //ponteiro para o topo
        p->topo = aux->proximo;     //atualizei o topo da pilha (useu aux por opcao)
        p->tam--;
        return aux;          //retorna a chave removida
        
    }else{
        printf("\nPilha vazia!\n");
    }
    
    return NULL;          //caso a pilha esteja vazia desde o inicio
}

void imprime(Pilha *p){
    celula *aux = p->topo;    //para n perder o topo da pilha
    
    printf("\n--------------- PILHA Tam: %d -------------------\n", p->tam);
    while(aux != NULL){
        imprimir_pessoa(aux->p);
        aux = aux->proximo;
    }
    printf("\n--------------- FIM PILHA -------------------\n");
}