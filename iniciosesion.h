#ifndef _INICIOSESION_
#define _INICIOSESION_
#include "struct_ficheros.h"
#include "Registro.h"

int iniciosesion(cliente* cliente, int* id ,admin_prov* adminprov, transportista* transportista ) // esto es un prototipo
void registarPerfilCliente(cliente * cliente, int id) // hay que poner el provtraps o como se llame
void registrarPerfilProv(admin_prov * admin, int id, int numprov) // hay que poner el provtraps o como se llame
void registrarPerfilTransport(transportista* transportista, int id) // hay que poner el numtraps o como se llame
