#include <stdio.h>
#define MAX 15

typedef struct{
    char nome[MAX];
    float potencia, tempo_horas;

}tipo_eletrodomestico;

void leitura(tipo_eletrodomestico lista[]);

void preco(tipo_eletrodomestico lista[], int tempo_dias);

//void imprime(tipo_eletrodomestico lista[]);

int main(){
    tipo_eletrodomestico lista[5];
    int tempo_dias;

    leitura(lista);
    scanf("%d", &tempo_dias);

    //imprime(lista);
    preco(lista,tempo_dias);

    return 0;

}

void leitura(tipo_eletrodomestico lista[]){
    tipo_eletrodomestico *p;

    for(p = lista; p < lista + 5;p++){
        scanf("%s", p->nome);
        //getchar();

        scanf("%f", &p->potencia);
        //getchar();

        scanf("%f", &p->tempo_horas);
        //getchar();
    }
}

void preco(tipo_eletrodomestico lista[], int tempo_dias){
    tipo_eletrodomestico *p;
    float consumo_total = 0.0, aux;

    for(p = lista; p < lista + 5; p++){
        consumo_total += (p->potencia) * (p->tempo_horas) * (tempo_dias);
    }

    printf("%.2f\n", consumo_total);
    for(p = lista; p < lista + 5; p++){
        aux = (p->potencia * p->tempo_horas * tempo_dias);
        printf("%.2f\n", (aux/consumo_total)*100);
    }
}


/*void imprime(tipo_eletrodomestico lista[]){
    tipo_eletrodomestico *p;

    for(p = lista; p < lista + 2;p++){
        printf("NOME: %s\n", p->nome);
        printf("POTENCIA: %f\n", p->potencia);
        printf("TEMPO_HORAS: %f\n", p->tempo_horas);
    }
}
*/