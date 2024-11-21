#include <stdio.h>
#include "funciones.h"

int main() {
    char nombresProd[5][50];
    float tiempoProduc[5];
    float costProduc[5];
    float cantDem[5];
    int totalProductos = 0;
    float tiempoDisponible; 
    float presupuestoDisponible;

    printf("Ingrese el tiempo dispone la empresa: ");
    scanf("%f", &tiempoDisponible);

    printf("Ingrese el presupuesto que dispone la empresa: ");
    scanf("%f", &presupuestoDisponible);

    int opcion;
    while (1) {
        printf("\n1. Agregar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Calcular produccion\n");
        printf("5. Mostrar productos\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarProducto(&totalProductos, nombresProd, tiempoProduc, costProduc, cantDem);
                break;
            case 2:
                editarProducto(totalProductos, nombresProd, tiempoProduc, costProduc, cantDem);
                break;
            case 3:
                eliminarProducto(&totalProductos, nombresProd, tiempoProduc, costProduc, cantDem);
                break;
            case 4:
                calcularProduccion(totalProductos, nombresProd, tiempoProduc, costProduc, cantDem, tiempoDisponible, presupuestoDisponible);
                break;
            case 5:
                mostrarProductos(totalProductos, nombresProd, tiempoProduc, costProduc, cantDem);
                break;
            case 6:
                return 0;
            default:
                printf("Opción no valida\n");
        }
    }
}
