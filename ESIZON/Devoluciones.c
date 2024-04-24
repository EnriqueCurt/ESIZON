#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "Devoluciones.h"
/*
    Permitirá al cliente llevar a cabo devoluciones de productos y realizar un seguimiento de dichas
    devoluciones. En el momento en el que se realiza la devolución de un producto, éste pasa a
    estado «pendiente» de aceptación. El cliente podrá consultar en todo momento las devoluciones
    pendientes de aceptación para, una vez aceptadas, poder cambiar el estado del producto a
    «enviado» para indicar que ya está de camino. Recalcar que las devoluciones de productos las
    gestiona ESIZON independientemente de quien las suministre.
    */
void devolucionCliente(devoluciones *devolucion, int *numdevoluciones, pedidos *pedidos, int *numpedidos,int id_cliente, productos *productos, int *numproductos, productos_pedidos *productos_pedidos, int *numproductos_pedido)
{
    int opcion;
    do{
        system("cls");
        printf("MENU DEVOLUCIONES\n");
        printf("\n\n1.- Realizar devolucion\n");
        printf("2.- Consultar devoluciones pendientes de aceptacion\n");
        printf("3.- Consultar devoluciones aceptadas\n");
        printf("4.- Consultar devoluciones rechazadas\n");
        printf("5.- Consultar devoluciones enviadas\n");
        printf("6.- Salir\n");
        printf("Introduce una opcion: ");
        scanf("%d", &opcion);
        system("cls");
        switch(opcion)
        {
            case 1:
                //vamos a realizar una devolucion
                //primero vamos a listar los pedidos del cliente
                listarPedidosCliente(pedidos, *numpedidos, id_cliente);
                //vamos a pedir el id del pedido
                char id_pedido[8];
                printf("Introduce el id del pedido: ");
                fflush(stdin);
                gets(id_pedido);
                //vamos a comprobar que el pedido existe y que es del cliente
                int pos = buscarPedido(pedidos, *numpedidos, id_pedido);
                if(pos != -1){
                    char id_cliente_char[8];
                    sprintf(id_cliente_char, "%07d", id_cliente);
                    if(strcmp(pedidos[pos].id_cliente, id_cliente_char) == 0){
                        //vamos a listar los productos del pedido
                        listarProductosPedido(productos_pedidos, *numproductos_pedido, id_pedido);
                        //vamos a pedir el id del producto
                        char id_prod[8];
                        printf("Introduce el id del producto: ");
                        fflush(stdin);
                        gets(id_prod);
                        //vamos a comprobar que el producto existe y que es del pedido
                        int pos2 = buscarProductoPedido(productos_pedidos, *numproductos_pedido, id_prod, id_pedido);
                        if(pos2 != -1){
                            if(strcmp(productos_pedidos[pos2].id_pedido, id_pedido) == 0){
                                //vamos a pedir el motivo de la devolucion
                                char motivo[51];
                                printf("Introduce el motivo de la devolucion: ");
                                fflush(stdin);
                                gets(motivo);
                                //vamos a guardar la devolucion
                                strcpy(devolucion[*numdevoluciones].id_pedido, id_pedido);
                                strcpy(devolucion[*numdevoluciones].id_prod, id_prod);
                                strcpy(devolucion[*numdevoluciones].motivo, motivo);
                                strcpy(devolucion[*numdevoluciones].estado, "pendiente");
                                (*numdevoluciones)++;
                                printf("Devolucion realizada con exito\n");
                                system("pause");
                                system("cls");
                            }
                            else
                            {
                                printf("El producto no pertenece al pedido\n");
                                system("pause");
                                system("cls");
                            }
                        }
                        else
                        {
                            printf("El producto no existe\n");
                            system("pause");
                            system("cls");
                        }
                    }
                    else
                    {
                        printf("El pedido no pertenece al cliente\n");
                        system("pause");
                        system("cls");
                    }
                }
                break;

            case 2:
                //vamos a listar las devoluciones pendientes de aceptacion
                listarDevolucionesPendientes(devolucion, *numdevoluciones, id_cliente, pedidos, *numpedidos);
                system("pause");

                break;
            case 3:
                listarDevolucionesAceptadas(devolucion, *numdevoluciones, id_cliente, pedidos, *numpedidos);
                system("pause");
                break;
            case 4:
                listarDevolucionesRechazadas(devolucion, *numdevoluciones, id_cliente, pedidos, *numpedidos);
                system("pause");
                break;
            case 5:
                listarDevolucionesEnviadas(devolucion, *numdevoluciones, id_cliente, pedidos, *numpedidos);
                system("pause");
                break;
            case 6:
                system("cls");
                break;
            default:
                system("cls");
                printf("Opcion no valida\n");
                system("pause");
                break;
        }
    }while(opcion != 6);
}

