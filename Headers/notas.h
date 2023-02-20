#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMNOMES 15
#define TAMPASSWORD 5
#define MAXALUNOS 30

typedef struct{
    int calculo;
    int fisica;
    int estatistica;
}CNotas;

void set_calculo(CNotas* pNotas, int nota);
int get_calculo(CNotas* pNotas);

void set_fisica(CNotas* pNotas, int nota);
int get_fisica(CNotas* pNotas);

void set_estatistica(CNotas* pNotas, int nota);
int get_estatistica(CNotas* pNotas);