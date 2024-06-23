#include <stdio.h>
#define MAX 100

typedef struct{
    int dia, mes, ano;
}tipo_data;

typedef struct{
    char modelo[MAX];
    char marca[MAX];
    float preco;
    tipo_data data;
}novo_tipo;

void cadastro(novo_tipo lista[], int n);

int ano(novo_tipo lista[], int n);

float media(novo_tipo lista[], int n, int ano);

int main(){
    novo_tipo lista[MAX];
    int n, aux;

    printf("Informe quantos carros serao cadatrados:\n");
    scanf("%d", &n);
    getchar();

    cadastro(lista, n);

    printf("o ano do carro mais velho eh: %d\n", ano(lista, n));

    printf("Informe o ano de desejo:\n");
    scanf("%d", &aux);
    getchar();

    printf("Media dos precos dos carros de ano %d eh: %f\n", aux, media(lista, n, aux));

    return 0;
}

void cadastro(novo_tipo lista[], int n){
    novo_tipo *p;

    for(p = lista; p < lista + n; p++){
        printf("Informe o modelo do carro:\n");
        scanf("%[^\n]", p->modelo);
        getchar();

        printf("Informe a marca do carro:\n");
        scanf("%[^\n]", p->marca);
        getchar();

        printf("Infomre o preco do carro:\n");
        scanf("%f", &p->preco);
        getchar();

        printf("Informe a data de lançamento do carro: dia/mes/ano\n");
        scanf("%d/%d/%d", &p->data.dia, &p->data.mes, &p->data.ano);
        getchar();
    }
}

int ano(novo_tipo lista[], int n){
    int aux = lista[0].data.ano;

    for(int i = 1; i < n; i++){
        if(lista[0].data.ano < aux){
            aux = lista[0].data.ano;
        }
    }

    return aux;
}

float media(novo_tipo lista[], int n, int ano){
    float soma = 0.0;
    int quant = 0;

    for(int i = 0; i < n;i++){
        if(lista[i].data.ano == ano){
            soma += lista[i].preco;
            quant++;
        }
    }

    if(quant != 0){
        return soma/quant;
    }else{
        return 0.0;
    }
}