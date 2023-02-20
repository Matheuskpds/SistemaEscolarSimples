#include "../Headers/notas.h"

void set_calculo(CNotas* pNotas, int nota){
    pNotas->calculo = nota;
}
int get_calculo(CNotas* pNotas){
    return pNotas->calculo;
}

void set_fisica(CNotas* pNotas, int nota){
    pNotas->fisica = nota;
}
int get_fisica(CNotas* pNotas){
    return pNotas->fisica;
}

void set_estatistica(CNotas* pNotas, int nota){
    pNotas->estatistica = nota;
}
int get_estatistica(CNotas* pNotas){
    return pNotas->estatistica;
}