int buscarPedido(pedidos *pedidos, int numpedidos, char id_pedido[8])
{   
    int resultado = -1;
    int i;
    for(i = 0; i < numpedidos && resultado == -1; i++){
        if(strcmp(pedidos[i].id_pedido, id_pedido) == 0){
            resultado = i;
        }
    }
    return resultado;
}

void listarDevolucionesPendientes(devoluciones *devolucion, int numdevoluciones, int id_cliente,pedidos *pedidos, int numpedidos)
{
    //vamos a listar las devoluciones pendientes de aceptacion de un cliente en concreto
    int i;
    char estado[11];
    strcpy(estado, "pendiente");
    //vamos a recorrer todas las devoluciones
    for(i = 0; i < numdevoluciones; i++){
        //vamos a comprobar si la devolucion es pendiente
        if(strcmp(devolucion[i].estado, estado) == 0){
            //vamos a comprobar si el pedido de la devolucion es del cliente
            printf("Id pedido: %s\n", devolucion[i].id_pedido);
            char id_cliente_char[8];
            sprintf(id_cliente_char, "%07d", id_cliente+1);
            if(strcmp(pedidos[buscarPedido(pedidos, numpedidos, devolucion[i].id_pedido)].id_cliente, id_cliente_char) == 0){
                printf("Id pedido: %s\n", devolucion[i].id_pedido);
                printf("Id producto: %s\n", devolucion[i].id_prod);
                printf("Motivo: %s\n", devolucion[i].motivo);
                printf("Estado: %s\n", devolucion[i].estado);
                printf("\n");
            }
        }
    }
}

void listarDevolucionesAceptadas(devoluciones *devolucion, int numdevoluciones, int id_cliente,pedidos *pedidos, int numpedidos)
{
    //vamos a listar las devoluciones aceptadas de un cliente en concreto
    int i;
    char estado[11];
    strcpy(estado, "aceptado");
    for(i = 0; i < numdevoluciones; i++){
        if(strcmp(devolucion[i].estado, estado) == 0){
            char id_cliente_char[8];
            sprintf(id_cliente_char, "%07d", id_cliente+1);
            if(strcmp(pedidos[buscarPedido(pedidos, numpedidos, devolucion[i].id_pedido)].id_cliente, id_cliente_char) == 0){
                printf("Id pedido: %s\n", devolucion[i].id_pedido);
                printf("Id producto: %s\n", devolucion[i].id_prod);
                printf("Motivo: %s\n", devolucion[i].motivo);
                printf("Estado: %s\n", devolucion[i].estado);
                printf("\n");
            }
        }
    }
}

void listarDevolucionesRechazadas(devoluciones *devolucion, int numdevoluciones, int id_cliente,pedidos *pedidos, int numpedidos)
{
    //vamos a listar las devoluciones rechazadas de un cliente en concreto
    int i;
    char estado[11];
    strcpy(estado, "denegado");
    for(i = 0; i < numdevoluciones; i++){
        if(strcmp(devolucion[i].estado,estado) == 0){
            char id_cliente_char[8];
            sprintf(id_cliente_char, "%07d", id_cliente+1);
            if(strcmp(pedidos[buscarPedido(pedidos, numpedidos, devolucion[i].id_pedido)].id_cliente, id_cliente_char) == 0){
                printf("Id pedido: %s\n", devolucion[i].id_pedido);
                printf("Id producto: %s\n", devolucion[i].id_prod);
                printf("Motivo: %s\n", devolucion[i].motivo);
                printf("Estado: %s\n", devolucion[i].estado);
                printf("\n");
            }
        }
    }
}

