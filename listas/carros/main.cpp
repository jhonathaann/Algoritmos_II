#include <stdio.h>
#include <stdlib.h>

#include "funcoes.cpp"

int main(){
    int opc, ano, codigo;
    float nota;
    char modelo[40];
    Marcas *marca = NULL;
    Carros *carro = NULL;

    do{
        printf("\n1 - Cadastrar uma marca");
        printf("\n2 - Cadastrar um carro");
        printf("\n3 - Listagem de carros");
        printf("\n4 - Exclusao de uma marca");
        printf("\n5 - Sair");
        printf("\nOpcao: ");
        scanf("%d", &opc);
        getchar();

        if(opc == 1){
            printf("Informe o codigo e a nota: \n");
            scanf("%d %f", &codigo, &nota);
            getchar();

            inserirMarca(&marca, codigo, nota);
        }else if(opc == 2){
            printf("Informe o codigo da marca:\n");
            scanf("%d", &codigo);
            getchar();

            // um carro só é para ser inserido caso ele seja de uma marca ja cadastrada

            if(buscaMarca(marca, codigo) == 0.0){
                printf("Codigo %d nao foi encontrado como uma das marcas de carros!\n", codigo);

            }else{
                printf("Informe o modelo do carro:\n");
                scanf("%[^\n]", modelo);
                getchar();

                printf("Informe o ano do carro:\n");
                scanf("%d", &ano);
                getchar();

                inserirCarro(&carro, modelo, ano, codigo);
            }

        }else if(opc == 3){
            listagem(marca, carro);
        }else if(opc == 4){
            // uma marca so pode ser excluida se nao existir nenhum carro cadastrado com ela
            printf("Informe o codigo da marca a ser removido:\n");
            scanf("%d", &codigo);
            getchar();

            removerMarca(&marca, carro, codigo);
        }

    

    }while(opc != 5);

    return 0;
}