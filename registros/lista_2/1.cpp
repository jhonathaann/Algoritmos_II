#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct novoT{
    char nome[50];
    float salario;
}novo_tipo;

void cadastro(novo_tipo lista[]);

void imposto(novo_tipo lista[]);

void busca(novo_tipo lista[], char letra);

void imprime(novo_tipo lista[]);

int comparar_salario(const void *p, const void *q);


int main(){
    novo_tipo lista[MAX];
    char letra;

    cadastro(lista);

    printf("Informe uma letra:\n");
    scanf("%c", &letra);

    busca(lista, letra);

    qsort(lista, MAX, sizeof(novo_tipo), comparar_salario);

    imprime(lista);

    return 0;
}

void cadastro(novo_tipo lista[]){
    novo_tipo *p;

    for(p = lista; p < lista + MAX; p++){
        printf("Digite o nome do funcionario:\n");
        scanf("%[^\n]", p->nome);
        getchar();

        printf("Agora digite o Salario:\n");
        scanf("%f", &p->salario);
        getchar();
    }
}

void imposto(novo_tipo lista[]){
    novo_tipo *p;
    float aux;

    for(p = lista; p < lista + MAX; p++){
        if(p->salario <= 850){
            printf("NOME: %s    ", p->nome);
            printf("Situacao: INSENTO!!\n");
        }else if(p->salario > 850 && p->salario < 1200){
            aux = 0.1 * p->salario;
            printf("NOME: %s    ", p->nome);
            printf("Situacao: valor do imposto = %.2f\n", aux);
            printf("Valor a receber: %.2f\n", p->salario - aux);
        }else{
            aux = 0.2 * p->salario;
            printf("NOME: %s    ", p->nome);
            printf("Situacao: valor do imposto = %.2f\n", aux);
            printf("Valor a receber: %.2f\n", p->salario - aux);
        }
    }
}

void busca(novo_tipo lista[], char letra){
    novo_tipo *p;
    int flag = 0;

    printf("-------------- %c -------------------\n", letra);
    for(p = lista; p < lista + MAX; p++){
        if(p->nome[0] == letra){
            printf("NOME: %s\n", p->nome);
            printf("SALARIO: %.2f\n", p->salario);
            flag = 1;
        }
    }

    if(flag == 0){
        printf("Nao foi encontrada nenhum nome que comeca com a letra %c!\n", letra);
    }
    
}

int comparar_salario(const void *p, const void *q){

    const novo_tipo *funcio_A = (const novo_tipo *)p;
    const novo_tipo *funcio_B = (const novo_tipo *)q;

    if (funcio_A->salario < funcio_B->salario) return -1;
    else if (funcio_A->salario > funcio_B->salario) return 1;
    else return 0;

}

void imprime(novo_tipo lista[]){
    
    printf("\nListagem dos salarios em ordem crescente:\n");
    for(int i = 0; i < MAX; i++){
        printf("NOME: %s, Salario: %.2f\n", lista[i].nome, lista[i].salario);
    }

   printf("\nListagem dos salarios em ordem decrescente:\n");
   for(int i = MAX - 1; i > -1; i--){
    printf("NOME: %s, Salario: %.2f\n", lista[i].nome, lista[i].salario);
   }
}