void listarDevolucionesEnviadas(devoluciones *devolucion, int numdevoluciones, int id_cliente,pedidos *pedidos, int numpedidos)
{
    //vamos a listar las devoluciones enviadas de un cliente en concreto
    int i;
    char estado[11];
    strcpy(estado, "enviado");
    for(i = 0; i < numdevoluciones; i++){
        if(strcmp(devolucion[i].estado, estado) == 0){
            char id_cliente_char[8];
            sprintf(id_cliente_char, "%07d", id_cliente+1);
            if(strcmp(pedidos[buscarPedido(pedidos, numpedidos, devolucion[i].id_pedido)].id_cliente, id_cliente_char) == 0){
                printf("Id pedido: %s\n", devolucion[i].id_pedido);
                printf("Id producto: %s\n", devolucion[i].id_prod);
                printf("Motivo: %s\n", devolucion[i].motivo);
                printf("Estado: %s\n", devolucion[i].estado);
                printf("\n");
            }
        }
    }
}

void listarPedidosCliente(pedidos *pedidos, int numpedidos, int id_cliente)
{
    //vamos a listar los pedidos de un cliente en concreto
    int i;
    char id_cliente_char[8];
    sprintf(id_cliente_char, "%07d", id_cliente+1);
    for(i = 0; i < numpedidos; i++){
        if(strcmp(pedidos[i].id_cliente, id_cliente_char) == 0){
            printf("Id pedido: %s\n", pedidos[i].id_pedido);
            printf("Fecha pedido: %s\n", pedidos[i].fecha_pedido);
            printf("Lugar: %s\n", pedidos[i].lugar);
            printf("Id locker: %s\n", pedidos[i].id_locker);
            printf("Id cod: %s\n", pedidos[i].id_cod);
            printf("\n");
        }
    }
}

void listarProductosPedido(productos_pedidos *productos_pedidos, int numproductos_pedido, char id_pedido[8])
{
    //vamos a listar los productos de un pedido en concreto
    int i;
    for(i = 0; i < numproductos_pedido; i++){
        if(strcmp(productos_pedidos[i].id_pedido, id_pedido) == 0){
            printf("Id producto: %s\n", productos_pedidos[i].id_prod);
            printf("Num unidades: %d\n", productos_pedidos[i].num_unid);
            printf("Fecha entrega: %s\n", productos_pedidos[i].fecha_entrega);
            printf("Importe: %d\n", productos_pedidos[i].importe);
            printf("Estado: %s\n", productos_pedidos[i].estado);
            printf("Id transp: %s\n", productos_pedidos[i].id_transp);
            printf("Id locker: %s\n", productos_pedidos[i].id_locker);
            printf("Cod locker: %s\n", productos_pedidos[i].cod_locker);
            printf("Fecha entrega devolucion: %s\n", productos_pedidos[i].fecha_entrega_devolucion);
            printf("\n");
        }
    }
}

int buscarProductoPedido(productos_pedidos *productos_pedidos, int numproductos_pedido, char id_prod[8], char id_pedido[8])
{
    int resultado = -1;
    int i;
    for(i = 0; i < numproductos_pedido && resultado==-1; i++){
        if(strcmp(productos_pedidos[i].id_prod, id_prod) == 0 && strcmp(productos_pedidos[i].id_pedido, id_pedido) == 0){
            resultado = i;
        }
    }
    return resultado;
}

/*
Mediante esta opción el administrador podrá acceder a la información de todas las
devoluciones de productos.
• Mediante el menú correspondiente podrá realizar altas de devoluciones (aunque lo
habitual es que sean generadas por los clientes se permite esta opción por si el
cliente tuviera algún problema y no pudiera realizarla), bajas, búsquedas, listados y
modificaciones de devoluciones.
• Entre las modificaciones de los pedidos el administrador tendrá la posibilidad de consultar
todos las devoluciones, solicitadas por un cliente, que se encuentran pendientes de
aceptación, así como modificar el estado de éstas para aceptarlas o no. Si la devolución es
aceptada se debe actualizar la fecha de aceptación y la fecha de caducidad de la devolución.
• También se permitirá modificar el estado a «recibido» en el momento que reciba el
producto. Hay que tener en cuenta que en este último caso se debe actualizar el stock
del producto recibido.
*/

