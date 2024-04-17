#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "Perfil.h"
#include "Productos.h"
#include "Pedidos.h"

//Necesito crear tres funciones void:ClientesPedidos,AdminPedidios y ProveedorPedidos
/*El Fichero Pedidos.txt, almacenará la información de los distintos pedidos realizados por los clientes
  registrados en la plataforma, con los siguientes campos separados por guiones:
o Identificador del pedido (Id_pedido), 7 dígitos.
o Fecha del pedido (día, mes y año)
o Identificador del cliente que realiza el pedido (Id_cliente), 7 dígitos.
o Lugar de entrega (Lugar): «domicilio» o «locker»
o Identificador de Locker (Id_locker), 10 caracteres máximo.
o Identificador del código promocional o cheque regalo (Id_cod), 10 caracteres máximo.*/

//ClientesPedidos: Permite al cliente realizar,eliminar,consultar y modificar pedidos.Todas estan operaciones se realizaran en la misma funcio ClientesPedidos

void ClientesPedidos(){
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

void RealizarPedido(){
	FILE *fichero;
	char id_pedido[8],fecha[11],id_cliente[8],lugar[10],id_locker[11],id_cod[11];
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
	fichero=fopen("Pedidos.txt","a");
	fprintf(fichero,"%s-%s-%s-%s-%s-%s\n",id_pedido,fecha,id_cliente,lugar,id_locker,id_cod);
	fclose(fichero);
}

void EliminarPedido(){
	FILE *fichero,*fichero2;
	char id_pedido[8],id_pedido2[8],fecha[11],id_cliente[8],lugar[10],id_locker[11],id_cod[11];
	printf("Introduzca el identificador del pedido a eliminar: ");
	scanf("%s",id_pedido);
	fichero=fopen("Pedidos.txt","r");
	fichero2=fopen("Pedidos2.txt","w");
	while(fscanf(fichero,"%s-%s-%s-%s-%s-%s\n",id_pedido2,fecha,id_cliente,lugar,id_locker,id_cod)!=EOF){
		if(strcmp(id_pedido,id_pedido2)!=0){
			fprintf(fichero2,"%s-%s-%s-%s-%s-%s\n",id_pedido2,fecha,id_cliente,lugar,id_locker,id_cod);
		}
	}
	fclose(fichero);
	fclose(fichero2);
	remove("Pedidos.txt");
	rename("Pedidos2.txt","Pedidos.txt");
}

void ConsultarPedido(){
	FILE *fichero;
	char id_pedido[8],id_pedido2[8],fecha[11],id_cliente[8],lugar[10],id_locker[11],id_cod[11];
	printf("Introduzca el identificador del pedido a consultar: ");
	scanf("%s",id_pedido);
	fichero=fopen("Pedidos.txt","r");
	while(fscanf(fichero,"%s-%s-%s-%s-%s-%s\n",id_pedido2,fecha,id_cliente,lugar,id_locker,id_cod)!=EOF){
		if(strcmp(id_pedido,id_pedido2)==0){
			printf("Identificador del pedido: %s\n",id_pedido2);
			printf("Fecha del pedido: %s\n",fecha);
			printf("Identificador del cliente: %s\n",id_cliente);
			printf("Lugar de entrega: %s\n",lugar);
			printf("Identificador del locker: %s\n",id_locker);
			printf("Identificador del codigo promocional: %s\n",id_cod);
		}
	}
	fclose(fichero);
}

void ModificarPedido(){
	FILE *fichero,*fichero2;
	char id_pedido[8],id_pedido2[8],fecha[11],id_cliente[8],lugar[10],id_locker[11],id_cod[11];
	printf("Introduzca el identificador del pedido a modificar: ");
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

//AdminPedidos: Mediante el menú correspondiente podrá realizar altas, bajas, búsquedas, listados ymodificaciones de pedidos.Asi como asignar transportistas a los productos y asignar lockers a los pedidos.

void AdminPedidos(){
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


void ProveedorPedidos(){
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

