#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Registro das Marcas
typedef struct mar{
    int codigo;
    float nota;
    struct mar *prox;
    struct mar *ant;
}Marcas;

// registro dos Carros
typedef struct car{
    int ano, codigomarca;
    char modelo [40];
    struct car *prox;
}Carros;


void inserirMarca(Marcas **marca, int codigo, float nota);

void imprime(Marcas *marca);

float buscaMarca(Marcas *marca, int codigo);

void inserirCarro(Carros **carro, char *modelo, int ano, int codigo);

void listagem(Marcas *marca, Carros *carro);

int marcaTemcarro(Carros *carro, int codigo);

void removerMarca(Marcas **marca, Carros *carro, int codigo);