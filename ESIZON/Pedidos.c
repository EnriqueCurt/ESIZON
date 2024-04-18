#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "Perfil.h"
#include "Pedidos.h"


void ClientesPedidos(clientes * cliente, int id){
	int opcion;
	printf("1. Realizar Pedido\n");
	printf("2. Eliminar Pedido\n");
	printf("3. Consultar Pedido\n");
	printf("4. Modificar Pedido\n");
	printf("5. Salir\n");
	printf("Seleccione una opcion: ");
	scanf("%d",&opcion);
	switch(opcion){
		case 1:
			RealizarPedido();
			break;
		case 2:
			EliminarPedido();
			break;
		case 3:
			ConsultarPedido();
			break;
		case 4:
			ModificarPedido();
			break;
		case 5:
			break;
		default:
			printf("Opcion no valida\n");
			break;
	}
}

void RealizarPedido(pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos,int id){
	system("cls");
    char cadena[11];
    sprintf(cadena, "%11d", (*numpedidos)+1);
    strcpy(pedido[*numpedidos].id_pedido,cadena);
	printf("Introduzca la fecha del pedido: ");
	sprintf(cadena, "%11d", (*numpedidos)+1);
    strcpy(pedido[*numpedidos].fecha_pedido,cadena);
	printf("Introduzca el identificador del cliente: ");
	sprintf(cadena, "%11d", (*numpedidos)+1);
    strcpy(pedido[*numpedidos].id_cliente,cadena);
	printf("Introduzca el lugar de entrega: ");
	sprintf(cadena, "%11d", (*numpedidos)+1);
    strcpy(pedido[*numpedidos].lugar,cadena);
	printf("Introduzca el identificador del locker: ");
	sprintf(cadena, "%11d", (*numpedidos)+1);
    strcpy(pedido[*numpedidos].id_locker,cadena);
	printf("Introduzca el identificador del codigo promocional: ");
	sprintf(cadena, "%11d", (*numpedidos)+1);
    strcpy(pedido[*numpedidos].id_cod,cadena);

	int i;
    int exit=0;
    for (i = 0; i < *numpedidos && exit == 0; i++)
    {
        if (strcmp(pedido[i].id_pedido, cadena) == 0)
        {
            int j;
            for (j = i; j < *numpedidos - 1; j++)
            {
                if(strcmp(pedido[i].id_pedido,productopedido[j].id_pedido)==0){
					int k;
					for(k=1;k<=*numproductos;k++){
						if(strcmp(productopedido[j].id_prod,producto[k].id_prod)==0){
							producto[k].stock=producto[k].stock-productopedido[j].num_unid;
						}
					}
						
					(*numpedidos)++;
				}
            }
            exit=1;
        }


}

void EliminarPedido(pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos,int id){
	 char cadena[8];
    sprintf(cadena, "%07d", id);
    int i;
    int exit=0;
    for (i = 0; i < *numpedidos && exit == 0; i++)
    {
        if (strcmp(pedido[i].id_pedido, cadena) == 0)
        {
            int j;
            for (j = i; j < *numpedidos - 1; j++)
            {
                if(strcmp(pedido[i].id_pedido,productopedido[j].id_pedido)==0){
					int k;
					for(k=1;k<=*numproductos;k++){
						if(strcmp(productopedido[j].id_prod,producto[k].id_prod)==0){
							producto[k].stock=producto[k].stock+productopedido[j].num_unid;
						}
					}
						
					(*numpedidos)--;
				}
            }
            (*numclientes)--;
            printf("Pedido eliminado\n");
            exit=1;
        }
}

void ConsultarPedido(pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos,int id){
	 int id;

    printf("Introduce el id del pedido a consultar: ");
    scanf("%d", &id);
    id--;

    system("cls");
	printf("ID Pedido\n");
    printf(" %s\n", pedido[id].id_pedido);
    printf("Fecha Pedido\n");
	printf("%s\n", pedido[id].fecha_pedido);
	printf("ID Cliente\n");
	printf("%s\n", pedido[id].id_cliente);
	printf("Lugar de Entrega\n");
	printf("%s\n", pedido[id].lugar);
	printf("ID Locker\n");
	printf("%s\n", pedido[id].id_locker);
	printf("ID Codigo Promocional\n");
	printf("%s\n", pedido[id].id_cod);

    
    
    system("pause");
    system("cls");

}

void ModificarPedido(pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos,int id){
	int id;

    printf("Introduce el id del pedido a modificar: ");
    scanf("%d", &id);
    id--;
	 printf("Introduzca la nueva fecha): ");
    gets(pedido[id].fecha_pedido);
	printf("Introduzca el nuevo id del cliente: ");
	gets(pedido[id].id_cliente);
	printf("Introduzca el nuevo lugar de entrega: ");
	gets(pedido[id].lugar);
	printf("Introduzca el nuevo id del locker: ");
	gets(pedido[id].id_locker);
	printf("Introduzca el nuevo id del codigo promocional: ");
	gets(pedido[id].id_cod);
    system("cls");
	
}

//AdminPedidos: Mediante el menú correspondiente podrá realizar altas, bajas, búsquedas, listados ymodificaciones de pedidos.Asi como asignar transportistas a los pedidos y asignar lockers a los pedidos.

void AdminPedidos(admin_prov * admin, int id){
	int opcion;
	printf("1. Realizar Pedido\n");
	printf("2. Eliminar Pedido\n");
	printf("3. Consultar Pedido\n");
	printf("4. Modificar Pedido\n");
	printf("5. Asignar Transportista\n");
	printf("6. Asignar Locker\n");
	printf("7. Salir\n");
	printf("Seleccione una opcion: ");
	scanf("%d",&opcion);
	switch(opcion){
		case 1:
			RealizarPedido();
			break;
		case 2:
			EliminarPedido();
			break;
		case 3:
			ConsultarPedido();
			break;
		case 4:
			ModificarPedido();
			break;
		case 5:
			AsignarTransportista();
			break;
		case 6:
			AsignarLocker();
			break;
		case 7:
			break;
		default:
			printf("Opcion no valida\n");
			break;
	}
}

void AsignarLocker(){
	FILE *fichero,*fichero2;
	char id_pedido[8],id_pedido2[8],fecha[11],id_cliente[8],lugar[10],id_locker[11],id_cod[11];
	printf("Introduzca el identificador del pedido a asignar locker: ");
	scanf("%s",id_pedido);
	fichero=fopen("Pedidos.txt","r");
	fichero2=fopen("Pedidos2.txt","w");
	while(fscanf(fichero,"%s-%s-%s-%s-%s-%s\n",id_pedido2,fecha,id_cliente,lugar,id_locker,id_cod)!=EOF){
		if(strcmp(id_pedido,id_pedido2)==0){
			printf("Introduzca el identificador del pedido: ");
			scanf("%s",id_pedido);
			printf("Introduzca la fecha del pedido: ");
			scanf("%s",fecha);
			printf("Introduzca el identificador del cliente: ");
			scanf("%s",id_cliente);
			printf("Introduzca el lugar de entrega: ");
			scanf("%s",lugar);
			printf("Introduzca el identificador del locker: ");
			scanf("%s",id_locker);
			printf("Introduzca el identificador del codigo promocional: ");
			scanf("%s",id_cod);
			fprintf(fichero2,"%s-%s-%s-%s-%s-%s\n",id_pedido,fecha,id_cliente,lugar,id_locker,id_cod);
		}else{
			fprintf(fichero2,"%s-%s-%s-%s-%s-%s\n",id_pedido2,fecha,id_cliente,lugar,id_locker,id_cod);
		}
	}
	fclose(fichero);
	fclose(fichero2);
	remove("Pedidos.txt");
	rename("Pedidos2.txt","Pedidos.txt");

}

void AsignarTransportista (){
	FILE *fichero,*fichero2;
	char id_pedido[8],id_pedido2[8],fecha[11],id_cliente[8],lugar[10],id_locker[11],id_cod[11];
	printf("Introduzca el identificador del pedido a asignar transportista: ");
	scanf("%s",id_pedido);
	fichero=fopen("Pedidos.txt","r");
	fichero2=fopen("Pedidos2.txt","w");
	while(fscanf(fichero,"%s-%s-%s-%s-%s-%s\n",id_pedido2,fecha,id_cliente,lugar,id_locker,id_cod)!=EOF){
		if(strcmp(id_pedido,id_pedido2)==0){
			printf("Introduzca el identificador del pedido: ");
			scanf("%s",id_pedido);
			printf("Introduzca la fecha del pedido: ");
			scanf("%s",fecha);
			printf("Introduzca el identificador del cliente: ");
			scanf("%s",id_cliente);
			printf("Introduzca el lugar de entrega: ");
			scanf("%s",lugar);
			printf("Introduzca el identificador del locker: ");
			scanf("%s",id_locker);
			printf("Introduzca el identificador del codigo promocional: ");
			scanf("%s",id_cod);
			fprintf(fichero2,"%s-%s-%s-%s-%s-%s\n",id_pedido,fecha,id_cliente,lugar,id_locker,id_cod);
		}else{
			fprintf(fichero2,"%s-%s-%s-%s-%s-%s\n",id_pedido2,fecha,id_cliente,lugar,id_locker,id_cod);
		}
	}
	fclose(fichero);
	fclose(fichero2);
	remove("Pedidos.txt");
	rename("Pedidos2.txt","Pedidos.txt");
}


void ProveedorPedidos(transportistas * transportista, int id){
	int opcion;
	printf("1. Consultar Pedido\n");
	printf("2. Modificar Pedido\n");
	printf("3. Asignar Transportista\n");
	printf("4. Asignar Locker\n");
	printf("5. Salir\n");
	printf("Seleccione una opcion: ");
	scanf("%d",&opcion);
	switch(opcion){
		case 1:
			ConsultarPedido();
			break;
		case 2:
			ModificarPedido();
			break;
		case 3:
			AsignarTransportista();
			break;
		case 4:
			AsignarLocker();
			break;
		case 5:
			break;
		default:
			printf("Opcion no valida\n");
			break;
	}
}
