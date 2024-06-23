#include <stdio.h>
#define MAX 10

typedef struct d{
    int dia, mes, ano;
}nova_data;

typedef struct novo_T{
    char nome[50];
    float altura;
    nova_data data;

}novo_tipo;

void cadastrar(novo_tipo lista[], int n);

void imprime(novo_tipo lista[], int n);

void busca(novo_tipo lista[], int n, int dia, int mes, int ano);

int main(){
    novo_tipo lista[MAX];
    int opc, dia, mes, ano, aux, flag;

    printf("Informe a quantidade de pessoas da lista: \n");
    scanf("%d", &aux);
    getchar();
    flag = aux;

    printf("\n0 - SAIR\n1 - INSERIR UMA PESSOA\n2 - LISTAS NOMES E ALTURAS\n3 - LISTAS PESSOAS DE UMA DATA FORNECIDA\n");
    scanf("%d", &opc);
    getchar();

    while(opc != 0){

        if(opc == 1){
            if(flag < MAX){
                cadastrar(lista, aux);
                flag++;
            }else{
                printf("LISTA SEM ESPACO!!\n");
            }
            
        }else if(opc == 3){
            printf("Digite a data de nascimento para ser bsucada: dia/mes/ano7\n");
            scanf("%d/%d/%d", &dia, &mes, &ano);
            getchar();
    
            busca(lista, aux, dia, mes, ano);
        }else if(opc == 2){
            imprime(lista, aux);
        }

        printf("0 - SAIR\n1 - INSERIR UMA PESSOA\n2 - LISTAS NOMES E ALTURAS\n3 - LISTAS PESSOAS DE UMA DATA FORNECIDA\n");
        scanf("%d", &opc);
        getchar();
    }

    return 0;
}

void cadastrar(novo_tipo lista[], int n){
    novo_tipo *p;

    for(p = lista; p < lista + n; p++){
        printf("Informe o nome: \n");
        scanf("%[^\n]", p->nome);
        getchar();

        printf("Informe a altura: \n");
        scanf("%f", &p->altura);
        getchar();

        printf("Informe a data de nascimento: dia/mes/ano\n");
        scanf("%d/%d/%d", &p->data.dia, &p->data.mes, &p->data.ano);
        getchar();
    }
}

void imprime(novo_tipo lista[], int n){
    novo_tipo *p;

    printf("---------------------\n");
    for(p = lista; p < lista + n; p++){
        printf("NOME: %s\n", p->nome);
        printf("ALTURA: %.2f\n", p->altura);
        printf("----------------------\n");
    }
}

void busca(novo_tipo lista[], int n, int dia, int mes, int ano){
    novo_tipo *p;

    for(p = lista; p < lista + n; p++){
        if(p->data.ano < ano){
            printf("NOME: %s\n", p->nome);
            printf("DATA DE NASCIMENTO: %d/%d/%d\n", p->data.dia, p->data.mes, p->data.ano);

        }else if(p->data.ano == ano && p->data.mes < mes){
            printf("NOME: %s\n", p->nome);
            printf("DATA DE NASCIMENTO: %d/%d/%d\n", p->data.dia, p->data.mes, p->data.ano);

        }else if((p->data.ano == ano && p->data.mes == mes) && p->data.dia < dia){
            printf("NOME: %s\n", p->nome);
            printf("DATA DE NASCIMENTO: %d/%d/%d\n", p->data.dia, p->data.mes, p->data.ano);

        }
    }
}