#include <stdio.h>
#include <string.h>
/*caso algum voo esteja cancelado, eu vou trocar o codigo se seu voo para -1
isso pq eu preciso imprimir todas as outra informacoes, menos o codigo*/

struct aeroporto{

	char nome[100];
	int capacidade;
	int identificador;
};

struct voo{

	char nome[100];
	int identificador;
	int destino;
	int origem;
};

void ler_aeroportos(aeroporto lista[], int n);

void cadastrar_voo(voo lista[]);

void busca(voo lista[], int n, int codigo);

void cancelar(voo lista[], int n, int codigo);


int main(){


	int qtd_aeroporto;
	scanf(" %d", &qtd_aeroporto);
	getchar();

	int qtd_voos;
	scanf(" %d", &qtd_voos);
	getchar();

	aeroporto lista_aeroporto[qtd_aeroporto];
    voo lista_voo[qtd_voos];

	ler_aeroportos(lista_aeroporto, qtd_aeroporto);


	/*ler os aeroportos */


	int j=0;
	int op;
	int aux;

    do{
		//printf("Selecione uma opcao:\n");
        scanf(" %d", &op);
		getchar();

		if(op == 1){// Adicionar Voo (orgiem e destino)

			printf("op 1 \n");
			if(j <= qtd_voos){
				cadastrar_voo(lista_voo);
				j++;
			}
			
			
		}else if (op == 2){// Consultar todos os Voos de origem ou destino de determinado aeroporto pelo ID, se tiver cancelado deve mostrar;
			//printf("digite o codifo para ser buscado:\n");
			scanf("%d", &aux);
			getchar();

			printf("op 2 \n");

			busca(lista_voo,qtd_voos, aux);

		}else if (op == 3){// Cancelar Voo pelo ID
			scanf("%d", &aux);
			getchar();
			cancelar(lista_voo, qtd_voos, aux);
			printf("op 3 \n");
        }

    }while(op != 0);

	return 0;
}

void ler_aeroportos(aeroporto lista[], int n){
    aeroporto *p;

    for(p = lista; p < lista + n; p++){
		//printf("Informe o nome do aeroporto:\n");
        scanf("%[^\n]", p->nome);
		getchar();

		//printf("Informe a capacidade do aeroporto:\n");
		scanf("%d", &p->capacidade);
		getchar();

		//printf("Informe o codigo chave do aeroporto:\n");
		scanf("%d", &p->identificador);
		getchar();
    }
}

void cadastrar_voo(voo lista[]){
	voo *p = lista;
	
	//printf("Informe o nome do voo:\n");
	scanf("%[^\n]", p->nome);
	getchar();

	//printf("Informe a origem do voo:\n");
	scanf("%d", &p->origem);
	getchar();

	//printf("Informe o destino do voo:\n");
	scanf("%d", &p->destino);
	getchar();

	//printf("Informe o codigo chave do voo:\n");
	scanf("%d", &p->identificador);
	getchar();
	
}

void busca(voo lista[], int n, int codigo){
	voo *p;

	for(p = lista; p < lista + n; p++){
		if(p->destino == codigo || p->origem == codigo){

			if(p->identificador != -1){
				printf("%s - %d - %d\n", p->nome, p->origem, p->destino);
			}else{
				printf("Cancelado - %s - %d - %d\n", p->nome, p->origem, p->destino);
			}
		}
	}

}

void cancelar(voo lista[], int n, int codigo){
	voo *p;

	for(p = lista; p < lista + n; p++){
		if(p->identificador == codigo){
			p->identificador = -1;
		}
	}
}