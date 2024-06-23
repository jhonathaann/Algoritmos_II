#include <stdio.h>
#define MAX 20

typedef struct{
    char tipo;
    char nome[MAX+1];
    float peso, precoKG;
}grao;

void leitura(grao lista[]);

void busca_melhor(grao lista[]);

int main(){
    grao lista[3];

    leitura(lista);
    busca_melhor(lista);

    return 0;
}

void leitura(grao lista[]){
    grao *p;

    for(p = lista; p < lista + 3; p++){
        scanf("%[^\n]", p->nome);
        getchar();

        scanf("%c", &p->tipo);
        getchar();

        scanf("%f", &p->peso);
        getchar();

        scanf("%f", &p->precoKG);
        getchar();
    }
}

void busca_melhor(grao lista[]){
    grao *p;
    int grao_ideal = (int)lista[0].tipo;
    int flag = 0;
    float preco1, preco2;

    for(p = lista; p < lista + 3; p++){
        if((int)p->tipo <= grao_ideal){
            grao_ideal = (int)p->tipo;
            flag++;
        }
    }

    if(flag <= 1){
        for(p = lista; p < lista + 3; p++){
            if((int)p->tipo == grao_ideal){
                printf("O grão ideal é o/a %s\n", p->nome);
            }
        }
    }else{
        //primeira e segunda sao iguais ao grao_ideal
       if((int)lista[0].tipo == grao_ideal && (int)lista[1].tipo == grao_ideal){
        scanf("%f", &preco1);
        scanf("%f", &preco2);

        if((preco1 * lista[0].precoKG) < (preco2 * lista[1].precoKG)){
            printf("O grão ideal é o/a %s\n", lista[0].nome);
        }else{
             printf("O grão ideal é o/a %s\n", lista[1].nome);
        }


        //primeira se e terceira sao iguais ao grao ideal
       }else if((int)lista[0].tipo == grao_ideal && (int)lista[2].tipo == grao_ideal){

        scanf("%f", &preco1);
        scanf("%f", &preco2);

        if((preco1 * lista[0].precoKG) < (preco2 * lista[2].precoKG)){
            printf("O grão ideal é o/a %s\n", lista[0].nome);
        }else{
             printf("O grão ideal é o/a %s\n", lista[2].nome);
        }


        //segunda e terceira sao iguais ao grao ideal
       }else if((int)lista[1].tipo == grao_ideal && (int)lista[2].tipo == grao_ideal){

        scanf("%f", &preco1);
        scanf("%f", &preco2);

        if((preco1 * lista[1].precoKG) < (preco2 * lista[2].precoKG)){
            printf("O grão ideal é o/a %s\n", lista[1].nome);
        }else{
             printf("O grão ideal é o/a %s\n", lista[2].nome);
        }
        
       }

    }

}