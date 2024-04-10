#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "Productos.h"
//mostrar solo los productos dado el nombre del producto o la categoria del producto
void Cliente_mostrarProductos(productos *producto, int numproductos)
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

//Gestionar todos los productos desde dar de alta, modificar, eliminar, mostar y buscar
void Admin_GestionarProductos(productos *producto, int *numproductos)
{
    int opcion;
    do{
        system("cls");
        printf("Que desea hacer con los productos?\n");
        printf("1. Dar de alta un producto\n");
        printf("2. Modificar un producto\n");
        printf("3. Eliminar un producto\n");
        printf("4. Mostrar todos los productos\n");
        printf("5. Buscar un producto\n");
        printf("6. Salir\n\n");
        printf("Introduzca la opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);
        system("cls");
        switch (opcion)
        {
        case 1:
            printf("Introduzca el ID del producto: ");
            gets(producto[*numproductos].id_prod);
            printf("Introduzca el nombre del producto: ");
            gets(producto[*numproductos].nombre);
            printf("Introduzca la descripcion del producto: ");
            gets(producto[*numproductos].descrip);
            printf("Introduzca el ID de la categoria del producto: ");
            gets(producto[*numproductos].id_categ);
            printf("Introduzca el ID del gestor del producto: ");
            gets(producto[*numproductos].id_gestor);
            printf("Introduzca el stock del producto: ");
            scanf("%d", &producto[*numproductos].stock);
            fflush(stdin);
            printf("Introduzca la entrega del producto: ");
            scanf("%d", &producto[*numproductos].entrega);
            fflush(stdin);
            printf("Introduzca el importe del producto: ");
            scanf("%d", &producto[*numproductos].importe);
            fflush(stdin);
            (*numproductos)++;
            break;
        case 2:
            printf("Introduzca el ID del producto a modificar: ");
            char id_prod[5];
            gets(id_prod);
            for (int i = 0; i < *numproductos; i++)
            {
                if (strcmp(producto[i].id_prod, id_prod) == 0)
                {
                    printf("Introduzca el nuevo ID del producto: ");
                    gets(producto[i].id_prod);
                    printf("Introduzca el nuevo nombre del producto: ");
                    gets(producto[i].nombre);
                    printf("Introduzca la nueva descripcion del producto: ");
                    gets(producto[i].descrip);
                    printf("Introduzca el nuevo ID de la categoria del producto: ");
                    gets(producto[i].id_categ);
                    printf("Introduzca el nuevo ID del gestor del producto: ");
                    gets(producto[i].id_gestor);
                    printf("Introduzca el nuevo stock del producto: ");
                    scanf("%d", &producto[i].stock);
                    fflush(stdin);
                    printf("Introduzca la nueva entrega del producto: ");
                    scanf("%d", &producto[i].entrega);
                    fflush(stdin);
                    printf("Introduzca el nuevo importe del producto: ");
                    scanf("%d", &producto[i].importe);
                    fflush(stdin);
                }
            }
            break;
        case 3:
            printf("Introduzca el ID del producto a eliminar: ");
            char id_prod2[5];
            gets(id_prod2);
            for (int i = 0; i < *numproductos; i++)
            {
                if (strcmp(producto[i].id_prod, id_prod2) == 0)
                {
                    for (int j = i; j < *numproductos; j++)
                    {
                        producto[j] = producto[j + 1];
                    }
                    (*numproductos)--;
                }
            }
            break;
        case 4:
            for (int i = 0; i < *numproductos; i++)
            {
                printf("ID: %s\n", producto[i].id_prod);
                printf("Nombre: %s\n", producto[i].nombre);
                printf("Descripcion: %s\n", producto[i].descrip);
                printf("ID de la categoria: %s\n", producto[i].id_categ);
                printf("ID del gestor: %s\n", producto[i].id_gestor);
                printf("Stock: %d\n", producto[i].stock);
                printf("Entrega: %d\n", producto[i].entrega);
                printf("Importe: %d\n\n\n", producto[i].importe);
            }
            system("pause");
            break;
        case 5:
            printf("Introduzca el ID del producto a buscar: ");
            char id_prod3[8];
            gets(id_prod3);
            for (int i = 0; i < *numproductos; i++)
            {
                if (strcmp(producto[i].id_prod, id_prod3) == 0)
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
        case 6:
            break;
        default:
            system("cls");
            printf("Opcion no valida\n");
            system("pause");
            break;
        }
    } while (opcion != 6);
}

//funcion para que el proveedor pueda gestionar los productos

void Proveedor_GestionarProductos(productos *producto, int *numproductos, admin_prov *admin, int id)
{
    int opcion;
    do{
        system("cls");
        printf("Que desea hacer con los productos?\n");
        printf("1. Dar de alta un producto\n");
        printf("2. Modificar un producto\n");
        printf("3. Eliminar un producto\n");
        printf("4. Mostrar todos los productos\n");
        printf("5. Buscar un producto\n");
        printf("6. Salir\n\n");
        printf("Introduzca la opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);
        system("cls");
        switch (opcion)
        {
        case 1:
            printf("Introduzca el ID del producto: ");
            gets(producto[*numproductos].id_prod);
            printf("Introduzca el nombre del producto: ");
            gets(producto[*numproductos].nombre);
            printf("Introduzca la descripcion del producto: ");
            gets(producto[*numproductos].descrip);
            printf("Introduzca el ID de la categoria del producto: ");
            gets(producto[*numproductos].id_categ);
            strcpy(producto[*numproductos].id_gestor, admin[id].id_empresa);
            printf("Introduzca el stock del producto: ");
            scanf("%d", &producto[*numproductos].stock);
            fflush(stdin);
            printf("Introduzca la entrega del producto: ");
            scanf("%d", &producto[*numproductos].entrega);
            fflush(stdin);
            printf("Introduzca el importe del producto: ");
            scanf("%d", &producto[*numproductos].importe);
            fflush(stdin);
            (*numproductos)++;
            break;
        case 2:
            printf("Introduzca el ID del producto a modificar: ");
            char id_prod[5];
            gets(id_prod);
            for (int i = 0; i < *numproductos; i++)
            {
                if (strcmp(producto[i].id_prod, id_prod) == 0 && strcmp(producto[i].id_gestor, admin[id].id_empresa) == 0)
                {
                    printf("Introduzca el nuevo ID del producto: ");
                    gets(producto[i].id_prod);
                    printf("Introduzca el nuevo nombre del producto: ");
                    gets(producto[i].nombre);
                    printf("Introducta la nueva descripcion del producto: ");   
                    gets(producto[i].descrip);
                    printf("Introduzca el nuevo ID de la categoria del producto: ");
                    gets(producto[i].id_categ);
                    printf("Introduzca el nuevo ID del gestor del producto: ");
                    gets(producto[i].id_gestor);
                    printf("Introduzca el nuevo stock del producto: ");
                    scanf("%d", &producto[i].stock);
                    fflush(stdin);
                    printf("Introduzca la nueva entrega del producto: ");
                    scanf("%d", &producto[i].entrega);
                    fflush(stdin);
                    printf("Introduzca el nuevo importe del producto: ");
                    scanf("%d", &producto[i].importe);
                    fflush(stdin);
                }
            }
            break;
        case 3:
            printf("Introduzca el ID del producto a eliminar: ");
            char id_prod2[5];
            gets(id_prod2);
            for (int i = 0; i < *numproductos; i++)
            {
                if (strcmp(producto[i].id_prod, id_prod2) == 0 && strcmp(producto[i].id_gestor, admin[id].id_empresa) == 0)
                {
                    for (int j = i; j < *numproductos; j++)
                    {
                        producto[j] = producto[j + 1];
                    }
                    (*numproductos)--;
                }
            }
            break;
        case 4:
            for (int i = 0; (i < *numproductos); i++)
            {
                if(strcmp(producto[i].id_gestor, admin[id].id_empresa) == 0)
                {
                    printf("ID: %s\n", producto[i].id_prod);
                    printf("Nombre: %s\n", producto[i].nombre);
                    printf("Descripcion: %s\n", producto[i].descrip);
                    printf("ID de la categoria: %s\n", producto[i].id_categ);
                    printf("ID del gestor: %s\n", producto[i].id_gestor);
                    printf("Stock: %d\n", producto[i].stock);
                    printf("Entrega: %d\n", producto[i].entrega);
                    printf("Importe: %d\n\n\n", producto[i].importe);
                }
            }
            system("pause");
            break;
        case 5:
            printf("Introduzca el ID del producto a buscar: ");
            char id_prod3[8];
            gets(id_prod3);
            for (int i = 0; i < *numproductos; i++)
            {
                if (strcmp(producto[i].id_prod, id_prod3) == 0 && strcmp(producto[i].id_gestor, admin[id].id_empresa) == 0)
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
        case 6:
            break;
        default:
            system("cls");
            printf("Opcion no valida\n");
            system("pause");
            break;
        }
    } while (opcion != 6);
}
