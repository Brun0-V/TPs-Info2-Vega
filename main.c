#include <stdio.h>
#include <string.h>

#define CANT_ARTICULOS 60

enum sucursales{
    SUCURSAL_1, SUCURSAL_2, SUCURSAL_3, CANT_SUCURSALES
};  // Usando enum para definir cada uno de los valores de 0 en adelante, siendo CANT_SUCURSALES = 3, la cantidad de sucursales

/* 
 * Aunque el enum puede mejorar la escalabilidad del codigo, con la implementacion actual
 * si se cambia la cantidad de sucursales el codigo no se adapta completamente a la nueva escala
 * Para que esto funcione se deberian hacer cambios en la funcion de impresion y recopilacion de datos
 * de forma que puedan aceptar un valor "n" de sucursales. Se intento implementarlo pero la legibilidad
 * del codigo se vio ampliamente afectada y sumaba una complejidad innecesaria
*/


typedef struct {
    char descripcion[90];
    int cantidad_sucursal[CANT_SUCURSALES];   
    int total;
}articulos_t;

void importar_articulos(articulos_t *articulos);
void ordenar_articulos(articulos_t *articulos);
void imprimir_articulos(articulos_t *articulos);
void swap(articulos_t *a, articulos_t *b);

int main(void)
{
    articulos_t articulos[CANT_ARTICULOS] = {0};
    printf("Bienvendio al Trabajo Practico N°1 de Info 2\n\n");
    importar_articulos(articulos);

    imprimir_articulos(articulos);
    printf("\n------------------------ORDENADO------------------------\n");
    ordenar_articulos(articulos);
    imprimir_articulos(articulos);

    return 0;
}

void swap(articulos_t *a, articulos_t *b){
    articulos_t temp;
    temp = *a;
    *a = *b;
    *b = temp;
    
    // Swap de la estructura completa usando punteros para editar los valores originales
}

void importar_articulos(articulos_t *articulos){
    char articulo[90];
    int i, index, opc, sucursal, temp;
    do{
        printf("Ingrese la descripcion del articulo: ");
        scanf("%s", articulo);

        i=0;
        while (articulos[i].descripcion[0] && strcmp(articulo, articulos[i].descripcion)) i++;
        index = i;
        strcpy(articulos[i].descripcion, articulo);

        do{
            printf("Para que sucursal va a realizar la carga? (1,2,3): ");
            scanf("%d", &sucursal);
            if (sucursal < 1 || sucursal > CANT_SUCURSALES) printf("Sucursal no valida, ingrese nuevamente\n");
        } while(sucursal < 1 || sucursal > CANT_SUCURSALES);

        do{
            printf("Ingrese la cantidad del articulo para la sucursal %d: ", sucursal);
            scanf("%d", &temp);
            if(temp<0) printf("Cantidad no valida, ingrese nuevamente\n");
        } while(temp<0);
        articulos[index].cantidad_sucursal[sucursal-1] = temp; 
        
        articulos[index].total = 0;
        for(i = 0; i < 3; i++) articulos[index].total += articulos[index].cantidad_sucursal[i];
        printf("Desea ingresar otro articulo? 1-Si, 2-No ");
        scanf("%d",&opc);
    } while (opc == 1);
    
}

void ordenar_articulos(articulos_t *articulos){
    for(int k = 1; k < CANT_ARTICULOS; k++){
        for(int i = 0; i < CANT_ARTICULOS-1; i++){
            if(articulos[i].total < articulos[i+1].total) swap(&articulos[i], &articulos[i+1]);
        }
    }
}

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
}
