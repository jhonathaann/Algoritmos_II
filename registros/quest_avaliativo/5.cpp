#include <stdio.h>

typedef struct{
    int dia, mes, ano;
}DATA;

void leitura(DATA *lista);

int calcula_dias(DATA *data1, DATA *data2);

int main(){
    DATA data1, data2;
    int aux;

    leitura(&data1);
    leitura(&data2);

    aux = calcula_dias(&data1, &data2);

    if(aux == -1){
        printf("Data invalida\n");
    }else{
        printf("%d", aux);
    }

    return 0;
}

void leitura(DATA *lista){

    scanf("%d/%d/%d", &lista->dia, &lista->mes, &lista->ano);
    

}

int calcula_dias(DATA *data1, DATA *data2){
    int dia1, dia2;

    //printf("dia : %d\n", (*data1).dia);
    if((*data1).dia < 0 || (*data1).dia > 31){
    return -1;
   }

    //printf("mes : %d\n", (*data1).mes);
   if((*data1).mes < 0 || (*data1).mes > 12){
    return -1;
   }

    //printf("dia : %d\n", (*data2).dia);
   if((*data2).dia < 0 || (*data2).dia > 31){
    return -1;
   }

    //printf("mes : %d\n", (*data2).mes);
   if((*data2).mes < 0 || (*data2).mes > 12){
    return -1;
   }

    dia1 = (*data1).dia + (*data1).mes * 30 + (*data1).ano * 365;
    dia2 = (*data2).dia + (*data2).mes * 30 + (*data2).ano * 365;

    if(dia1 > dia2){
        return dia1 - dia2;
    }else{
        return dia2 - dia1;
    }

}