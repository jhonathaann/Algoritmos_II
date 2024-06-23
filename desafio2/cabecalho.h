// definindo apenas as assinaturas do métodos

#ifndef CABECALHO_H
#define CABECALHO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// definindo as assinaturas do métodos de ordenação
void insertion_sort(int *lista, int n);
void selection_sort(int *lista, int n);
void merge_sort(int *lista, int comeco, int fim);
void quick_sort(int comeco, int fim, int *lista);

// definindo as assinaturas dos métodos auxiliares do merge e do quick
void intercala(int *lista, int inicio, int meio, int fim);
int separa(int comeco, int fim, int *lista);

#endif

