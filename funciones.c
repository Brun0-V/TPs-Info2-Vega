#include <stdio.h>
#include <string.h>
#include "funciones.h"

void importar_articulos(articulos_t *articulos){
    char articulo[90];
    int i, index, opc, sucursal, temp;
    do{
        printf("Ingrese la descripcion del articulo: ");
        scanf("%s", articulo);

        i=0;
        while (articulos[i].descripcion[0] && strcmp(articulo, articulos[i].descripcion)) i++;
        
        if (i >= CANT_ARTICULOS) {
            printf("No se puede agregar articulos nuevos, límite alcanzado (%d)\n", CANT_ARTICULOS);
            printf("Desea ingresar otro articulo? 1-Si, 2-No: ");
            scanf("%d",&opc);
            continue;
        }   // Check de limite de articulos
        
        index = i;
        strcpy(articulos[i].descripcion, articulo);

        do{
            printf("Para que sucursal va a realizar la carga? (1,2,3): ");
            scanf("%d", &sucursal);
            if (sucursal < 1 || sucursal > CANT_SUCURSALES) printf("Sucursal no valida, ingrese nuevamente\n");
        } while(sucursal < 1 || sucursal > CANT_SUCURSALES); // Check de sucursal

        do{
            printf("Ingrese la cantidad del articulo para la sucursal %d: ", sucursal);
            scanf("%d", &temp);
            if(temp<0) printf("Cantidad no valida, ingrese nuevamente\n");
        } while(temp<0); // Check mayor a 0
        articulos[index].cantidad_sucursal[sucursal-1] = temp; 
        
        articulos[index].total = 0;
        for(i = 0; i < 3; i++) articulos[index].total += articulos[index].cantidad_sucursal[i]; // Suma del total

        printf("Desea ingresar otro articulo? 1-Si, 2-No: ");
        scanf("%d",&opc);
    } while (opc == 1);
    
}

void ordenar_articulos(articulos_t *articulos){
    for(int k = 1; k < CANT_ARTICULOS; k++){
        for(int i = 0; i < CANT_ARTICULOS-1; i++){
            if(articulos[i].total < articulos[i+1].total) swap(&articulos[i], &articulos[i+1]);
        }
    }
}   // Bubble sort de mayor a menor usando la funcion swap para intercambiar los valores de las estructuras completas

void swap(articulos_t *a, articulos_t *b){
    articulos_t temp;
    temp = *a;
    *a = *b;
    *b = temp;
}   // Swap de la estructura completa usando punteros para editar los valores originales

void imprimir_articulos(articulos_t *articulos){
    int i=0;
    printf("\n%-15s %-15s %-15s %-15s %-10s\n",
           "Articulo",
           "Sucursal 1",
           "Sucursal 2",
           "Sucursal 3",
           "Total");

    while(i< CANT_ARTICULOS && articulos[i].descripcion[0]){
        printf("%-15s %-15d %-15d %-15d %-10d\n",
               articulos[i].descripcion,
               articulos[i].cantidad_sucursal[SUCURSAL_1],
               articulos[i].cantidad_sucursal[SUCURSAL_2],
               articulos[i].cantidad_sucursal[SUCURSAL_3],
               articulos[i].total);
        i++;
    }
}   // Imprime los articulos con su cantidad por sucursal y total en formato de tabla

