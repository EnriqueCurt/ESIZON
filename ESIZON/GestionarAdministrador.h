#ifndef GESTIONARADMINISTRADOR_H
#define GESTIONARADMINISTRADOR_H
#include "Structs.h"

void GestionarClientes(clientes *clientes, int *numclientes);
void eliminarPerfilCliente(clientes *clientes, int *numclientes, int id);
void listarClientes(clientes *clientes, int *numclientes);
void GestionarProveedores(admin_prov *provedores, int *numprovedores);
void eliminarPerfilProveedor(admin_prov *provedores, int *numprovedores, int id);
void listarProveedores(admin_prov *provedores, int *numprovedores);
void GestionarTransportistas(transportistas *transportistas, int *numtransportistas);
void eliminarPerfilTransportista(transportistas *transportistas, int *numtransportistas, int id);
void listarTransportistas(transportistas *transportistas, int *numtransportistas);
void GestionarCategoria(categorias *categorias, int *numcategorias);
void registrarCategoria(categorias *categorias, int *numcategorias);
void eliminarCategoria(categorias *categorias, int *numcategorias, int id);
void listarCategorias(categorias *categorias, int *numcategorias);
void consultarCategoria(categorias *categorias, int *numcategorias);
void modificarCategoria(categorias *categorias,int id);
#endif