#include <stdio.h>
#include <string.h>
#include "funciones.h"


void agregarProducto(int *cantidadProductos, char productos[5][50], float tiemposFabricacion[5], float costoProducción[5], float cantidadesDemandadas[5]) {
    if (*cantidadProductos < 5) {
        printf("Nombre del producto: ");
        getchar();
        fgets(productos[*cantidadProductos], 50, stdin);
        do {
            printf("Tiempo de fabricacion del producto en horas (debe ser positivo): ");
            scanf("%f", &tiemposFabricacion[*cantidadProductos]);
            if (tiemposFabricacion[*cantidadProductos] < 0) {
                printf("Error: No se permiten valores negativos.\n");
            }
        } while (tiemposFabricacion[*cantidadProductos] < 0);

        do {
            printf("Costo de produccion del producto (debe ser positivo): ");
            scanf("%f", &costoProducción[*cantidadProductos]);
            if (costoProducción[*cantidadProductos] < 0) {
                printf("Error: No se permiten valores negativos.\n");
            }
        } while (costoProducción[*cantidadProductos] < 0);

        do {
            printf("Cantidad demandada del producto (debe ser positiva): ");
            scanf("%f", &cantidadesDemandadas[*cantidadProductos]);
            if (cantidadesDemandadas[*cantidadProductos] < 0) {
                printf("Error: No se permiten valores negativos.\n");
            }
        } while (cantidadesDemandadas[*cantidadProductos] < 0);

        (*cantidadProductos)++;
    } else {
        printf("No se pueden agregar más productos.\n");
    }
}



void editarProducto(int cantidadProductos, char productos[5][50], float tiemposFabricacion[5], float costoProducción[5], float cantidadesDemandadas[5]) {
    char nombre[50];
    printf("\nNombre del producto que quiere editar: ");
    getchar();
    fgets(nombre, 50, stdin);

    for (int i = 0; i < cantidadProductos; i++) {
        if (strcmp(productos[i], nombre) == 0) {
            do {
                printf("Nuevo tiempo de fabricacion del producto en horas (positivo): ");
                scanf("%f", &tiemposFabricacion[i]);
                if (tiemposFabricacion[i] < 0) {
                    printf("El tiempo de fabricación no puede ser negativo.\n");
                }
            } while (tiemposFabricacion[i] < 0);

            do {
                printf("Nuevo costo de produccion del producto (positivo): ");
                scanf("%f", &costoProducción[i]);
                if (costoProducción[i] < 0) {
                    printf("El costo de producción no puede ser negativo.\n");
                }
            } while (costoProducción[i] < 0);

            do {
                printf("Nueva cantidad demandada del producto (positivo): ");
                scanf("%f", &cantidadesDemandadas[i]);
                if (cantidadesDemandadas[i] < 0) {
                    printf("La cantidad demandada no puede ser negativa.\n");
                }
            } while (cantidadesDemandadas[i] < 0);

            getchar(); 
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void eliminarProducto(int *cantidadProductos, char productos[5][50], float tiemposFabricacion[5], float costoProducción[5], float cantidadesDemandadas[5]) {
    char nombre[50];
    printf("\nNombre del producto a eliminar: ");
    getchar();
    fgets(nombre, 50, stdin);

    for (int i = 0; i < *cantidadProductos; i++) {
        if (strcmp(productos[i], nombre) == 0) {
            for (int j = i; j < *cantidadProductos - 1; j++) {
                strcpy(productos[j], productos[j + 1]);
                tiemposFabricacion[j] = tiemposFabricacion[j + 1];
                costoProducción[j] = costoProducción[j + 1];
                cantidadesDemandadas[j] = cantidadesDemandadas[j + 1];
            }
            (*cantidadProductos)--;
            printf("Producto eliminado correctamente.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
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
