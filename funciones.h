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