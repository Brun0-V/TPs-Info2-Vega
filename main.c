#include "funciones.h"
#include <stdio.h>

int main(void)
{
    articulos_t articulos[CANT_ARTICULOS] = {0};
    printf("Bienvenido al Trabajo Practico N°1 de Info 2\n\n");
    importar_articulos(articulos);
    imprimir_articulos(articulos);
    printf("\n------------------------ORDENADO------------------------\n");
    ordenar_articulos(articulos);
    imprimir_articulos(articulos);

    return 0;
}