void devolucionesAdmin(devoluciones *devolucion, int *numdevoluciones, pedidos *pedidos, int numpedidos,productos *productos, int *numproductos, productos_pedidos *productos_pedidos, int *numproductos_pedido)
{
    int opcion;
    char id_pedido[8];
    char id_devolucion[8];
    int pos;
    int pos2;
    do{
        system("cls");
        printf("MENU DEVOLUCIONES ADMIN\n");
        printf("\n\n1.- Realizar devolucion\n");
        printf("2.- Modificar devolucion\n");
        printf("3.- Consultar devoluciones pendientes de aceptacion\n");
        printf("4.- Consultar devoluciones aceptadas\n");
        printf("5.- Consultar devoluciones rechazadas\n");
        printf("6.- Consultar devoluciones enviadas\n");
        printf("7.- Listar devoluciones\n");
        printf("8.- Salir\n");
        printf("Introduce una opcion: ");
        scanf("%d", &opcion);
        system("cls");
        switch(opcion)
        {
            case 1:
                //vamos a realizar una devolucion
                //primero vamos a listar los pedidos del cliente
                for(int i = 0; i < numpedidos; i++){
                    printf("Id pedido: %s\n", pedidos[i].id_pedido);
                    printf("Fecha pedido: %s\n", pedidos[i].fecha_pedido);
                    printf("Lugar: %s\n", pedidos[i].lugar);
                    printf("Id locker: %s\n", pedidos[i].id_locker);
                    printf("Id cod: %s\n", pedidos[i].id_cod);
                    printf("\n");
                }
                //vamos a pedir el id del pedido
                printf("Introduce el id del pedido: ");
                fflush(stdin);
                gets(id_pedido);
                //vamos a comprobar que el pedido existe
                pos = buscarPedido(pedidos, numpedidos, id_pedido);
                if(pos != -1)
                {
                    char id_cliente_char[8];
                    printf("Introduce el id del cliente: ");
                    fflush(stdin);
                    gets(id_cliente_char);
                    if(strcmp(pedidos[pos].id_cliente, id_cliente_char) == 0)
                    {
                        //vamos a listar los productos del pedido
                        listarProductosPedido(productos_pedidos, *numproductos_pedido, id_pedido);
                        //vamos a pedir el id del producto
                        char id_prod[8];
                        printf("Introduce el id del producto: ");
                        fflush(stdin);
                        gets(id_prod);
                        //vamos a comprobar que el producto existe y que es del pedido
                        pos2 = buscarProductoPedido(productos_pedidos, *numproductos_pedido, id_prod, id_pedido);
                        if(pos2 != -1)
                        {
                            if(strcmp(productos_pedidos[pos2].id_pedido, id_pedido) == 0)
                            {
                                //vamos a pedir el motivo de la devolucion
                                char motivo[51];
                                printf("Introduce el motivo de la devolucion: ");
                                fflush(stdin);
                                gets(motivo);
                                //vamos a guardar la devolucion
                                strcpy(devolucion[*numdevoluciones].id_pedido, id_pedido);
                                strcpy(devolucion[*numdevoluciones].id_prod, id_prod);
                                strcpy(devolucion[*numdevoluciones].motivo, motivo);
                                strcpy(devolucion[*numdevoluciones].estado, "pendiente");
                                (*numdevoluciones)++;
                                printf("Devolucion realizada con exito\n");
                                system("pause");
                                system("cls");
                            }
                            else
                            {
                                printf("El producto no pertenece al pedido\n");
                                system("pause");
                                system("cls");
                            }
                        }
                        else
                        {
                            printf("El producto no existe\n");
                            system("pause");
                            system("cls");
                        }
                    }
                    else
                    {
                        printf("El pedido no existe\n");
                        system("pause");
                        system("cls");
                    }
                    break;
                }
            case 2:
                //vamos a modificar el estado de una devolucion
                //selecionamos la devolucion a cambiar el estado
                printf("Introduce el id del pedido: ");
                fflush(stdin);
                gets(id_pedido);
                pos = buscarPedido(pedidos, numpedidos, id_pedido);
                if(pos != -1)
                {
                    char id_cliente_char[8];
                    printf("Introduce el id del cliente: ");
                    fflush(stdin);
                    gets(id_cliente_char);
                    if(strcmp(pedidos[pos].id_cliente, id_cliente_char) == 0)
                    {
                        //vamos a pedir el id de la devolucion
                        char id_devolucion[8];
                        printf("Introduce el id de la devolucion: ");
                        fflush(stdin);
                        gets(id_devolucion);
                        //vamos a buscar la devolucion
                        pos2 = buscarPedido(pedidos, numpedidos, id_devolucion);
                        if(pos2 != -1)
                        {
                            if(strcmp(pedidos[pos2].id_cliente, id_cliente_char) == 0)
                            {
                                //vamos a cambiar el estado de la devolucion
                                char estado[11];
                                printf("Introduce el nuevo estado de la devolucion: ");
                                fflush(stdin);
                                gets(estado);
                                if(strcmp(estado, "aceptado") == 0)
                                {
                                    //vamos a actualizar la fecha de aceptacion y la fecha de caducidad
                                    strcpy(devolucion[pos2].estado, estado);
                                    char fecha_aceptacion[11];
                                    printf("Introduce la fecha de aceptacion: ");
                                    fflush(stdin);
                                    gets(fecha_aceptacion);
                                    strcpy(devolucion[pos2].fecha_aceptacion, fecha_aceptacion);
                                    char fecha_caducidad[11];
                                    printf("Introduce la fecha de caducidad: ");
                                    fflush(stdin);
                                    gets(fecha_caducidad);
                                    strcpy(devolucion[pos2].fecha_caducidad, fecha_caducidad);
                                }
                                else if(strcmp(estado, "enviado") == 0)
                                {
                                    strcpy(devolucion[pos2].estado, estado);
                                    char fecha_aceptacion[11];
                                    printf("Introduce la fecha de aceptacion: ");
                                    fflush(stdin);
                                    gets(fecha_aceptacion);
                                    strcpy(devolucion[pos2].fecha_aceptacion, fecha_aceptacion);
                                    char fecha_caducidad[11];
                                    printf("Introduce la fecha de caducidad: ");
                                    fflush(stdin);
                                    gets(fecha_caducidad);
                                    strcpy(devolucion[pos2].fecha_caducidad, fecha_caducidad);
                                    
                                }
                                else if(strcmp(estado, "denegado") == 0)
                                {
                                    strcpy(devolucion[pos2].estado, estado);
                                    char fecha_aceptacion[11];
                                    printf("Introduce la fecha de aceptacion: ");
                                    fflush(stdin);
                                    gets(fecha_aceptacion);
                                    strcpy(devolucion[pos2].fecha_aceptacion, fecha_aceptacion);
                                    char fecha_caducidad[11];
                                    printf("Introduce la fecha de caducidad: ");
                                    fflush(stdin);
                                    gets(fecha_caducidad);
                                    strcpy(devolucion[pos2].fecha_caducidad, fecha_caducidad);
                                }
                                else if(strcmp(estado, "recibido") == 0)
                                {
                                    strcpy(devolucion[pos2].estado, estado);
                                    char fecha_aceptacion[11];
                                    printf("Introduce la fecha de aceptacion: ");
                                    fflush(stdin);
                                    gets(fecha_aceptacion);
                                    strcpy(devolucion[pos2].fecha_aceptacion, fecha_aceptacion);
                                    char fecha_caducidad[11];
                                    printf("Introduce la fecha de caducidad: ");
                                    fflush(stdin);
                                    gets(fecha_caducidad);
                                    strcpy(devolucion[pos2].fecha_caducidad, fecha_caducidad);
                                }
                                printf("Devolucion modificada con exito\n");
                                system("pause");
                                system("cls");
                            }   
                            else
                            {
                                printf("El estado no es valido\n");
                                system("pause");
                                system("cls");
                            }
                        }
                        else
                        {
                            printf("La devolucion no pertenece al cliente\n");
                            system("pause");
                            system("cls");
                        }
                    }
                    else
                    {
                        printf("La devolucion no existe\n");
                        system("pause");
                        system("cls");
                    }
                }
                else
                {
                    printf("El pedido no existe\n");
                    system("pause");
                    system("cls");
                }
            break;

            case 3:
                //vamos a listar las devoluciones pendientes de aceptacion
                listarDevolucionesPendientesAdmin(devolucion, *numdevoluciones);
                system("pause");
                break;
            case 4:
                //vamos a listar las devoluciones aceptadas
                listarDevolucionesAceptadasAdmin(devolucion, *numdevoluciones);
                system("pause");
                break;
            case 5:
                //vamos a listar las devoluciones rechazadas
                listarDevolucionesRechazadasAdmin(devolucion, *numdevoluciones);
                system("pause");
                break;
            case 6:
                //vamos a listar las devoluciones enviadas
                listarDevolucionesEnviadasAdmin(devolucion, *numdevoluciones);
                system("pause");
                break;
            case 7:
                //vamos a listar todas las devoluciones
                for(int i = 0; i < *numdevoluciones; i++){
                    printf("Id pedido: %s\n", devolucion[i].id_pedido);
                    printf("Id producto: %s\n", devolucion[i].id_prod);
                    printf("Motivo: %s\n", devolucion[i].motivo);
                    printf("Estado: %s\n", devolucion[i].estado);
                    printf("\n");
                }
                system("pause");
                break;
            case 8:
                system("cls");
                break;
            default:
                system("cls");
                printf("Opcion no valida\n");
                system("pause");
                break;
        }

    }while(opcion != 8);
}

