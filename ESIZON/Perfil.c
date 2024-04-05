//Realizar las funciones de Perfil.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "Perfil.h"
/*typedef struct{
     char id_cliente[8];
    char nombre[21];
    char direccion[51];
    char localidad[21];
    char provincia[21];
    char email[31];
    char password[16];
    int cartera;
} clientes;
*/

void mostrarPerfilCliente(clientes * cliente, int id)
{
    system("cls");
    printf("Sus datos son: \n\n\n");
    printf("ID: %s\n", cliente[id].id_cliente);
    printf("Nombre: %s\n", cliente[id].nombre);
    printf("Direccion: %s\n", cliente[id].direccion);
    printf("Localidad: %s\n", cliente[id].localidad);
    printf("Provincia: %s\n", cliente[id].provincia);
    printf("Email: %s\n", cliente[id].email);
    printf("Password: %s\n", cliente[id].password);
    printf("Cartera: %d\n\n\n", cliente[id].cartera);

    system("pause");
    system("cls");
}

void modificarPerfilCliente(clientes * cliente, int id)
{   int opcion;
    do
    {
        system("cls");
        printf("Que dato desea modificar?\n");
        printf("1. Nombre\n");
        printf("2. Direccion\n");
        printf("3. Localidad\n");
        printf("4. Provincia\n");
        printf("5. Email\n");
        printf("6. Password\n");
        printf("7. Cartera\n");
        printf("8. Salir\n\n");
        printf("Introduzca la opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);
        system("cls");
        switch (opcion)
        {
        case 1:

            printf("Introduzca el nuevo nombre(20 caracteres maximo): ");
            gets(cliente[id].nombre);
            break;
        case 2:
            printf("Introduzca la nueva direccion(50 caracteres maximo): ");
            gets(cliente[id].direccion);
            break;
        case 3:
            printf("Introduzca la nueva localidad(20 caracteres maximo): ");
            gets(cliente[id].localidad);
            break;
        case 4:
            printf("Introduzca la nueva provincia(20 caracteres maximo): ");
            gets(cliente[id].provincia);
            break;
        case 5:
            printf("Introduzca el nuevo email(30 caracteres maximo): ");
            gets(cliente[id].email);
            break;
        case 6:
            printf("Introduzca la nueva password(15 caracteres maximo): ");
            gets(cliente[id].password);
            break;
        case 7:
            printf("Introduzca la nueva cartera: ");
            //comprobar que es un numero lo que se esta introduciendo
            scanf("%d", &cliente[id].cartera);
            fflush(stdin);
            break;
        case 8:
            break;
        default:
            system("cls");
            printf("Opcion no valida\n");
            system("pause");
            break;
        }
    } while (opcion != 8);
    system("cls");
}
/*
typedef struct{
    char id_empresa[5];
    char nombre[21];
    char email[31];
    char password[16];
    char perfil_usuario[14];
} admin_prov;
*/
void mostrarPerfilAdmin_Prov(admin_prov * admin, int id)
{
    system("cls");
    printf("Sus datos son: \n\n\n");
    printf("ID: %s\n", admin[id].id_empresa);
    printf("Nombre: %s\n", admin[id].nombre);
    printf("Email: %s\n", admin[id].email);
    printf("Password: %s\n", admin[id].password);
    printf("Perfil de usuario: %s\n\n\n", admin[id].perfil_usuario);

    system("pause");
    system("cls");
}

void modificarPerfilAdmin_Prov(admin_prov * admin, int id)
{   int opcion;
    do
    {
        system("cls");
        printf("Que dato desea modificar?\n");
        printf("1. Email\n");
        printf("2. Password\n");
        printf("3. Salir\n\n");
        printf("Introduzca la opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);
        system("cls");
        switch (opcion)
        {
        case 1:
            printf("Introduzca el nuevo email(30 caracteres maximo): ");
            gets(admin[id].email);
            break;
        case 2:
            printf("Introduzca la nueva password(15 caracteres maximo): ");
            gets(admin[id].password);
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
    system("cls");
}

void mostrarPerfilTransportista(transportistas * transportista, int id)
{
    system("cls");
    printf("Sus datos son: \n\n\n");
    printf("ID: %s\n", transportista[id].id_transp);
    printf("Nombre: %s\n", transportista[id].nombre);
    printf("Email: %s\n", transportista[id].email);
    printf("Password: %s\n", transportista[id].password);
    printf("Empresa: %s\n", transportista[id].empresa);
    printf("Ciudad: %s\n", transportista[id].ciudad);   

    system("pause");
    system("cls");

}

void modificarPerfilTransportista(transportistas * transportista, int id)
{   int opcion;
    do
    {
        system("cls");
        printf("Que dato desea modificar?\n");
        printf("1. Email\n");
        printf("2. Password\n");
        printf("3. Nombre\n");
        printf("4. Nombre de la empresa\n");
        printf("5. Ciudad\n");
        printf("6. Salir\n\n");
        printf("Introduzca la opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);
        system("cls");
        switch (opcion)
        {
        case 1:
            printf("Introduzca el nuevo email(30 caracteres maximo): ");
            gets(transportista[id].email);
            break;
        case 2:
            printf("Introduzca la nueva password(15 caracteres maximo): ");
            gets(transportista[id].password);
            break;
        case 3:
            printf("Introduzca el nuevo nombre(20 caracteres maximo): ");
            gets(transportista[id].nombre);
            break;
        case 4:
            printf("Introduzca el nuevo nombre de la empresa(20 caracteres maximo): ");
            gets(transportista[id].empresa);
            break;
        case 5:
            printf("Introduzca la nueva ciudad(20 caracteres maximo): ");
            gets(transportista[id].ciudad);
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
    system("cls");
}
