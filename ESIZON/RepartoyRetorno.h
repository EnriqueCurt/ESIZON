#ifndef REPARTOYRETORNO_H
#define REPARTOYRETORNO_H
#include "Structs.h"
void TransportistaReparto(transportistas *transportista, int numtransportistas, productos_pedidos *productos_pedidos, int numproductos_pedido, productos *productos, int numproductos, pedidos *pedidos, int numpedidos, lockers *lockers, int numlockers, compartimentos_lockers *compartimentoslockers, int numcompartimentoslockers,devoluciones *devoluciones, int numdevoluciones, int transportistaid);
void listarEntregasAsignadas(pedidos *pedidos, int numpedidos, productos_pedidos *productos_pedidos, int numproductos_pedido, productos *productos, int numproductos, transportistas *transportistas, int numtransportistas, int transportistaid);
void realizarEntregaDomicilio(productos_pedidos *productos_pedidos, int numproductos_pedido, productos *productos, int numproductos, pedidos *pedidos, int numpedidos, devoluciones *devoluciones, int numdevoluciones);
void entregaNoPosible(productos_pedidos *productos_pedidos, int numproductos_pedido, productos *productos, int numproductos, pedidos *pedidos, int numpedidos, devoluciones *devoluciones, int numdevoluciones);
void realizarEntregaLocker(productos_pedidos *productos_pedidos, int numproductos_pedido, productos *productos, int numproductos, pedidos *pedidos, int numpedidos, lockers *lockers, int numlockers, compartimentos_lockers *compartimentoslockers, int numcompartimentoslockers);
void retornoTransportista(transportistas *transportista, int numtransportistas, productos_pedidos *productos_pedidos, int numproductos_pedido, productos *productos, int numproductos, pedidos *pedidos, int numpedidos, lockers *lockers, int numlockers, compartimentos_lockers *compartimentoslockers, int numcompartimentoslockers, devoluciones *devoluciones, int numdevoluciones, int transportistaid);
void consultarLockersLocalidad(lockers *lockers, int numlockers,compartimentos_lockers *compartimentoslockers, int numcompartimentoslockers);
void realizarRetornoProductos(productos_pedidos *productos_pedidos, int numproductos_pedido, productos *productos, int numproductos, lockers *lockers, int numlockers, compartimentos_lockers *compartimentoslockers, int numcompartimentoslockers);



#endif