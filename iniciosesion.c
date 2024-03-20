#include <stdio.h>
#include <string.h>
#include "InicioSesion.h" # los nombres son prototipos
#include "Registro.h" # los nombres son prototipos
#include "m_menu.h" # los nombres son prototipos
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
