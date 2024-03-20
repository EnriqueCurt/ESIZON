#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "Perfil.h"

/*typedef struct{
    char id_pedido[8];
    char fecha_pedido[11];
    char id_cliente[8];
    char lugar[9];
    char id_locker[11];
    char id_cod[11];
} pedidos;
*/
void admin_pedido(){
    Pedidos *pedi1;
    printf("\nBienvenido Administrador al apartado de Pedidos.\nAquí podrás modificar el estado en el que se encuentra los diferentes pedidos realizados.\n");
    pedi1=guardar_fichero_pedido();
    printf("\nA contiuación, vas a acceder al menú donde podrás modificar el estado de diferentes pedidos.\n");
    imprimir_actualizacion_pedido(pedi1);
}
pedidos *guardar_fichero_pedido(){
    FILE *F;
    int n, i;
    Pedidos *pedi1;
    Pedidos pedi2;
    n=longitud_fichero_pedido();
    pedi1=(Pedidos *)malloc((n+1)*sizeof(Pedidos)); //Reserva el pespacio para poder alamcenar toda la informaciñon del fichero Pedido.txt
    F=fopen("Pedido.txt", "r");
    if(F==NULL)
        printf("Error en la apertura de la base de datos, por favor, vuelva a intentarlo más tarde");
    else
        for(i=0;i<n;i++){
            pedi2=pedi1[i];
            fscanf(F, "%[^/]/%[^/]/%[^/]/%[^\n]", pedi2.idprod, pedi2.cantidad, pedi2.precio, pedi2.estado);
            pedi1[i]=pedi2;
    }
    return pedi1;
}
