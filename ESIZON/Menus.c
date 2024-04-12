//Funciones del menus.h

#include "Menus.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "Perfil.h"
#include "Perfil.c"
#include "Productos.h"
#include "Productos.c"
#include "iniciosesion.h"
#include "iniciosesion.c"


void menuCliente(int *id,clientes *clientes, int *numclientes, transportistas *transportistas, int *numtransportistas, productos_pedidos *productos_pedidos, int *numproductos_pedido, productos *productos, int *numproductos, categorias *categorias, int *numcategorias, descuentos *descuentos, int *numdescuentos, descuentos_clientes *descuentosclientes, int *numdescuentosclientes, lockers *lockers, int *numlockers, compartimentos_lockers *compartimentoslockers, int *numcompartimentoslockers, admin_prov *admin_prov, int *numadmin_prov, pedidos *pedidos, int *numpedidos, devoluciones *devoluciones, int *numdevoluciones)
{
    int opcion;
    do{
        system("cls");
        printf("Usuario: %s\n\n", clientes[*id].nombre);
        printf("1. Perfil\n");
        printf("2. Productos\n");
        printf("3. Descuentos\n");
        printf("4. Pedidos\n");
        printf("5. Devoluciones\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);
        switch(opcion){
            case 1:
                system("cls");
                do{
                    printf("1. Ver perfil\n");
                    printf("2. Modificar perfil\n");
                    printf("3. Salir\n");
                    printf("Seleccione una opcion: ");
                    scanf("%d", &opcion);
                    fflush(stdin);
                    switch(opcion){
                        case 1:
                            mostrarPerfilCliente(clientes, *id);
                            break;
                        case 2:
                            modificarPerfilCliente(clientes, *id);
                            break;
                        case 3:
                            system("cls");
                            break;
                        default:
                            system("cls");
                            printf("Opcion no valida\n\n");
                            system("pause");
                            break;
                    }
                }while(opcion != 3);
                break;
            case 2:
                Cliente_mostrarProductos(productos, *numproductos);
                break;
            case 3:
                printf("Descuentos\n");
                system("pause");
                //descuentos(clientes, numclientes, transportistas, numtransportistas, productos_pedidos, numproductos_pedido, productos, numproductos, categorias, numcategorias, descuentos, numdescuentos, descuentosclientes, numdescuentosclientes, lockers, numlockers, compartimentoslockers, numcompartimentoslockers, admin_prov, numadmin_prov, pedidos, numpedidos, devoluciones, numdevoluciones);
                break;
            case 4:
                printf("Pedidos\n");
                system("pause");
                //pedidos(clientes, numclientes, transportistas, numtransportistas, productos_pedidos, numproductos_pedido, productos, numproductos, categorias, numcategorias, descuentos, numdescuentos, descuentosclientes, numdescuentosclientes, lockers, numlockers, compartimentoslockers, numcompartimentoslockers, admin_prov, numadmin_prov, pedidos, numpedidos, devoluciones, numdevoluciones);
                break;
            case 5:
                printf("Devoluciones\n");
                system("pause");
                //devoluciones(clientes, numclientes, transportistas, numtransportistas, productos_pedidos, numproductos_pedido, productos, numproductos, categorias, numcategorias, descuentos, numdescuentos, descuentosclientes, numdescuentosclientes, lockers, numlockers, compartimentoslockers, numcompartimentoslockers, admin_prov, numadmin_prov, pedidos, numpedidos, devoluciones, numdevoluciones);
                break;
            case 6:
                system("cls");
                break;
            default:
                system("cls");
                printf("Opcion no valida\n\n");
                system("pause");
                break;
        }
    }while( opcion != 6);
}

void menuAdmin(int *id,clientes *clientes, int *numclientes, transportistas *transportistas, int *numtransportistas, productos_pedidos *productos_pedidos, int *numproductos_pedido, productos *productos, int *numproductos, categorias *categorias, int *numcategorias, descuentos *descuentos, int *numdescuentos, descuentos_clientes *descuentosclientes, int *numdescuentosclientes, lockers *lockers, int *numlockers, compartimentos_lockers *compartimentoslockers, int *numcompartimentoslockers, admin_prov *admin_prov, int *numadmin_prov, pedidos *pedidos, int *numpedidos, devoluciones *devoluciones, int *numdevoluciones){
    int opcion;
     //Para que se puedan imprimir caracteres especiales
    setlocale(LC_ALL, "spanish");
    SetConsoleOutputCP(1252);  //para que se muestren bien los caracteres especiales en la consola
    do{
        system("cls");
        printf("ADMINISTRADOR\n\n");
        printf("1. Perfil\n");
        printf("2. Clientes\n");
        printf("3. Proveedores\n");
        printf("4. Productos\n");
        printf("5. Categorias\n");
        printf("6. Pedidos\n");
        printf("7. Transportista\n");
        printf("8. Descuentos\n");
        printf("9. Devoluciones\n");
        printf("10. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);
        switch(opcion){
            case 1:
                system("cls");
                do{
                    printf("1. Ver perfil\n");
                    printf("2. Modificar perfil\n");
                    printf("3. Salir\n");
                    printf("Seleccione una opcion: ");
                    scanf("%d", &opcion);
                    fflush(stdin);
                    switch(opcion){
                        case 1:
                            mostrarPerfilAdmin_Prov(admin_prov, *id); //esto esta por terminar una vez login hecho
                            break;
                        case 2:
                            modificarPerfilAdmin_Prov(admin_prov, *id);
                            break;
                        case 3:
                            system("cls");
                            break;
                        default:
                            system("cls");
                            printf("Opcion no valida\n\n");
                            system("pause");
                            break;
                    }
                }while(opcion != 3);
                break;
            case 2:
                printf("Clientes\n");
                system("pause");
                //productos();
                break;
            case 3:
                printf("Proveedores\n");
                system("pause");
                //descuentos();
                break;
            case 4:
                Admin_GestionarProductos(productos, numproductos);
                break;
            case 5:
                printf("Categorías\n");
                system("pause");
                //devoluciones();
                break;
            case 6:
                printf("Pedidos\n");
                system("pause");
                //pedidos
                break;
            case 7:
                printf("Transportista\n");
                system("pause");
                //Transportistas
                break;
            case 8:
                printf("Descuentos\n");
                system("pause");
                //descuentos();
                break;
            case 9:
                printf("Devoluciones\n");
                system("pause");
                //devoluciones();
                break;
            case 10:
                system("cls");
                break;
            default:
                system("cls");
                printf("Opcion no valida\n\n");
                system("pause");
                break;
        }
    }while( opcion != 10);
}

void menuProveedor(int *id,clientes *clientes, int *numclientes, transportistas *transportistas, int *numtransportistas, productos_pedidos *productos_pedidos, int *numproductos_pedido, productos *productos, int *numproductos, categorias *categorias, int *numcategorias, descuentos *descuentos, int *numdescuentos, descuentos_clientes *descuentosclientes, int *numdescuentosclientes, lockers *lockers, int *numlockers, compartimentos_lockers *compartimentoslockers, int *numcompartimentoslockers, admin_prov *admin_prov, int *numadmin_prov, pedidos *pedidos, int *numpedidos, devoluciones *devoluciones, int *numdevoluciones){
    int opcion;
    do{
        system("cls");
        printf("Empresa: %s\n\n", admin_prov[*id].nombre);
        printf("1. Perfil\n");
        printf("2. Productos\n");
        printf("3. Pedidos\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);
        switch(opcion){
            case 1:
                system("cls");
                do{
                    printf("1. Ver perfil\n");
                    printf("2. Modificar perfil\n");
                    printf("3. Salir\n");
                    printf("Seleccione una opcion: ");
                    scanf("%d", &opcion);
                    fflush(stdin);
                    switch(opcion){
                        case 1:
                            mostrarPerfilAdmin_Prov(admin_prov, *id); //esto esta por terminar una vez login hecho
                            break;
                        case 2:
                            modificarPerfilAdmin_Prov(admin_prov, *id);
                            break;
                        case 3:
                            system("cls");
                            break;
                        default:
                            system("cls");
                            printf("Opcion no valida\n\n");
                            system("pause");
                            break;
                    }
                }while(opcion != 3);
                break;
            case 2:
                printf("Productos\n");
                system("pause");
                //productos();
                break;
            case 3:
                printf("Pedidos\n");
                system("pause");
                //pedidos();
                break;
            case 4:
                system("cls");
                break;
            default:
                system("cls");
                printf("Opcion no valida\n\n");
                system("pause");
                break;
        }
    }while( opcion != 4);

}

void menuTransportista(int *id,clientes *clientes, int *numclientes, transportistas *transportistas, int *numtransportistas, productos_pedidos *productos_pedidos, int *numproductos_pedido, productos *productos, int *numproductos, categorias *categorias, int *numcategorias, descuentos *descuentos, int *numdescuentos, descuentos_clientes *descuentosclientes, int *numdescuentosclientes, lockers *lockers, int *numlockers, compartimentos_lockers *compartimentoslockers, int *numcompartimentoslockers, admin_prov *admin_prov, int *numadmin_prov, pedidos *pedidos, int *numpedidos, devoluciones *devoluciones, int *numdevoluciones){
    int opcion;
    do{
        system("cls");
        printf("Transportista: %s\n\n", transportistas[*id].nombre);
        printf("1. Perfil\n");
        printf("2. Repartos\n");
        printf("3. Retornos\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);
        switch(opcion){
            case 1:
                system("cls");
                printf("Perfil\n");
                do{
                    printf("1. Ver perfil\n");
                    printf("2. Modificar perfil\n");
                    printf("3. Salir\n");
                    printf("Seleccione una opcion: ");
                    scanf("%d", &opcion);
                    fflush(stdin);
                    switch(opcion){
                        case 1:
                            mostrarPerfilTransportista(transportistas,*id); //esto esta por terminar una vez login hecho
                            break;
                        case 2:
                            modificarPerfilTransportista(transportistas,*id);
                            break;
                        case 3:
                            system("cls");
                            break;
                        default:
                            system("cls");
                            printf("Opcion no valida\n\n");
                            system("pause");
                            break;
                    }
                }while(opcion != 3);
                break;

            case 2:
                printf("Pedidos\n");
                system("pause");
                //pedidos();
                break;
            case 3:
                printf("Devoluciones\n");
                system("pause");
                //devoluciones();
                break;
            case 4:
                system("cls");
                break;
            default:
                system("cls");
                printf("Opcion no valida\n\n");
                system("pause");
                break;
        }
    }while( opcion != 4);

}

//Funcion para el menu principal
void menuInicial(clientes *clientes, int *numclientes, transportistas *transportistas, int *numtransportistas, productos_pedidos *productos_pedidos, int *numproductos_pedido, productos *productos, int *numproductos, categorias *categorias, int *numcategorias, descuentos *descuentos, int *numdescuentos, descuentos_clientes *descuentosclientes, int *numdescuentosclientes, lockers *lockers, int *numlockers, compartimentos_lockers *compartimentoslockers, int *numcompartimentoslockers, admin_prov *admin_prov, int *numadmin_prov, pedidos *pedidos, int *numpedidos, devoluciones *devoluciones, int *numdevoluciones){
    int opcion=0;
    do{
    printf(" _____ ____ ___ ________  _   _ \n");
    printf("| ____/ ___|_ _|__  / _ \\| \\ | |\n");
    printf("|  _| \\___ \\| |  / / | | |  \\| |\n");
    printf("| |___ ___) | | / /| |_| | |\\  |\n");
    printf("|_____|____/___/____\\___/|_| \\_|\n\n\n");
    printf("1. Iniciar sesion\n");
    printf("2. Registrarse\n");
    printf("3. Salir\n");
    printf("Seleccione una opcion: ");

    int id;
    
        scanf("%d", &opcion);
        fflush(stdin);
        switch(opcion){
            case 1:
                system("cls");
                printf("Iniciar sesion\n");
                system("pause");
                system("cls");
                int tipo_usuario = 0;
                tipo_usuario=iniciosesion(clientes,*numclientes,&id, admin_prov,*numadmin_prov, transportistas,*numtransportistas);
                if(tipo_usuario==1)
                {
                    menuCliente(&id,clientes, numclientes, transportistas, numtransportistas, productos_pedidos, numproductos_pedido, productos, numproductos, categorias, numcategorias, descuentos, numdescuentos, descuentosclientes, numdescuentosclientes, lockers, numlockers, compartimentoslockers, numcompartimentoslockers, admin_prov, numadmin_prov, pedidos, numpedidos, devoluciones, numdevoluciones);
                }
                else if(tipo_usuario==2)
                {
                    menuAdmin(&id,clientes, numclientes, transportistas, numtransportistas, productos_pedidos, numproductos_pedido, productos, numproductos, categorias, numcategorias, descuentos, numdescuentos, descuentosclientes, numdescuentosclientes, lockers, numlockers, compartimentoslockers, numcompartimentoslockers, admin_prov, numadmin_prov, pedidos, numpedidos, devoluciones, numdevoluciones);
                }
                else if(tipo_usuario==3)
                {
                    menuProveedor(&id,clientes, numclientes, transportistas, numtransportistas, productos_pedidos, numproductos_pedido, productos, numproductos, categorias, numcategorias, descuentos, numdescuentos, descuentosclientes, numdescuentosclientes, lockers, numlockers, compartimentoslockers, numcompartimentoslockers, admin_prov, numadmin_prov, pedidos, numpedidos, devoluciones, numdevoluciones);
                }
                else if(tipo_usuario==4)
                {
                menuTransportista(&id,clientes, numclientes, transportistas, numtransportistas, productos_pedidos, numproductos_pedido, productos, numproductos, categorias, numcategorias, descuentos, numdescuentos, descuentosclientes, numdescuentosclientes, lockers, numlockers, compartimentoslockers, numcompartimentoslockers, admin_prov, numadmin_prov, pedidos, numpedidos, devoluciones, numdevoluciones);
                }
                else
                {
                    printf("Usuario no encontrado\n");
                }
                break;
            case 2:
                do{ 
                    system("cls");
                    printf("1. Registrarse como cliente\n");
                    printf("2. Registrarse como proveedor\n");
                    printf("3. Registrarse como transportista\n");
                    printf("4. Salir\n\n\n");
                    printf("Seleccione una opcion: ");
                    fflush(stdin);
                    scanf("%d", &opcion);
                    fflush(stdin);
                    switch(opcion){
                        case 1:
                            registrarPerfilCliente(clientes, numclientes);
                            break;
                        case 2:
                            registrarPerfilProv(admin_prov, numadmin_prov);
                            break;
                        case 3:
                            registrarPerfilTransport(transportistas, numtransportistas);
                            break;
                        case 4:
                            system("cls");
                            break;
                        default:
                            system("cls");
                            printf("Opcion no valida\n\n");
                            system("pause");
                            break;
                    }
                }while(opcion != 4);
                break;

            case 3:
            system("cls");
                return;
                break;

            default:
                system("cls");
                printf("Opcion no valida\n\n");
                system("pause");
                system("cls");
                break;
        }
    }while(opcion != 3);
}