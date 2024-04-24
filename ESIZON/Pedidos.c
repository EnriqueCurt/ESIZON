#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "Perfil.h"


void ClientesPedidos(clientes * cliente, int id,pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos, int numclientes){
	int opcion;
	do{
	printf("1. Realizar Pedido\n");
	printf("2. Consultar Pedido\n");
	printf("3. Modificar Pedido\n");
	printf("4. Salir\n");
	printf("Seleccione una opcion: ");
	scanf("%d",&opcion);
	switch(opcion)
	{
		case 1:
			RealizarPedidoCliente(pedido,productopedido,producto,numpedidos,numproductos,id);
			break;
		case 2:
			ConsultarPedidoCliente(pedido,productopedido,producto,numpedidos,numproductos,id);
			break;
		case 3:
			ModificarPedidoPropioCliente(cliente,numclientes,pedido,productopedido,producto,numpedidos,numproductos,id);
			break;
		case 4:
		system("cls");
			break;
		default:
			printf("Opcion no valida\n");
			system("pause");
			system("cls");
			break;
	}

	}while(opcion!=4);
}

void RealizarPedidoAdmin(pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos,int id){
	system("cls");
    char cadena[11];
    sprintf(cadena, "%11d", (*numpedidos)+1);
    strcpy(pedido[*numpedidos].id_pedido,cadena);
	printf("Introduzca la fecha del pedido: ");
	gets(pedido[*numpedidos].fecha_pedido);
	printf("Introduzca el identificador del cliente: ");
	gets(pedido[*numpedidos].id_cliente);
	printf("Introduzca el lugar de entrega: ");
	gets(pedido[*numpedidos].lugar);
	printf("Introduzca el identificador del locker: ");
	gets(pedido[*numpedidos].id_locker);
	printf("Introduzca el identificador del codigo promocional: ");
	gets(pedido[*numpedidos].id_cod);
	system("cls");
	int i;
	do{
		printf("Introduzca el identificador del producto: ");
		gets(productopedido[*numpedidos].id_prod);
		for(i=0;i<*numproductos;i++)
		{
			if(strcmp(producto[i].id_prod,productopedido[*numpedidos].id_prod)==0){
				break;
			}
		}
		printf("Introduzca el numero de unidades: ");
		scanf("%d",&productopedido[*numpedidos].num_unid);
		if(producto[i].stock<productopedido[*numpedidos].num_unid)
		{
			printf("No hay suficiente stock\n");
		}
		else
		{
			producto[i].stock=producto[i].stock-productopedido[*numpedidos].num_unid;
		}
	}while(producto[i].stock<productopedido[*numpedidos].num_unid);
}
void RealizarPedidoCliente(pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos,int id){
	system("cls");
    char cadena[11];
	char id_cliente[8];
    sprintf(cadena, "%11d", (*numpedidos)+1);
    strcpy(pedido[*numpedidos].id_pedido,cadena);
	printf("Introduzca la fecha del pedido: ");
	gets(pedido[*numpedidos].fecha_pedido);
	sprintf(cadena, "%07d", id+1);
	strcpy(pedido[*numpedidos].id_cliente,id_cliente);
	printf("Introduzca el lugar de entrega: ");
	gets(pedido[*numpedidos].lugar);
	printf("Introduzca el identificador del locker: ");
	gets(pedido[*numpedidos].id_locker);
	printf("Introduzca el identificador del codigo promocional: ");
	gets(pedido[*numpedidos].id_cod);
	system("cls");
	int i;
	do{
		printf("Introduzca el identificador del producto: ");
		gets(productopedido[*numpedidos].id_prod);
		for(i=0;i<*numproductos;i++)
		{
			if(strcmp(producto[i].id_prod,productopedido[*numpedidos].id_prod)==0){
				break;
			}
		}
		printf("Introduzca el numero de unidades: ");
		scanf("%d",&productopedido[*numpedidos].num_unid);
		if(producto[i].stock<productopedido[*numpedidos].num_unid)
		{
			printf("No hay suficiente stock\n");
		}
		else
		{
			producto[i].stock=producto[i].stock-productopedido[*numpedidos].num_unid;
		}
	}while(producto[i].stock<productopedido[*numpedidos].num_unid);
}

void EliminarPedidoAdmin(pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos,int id)
{
	char cadena[8];
    printf("Introduce el id del pedido a eliminar: ");
	gets(cadena);
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
					//eliminar producto pedido
					for (k = j; k < *numproductos - 1; k++)
					{
						productopedido[k] = productopedido[k + 1];
					}
					(*numproductos)--;
				}
            }
            //eliminar pedido
			for (j = i; j < *numpedidos - 1; j++)
			{
				pedido[j] = pedido[j + 1];
			}
			(*numpedidos)--;
            printf("Pedido eliminado\n");

            exit=1;

        }
	}
}

