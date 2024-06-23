#include <stdio.h>
#define MAX 20

typedef struct{
    int dia, mes, ano;
}tipo_data;

typedef struct{
    char nome[MAX];
    float preco;
    tipo_data data;
    int quantidade;
}novo_T;


void cadastro(novo_T lista[], int n);

void listaVencidos(tipo_data data, int n, novo_T lista[]);

int busca(novo_T lista[], int n);

int main(){
    int n, aux;
    novo_T lista[MAX];
    tipo_data data_vencimento;

    scanf("%d", &n);
    getchar();

    cadastro(lista, n);
   
    scanf("%d/%d/%d", &data_vencimento.dia, &data_vencimento.mes, &data_vencimento.ano);
    getchar();

   listaVencidos(data_vencimento, n, lista);

   aux = busca(lista, n);

   if(aux == -1){
    printf("Produtos inexistentes\n");
   }else{
    printf("%s - %f - %d\n", lista[aux].nome, lista[aux].preco, lista[aux].quantidade);
   }

}

void cadastro(novo_T lista[], int n){
    novo_T *p;

    for(p = lista; p < lista + n; p++){
        scanf("%[^\n]", p->nome);
        getchar();

        scanf("%f %d %d/%d/%d", &p->preco, &p->quantidade, &p->data.dia, &p->data.mes, &p->data.ano);
        getchar();
    }
}

void listaVencidos(tipo_data data, int n, novo_T lista[]){

    for(int i = 0; i < n;i++){
        if(lista[i].data.ano < data.ano){

            printf("%s %d/%d/%d\n", lista[i].nome, lista[i].data.dia, lista[i].data.mes, lista[i].data.ano);

        }else if(lista[i].data.ano == data.ano){

            if(lista[i].data.mes < data.mes){

                printf("%s %d/%d/%d\n", lista[i].nome, lista[i].data.dia, lista[i].data.mes, lista[i].data.ano);

            }else if(lista[i].data.mes == data.mes){

                if(lista[i].data.dia <= data.dia){

                    printf("%s %d/%d/%d\n", lista[i].nome, lista[i].data.dia, lista[i].data.mes, lista[i].data.ano);
                }
            }
        }
    }

}

int busca(novo_T lista[], int n){
    int flag = 0, aux = 0;
    float menor = lista[0].preco * lista[0].quantidade;

    for(int i = 1; i < n; i++){
        if(lista[i].quantidade <= 5){
            flag = 1;
            if((lista[i].preco * lista[i].quantidade) < menor){
                menor = lista[i].preco * lista[i].quantidade;
                aux = i;
            }
        }
    }

    if(flag == 0){
        return -1;
    }else{
        return aux;
    }
    
}