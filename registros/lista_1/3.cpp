#include <stdio.h>
#define MAX 50

typedef struct novoT{
    int codigo;
    float preco;
    char nome[MAX];
}novo_tipo;

void cadastrar(novo_tipo lista[], int n);

void busca(novo_tipo lista[], int n, int codigo);


int main(){
    novo_tipo lista[MAX];
    int opc, tam;

    printf("digite o tamanho da lista: \n");
    scanf("%d", &tam);
    getchar();
    
    
    cadastrar(lista, tam);

    printf("informe o codigo do produto para ser buscado, e digite 0 para sair: \n");
    scanf("%d", &opc);
    getchar();

    while(opc != 0){
        
        busca(lista, tam, opc);
        printf("informe o codigo do produto para ser buscado, e digite 0 para sair: \n");
        scanf("%d", &opc);
        getchar();

    }
    
   return 0;

}

void cadastrar(novo_tipo lista[], int n){
    novo_tipo *p;  // criei um ponteiro do tipo novo_tipo

    for(p = lista; p < lista + n; p++){
        printf("Informe o nome do produto: \n");
        scanf("%[^\n]", p->nome);
        getchar();

        printf("informe o codigo do produto: \n");
        scanf("%d", &p->codigo);
        getchar();

        printf("informe o preco do produto: \n");
        scanf("%f", &p->preco);
        getchar();
    }

}

void busca(novo_tipo lista[], int n, int codigo){
    novo_tipo *p;
    int flag = 0;

    for(p = lista; p < lista + n; p++){
        if(p->codigo == codigo){
            printf("Preco do produto de codigo %d: RS%f\n", p->codigo, p->preco);
            flag = 1;
            break;
        }
    }

    if(flag == 0){
        printf("codigo do produto nao encontrado!!\n");
    }
}