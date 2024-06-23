#include <stdio.h>
#define MAX 50

typedef struct  novoT{
    char nome[MAX], sexo;
    float altura, peso;
    int cpf;
}novo_tipo;

void cadastrar(novo_tipo lista[], int posicao);

void busca(novo_tipo lista[], int cpf, int tam);

void imprime_M(novo_tipo lista[], int tam);

int main(){
    novo_tipo lista[50];
    int opc, i = 0, aux;

    do{
        printf("\n0 - SAIR\n1 - CADASTRAR\n2 - BUSCAR PELO CPF\n3 - SEXO M\n");
        scanf("%d", &opc);
        getchar();

        if(opc == 1){
            cadastrar(lista, i);
            i++;
        }else if(opc == 2){
            printf("Informe o CPF desejado:\n");
            scanf("%d", &aux);
            getchar();

            busca(lista, aux, i);
        }else if(opc == 3){
            imprime_M(lista, i);
        }
    }while(opc != 0);
}

void cadastrar(novo_tipo lista[], int posicao){

    printf("Informe o nome: \n");
    scanf("%[^\n]", lista[posicao].nome);
    getchar();

    printf("Informe o sexo: M/F\n");
    scanf("%c", &lista[posicao].sexo);
    getchar();

    printf("informe o CPF: \n");
    scanf("%d", &lista[posicao].cpf);
    getchar();

    printf("informe a altura e o peso: \n");
    scanf("%f %f", &lista[posicao].altura, &lista[posicao].peso);
    getchar();
}

void busca(novo_tipo lista[], int cpf, int tam){
    int flag = 0, i;

    for(i = 0; i < tam; i++){
        if(lista[i].cpf == cpf){
            flag = 1;
            break;
        }
    }

    if(flag == 1){
        printf("CPF %d encontrado! IMC= %f", cpf, lista[i].peso / (lista[i].altura * lista[i].altura));
    }else{
        printf("CPF %d nao encontrado!", cpf);
    }
}

void imprime_M(novo_tipo lista[], int tam){

    for(int i = 0; i < tam; i++){
        if(lista[i].sexo == 'M'){
            printf("-----------------------------------\n");
            printf("nome: %s\n", lista[i].nome);
            printf("IMC: %f\n", lista[i].peso / (lista[i].altura * lista[i].altura ));
        }
    }
}