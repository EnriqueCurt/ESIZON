#ifndef DESCUENTOS_H
#define DESCUENTOS_H
#include "Structs.h"

void listarDescuentosCliente(descuentos_clientes *descuentosclientes, int numdescuentosclientes,int id);
void GestionarDescuentosAdmin(descuentos *descuentos, int *numdescuentos, descuentos_clientes *descuentosclientes, int *numdescuentosclientes, int numclientes);
void altaDescuento(descuentos *descuentos, int *numdescuentos,descuentos_clientes *descuentosclientes, int *numdescuentosclientes, int numclientes);
void bajaDescuento(descuentos *descuentos, int *numdescuentos);
void busquedaDescuento(descuentos *descuentos, int numdescuentos);
void listarDescuentos(descuentos *descuentos, int numdescuentos);
void listarClientesConDescuentos(descuentos_clientes *descuentosclientes, int numdescuentosclientes);
void listarClientesConDescuentosUsados(descuentos_clientes *descuentosclientes, int numdescuentosclientes);
void asignarDescuentoCliente(descuentos_clientes *descuentosclientes, int *numdescuentosclientes);


#endif // DESCUENTOS_H