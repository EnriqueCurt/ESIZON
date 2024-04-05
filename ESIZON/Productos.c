#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "Productos.h"
//mostrar solo los productos dado el nombre del producto o la categoria del producto
void mostrarProductos(productos *producto, int numproductos)
{
    int opcion;
    do{
        system("cls");
        printf("Como desea buscar los productos?\n");
        printf("1. Por nombre\n");
        printf("2. Por categoria\n");
        printf("3. Salir\n\n");
        printf("Introduzca la opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);
        system("cls");
        switch (opcion)
        {   
        case 1:
            printf("Introduzca el nombre del producto: ");
            char nombre[15];
            gets(nombre);
            for (int i = 0; i < numproductos; i++)
            {
                if (strcmp(producto[i].nombre, nombre) == 0)
                {
                    printf("ID: %s\n", producto[i].id_prod);
                    printf("Nombre: %s\n", producto[i].nombre);
                    printf("Descripcion: %s\n", producto[i].descrip);
                    printf("ID de la categoria: %s\n", producto[i].id_categ);
                    printf("ID del gestor: %s\n", producto[i].id_gestor);
                    printf("Stock: %d\n", producto[i].stock);
                    printf("Entrega: %d\n", producto[i].entrega);
                    printf("Importe: %d\n\n\n", producto[i].importe);
                    system("pause");
                }
            }
            break;
        case 2:
            printf("Introduzca el ID de la categoria: ");
            char id_categ[5];
            gets(id_categ);
            for (int i = 0; i < numproductos; i++)
            {
                if (strcmp(producto[i].id_categ, id_categ) == 0)
                {
                    printf("ID: %s\n", producto[i].id_prod);
                    printf("Nombre: %s\n", producto[i].nombre);
                    printf("Descripcion: %s\n", producto[i].descrip);
                    printf("ID de la categoria: %s\n", producto[i].id_categ);
                    printf("ID del gestor: %s\n", producto[i].id_gestor);
                    printf("Stock: %d\n", producto[i].stock);
                    printf("Entrega: %d\n", producto[i].entrega);
                    printf("Importe: %d\n\n\n", producto[i].importe);
                    system("pause");
                }
            }
            break;
        case 3:
            break;
        default:
            system("cls");
            printf("Opcion no valida\n");
            system("pause");
            break;
        }
    } while (opcion != 3);
}   