void listarDevolucionesPendientesAdmin(devoluciones *devolucion, int numdevoluciones)
{
    //vamos a listar las devoluciones pendientes de aceptacion
    int i;
    char estado[11];
    strcpy(estado, "pendiente");
    for(i = 0; i < numdevoluciones; i++){
        if(strcmp(devolucion[i].estado, estado) == 0){
            printf("Id pedido: %s\n", devolucion[i].id_pedido);
            printf("Id producto: %s\n", devolucion[i].id_prod);
            printf("Motivo: %s\n", devolucion[i].motivo);
            printf("Estado: %s\n", devolucion[i].estado);
            printf("\n");
        }
    }
}

void listarDevolucionesAceptadasAdmin(devoluciones *devolucion, int numdevoluciones)
{
    //vamos a listar las devoluciones aceptadas
    int i;
    char estado[11];
    strcpy(estado, "aceptado");
    for(i = 0; i < numdevoluciones; i++){
        if(strcmp(devolucion[i].estado, estado) == 0){
            printf("Id pedido: %s\n", devolucion[i].id_pedido);
            printf("Id producto: %s\n", devolucion[i].id_prod);
            printf("Motivo: %s\n", devolucion[i].motivo);
            printf("Estado: %s\n", devolucion[i].estado);
            printf("\n");
        }
    }
}

