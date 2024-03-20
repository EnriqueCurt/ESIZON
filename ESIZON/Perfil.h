//Mostrar los diferentes perfiles de usuario

#ifndef PERFIL_H
#define PERFIL_H
#include "Structs.h"

void mostrarPerfilCliente(clientes *cliente, int id);
void mostrarPerfilAdmin_Prov(admin_prov *admin, int id);
//void mostrarPerfilTransportista(transportistas *transportista, int id);
void modificarPerfilCliente(clientes *cliente, int id);
void modificarPerfilAdmin_Prov(admin_prov *admin, int id);
//void modificarPerfilTransportista(transportistas *transportista, int id);

#endif // PERFIL_H