#include <stdio.h>

void maior_menor(float *maior, float *menor, float *media, FILE *arq_entrada);

void dias(int *dia_superior, int *dias_inferior, float media, FILE *arq_entrada);

int main(){
    float maior = 14.0;
    float menor = 40.0;
    float media;
    char nome_arquivo[20];
    int dias_superior = 0, dias_inferior = 0;
    FILE *pt_arq;

    printf("Informe o nome do arquivo:\n");
    scanf("%[^\n]", nome_arquivo);

    pt_arq = fopen(nome_arquivo, "r");
    if(pt_arq == NULL){
        printf("Nao foi possivel abrir o arquivo!\n");
        return 1;
    }

    maior_menor(&maior, &menor, &media, pt_arq);

    printf("Maior temperatura: %.2f\n", maior);
    printf("Menor temperatura: %.2f\n", menor);
    printf("Media das temperaturas: %.2f\n", media);
    
    //fclose(pt_arq);
    pt_arq = fopen(nome_arquivo, "r");
    dias(&dias_superior, &dias_inferior, media, pt_arq);

    printf("Numero de dias em que a temperatura foi superior a media: %d\n", dias_superior);
    printf("Numero de dias em que a temperatura foi inferior a media: %d\n", dias_inferior);

    fclose(pt_arq);

    return 0;
}

void maior_menor(float *maior, float *menor, float *media, FILE *arq_entrada){
    float soma = 0.0;
    float aux;
    int quant = 0;

    while(feof(arq_entrada) == 0){
        fscanf(arq_entrada, "%f", &aux);
        soma += aux;

        if(aux > *maior){
            *maior = aux;
        }

        if(aux < *menor){
            *menor = aux;
        }
        quant++;
        
    }

    fclose(arq_entrada);
    

    *media = soma / quant;
}

void dias(int *dia_superior, int *dias_inferior, float media, FILE *arq_entrada){
    float aux;

    while(feof(arq_entrada) == 0){

        fscanf(arq_entrada, "%f", &aux);

        if(aux > media){
            *dia_superior += 1;
        }

        if(aux < media){
            *dias_inferior += 1;
        }

        
    }

    fclose(arq_entrada);
}

