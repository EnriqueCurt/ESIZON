//Main del proyecto
//terminal en español
#include "Ficheros.c"
#include "Structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "Menus.c"
#include "Menus.h"


 int main()
 {
    setlocale(LC_ALL, "spanish");                          
    SetConsoleOutputCP(1252);  //para que se muestren bien los caracteres especiales en la consola
    SetConsoleCP(1252); //para que se muestren bien los caracteres especiales en la consola

    clientes clientes[100];
    int numclientes = 0;

    transportistas transportistas[100];
    int numtransportistas = 0;

    productos productos[100];
    int numproductos = 0;


    categorias categorias[100];
    int numcategorias = 0;

    descuentos descuentos[100];
    int numdescuentos = 0;

    productos_pedidos productos_pedidos[100];
    int numproductos_pedido = 0;

    descuentos_clientes descuentosclientes[100];
    int numdescuentosclientes = 0;

    lockers lockers[100];
    int numlockers = 0;

    compartimentos_lockers compartimentoslockers[100];
    int numcompartimentoslockers = 0;

    admin_prov admin_prov[100];
    int numadmin_prov = 0;

    pedidos pedidos[100];
    int numpedidos = 0;

    devoluciones devoluciones[100];
    int numdevoluciones = 0;


    cargarTodo(clientes, &numclientes, transportistas, &numtransportistas, productos_pedidos, &numproductos_pedido, productos, &numproductos, categorias, &numcategorias, descuentos, &numdescuentos, descuentosclientes, &numdescuentosclientes, lockers, &numlockers, compartimentoslockers, &numcompartimentoslockers, admin_prov, &numadmin_prov, pedidos, &numpedidos, devoluciones, &numdevoluciones);
  
    printf("\nEl numero de descuentosclientes es: %d\n", numdescuentosclientes); //esto es solo para pruebas
    printf("\nEl numero de lockers es: %d\n", numlockers); //esto es solo para pruebas
    printf("\nEl numero de compartimentoslockers es: %d\n", numcompartimentoslockers); //esto es solo para pruebas
    printf("\nEl numero de admin_prov es: %d\n", numadmin_prov); //esto es solo para pruebas
    printf("\nEl numero de pedidos es: %d\n", numpedidos); //esto es solo para pruebas
    printf("\nEl numero de devoluciones es: %d\n", numdevoluciones); //esto es solo para pruebas
    system("pause");
    system("cls");
    
    menuInicial(clientes, &numclientes, transportistas, &numtransportistas, productos_pedidos, &numproductos_pedido, productos, &numproductos, categorias, &numcategorias, descuentos, &numdescuentos, descuentosclientes, &numdescuentosclientes, lockers, &numlockers, compartimentoslockers, &numcompartimentoslockers, admin_prov, &numadmin_prov, pedidos, &numpedidos, devoluciones, &numdevoluciones);
    printf("Gracias por usar\n\n");
    printf(" _____ ____ ___ ________  _   _ \n");
    printf("| ____/ ___|_ _|__  / _ \\| \\ | |\n");
    printf("|  _| \\___ \\| |  / / | | |  \\| |\n");
    printf("| |___ ___) | | / /| |_| | |\\  |\n");
    printf("|_____|____/___/____\\___/|_| \\_|\n\n\n");
    system("pause");

    guardarTodo(clientes, numclientes, transportistas, numtransportistas, productos_pedidos, numproductos_pedido, productos, numproductos, categorias, numcategorias, descuentos, numdescuentos, descuentosclientes, numdescuentosclientes, lockers, numlockers, compartimentoslockers, numcompartimentoslockers, admin_prov, numadmin_prov, pedidos, numpedidos, devoluciones, numdevoluciones);


  return 0;
 }

