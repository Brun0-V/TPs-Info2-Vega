#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define CANT_ARTICULOS 60

#define SUCURSAL_1 0
#define SUCURSAL_2 1
#define SUCURSAL_3 2

typedef struct {
    char descripcion[90];
    int cantidad_sucursal[3];   
    int total;
}articulos_t;

void importar_articulos(articulos_t *articulos);
void ordenar_articulos(articulos_t *articulos);
void imprimir_articulos(articulos_t *articulos);

int main(void)
{
    articulos_t articulos[CANT_ARTICULOS] = {0};
    printf("Bienvendio al final de Info 1\n\n");
    importar_articulos(articulos);

    imprimir_articulos(articulos);
    printf("\n------------------------ORDENADO------------------------\n");
    ordenar_articulos(articulos);
    imprimir_articulos(articulos);

    return 0;
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
            printf("Para que sucursal va a realizar la carga? (1,2,3) ");
            scanf("%d", &sucursal);
            if(sucursal<1 || sucursal>3) printf("Sucursal no valida, ingrese nuevamente\n");
        } while(sucursal<1 || sucursal>3);

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
    char desc_temp[90];
    int temp;
    for(int k = 1; k < CANT_ARTICULOS; k++){
        for(int i = 0; i < CANT_ARTICULOS-1; i++){
            if(articulos[i].total < articulos[i+1].total){
                strcpy(desc_temp, articulos[i].descripcion);
                strcpy(articulos[i].descripcion, articulos[i+1].descripcion);
                strcpy(articulos[i+1].descripcion, desc_temp);

                temp = articulos[i].cantidad_sucursal[SUCURSAL_1];
                articulos[i].cantidad_sucursal[SUCURSAL_1] = articulos[i+1].cantidad_sucursal[SUCURSAL_1];
                articulos[i+1].cantidad_sucursal[SUCURSAL_1] = temp;

                temp = articulos[i].cantidad_sucursal[SUCURSAL_2];
                articulos[i].cantidad_sucursal[SUCURSAL_2] = articulos[i + 1].cantidad_sucursal[SUCURSAL_2];
                articulos[i + 1].cantidad_sucursal[SUCURSAL_2] = temp;

                temp = articulos[i].cantidad_sucursal[SUCURSAL_3];
                articulos[i].cantidad_sucursal[SUCURSAL_3] = articulos[i + 1].cantidad_sucursal[SUCURSAL_3];
                articulos[i + 1].cantidad_sucursal[SUCURSAL_3] = temp;

                temp = articulos[i].total;
                articulos[i].total = articulos[i + 1].total;
                articulos[i + 1].total = temp;
            }
        }
    }
}

void imprimir_articulos(articulos_t *articulos){
    int i=0;
    printf("%-15s %-15s %-15s %-15s %-10s\n",
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