#include <stdio.h>
#define MAX 1

typedef struct novoT{
    char nome[50];
    int cpf;
    float saldo;
}novo_tipo;

void criar(novo_tipo lista[]);

void saque(novo_tipo lista[]);

void deposito(novo_tipo lista[]);

void imprime(novo_tipo lista[]);


int main(){
    novo_tipo lista[3];
    int opc;

    criar(lista);

    printf("0 - SAIR\n1 - DEPOSITO\n2 - SAQUE\n");
    scanf("%d", &opc);
    getchar();

    while(opc != 0){
        if(opc == 1){
            deposito(lista);

            
        }else if(opc == 2){
            saque(lista);
           
        }else{
            printf("Opcao invalida!\n");
        }

        printf("0 - SAIR\n1 - DEPOSITO\n2 - SAQUE\n");
        scanf("%d", &opc);
        getchar();
    }

    return 0;

}

void criar(novo_tipo lista[]){
    novo_tipo *p;

    for(p = lista; p < lista + MAX; p++){
        printf("Informe o nome: \n");
        scanf("%[^\n]", p->nome);
        getchar();

        printf("Informe o CPF: (%s)\n", p->nome);
        scanf("%d", &p->cpf);
        getchar();

        printf("Digite o saldo inicial: (%s)\n", p->nome);
        scanf("%f", &p->saldo);
        getchar();
    }
}

void saque(novo_tipo lista[]){
    int cpf, flag = 0;
    float aux;

    printf("Informe o CPF da conta para realizar o saque: \n");
    scanf("%d", &cpf);
    getchar();

    for(novo_tipo *p = lista; p < lista + MAX; p++){
        if(p->cpf == cpf){
            flag = 1;

            printf("Informe o valor para desejado para sacar: \n");
            scanf("%f", &aux);
            getchar();

            if(aux <= p->saldo){
                p->saldo -= aux;
            }else{
                printf("Saldo da conta indisponivel!!\n");
            }

            imprime(lista);
            break;
        }
        
    }

    if(flag == 0){
        printf("Conta de CPF %d NAO encontrada!!\n", cpf);
    }
}

void deposito(novo_tipo lista[]){
    int cpf, flag = 0;
    float aux;

    printf("Informe o CPF da conta para realizar o deposito: \n");
    scanf("%d", &cpf);
    getchar();

    for(novo_tipo *p = lista; p < lista + MAX; p++){
        
        if(p->cpf == cpf){
            flag = 1;

            printf("Informe o valor do deposito: \n");
            scanf("%f", &aux);
            getchar();

            p->saldo += aux;

            imprime(lista);

            break;
        }
    }

    if(flag == 0){
        printf("Conta de CPF %d NAO encontrada!!\n", cpf);
    }

}

void imprime(novo_tipo lista[]){
    printf("\n---------------------------\n");

    for(novo_tipo *p = lista; p < lista + MAX; p++){
        printf("Nome: %s\n", p->nome);
        printf("CPF: %d\n", p->cpf);
        printf("SALDO: %.2f\n", p->saldo);
    }
}