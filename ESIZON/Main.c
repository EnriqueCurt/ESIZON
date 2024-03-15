//Main del proyecto
//terminal en español
#include "Ficheros.c"
#include "Structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


 int main()
 {
  setlocale(LC_ALL, "spanish");
  descuentos_clientes descuentosclientes[100];
  int numdescuentosclientes = 0;

  cargardescuentosclientes(descuentosclientes, &numdescuentosclientes);
  printf("\nEl numero de descuentosclientes es: %d\n", numdescuentosclientes); //esto es solo para pruebas
  guardardescuentosclientes(descuentosclientes, numdescuentosclientes);

  lockers lockers[100];
  int numlockers = 0;

  cargarlockers(lockers, &numlockers);
  printf("\nEl numero de lockers es: %d\n", numlockers); //esto es solo para pruebas
  guardarlockers(lockers, numlockers);

  compartimentos_lockers compartimentoslockers[100];
  int numcompartimentoslockers = 0;

  cargarcompartimentoslockers(compartimentoslockers, &numcompartimentoslockers);
  printf("\nEl numero de compartimentoslockers es: %d\n", numcompartimentoslockers); //esto es solo para pruebas
  guardarcompartimentoslockers(compartimentoslockers, numcompartimentoslockers);

  admin_prov admin_prov[100];
  int numadmin_prov = 0;

  cargaradmin_prov(admin_prov, &numadmin_prov);
  printf("\nEl numero de admin_prov es: %d\n", numadmin_prov); //esto es solo para pruebas
  guardaradmin_prov(admin_prov, numadmin_prov);

  pedidos pedidos[100];
  int numpedidos = 0;

  cargarpedidos(pedidos, &numpedidos);
  printf("\nEl numero de pedidos es: %d\n", numpedidos); //esto es solo para pruebas
  guardarpedidos(pedidos, numpedidos);

  devoluciones devoluciones[100];
  int numdevoluciones = 0;

  cargardevoluciones(devoluciones, &numdevoluciones);
  printf("\nEl numero de devoluciones es: %d\n", numdevoluciones); //esto es solo para pruebas
  guardardevoluciones(devoluciones, numdevoluciones);
  

  



  return 0;
 }

