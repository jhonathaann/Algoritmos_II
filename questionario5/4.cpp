#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int valor;
    struct cel *proximo;
}celula;

void inserir_ordenado(celula **lista, int numero);

void imprimir(celula *lista);

int main(){
    celula *lista = NULL;
    int quant, numero;

    scanf("%d", &quant);

    for(int i = 0; i < quant; i++){
        scanf("%d", &numero);

        inserir_ordenado(&lista, numero);
    }

    imprimir(lista);

    return 0;
}

void inserir_ordenado(celula **lista, int numero){
    celula *aux, *nova = (celula *) malloc(sizeof(celula));

    if(nova == NULL){
        printf("Erro na alocacao!\n");
        return;
    }

    // o campo valor dessa nova celula recebe o novo numero
    nova->valor = numero;

    // verificando se a lista esta vazia
    if(*lista == NULL){

        // essa nova celula vai ser a única estrutura da minha lista, por isso o prox dela deve ser null
        nova->proximo = NULL;
        *lista = nova;

    }else if(nova->valor < (*lista)->valor){  // o numero que eu quero inserir é menor?

        /* como nesse caso, o campo "valor" dessa nova celula que foi criada é menor que o campo valor que ja esta presente 
        na nossa lista, essa nova celula tem vir antes da "lista", já que a ordenação é crescente, por isso o 
        proximo da nova recebe a lista */ 
        nova->proximo = *lista;

        // atualiza a nossa lista da main
        *lista = nova;

    }else{

        /*nesse caso, o campo valor da nossa celula não é menor (ele é maior). portanto, nos temos que achar uma celula na nossa lista
        que possui o campo valor maior. porque achado essa celula, o novo nó que nos criamos deve ser inserido imediatamente antes dessa celula
        que contem o campo valor maior*/

        aux = *lista;
        while(aux->proximo != NULL && nova->valor > aux->proximo->valor){
            aux = aux->proximo;
        }

        /* o proximo da nova celula tem que receber o aux->proximo independente de como o laço foi quebrado
        porque no caso onde aux->proximo for iguala a null, a nossa nova celula vai ser o ultimo no da estrutura
        e no caso onde isso nao acontece, o campo valor da celula aux->proximo é maior que o campo valor da nossa nova celula*/
        nova->proximo = aux->proximo;
        
        aux->proximo = nova;
    }

}

void imprimir(celula *lista){
    celula *p;

    for(p = lista; p != NULL; p = p->proximo){
        printf("%d ", p->valor);
    }
}