void listarDevolucionesRechazadasAdmin(devoluciones *devolucion, int numdevoluciones)
{
    //vamos a listar las devoluciones rechazadas
    int i;
    char estado[11];
    strcpy(estado, "denegado");
    for(i = 0; i < numdevoluciones; i++){
        if(strcmp(devolucion[i].estado, estado) == 0){
            printf("Id pedido: %s\n", devolucion[i].id_pedido);
            printf("Id producto: %s\n", devolucion[i].id_prod);
            printf("Motivo: %s\n", devolucion[i].motivo);
            printf("Estado: %s\n", devolucion[i].estado);
            printf("\n");
        }
    }
}

void listarDevolucionesEnviadasAdmin(devoluciones *devolucion, int numdevoluciones)
{
    //vamos a listar las devoluciones enviadas
    int i;
    char estado[11];
    strcpy(estado, "enviado");
    for(i = 0; i < numdevoluciones; i++){
        if(strcmp(devolucion[i].estado, estado) == 0){
            printf("Id pedido: %s\n", devolucion[i].id_pedido);
            printf("Id producto: %s\n", devolucion[i].id_prod);
            printf("Motivo: %s\n", devolucion[i].motivo);
            printf("Estado: %s\n", devolucion[i].estado);
            printf("\n");
        }
    }
}
