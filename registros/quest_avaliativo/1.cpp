#include <stdio.h>
#define MAX 60

typedef struct{
    int dia, mes, ano;
}DATA;

typedef struct{
    char compromisso[MAX];
    DATA data;
}Agenda;

void cadastrar(Agenda lista[]);

void busca(Agenda lista[], int mes, int ano);

int main(){
    Agenda lista[5];
    int mes, ano;

    
    cadastrar(lista);
    scanf("%d/%d", &mes, &ano);

    while(mes != 0){

        busca(lista, mes, ano);
        scanf("%d/%d", &mes, &ano);

    }

    return 0;
}


void cadastrar(Agenda lista[]){
    Agenda *p;

    for(p = lista; p < lista + 5; p++){
        scanf("%[^\n]", p->compromisso);
        getchar();

        scanf("%d/%d/%d", &p->data.dia, &p->data.mes, &p->data.ano);
        getchar();
    }
}

void busca(Agenda lista[], int mes, int ano){
    Agenda *p;

    for(p = lista; p < lista + 5; p++){
        if(p->data.mes == mes && p->data.ano == ano){
            printf("%s\n", p->compromisso);
        }
    }
}