void ConsultarPedidoAdmin(pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos){
	int i;

    printf("Introduce el id del pedido a consultar: ");
    scanf("%d", &i);
    i--;

    system("cls");
	printf("ID Pedido\n");
    printf(" %s\n", pedido[i].id_pedido);
    printf("Fecha Pedido\n");
	printf("%s\n", pedido[i].fecha_pedido);
	printf("ID Cliente\n");
	printf("%s\n", pedido[i].id_cliente);
	printf("Lugar de Entrega\n");
	printf("%s\n", pedido[i].lugar);
	printf("ID Locker\n");
	printf("%s\n", pedido[i].id_locker);
	printf("ID Codigo Promocional\n");
	printf("%s\n", pedido[i].id_cod);

    system("pause");
    system("cls");
}

void ModificarPedidoAdmin(pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos,int id){
	int i,s;
	char cad[8];
	printf("Introduce el id del pedido a modificar: ");
	scanf("%s", cad);
	for(int i=0;i<*numpedidos;i++){
		if(strcmp(pedido[i].id_pedido,cad)==0){
			printf("Introduzca la nueva fecha): ");
			gets(pedido[i].fecha_pedido);
			printf("Introduzca el nuevo lugar de entrega: ");
			gets(pedido[i].lugar);
			printf("Introduzca el nuevo id del locker: ");
			gets(pedido[i].id_locker);
			printf("Introduzca el nuevo id del codigo promocional: ");
			gets(pedido[id].id_cod);
			system("cls");
			printf("Datos modificados correctamente");
		}
	}
	system("cls");
}
//void ModificarPedidoPropio cumple la misma funcion que ModificarPedido,pero solo los del mismo usuario,y no de otros.
void ModificarPedidoPropioCliente(clientes *cliente,int numclientes,pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos,int id){
	int i,s;
	char cad[8];
	char id_cliente[8];
	sprintf(id_cliente, "%07d", id+1);
	printf("Introduce el id del pedido a modificar: ");
	scanf("%s", cad);
	for(int i=0;i<*numpedidos;i++){
		if(strcmp(pedido[i].id_pedido,cad)==0 && strcmp(pedido[id].id_cliente,id_cliente)==0){
			printf("Introduzca la nueva fecha): ");
			gets(pedido[i].fecha_pedido);
			printf("Introduzca el nuevo lugar de entrega: ");
			gets(pedido[i].lugar);
			printf("Introduzca el nuevo id del locker: ");
			gets(pedido[i].id_locker);
			printf("Introduzca el nuevo id del codigo promocional: ");
			gets(pedido[id].id_cod);
			system("cls");
			printf("Datos modificados correctamente");
		}
	}
	system("cls");
}

//AdminPedidos: Mediante el menú correspondiente podrá realizar altas, bajas, búsquedas, listados ymodificaciones de pedidos.Asi como asignar transportistas a los pedidos y asignar lockers a los pedidos.

void AdminPedidos(admin_prov * admin, int id,pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos,lockers *locker,int numlockers,transportistas *transportista,int numtransportistas, int *productopedidos){
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
			RealizarPedidoAdmin(pedido,productopedido,producto,numpedidos,numproductos,id);
			break;
		case 2:
			EliminarPedidoAdmin(pedido,productopedido,producto,numpedidos,numproductos,id);
			break;
		case 3:
			ConsultarPedidoAdmin(pedido,productopedido,producto,numpedidos,numproductos);
			break;
		case 4:
			ModificarPedidoAdmin(pedido,productopedido,producto,numpedidos,numproductos,id);
			break;
		case 5:
			AsignarTransportista(pedido,numpedidos,transportista,numtransportistas,productopedido,*productopedidos);
			break;
		case 6:
			AsignarLocker(pedido,numpedidos,locker);
			break;
		case 7:
			break;
		default:
			printf("Opcion no valida\n");
			break;
	}
}

void AsignarLocker(pedidos *pedido,int *numpedidos,lockers *locker){
	char pedi[8];
	int exit=0;
	printf("Introduzca el identificador del pedido a asignar locker: ");
	scanf("%s",pedi);
	int i;
	for(i=0;i<*numpedidos && exit==0;i++){
		if(strcmp(pedido[i].id_pedido,pedi)==0){
			printf("Introduzca el identificador del locker: ");
			scanf("%s",pedido[i].id_locker);
			exit=1;
		}
	}
	system("cls");
}

