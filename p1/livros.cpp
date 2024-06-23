#include <stdio.h>
#define MAX 100

typedef struct{
    int dia, mes, ano;
}tipo_data;

typedef struct{
    char titulo[MAX];
    char autor[MAX];
    float preco;
    tipo_data data;
    int quantidade;
}novo_tipo;

void cadastrar(novo_tipo lista[], int n);

void busca(tipo_data data, novo_tipo lista[], int n);

int estoque(novo_tipo lista[], int n);


int main(){
    novo_tipo lista[MAX];
    int n, aux;
    tipo_data data;

    printf("Informe um n:\n");
    scanf("%d", &n);
    getchar();

    cadastrar(lista, n);

    printf("Digite uma data de referencia:\n");
    scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);

    busca(data, lista, n);

    aux = estoque(lista, n);
    if(aux == -1){
        printf("Livros inexistentes\n");
    }else{
        printf("%s %.2f", lista[aux].titulo, lista[aux].quantidade * lista[aux].preco);
    }

    return 0;
}

void cadastrar(novo_tipo lista[], int n){
    
    for(int i = 0; i < n; i++){
        printf("Informe o titulo do livro:\n");
        scanf("%[^\n]", lista[i].titulo);
        getchar();

        printf("Informe o nome do autor:\n");
        scanf("%[^\n]", lista[i].autor);
        getchar();

        printf("Informe o preco do livro:\n");        
        scanf("%f", &lista[i].preco);
        getchar();

        printf("Informe a data de lancamento do livro:\n");
        scanf("%d/%d/%d", &lista[i].data.dia, &lista[i].data.mes, &lista[i].data.ano);
        getchar();

        printf("Informe a quantidade em estoque do livro:\n");
        scanf("%d", &lista[i].quantidade);
        getchar();

    }
}

void busca(tipo_data data, novo_tipo lista[], int n){

    for(int i = 0; i < n; i++){
        if(lista[i].data.ano > data.ano){
            printf("NOME: %s\n", lista[i].titulo);
            printf("DATA: %d/%d/%d\n", lista[i].data.dia, lista[i].data.mes, lista[i].data.ano);

        }else if(lista[i].data.ano == data.ano){

            if(lista[i].data.mes > data.mes){
                printf("NOME: %s\n", lista[i].titulo);
                printf("DATA: %d/%d/%d\n", lista[i].data.dia, lista[i].data.mes, lista[i].data.ano);
            }else if(lista[i].data.mes == data.mes){

                if(lista[i].data.dia < data.dia){
                    printf("NOME: %s\n", lista[i].titulo);
                    printf("DATA: %d/%d/%d\n", lista[i].data.dia, lista[i].data.mes, lista[i].data.ano);
                }
            }
        }
    }
}

int estoque(novo_tipo lista[], int n){
    float valor_final = lista[0].quantidade * lista[0].preco;
    int aux, flag = 0;

    for(int i = 1; i < n; i++){
        if(lista[i].quantidade <= 5){
            flag = 1;
            if((lista[i].quantidade * lista[i].preco) > valor_final){
                valor_final = lista[i].quantidade * lista[i].preco;
                aux = i;
            }
        }
    }

    if(flag != 0){
        return aux;
    }else{
        return -1;
    }
}