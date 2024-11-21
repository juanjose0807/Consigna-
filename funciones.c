#include <stdio.h>
#include <string.h>
#include "funciones.h"

void agregarProducto(int *cantidadProductos, char productos[5][50], float tiemposFabricacion[5], float costoProducción[5], float cantidadesDemandadas[5]) {
    if (*cantidadProductos < 5) {
        printf("Nombre del producto: ");
        scanf("%s", productos[*cantidadProductos]);
        printf("Tiempo de fabricacion del producto en horas: ");
        scanf("%f", &tiemposFabricacion[*cantidadProductos]);
        printf("Costo de produccion del producto: ");
        scanf("%f", &costoProducción[*cantidadProductos]);
        printf("Cantidad demandada del producto: ");
        scanf("%f", &cantidadesDemandadas[*cantidadProductos]);
        (*cantidadProductos)++;
    } else {
        printf("No se pueden agregar más productos.\n");
    }
}

void editarProducto(int cantidadProductos, char productos[5][50], float tiemposFabricacion[5], float costoProducción[5], float cantidadesDemandadas[5]) {
    char nombre[50];
    printf("\nNombre del producto que quiere editar: ");
    scanf("%s", nombre);

    for (int i = 0; i < cantidadProductos; i++) {
        if (strcmp(productos[i], nombre) == 0) {
            printf("Nuevo tiempo de fabricacion del producto en horas: ");
            scanf("%f", &tiemposFabricacion[i]);
            printf("Nuevo costo de produccion del producto: ");
            scanf("%f", &costoProducción[i]);
            printf("Nueva cantidad demandada del producto: ");
            scanf("%f", &cantidadesDemandadas[i]);
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void eliminarProducto(int *cantidadProductos, char productos[5][50], float tiemposFabricacion[5], float costoProducción[5], float cantidadesDemandadas[5]) {
    char nombre[50];
    printf("\nNombre del producto a eliminar: ");
    scanf("%s", nombre);

    for (int i = 0; i < *cantidadProductos; i++) {
        if (strcmp(productos[i], nombre) == 0) {
            for (int j = i; j < *cantidadProductos - 1; j++) {
                strcpy(productos[j], productos[j + 1]);
                tiemposFabricacion[j] = tiemposFabricacion[j + 1];
                costoProducción[j] = costoProducción[j + 1];
                cantidadesDemandadas[j] = cantidadesDemandadas[j + 1];
            }
            (*cantidadProductos)--;
            return;
        }
    }
    printf("Producto no encontrado\n");
}

void calcularProduccion(int cantidadProductos, char productos[5][50], float tiemposFabricacion[5], float costoProducción[5], float cantidadesDemandadas[5], float tiempoDisponible, float presupuestoDisponible) {
    float tiempoTotal = 0, recursosTotales = 0;
    for (int i = 0; i < cantidadProductos; i++) {
        tiempoTotal += tiemposFabricacion[i] * cantidadesDemandadas[i];
        recursosTotales += costoProducción[i] * cantidadesDemandadas[i];
    }

    printf("\nTiempo total de fabricacion: %.2f horas\n", tiempoTotal);
    printf("Presupuesto necesario: %.2f\n", recursosTotales);

    if (tiempoTotal > tiempoDisponible) {
        printf("No hay suficiente tiempo para cumplir con la demanda.\n");
    } else {
        printf("Tenemos el tiempo necesario para cumplir con la demanda.\n");
    }

    if (recursosTotales > presupuestoDisponible) {
        printf("No tenemos el presupuesto necesario para cumplir con la demanda.\n");
    } else {
        printf("Tenemos el presupuesto necesario para cumplir con la demanda.\n");
    }
}

void mostrarProductos(int cantidadProductos, char productos[5][50], float tiemposFabricacion[5], float costoProducción[5], float cantidadesDemandadas[5]) {
    if (cantidadProductos == 0) {
        printf("\nNo hay productos registrados.\n");
        return;
    }

    printf("\nLista de productos:\n");
    for (int i = 0; i < cantidadProductos; i++) {
        printf("Producto %d:\n", i + 1);
        printf("  Nombre: %s\n", productos[i]);
        printf("  Tiempo de fabricacion: %.2f horas\n", tiemposFabricacion[i]);
        printf("  Costo de produccion: %.2f\n", costoProducción[i]);
        printf("  Cantidad demandada: %.2f\n", cantidadesDemandadas[i]);
    }
}
