#ifndef _INICIOSESION_H_
#define _INICIOSESION_H_
#include "Structs.h"

int iniciosesion(clientes* cliente, int numclientes, int* id ,admin_prov* adminprov, int numadminprov, transportistas* transportista, int numtransportistas );// esto es un prototipo
void registrarPerfilCliente(clientes * cliente,int *numclientes); // hay que poner el provtraps o como se llame
void registrarPerfilProv(admin_prov * admin, int *numprov); // hay que poner el provtraps o como se llame
void registrarPerfilTransport(transportistas* transportista, int *numtransportistas); // hay que poner el numtraps o como se llame

#endif // _INICIOSESION_