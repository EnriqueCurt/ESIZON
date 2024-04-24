#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "RepartoyRetorno.h"

/*Repartos
Esta opción permitirá al transportista consultar la lista de productos que tiene asignados para
su entrega así como la fecha prevista para la misma, lo que le permite realizar su ruta de
reparto.
• Cuando el transportista realice la entrega de productos a domicilio, automáticamente
deben ser modificados sus estados y el stock de los mismos.
• Si la entrega es a domicilio y no se hubiese podido llevar a cabo, el estado de los productos
debe actualizarse.
• Si la entrega se realiza en un locker, el transportista tendrá que asignar un código locker a
los productos, asociando un compartimento locker con los productos. Automáticamente se
debe actualizar el número de compartimentos ocupados en los compatimentos lockers.
*/

void TransportistaReparto(transportistas *transportista, int numtransportistas, productos_pedidos *productos_pedidos, int numproductos_pedido, productos *productos, int numproductos, pedidos *pedidos, int numpedidos, lockers *lockers, int numlockers, compartimentos_lockers *compartimentoslockers, int numcompartimentoslockers,devoluciones *devoluciones, int numdevoluciones, int transportistaid)
{
    int opcion;
    do
    {   
        system("cls");
        printf("\n");
        printf("1. Consultar lista de productos asignados para su entrega\n");
        printf("2. Realizar entrega de producto a domicilio\n");
        printf("3. Modificar pedido que no ha podido entregarse\n");
        printf("4. Realizar entrega en locker\n");
        printf("5. Salir\n");
        printf("Introduce una opción: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            listarEntregasAsignadas(pedidos, numpedidos, productos_pedidos, numproductos_pedido, productos, numproductos, transportista, numtransportistas, transportistaid);
            system("pause");
            break;
        case 2:
            realizarEntregaDomicilio(productos_pedidos, numproductos_pedido, productos, numproductos, pedidos, numpedidos, devoluciones, numdevoluciones);
            system("pause");
            break;
        case 3:
            entregaNoPosible(productos_pedidos, numproductos_pedido, productos, numproductos, pedidos, numpedidos, devoluciones, numdevoluciones);
            system("pause");
            break;
        case 4:
            realizarEntregaLocker(productos_pedidos, numproductos_pedido, productos, numproductos, pedidos, numpedidos, lockers, numlockers, compartimentoslockers, numcompartimentoslockers);
            system("pause");
            break;

        case 5:
            printf("Saliendo de la opción de reparto\n");
            system("pause");
            system("cls");
            break;
        default:
            printf("Opción no válida\n");
            system("pause");
            system("cls");
            break;
        }
    } while (opcion != 5);
}

void listarEntregasAsignadas(pedidos *pedidos, int numpedidos, productos_pedidos *productos_pedidos, int numproductos_pedido, productos *productos, int numproductos, transportistas *transportistas, int numtransportistas, int transportistaid)
{
    int i;
    char id_transp_char[5];
    sprintf(id_transp_char, "%04d", transportistaid);
    for (i = 0; i < numproductos_pedido; i++)
    {
        if (strcmp(productos_pedidos[i].id_transp, id_transp_char) == 0)
        {
            printf("ID Pedido: %s\n", productos_pedidos[i].id_pedido);
            printf("ID Producto: %s\n", productos_pedidos[i].id_prod);
            printf("Número de unidades: %d\n", productos_pedidos[i].num_unid);
            printf("Fecha de entrega: %s\n", productos_pedidos[i].fecha_entrega);
            printf("Importe: %d\n", productos_pedidos[i].importe);
            printf("Estado: %s\n", productos_pedidos[i].estado);
            printf("ID Transportista: %s\n", productos_pedidos[i].id_transp);
        }
    }
}

