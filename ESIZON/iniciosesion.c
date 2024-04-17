#include <stdio.h>
#include <string.h>
#include "iniciosesion.h" 
#include <locale.h>
#include <windows.h>
#include "Perfil.h"
//precondicion tener los datos de clientes adminprov y transportista
//postcondicion devuelve 0 en caso de que el login se incorrrecto ,1 si es un cliente 2 si es un administrador 3 si es un provehedor y 4 si es un transportista
int iniciosesion(clientes* cliente,int numclientes, int* id ,admin_prov* adminprov,int numadminprov, transportistas* transportista, int numtransportistas)
{ 
    int i,no_existe,tamano;
    //dime el tamaño de la estructura cliente
    i=0;
    no_existe=0;
    fflush(stdin);
    char email[31],contrasena[16];
    printf("Email:\n");
    scanf("%31s",email);
    fflush(stdin);
    printf("Contrasena:\n");
    scanf("%16s",contrasena);
    fflush(stdin);

    for(i=0; (no_existe==0) && (i <= numclientes);i++){
        if((strncmp((cliente)[i].email,email,31)== 0) && (strncmp((cliente)[i].password,contrasena,16)==0)){
        no_existe=1;
        *id=i;
        system("cls");
        printf("\nLogin correcto\n\n");
        system("pause");
        system("cls");
        }
    }

    for(i=0; (no_existe==0) && (i <= numadminprov) ;i++){
        if((strncmp((adminprov)[i].email,email,31)== 0) && (strncmp((adminprov)[i].password,contrasena,16)==0)){
            if((strncmp((adminprov)[i].perfil_usuario,"administrador",16)== 0)){
            no_existe=2;
            }else{
            no_existe=3;
            }
        *id=i;
        system("cls");
        printf("\nLogin correcto\n\n");
        system("pause");
        system("cls");
        }
    }

    for(i=0; (no_existe==0) && (i <= numtransportistas) ;i++){
        if((strncmp((transportista)[i].email,email,31)== 0) && (strncmp((transportista)[i].password,contrasena,16)==0)){
        no_existe=4;
        *id=i;
        system("cls");
        printf("\nLogin correcto\n\n");
        system("pause");
        system("cls");
        }
    }
    return no_existe;
}

void registrarPerfilCliente(clientes * cliente,int *numclientes) // hay que poner el provtraps o como se llame
{   int opcion;
    system("cls");
        char cadena[8];
        sprintf(cadena, "%07d", (*numclientes)+1);
        strcpy(cliente[*numclientes].id_cliente,cadena);
        printf("1. Nombre\n");
            printf("Introduzca un nombre(20 caracteres maximo): ");
            gets(cliente[*numclientes].nombre);

        printf("2. Direccion\n");
            printf("Introduzca la direccion(50 caracteres maximo): ");
            gets(cliente[*numclientes].direccion);

        printf("3. Localidad\n");
            printf("Introduzca la localidad(20 caracteres maximo): ");
            gets(cliente[*numclientes].localidad);

        printf("4. Provincia\n");
            printf("Introduzca la provincia(20 caracteres maximo): ");
            gets(cliente[*numclientes].provincia);

        printf("5. Email\n");
            printf("Introduzca el email(30 caracteres maximo): ");
            gets(cliente[*numclientes].email);

        printf("6. Password\n");
            printf("Introduzca la password(15 caracteres maximo): ");
            gets(cliente[*numclientes].password);

        printf("7. Cartera\n");
            printf("Introduzca la cartera: ");
            //comprobar que es un numero lo que se esta introduciendo
            scanf("%d", &cliente[*numclientes].cartera);
            fflush(stdin);
    (*numclientes)++;
    system("cls");
}

void registrarPerfilProv(admin_prov * admin,int *numprov) // hay que poner el provtraps o como se llame
{   int opcion;
        system("cls");
        fflush(stdin);
        char cadena[5];
        sprintf(cadena, "%04d", (*numprov)+1);
        strcpy(admin[*numprov].id_empresa,cadena);

        printf("0. nombre\n");
            printf("Introduzca nombre de la empresa(20 caracteres maximo): ");
            gets(admin[*numprov].nombre);

        printf("1. Email\n");
            printf("Introduzca el nuevo email(30 caracteres maximo): ");
            gets(admin[*numprov].email);

        printf("2. Password\n");
            printf("Introduzca la nueva password(15 caracteres maximo): ");
            gets(admin[*numprov].password);

        strcpy(admin[*numprov].perfil_usuario,"proveedor");

    (*numprov)++;

    system("cls");
}

void registrarPerfilTransport(transportistas* transportista,int *numtransportistas) // hay que poner el numtraps o como se llame
{   int opcion;
        system("cls");
        fflush(stdin);
        char cadena[5];
        sprintf(cadena, "%04d", (*numtransportistas)+1);
        strcpy(transportista[*numtransportistas].id_transp,cadena);
        printf("0. nombre\n");
            printf("Introduzca nombre (20 caracteres maximo): ");
            gets(transportista[*numtransportistas].nombre);

        printf("1. Email\n");
            printf("Introduzca el nuevo email(30 caracteres maximo): ");
            gets(transportista[*numtransportistas].email);

        printf("2. Password\n");
            printf("Introduzca la nueva password(15 caracteres maximo): ");
            gets(transportista[*numtransportistas].password);

    (*numtransportistas)++;
    system("cls");
}