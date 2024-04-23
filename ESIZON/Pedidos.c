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
			ModificarPedidoPropioCliente();
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

void ModificarPedidoAdmin(pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos,int id){
	int id;
	char cad;

	printf("Introduce el id del pedido a modificar: ");
	scanf("%s", &cad);
	for(id=0;id<*numpedidos;id++){
		if(strcmp(pedido[id].id_pedido,cad)==0){
			break;
		}
	})
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
//void ModificarPedidoPropio cumple la misma funcion que ModificarPedido,pero solo los del mismo usuario,y no de otros.
void ModificarPedidoPropioCliente(clientes *cliente,int *numclientes,pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos,int id){
	int id,s;
	char cad;

	printf("Introduce el id del pedido a modificar: ");
	scanf("%s", &cad);
	for(id=0;id<*numpedidos;id++){
		if(strcmp(pedido[id].id_pedido,cad)==0){
			break;
		}
	})
	id--;
	for(s=0;s<*numclientes;s++){
		if(strcmp(cliente[s].id_cliente,pedido[id].id_cliente)==0){
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

		}else{
			printf("No puedes modificar pedidos de otros clientes\n");
		}}
	 
	
}

void ModificarPedidoPropioTransportista(transportistas *transportista,int *numtransportista,pedidos *pedido,productos_pedidos *productopedido,productos *producto,int *numpedidos,int *numproductos,int id){
	int id,s;
	char cad;

	printf("Introduce el id del pedido a modificar: ");
	scanf("%s", &cad);
	for(id=0;id<*numtransportista;id++){
		if(strcmp(pedido[id].id_pedido,cad)==0){
			break;
		}
	})
	id--;
	for(s=0;s<*numtransportista;s++){
		if(strcmp(transportista[s].id_transp,pedido[id].id_cliente)==0){
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

		}else{
			printf("No puedes modificar pedidos de otros transportistas\n");
		}}
	 
	
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
			ModificarPedidoAdmin();
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

void AsignarLocker(clientes *cliente,int *numclientes,pedidos *pedido,int *numpedidos,lockers *locker,descuentos_clientes *promocion){
	char pedi;
	printf("Introduzca el identificador del pedido a asignar locker: ");
	scanf("%s",pedi);
	int i;
	for(i=0;i<*numpedidos;i++){
		if(strcmp(pedido[i].id_pedido,pedi)==0){
			break;
		}
	}
	printf("Introduzca el identificador del locker: ");
	scanf("%s",pedido[i].id_locker);
	printf("Introduzca el identificador del codigo promocional: ");
	scanf("%s",pedido[i].id_cod);
	printf("Introduzca el identificador del cliente: ");
	scanf("%s",pedido[i].id_cliente);
	printf("Introduzca el lugar de entrega: ");
	scanf("%s",pedido[i].lugar);
	printf("Introduzca el identificador del locker: ");
	scanf("%s",pedido[i].id_locker);
	printf("Introduzca la fecha del pedido: ");
	scanf("%s",pedido[i].fecha_pedido);

}

void AsignarTransportista (pedidos *pedido,int *numpedidos,transportistas *transportista){
	char pedi;
	printf("Introduzca el identificador del pedido a asignar transportista: ");
	scanf("%s",pedi);
	int i;
	for(i=0;i<*numpedidos;i++){
		if(strcmp(pedido[i].id_pedido,pedi)==0){
			break;
		}
	}
	printf("Introduzca el identificador del transportista: ");
	scanf("%s",transportista[i].id_transp);
	printf("Introduzca el nombre del transportista: ");
	scanf("%s",transportista[i].nombre);
	printf("Introduzca el email del transportista: ");
	scanf("%s",transportista[i].email);
	printf("Introduzca la empresa del transportista: ");
	scanf("%s",transportista[i].empresa);
	printf("Introduzca la ciudad en que opera del transportista: ");
	scanf("%s",transportista[i].ciudad);
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
			ModificarPedidoPropioTransportista();
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




    