void realizarEntregaDomicilio(productos_pedidos *productos_pedidos, int numproductos_pedido, productos *productos, int numproductos, pedidos *pedidos, int numpedidos, devoluciones *devoluciones, int numdevoluciones)
{
    int i;
    char id_pedido[8];
    char id_producto[8];
    printf("Introduce el ID del pedido: ");
    scanf("%s", id_pedido);
    printf("Introduce el ID del producto: ");
    scanf("%s", id_producto);
    for (i = 0; i < numproductos_pedido; i++)
    {
        if (strcmp(productos_pedidos[i].id_pedido, id_pedido) == 0 && strcmp(productos_pedidos[i].id_prod, id_producto) == 0)
        {
            printf("Introduce la fecha de entrega: ");
            scanf("%s", productos_pedidos[i].fecha_entrega_devolucion);
            strcpy(productos_pedidos[i].estado, "entregado");
            printf("Producto entregado\n");
        }
    }
}

void entregaNoPosible(productos_pedidos *productos_pedidos, int numproductos_pedido, productos *productos, int numproductos, pedidos *pedidos, int numpedidos, devoluciones *devoluciones, int numdevoluciones)
{
    int i;
    char id_pedido[8];
    char id_producto[8];
    printf("Introduce el ID del pedido: ");
    scanf("%s", id_pedido);
    printf("Introduce el ID del producto: ");
    scanf("%s", id_producto);
    for (i = 0; i < numproductos_pedido; i++)
    {
        if (strcmp(productos_pedidos[i].id_pedido, id_pedido) == 0 && strcmp(productos_pedidos[i].id_prod, id_producto) == 0)
        {
            strcpy(productos_pedidos[i].estado, "devuelto");
            printf("Producto no entregado\n");
            //actualizar stock
            int j;
            for (j = 0; j < numproductos; j++)
            {
                if (strcmp(productos[j].id_prod, id_producto) == 0)
                {
                    productos[j].stock = productos[j].stock + productos_pedidos[i].num_unid;
                }
            }
        }
    }
}

void realizarEntregaLocker(productos_pedidos *productos_pedidos, int numproductos_pedido, productos *productos, int numproductos, pedidos *pedidos, int numpedidos, lockers *lockers, int numlockers, compartimentos_lockers *compartimentoslockers, int numcompartimentoslockers)
{
    int i;
    char id_pedido[8];
    char id_producto[8];
    char id_locker[11];
    char cod_locker[11];
    printf("Introduce el ID del pedido: ");
    scanf("%s", id_pedido);
    printf("Introduce el ID del producto: ");
    scanf("%s", id_producto);
    printf("Introduce el ID del locker: ");
    scanf("%s", id_locker);
    printf("Introduce el código del locker: ");
    scanf("%s", cod_locker);
    for (i = 0; i < numproductos_pedido; i++)
    {
        if (strcmp(productos_pedidos[i].id_pedido, id_pedido) == 0 && strcmp(productos_pedidos[i].id_prod, id_producto) == 0)
        {
            strcpy(productos_pedidos[i].id_locker, id_locker);
            strcpy(productos_pedidos[i].cod_locker, cod_locker);
            strcpy(productos_pedidos[i].estado, "entregado");
            printf("Producto entregado en locker\n");
            //actualizar compartimentos ocupados
            int k;
            for (k = 0; k < numcompartimentoslockers; k++)
            {
                if (strcmp(compartimentoslockers[k].id_locker, id_locker) == 0)
                {
                    compartimentoslockers[k].num_comp = compartimentoslockers[k].num_comp + 1;
                }
            }
        }
    }
}

