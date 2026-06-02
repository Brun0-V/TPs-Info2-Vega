# Trabajo Práctico 1 - Informática 2

Este repositorio contiene un programa en C para gestionar el registro de artículos y sus cantidades por sucursal.

## Archivos principales

- `main.c` - Programa principal que carga artículos, imprime la lista y muestra el ordenado por total.
- `funciones.h` - Definición de tipos y declaraciones de funciones.
- `funciones.c` - Implementación de las funciones de importación, ordenado e impresión.
- `enunciado.md` - Enunciado del trabajo práctico.

## Descripción

El programa permite:
- cargar la descripción de un artículo una sola vez,
- registrar la cantidad por sucursal (1 a 3),
- calcular el total por artículo,
- mostrar una tabla con las cantidades por sucursal y el total,
- ordenar los artículos de mayor a menor según el total.

## Compilación y ejecución

En Linux, compilar con:

```bash
gcc main.c funciones.c -o tp1
```

Ejecutar con:

```bash
./tp1
```

