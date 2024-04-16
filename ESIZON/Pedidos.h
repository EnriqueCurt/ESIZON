#ifndef PEDIDOS_H
#define PEDIDOS_H
#include "Structs.h"

void ClientePedidos(pedidos *pedidos, int numpedidos);
void AdminPedidos(pedidos *pedidos, int *numpedidos);
void ProveedorPedidos(pedidos *pedidos, int *numpedidos, admin_prov *admin, int id);

#endif