/*
el sistema facilitará al transportista la tarea de retornar a origen todos los productos que no
hayan sido recogidos de los lockers en el plazo determinado, permitiéndole consultar todos los
lockers por localidad y mostrando sus pedidos. En el momento de la recogida de los productos
para su retorno, el sistema debe actualizar automáticamente el número de compartimentos
ocupados y eliminar el código locker asociado al producto. Así como el estado de los productos
y el stock de los mismos para que quede reflejada la operación
*/
void retornoTransportista(transportistas *transportista, int numtransportistas, productos_pedidos *productos_pedidos, int numproductos_pedido, productos *productos, int numproductos, pedidos *pedidos, int numpedidos, lockers *lockers, int numlockers, compartimentos_lockers *compartimentoslockers, int numcompartimentoslockers, devoluciones *devoluciones, int numdevoluciones, int transportistaid)
{
    int opcion;
    do
    {
        system("cls");
        printf("\n");
        printf("1. Consultar lockers por localidad\n");
        printf("2. Realizar retorno de productos\n");
        printf("3. Salir\n");
        printf("Introduce una opción: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            consultarLockersLocalidad(lockers, numlockers, compartimentoslockers, numcompartimentoslockers);
            system("pause");
            break;
        case 2:
            realizarRetornoProductos(productos_pedidos, numproductos_pedido, productos, numproductos, lockers, numlockers, compartimentoslockers, numcompartimentoslockers);
            system("pause");
            break;
        case 3:
            printf("Saliendo de la opción de retorno\n");
            system("pause");
            system("cls");
            break;
        default:
            printf("Opción no válida\n");
            system("pause");
            system("cls");
            break;
        }
    } while (opcion != 3);
}

void consultarLockersLocalidad(lockers *lockers, int numlockers,compartimentos_lockers *compartimentoslockers, int numcompartimentoslockers)
{
    int i;
    char localidad[21];
    printf("Introduce la localidad: ");
    scanf("%s", localidad);
    for (i = 0; i < numlockers; i++)
    {
        if (strcmp(lockers[i].localidad, localidad) == 0)
        {
           //imprime todos los compartimentos de ese locker
            int j;
            for (j = 0; j < numcompartimentoslockers; j++)
            {
                if (strcmp(compartimentoslockers[j].id_locker, lockers[i].id_locker) == 0)
                {
                   //imprime los datos de ese compartimento del locker
                    printf("ID Locker: %s\n", compartimentoslockers[j].id_locker);
                    printf("Número de compartimentos: %d\n", compartimentoslockers[j].num_comp);
                    printf("Estado: %s\n", compartimentoslockers[j].estado);
                    printf("Fecha de ocupación: %s\n", compartimentoslockers[j].fecha_ocupacion);
                    printf("Fecha de caducidad: %s\n", compartimentoslockers[j].fecha_caducidad);
                }
            }
        }
    }
}

void realizarRetornoProductos(productos_pedidos *productos_pedidos, int numproductos_pedido, productos *productos, int numproductos, lockers *lockers, int numlockers, compartimentos_lockers *compartimentoslockers, int numcompartimentoslockers)
{
    int i;
    char id_pedido[8];
    char id_producto[8];
    char id_locker[11];
    char cod_locker[11];
    printf("Introduce el ID del pedido: ");
    scanf("%s", id_pedido);
    printf("Introduce el ID del producto: ");
    scanf("%s", id_producto);
    printf("Introduce el ID del locker: ");
    scanf("%s", id_locker);
    printf("Introduce el código del locker: ");
    scanf("%s", cod_locker);
    for (i = 0; i < numproductos_pedido; i++)
    {
        if (strcmp(productos_pedidos[i].id_pedido, id_pedido) == 0 && strcmp(productos_pedidos[i].id_prod, id_producto) == 0 && strcmp(productos_pedidos[i].id_locker, id_locker) == 0 && strcmp(productos_pedidos[i].cod_locker, cod_locker) == 0)
        {
            strcpy(productos_pedidos[i].id_locker, "");
            strcpy(productos_pedidos[i].cod_locker, "");
            strcpy(productos_pedidos[i].estado, "devuelto");
            printf("Producto devuelto\n");
            //actualizar compartimentos ocupados
            int k;
            for (k = 0; k < numcompartimentoslockers; k++)
            {
                if (strcmp(compartimentoslockers[k].id_locker, id_locker) == 0)
                {
                    compartimentoslockers[k].num_comp = compartimentoslockers[k].num_comp - 1;
                }
            }
            //actualizar stock
            int j;
            for (j = 0; j < numproductos; j++)
            {
                if (strcmp(productos[j].id_prod, id_producto) == 0)
                {
                    productos[j].stock = productos[j].stock + productos_pedidos[i].num_unid;
                }
            }
        }
    }
}

