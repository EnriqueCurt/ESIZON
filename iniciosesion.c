#include <stdio.h>
#include <string.h>
#include "InicioSesion.h" # los nombres son prototipos
#include "Registro.h" # los nombres son prototipos
#include "m_menu.h" # los nombres son prototipos
#include <locale.h>
#include <windows.h>
#include "Perfil.h"
//precondicion tener los datos de clientes adminprov y transportista
//postcondicion devuelve 0 en caso de que el login se incorrrecto ,1 si es un cliente 2 si es un administrador 3 si es un provehedor y 4 si es un transportista
int iniciosesion(cliente* cliente, int* id ,admin_prov* adminprov, transportista* transportista ){ // esto es un prototipo
int i,no_existe,tamano;
tamano=sizeof(cliente)/(sizeof(cliente[0]);
i=0;
no_existe=0;

char correo[6],contresena[14];
printf("Email:\n");
fflush(stdin);
scanf("%29s",correo);
printf("Contrasena:\n");
fflush(stdin);
scanf("%14s",contrasena);

for(i=0; (no_existe==0) && (i < tamano ;i++){
    if((strncmp((*cliente)[i].email,email,29)== 0) && (strncmp((*cliente)[i].password,contrasena,14)==0)){
    no_existe=1;
    *id=i;
    printf("\nLogin correcto\n\n");
    system("pause");
    system("cls");
    break;
    }
}

tamano=sizeof(adminprov)/(sizeof(adminprov[0]);
for(i=0; (no_existe==0) && (i < tamano) ;i++){
    if((strncmp((*adminprov)[i].email,email,29)== 0) && (strncmp((*adminprov)[i].password,contrasena,14)==0)){
        if((strncmp((*adminprov)[i].perfil_usuario,"administrador",14)== 0)){
        no_existe=2;
        }else{
        no_existe=3;
        }
    *id=i;
    printf("\nLogin correcto\n\n");
    system("pause");
    system("cls");
    break;
    }
}

tamano=sizeof(transportista)/(sizeof(transportista[0]);
for(i=0; (no_existe==0) && (i < tamano) ;i++){
    if((strncmp((*transportista)[i].email,email,29)== 0) && (strncmp((*transportista)[i].password,contrasena,14)==0)){
    no_existe=4;
    *id=i;
    printf("\nLogin correcto\n\n");
    system("pause");
    system("cls");
    break;
    }
}
return no_existe;
}

void modificarPerfilCliente(cliente * cliente, int id)
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
