#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "Perfil.h"
#include "Productos.h"
#include "Pedidos.h"
#include "GestionarAdministrador.h"
#include "iniciosesion.h"

void GestionarClientes(clientes *clientes, int *numclientes)
{
    int opcion;
    int id;
    do{
    printf("1. Añadir Cliente\n");
    printf("2. Eliminar Cliente\n");
    printf("3. Consultar Cliente\n");
    printf("4. Modificar Cliente\n");
    printf("5.Listar Clientes\n");
    printf("6. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    system("cls");
    switch (opcion)
    {
    case 1:
    system("cls");
        registrarPerfilCliente(clientes, numclientes);
        break;
    case 2:
        system("cls");
        printf("Introduce el id del cliente a eliminar: ");
        scanf("%d", &id);
        eliminarPerfilCliente(clientes, numclientes, id);
        break;
    case 3:
        system("cls");
        printf("Introduce el id del cliente a consultar: ");
        scanf("%d", &id);
        id--;
        mostrarPerfilCliente(clientes, id);
        break;
    case 4:
        system("cls");
        printf("Introduce el id del cliente a modificar: ");
        scanf("%d", &id);
        id--;
        modificarPerfilCliente(clientes,id);
        break;
    case 5:
        system("cls");
        listarClientes(clientes, numclientes);
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
    }while(opcion!=6);
}

void eliminarPerfilCliente(clientes *clientes, int *numclientes, int id)
{
    char cadena[8];
    sprintf(cadena, "%07d", id);
    int i;
    int exit=0;
    for (i = 0; i < *numclientes && exit == 0; i++)
    {
        if (strcmp(clientes[i].id_cliente, cadena) == 0)
        {
            int j;
            for (j = i; j < *numclientes - 1; j++)
            {
                clientes[j] = clientes[j + 1];
            }
            (*numclientes)--;
            printf("Cliente eliminado\n");
            exit=1;
        }
    }
}

void listarClientes(clientes *clientes, int *numclientes)
{
    int i;
    for (i = 0; i < *numclientes; i++)
    {
        printf("ID: %s\n", clientes[i].id_cliente);
        printf("Nombre: %s\n", clientes[i].nombre);
        printf("Direccion: %s\n", clientes[i].direccion);
        printf("Localidad: %s\n", clientes[i].localidad);
        printf("Provincia: %s\n", clientes[i].provincia);
        printf("Email: %s\n", clientes[i].email);
        printf("Password: %s\n", clientes[i].password);
        printf("Cartera: %d\n\n\n", clientes[i].cartera);
    }
    system("pause");
    system("cls");
}

void GestionarProveedores(admin_prov *provedores, int *numprovedores)
{
    int opcion;
    int id;
    do{
    printf("1. Añadir Proveedor\n");
    printf("2. Eliminar Proveedor\n");
    printf("3. Consultar Proveedor\n");
    printf("4. Modificar Proveedor\n");
    printf("5.Listar Proveedores\n");
    printf("6. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    system("cls");
    switch (opcion)
    {
    case 1:
    system("cls");
        registrarPerfilProv(provedores, numprovedores);
        break;
    case 2:
        system("cls");
        printf("Introduce el id del proveedor a eliminar: ");
        scanf("%d", &id);
        eliminarPerfilProveedor(provedores, numprovedores, id);
        break;
    case 3:
        printf("Introduce el id del proveedor a consultar: ");
        scanf("%d", &id);
        id--;
        system("cls");
        mostrarPerfilAdmin_Prov(provedores, id);
        break;
    case 4:
        system("cls");
        printf("Introduce el id del proveedor a modificar: ");
        scanf("%d", &id);
        id--;
        modificarPerfilAdmin_Prov(provedores,id);
        break;
    case 5:
        system("cls");
        listarProveedores(provedores, numprovedores);
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
    }while(opcion!=6);
}

void eliminarPerfilProveedor(admin_prov *provedores, int *numprovedores, int id)
{
    char cadena[8];
    sprintf(cadena, "%07d", id);
    int i;
    int exit=0;
    for (i = 0; i < *numprovedores && exit == 0; i++)
    {
        if (strcmp(provedores[i].id_empresa, cadena) == 0 && provedores[i].perfil_usuario=="proveedor")
        {
            int j;
            for (j = i; j < *numprovedores - 1; j++)
            {
                provedores[j] = provedores[j + 1];
            }
            (*numprovedores)--;
            printf("Proveedor eliminado\n");
            exit=1;
        }
    }
}

void listarProveedores(admin_prov *provedores, int *numprovedores)
{
    int i;
    for (i = 0; i < *numprovedores; i++)
    {
        printf("ID: %s\n", provedores[i].id_empresa);
        printf("Nombre: %s\n", provedores[i].nombre);
        printf("Email: %s\n", provedores[i].email);
        printf("Password: %s\n", provedores[i].password);
        printf("Perfil de usuario: %s\n\n\n", provedores[i].perfil_usuario);
    }
    system("pause");
    system("cls");
}

void GestionarTransportistas(transportistas *transportistas, int *numtransportistas)
{
    int opcion;
    int id;
    do{
    printf("1. Añadir Transportista\n");
    printf("2. Eliminar Transportista\n");
    printf("3. Consultar Transportista\n");
    printf("4. Modificar Transportista\n");
    printf("5.Listar Transportistas\n");
    printf("6. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    system("cls");
    switch (opcion)
    {
    case 1:
    system("cls");
        registrarPerfilTransport(transportistas, numtransportistas);
        break;
    case 2:
        system("cls");
        printf("Introduce el id del transportista a eliminar: ");
        scanf("%d", &id);
        eliminarPerfilTransportista(transportistas, numtransportistas, id);
        break;
    case 3:
        printf("Introduce el id del transportista a consultar: ");
        scanf("%d", &id);
        id--;
        system("cls");
        mostrarPerfilTransportista(transportistas, id);
        break;
    case 4:
        system("cls");
        printf("Introduce el id del transportista a modificar: ");
        scanf("%d", &id);
        id--;
        modificarPerfilTransportista(transportistas,id);
        break;
    case 5:
        system("cls");
        listarTransportistas(transportistas, numtransportistas);
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
    }while(opcion!=6);
}

void eliminarPerfilTransportista(transportistas *transportistas, int *numtransportistas, int id)
{
    char cadena[5];
    sprintf(cadena, "%05d", id);
    int i;
    int exit=0;
    for (i = 0; i < *numtransportistas && exit == 0; i++)
    {
        if (strcmp(transportistas[i].id_transp, cadena) == 0)
        {
            int j;
            for (j = i; j < *numtransportistas - 1; j++)
            {
                transportistas[j] = transportistas[j + 1];
            }
            (*numtransportistas)--;
            printf("Transportista eliminado\n");
            exit=1;
        }
    }
}

void listarTransportistas(transportistas *transportistas, int *numtransportistas)
{
    int i;
    for (i = 0; i < *numtransportistas; i++)
    {
        printf("ID: %s\n", transportistas[i].id_transp);
        printf("Nombre: %s\n", transportistas[i].nombre);
        printf("Email: %s\n", transportistas[i].email);
        printf("Password: %s\n", transportistas[i].password);
        printf("Empresa: %s\n", transportistas[i].empresa);
        printf("Ciudad: %s\n\n\n", transportistas[i].ciudad);
    }
    system("pause");
    system("cls");
}

void GestionarCategoria(categorias *categorias, int *numcategorias)
{
    int opcion;
    int id;
    do{
    printf("1. Añadir Categoria\n");
    printf("2. Eliminar Categoria\n");
    printf("3. Consultar Categoria\n");
    printf("4. Modificar Categoria\n");
    printf("5.Listar Categorias\n");
    printf("6. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    system("cls");
    switch (opcion)
    {
    case 1:
    system("cls");
        registrarCategoria(categorias, numcategorias);
        break;
    case 2:
        system("cls");
        printf("Introduce el id de la categoria a eliminar: ");
        scanf("%d", &id);
        eliminarCategoria(categorias, numcategorias, id);
        break;
    case 3:
        system("cls");
        consultarCategoria(categorias, numcategorias);
        break;
    case 4:
        system("cls");
        printf("Introduce el id de la categoria a modificar: ");
        scanf("%d", &id);
        id--;
        modificarCategoria(categorias,id);
        break;
    case 5:
        system("cls");
        listarCategorias(categorias, numcategorias);
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
    }while(opcion!=6);
}

void registrarCategoria(categorias *categorias, int *numcategorias)
{
    int opcion;
    system("cls");
    char cadena[5];
    sprintf(cadena, "%05d", (*numcategorias)+1);
    strcpy(categorias[*numcategorias].id_categ,cadena);
    printf("Introduzca una descripcion(20 caracteres maximo): ");
    gets(categorias[*numcategorias].descrip);
    (*numcategorias)++;
    system("cls");
}

void eliminarCategoria(categorias *categorias, int *numcategorias, int id)
{
    char cadena[5];
    sprintf(cadena, "%05d", id);
    int i;
    int exit=0;
    for (i = 0; i < *numcategorias && exit == 0; i++)
    {
        if (strcmp(categorias[i].id_categ, cadena) == 0)
        {
            int j;
            for (j = i; j < *numcategorias - 1; j++)
            {
                categorias[j] = categorias[j + 1];
            }
            (*numcategorias)--;
            printf("Categoria eliminada\n");
            exit=1;
        }
    }
}

void listarCategorias(categorias *categorias, int *numcategorias)
{
    int i;
    for (i = 0; i < *numcategorias; i++)
    {
        printf("ID: %s\n", categorias[i].id_categ);
        printf("Descripcion: %s\n\n\n", categorias[i].descrip);
    }
    system("pause");
    system("cls");
}

void consultarCategoria(categorias *categorias, int *numcategorias)
{
    int id;

    printf("Introduce el id de la categoria a consultar: ");
    scanf("%d", &id);
    id--;

    system("cls");

    printf("ID: %s\n", categorias[id].id_categ);
    printf("Descripcion: %s\n\n\n", categorias[id].descrip);
    
    system("pause");
    system("cls");

}

void modificarCategoria(categorias *categorias, int id)
{
    printf("Introduzca una descripcion(20 caracteres maximo): ");
    gets(categorias[id].descrip);
    system("cls");
     
}
