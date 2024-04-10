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
int iniciosesion(cliente* cliente, int* id ,admin_prov* adminprov, transportista* transportista ){ // AQUI
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

void registarPerfilCliente(cliente * cliente, int id) // hay que poner el provtraps o como se llame
{   int opcion;
  system("cls");
        fflush(stdin);
        admin[id].perfil_prov=numprov; // AQUI******
        printf("1. Nombre\n");
            printf("Introduzca un nombre(20 caracteres maximo): ");
            gets(cliente[id].nombre);

        printf("2. Direccion\n");
            printf("Introduzca la direccion(50 caracteres maximo): ");
            gets(cliente[id].direccion);

        printf("3. Localidad\n");
            printf("Introduzca la localidad(20 caracteres maximo): ");
            gets(cliente[id].localidad);

        printf("4. Provincia\n");
            printf("Introduzca la provincia(20 caracteres maximo): ");
            gets(cliente[id].provincia);

        printf("5. Email\n");
            printf("Introduzca el email(30 caracteres maximo): ");
            gets(cliente[id].email);

        printf("6. Password\n");
            printf("Introduzca la password(15 caracteres maximo): ");
            gets(cliente[id].password);

        printf("7. Cartera\n");
            printf("Introduzca la cartera: ");
            //comprobar que es un numero lo que se esta introduciendo
            scanf("%d", &cliente[id].cartera);
            fflush(stdin);
    system("cls");
}

void registrarPerfilProv(admin_prov * admin, int id, int numprov) // hay que poner el provtraps o como se llame
{   int opcion;
        system("cls");
        fflush(stdin);
        admin[id].perfil_prov=numprov;  // AQUI******

        printf("0. nombre\n");
            printf("Introduzca nombre de la empresa(20 caracteres maximo): ");
            gets(admin[id].nombre);

        printf("1. Email\n");
            printf("Introduzca el nuevo email(30 caracteres maximo): ");
            gets(admin[id].email);

        printf("2. Password\n");
            printf("Introduzca la nueva password(15 caracteres maximo): ");
            gets(admin[id].password);

            admin[id].perfil_usuario="proveedor";

    system("cls");
}

void registrarPerfilTransport(transportista* transportista, int id) // hay que poner el numtraps o como se llame
{   int opcion;
        system("cls");
        fflush(stdin);
                transportista[id].perfil_transp=numtransp;  // AQUI******
        printf("0. nombre\n");
            printf("Introduzca nombre (20 caracteres maximo): ");
            gets(transportista[id].nombre);

        printf("1. Email\n");
            printf("Introduzca el nuevo email(30 caracteres maximo): ");
            gets(transportista[id].email);

        printf("2. Password\n");
            printf("Introduzca la nueva password(15 caracteres maximo): ");
            gets(transportista[id].password);


    system("cls");
}