void AsignarTransportista (pedidos *pedido,int *numpedidos,transportistas *transportista,int numtransportistas,productos_pedidos *productopedido,int numproductos_pedidos){
	char pedi[8];
	int exit=0;
	printf("Introduzca el identificador del pedido a asignar transportista: ");
	scanf("%s",pedi);
	int i;
	//asignar transportista a cada producto pedido con el mismo id_pedido
	for(i=0;i<numproductos_pedidos;i++){
		if(strcmp(productopedido[i].id_pedido,pedi)==0){
			printf("Introduzca el identificador del transportista: ");
			gets(productopedido[i].id_transp);
		}
	}
	system("cls");
}


void ProveedorPedidos(admin_prov * admin, int id,pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos,lockers *locker,int numlockers,transportistas *transportista,int numtransportistas, int *productopedidos){
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
			ConsultarPedidoProv(pedido,productopedido,producto,numpedidos,numproductos,id);
			break;
		case 2:
			ModificarPedidoPropioProv(pedido,productopedido,producto,numpedidos,numproductos,id);
			break;
		case 3:
			AsignarTransportista(pedido,numpedidos,transportista,numtransportistas,productopedido,*productopedidos);
			break;
		case 4:
			AsignarLocker(pedido,numpedidos,locker);
			break;
		case 5:
			break;
		default:
			printf("Opcion no valida\n");
			break;
	}
}

void ConsultarPedidoProv(pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos, int id)
{
int i;

    printf("Introduce el id del pedido a consultar: ");
    scanf("%d", &i);
    i--;
    system("cls");
	//consultar si en el producto pedido tiene el id pedido y el producto tiene el id igual que el del proveedor
	if(strcmp(productopedido[i].id_pedido,pedido[i].id_pedido)==0 && strcmp(producto[i].id_prod,productopedido[i].id_prod)==0)
	{
		printf("ID Pedido\n");
		printf(" %s\n", pedido[i].id_pedido);
		printf("Fecha Pedido\n");
		printf("%s\n", pedido[i].fecha_pedido);
		printf("ID Cliente\n");
		printf("%s\n", pedido[i].id_cliente);
		printf("Lugar de Entrega\n");
		printf("%s\n", pedido[i].lugar);
		printf("ID Locker\n");
		printf("%s\n", pedido[i].id_locker);
		printf("ID Codigo Promocional\n");
		printf("%s\n", pedido[i].id_cod);
		printf("ID Producto\n");
		printf("%s\n", productopedido[i].id_prod);
		printf("Numero de unidades\n");
		printf("%d\n", productopedido[i].num_unid);
	}
	system("pause");
	system("cls");
}

void ModificarPedidoPropioProv(pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos, int id)
{
	int i,s;
	char cad[8];
	char id_cliente[8];
	sprintf(id_cliente, "%07d", id+1);
	printf("Introduce el id del pedido a modificar: ");
	scanf("%s", cad);
	for(int i=0;i<*numpedidos;i++){

		if(strcmp(productopedido[i].id_pedido,pedido[i].id_pedido)==0 && strcmp(producto[i].id_prod,productopedido[i].id_prod)==0){
			printf("Introduzca la nueva fecha): ");
			gets(pedido[i].fecha_pedido);
			printf("Introduzca el nuevo lugar de entrega: ");
			gets(pedido[i].lugar);
			printf("Introduzca el nuevo id del locker: ");
			gets(pedido[i].id_locker);
			printf("Introduzca el nuevo id del codigo promocional: ");
			gets(pedido[id].id_cod);
			system("cls");
			printf("Datos modificados correctamente");
		}
	}
	system("cls");
}

void ConsultarPedidoCliente(pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos, int id)
{
	int i;
	 printf("Introduce el id del pedido a consultar: ");
	scanf("%d", &i);
	i--;
	char id_cliente[8];
	sprintf(id_cliente, "%07d", id+1);
	system("cls");
	for(int i=0;i<*numpedidos;i++){
		if(strcmp(pedido[i].id_pedido,productopedido[i].id_pedido)==0 && strcmp(producto[i].id_prod,productopedido[i].id_prod)==0 && strcmp(pedido[i].id_cliente,id_cliente)==0){
			printf("ID Pedido\n");
			printf(" %s\n", pedido[i].id_pedido);
			printf("Fecha Pedido\n");
			printf("%s\n", pedido[i].fecha_pedido);
			printf("ID Cliente\n");
			printf("%s\n", pedido[i].id_cliente);
			printf("Lugar de Entrega\n");
			printf("%s\n", pedido[i].lugar);
			printf("ID Locker\n");
			printf("%s\n", pedido[i].id_locker);
			printf("ID Codigo Promocional\n");
			printf("%s\n", pedido[i].id_cod);
			printf("ID Producto\n");
			printf("%s\n", productopedido[i].id_prod);
			printf("Numero de unidades\n");
			printf("%d\n", productopedido[i].num_unid);
		}
	}
}