//realizar las funciones de Ficheros.h

#include "Ficheros.h"
#include "Structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargarclientes(clientes *clientes, int *numclientes)
{
    
    FILE *fichero; 
    fichero = fopen("clientes.txt", "r");
    if (!fichero)
    {
        printf("Error al abrir el fichero de clientes\n");
        exit(1);
    }
    char linea[300];
    while (fgets(linea, 200, fichero))
    {    //formato a leer
        sscanf(linea, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%i\n", clientes[*numclientes].id_cliente, clientes[*numclientes].nombre, clientes[*numclientes].direccion, clientes[*numclientes].localidad, clientes[*numclientes].provincia, clientes[*numclientes].email, clientes[*numclientes].password, &clientes[*numclientes].cartera);
        (*numclientes)++;
        //imprimir el contenido de la línea, esto es solo para pruebas
        printf("%s", linea);
    }
    fclose(fichero);
}

void guardarclientes(clientes *clientes, int numclientes){
    FILE *fichero;
    fichero = fopen("clientes.txt", "w");
    if (!fichero)
    {
        printf("Error al abrir el fichero de clientes\n");
        exit(1);
    }
    for (int i = 0; i < numclientes; i++)
    {
        fprintf(fichero, "%s-%s-%s-%s-%s-%s-%s-%i\n", clientes[i].id_cliente, clientes[i].nombre, clientes[i].direccion, clientes[i].localidad, clientes[i].provincia, clientes[i].email, clientes[i].password, clientes[i].cartera);
    }
    fclose(fichero);
}
//realiza la funcion de cargartransportistas
// el formato de linea es: 0001-Rafael Gutierrez-rafael@gutitrans.com-rf001-GutiTrans-Cadiz
void cargartransportistas(transportistas *transportistas, int *numtransportistas)
{
    
    FILE *fichero; 
    fichero = fopen("transportistas.txt", "r");
    if (!fichero)
    {
        printf("Error al abrir el fichero de transportistas\n");
        exit(1);
    }
    char linea[300];
    while (fgets(linea, 200, fichero))
    {    //formato a leer
        sscanf(linea, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]\n", transportistas[*numtransportistas].id_transp, transportistas[*numtransportistas].nombre, transportistas[*numtransportistas].email, transportistas[*numtransportistas].password, transportistas[*numtransportistas].empresa, transportistas[*numtransportistas].ciudad);
        (*numtransportistas)++;
        //imprimir el contenido de la línea, esto es solo para pruebas
        printf("%s", linea);
    }
    fclose(fichero);
}

//realiza la funcion de guardartransportistas
// el formato de linea es: 0001-Rafael Gutierrez-rafael@gutitrans.com-rf001-GutiTrans-Cadiz
void guardartransportistas(transportistas *transportistas, int numtransportistas){
    FILE *fichero;
    fichero = fopen("transportistas.txt", "w");
    if (!fichero)
    {
        printf("Error al abrir el fichero de transportistas\n");
        exit(1);
    }
    for (int i = 0; i < numtransportistas; i++)
    {
        fprintf(fichero, "%s-%s-%s-%s-%s-%s", transportistas[i].id_transp, transportistas[i].nombre, transportistas[i].email, transportistas[i].password, transportistas[i].empresa, transportistas[i].ciudad);
    }
    fclose(fichero);
}
//funcion cargarproductos_pedidos
// en caso de el estado sea enPreparacion o enviado el formato de linea es: 0000001-000001-1-07/03/2024-340-enPreparacion
// en caso de el estado sea enReparto o enLocker el formato de linea es: 0000002-000001-2-08/02/2024-45-enLocker-0002-Lock001-134697-08/02/2024
//en el caso que el estado sea entregado o devuelto el formato de linea es: 0000001-000002-1-03/02/2024-45-entregado-0001

void cargarproductos_pedidos(productos_pedidos *productos_pedidos, int *numproductos_pedido)
{
    
    FILE *fichero; 
    fichero = fopen("productosPedidos.txt", "r");
    if (!fichero)
    {
        printf("Error al abrir el fichero de productos_pedidos\n");
        exit(1);
    }
    char linea[300];
    while (fgets(linea, 200, fichero))
    {    //formato a leer
        if (strstr(linea, "enPreparacion") || strstr(linea, "enviado"))
        {
            sscanf(linea, "%[^-]-%[^-]-%i-%[^-]-%i-%[^-]", productos_pedidos[*numproductos_pedido].id_pedido, productos_pedidos[*numproductos_pedido].id_prod, &productos_pedidos[*numproductos_pedido].num_unid, productos_pedidos[*numproductos_pedido].fecha_entrega, &productos_pedidos[*numproductos_pedido].importe, productos_pedidos[*numproductos_pedido].estado);
        }
        else if (strstr(linea, "enReparto") || strstr(linea, "enLocker"))
        {
            sscanf(linea, "%[^-]-%[^-]-%i-%[^-]-%i-%[^-]-%[^-]-%[^-]-%i-%[^-]", productos_pedidos[*numproductos_pedido].id_pedido, productos_pedidos[*numproductos_pedido].id_prod, &productos_pedidos[*numproductos_pedido].num_unid, productos_pedidos[*numproductos_pedido].fecha_entrega, &productos_pedidos[*numproductos_pedido].importe, productos_pedidos[*numproductos_pedido].estado, productos_pedidos[*numproductos_pedido].id_transp, productos_pedidos[*numproductos_pedido].id_locker, &productos_pedidos[*numproductos_pedido].cod_locker, productos_pedidos[*numproductos_pedido].fecha_entrega_devolucion);
        }
        else if (strstr(linea, "entregado") || strstr(linea, "devuelto"))
        {
            sscanf(linea, "%[^-]-%[^-]-%i-%[^-]-%i-%[^-]-%[^-]", productos_pedidos[*numproductos_pedido].id_pedido, productos_pedidos[*numproductos_pedido].id_prod, &productos_pedidos[*numproductos_pedido].num_unid, productos_pedidos[*numproductos_pedido].fecha_entrega, &productos_pedidos[*numproductos_pedido].importe, productos_pedidos[*numproductos_pedido].estado, productos_pedidos[*numproductos_pedido].id_transp);
        }
        (*numproductos_pedido)++;
        //imprimir el contenido de la línea, esto es solo para pruebas
        printf("%s", linea);
    }
    fclose(fichero);
}

//funcion guardarproductos_pedidos
// en caso de el estado sea enPreparacion o enviado el formato de linea es: 0000001-000001-1-07/03/2024-340-enPreparacion
// en caso de el estado sea enReparto o enLocker el formato de linea es: 0000002-000001-2-08/02/2024-45-enLocker-0002-Lock001-134697-08/02/2024
//en el caso que el estado sea entregado o devuelto el formato de linea es: 0000001-000002-1-03/02/2024-45-entregado-0001
void guardarproductos_pedidos(productos_pedidos *productos_pedidos, int numproductos_pedido){
    FILE *fichero;
    fichero = fopen("ProductosPedidos.txt", "w");
    if (!fichero)
    {
        printf("Error al abrir el fichero de productos_pedidos\n");
        exit(1);
    }
    for (int i = 0; i < numproductos_pedido; i++)
    {
        if (strstr(productos_pedidos[i].estado, "enPreparacion") || strstr(productos_pedidos[i].estado, "enviado"))
        {
            fprintf(fichero, "%s-%s-%i-%s-%i-%s", productos_pedidos[i].id_pedido, productos_pedidos[i].id_prod, productos_pedidos[i].num_unid, productos_pedidos[i].fecha_entrega, productos_pedidos[i].importe, productos_pedidos[i].estado);
        }
        else if (strstr(productos_pedidos[i].estado, "enReparto") || strstr(productos_pedidos[i].estado, "enLocker"))
        {
            fprintf(fichero, "%s-%s-%i-%s-%i-%s-%s-%s-%i-%s", productos_pedidos[i].id_pedido, productos_pedidos[i].id_prod, productos_pedidos[i].num_unid, productos_pedidos[i].fecha_entrega, productos_pedidos[i].importe, productos_pedidos[i].estado, productos_pedidos[i].id_transp, productos_pedidos[i].id_locker, productos_pedidos[i].cod_locker, productos_pedidos[i].fecha_entrega_devolucion);
        }
        else if (strstr(productos_pedidos[i].estado, "entregado") || strstr(productos_pedidos[i].estado, "devuelto"))
        {
            fprintf(fichero, "%s-%s-%i-%s-%i-%s-%s", productos_pedidos[i].id_pedido, productos_pedidos[i].id_prod, productos_pedidos[i].num_unid, productos_pedidos[i].fecha_entrega, productos_pedidos[i].importe, productos_pedidos[i].estado, productos_pedidos[i].id_transp);
        }
    }
    fclose(fichero);
}

//funcion cargarproductos
//el formato de linea es : 0000001-televisor 32” 3D-0001-0001-50-5-340

void cargarproductos(productos *productos, int *numproductos)
{
    
    FILE *fichero; 
    fichero = fopen("Productos.txt", "r");
    if (!fichero)
    {
        printf("Error al abrir el fichero de productos\n");
        exit(1);
    }
    char linea[300];
    while (fgets(linea, 200, fichero))
    {    //formato a leer
        sscanf(linea, "%[^-]-%[^-]-%[^-]-%[^-]-%i-%i-%i", productos[*numproductos].id_prod, productos[*numproductos].descrip, productos[*numproductos].id_categ, productos[*numproductos].id_gestor, &productos[*numproductos].stock, &productos[*numproductos].entrega, &productos[*numproductos].importe);
        (*numproductos)++;
        //imprimir el contenido de la línea, esto es solo para pruebas
        printf("%s", linea);
    }
    fclose(fichero);
}

//funcion guardarproductos
//el formato de linea es : 0000001-televisor 32” 3D-0001-0001-50-5-340
void guardarproductos(productos *productos, int numproductos){
    FILE *fichero;
    fichero = fopen("Productos.txt", "w");
    if (!fichero)
    {
        printf("Error al abrir el fichero de productos\n");
        exit(1);
    }
    for (int i = 0; i < numproductos; i++)
    {
        fprintf(fichero, "%s-%s-%s-%s-%i-%i-%i\n", productos[i].id_prod, productos[i].descrip, productos[i].id_categ, productos[i].id_gestor, productos[i].stock, productos[i].entrega, productos[i].importe);
    }
    fclose(fichero);
}

//funcion cargarcategorias
//el formato de linea es : 0001-tv video home cinema

void cargarcategorias(categorias *categorias, int *numcategorias)
{
    
    FILE *fichero; 
    fichero = fopen("Categorias.txt", "r");
    if (!fichero)
    {
        printf("Error al abrir el fichero de categorias\n");
        exit(1);
    }
    char linea[300];
    while (fgets(linea, 200, fichero))
    {    //formato a leer
        sscanf(linea, "%[^-]-%[^-]", categorias[*numcategorias].id_categ, categorias[*numcategorias].descrip);
        (*numcategorias)++;
        //imprimir el contenido de la línea, esto es solo para pruebas
        printf("%s", linea);
    }
    fclose(fichero);
}

//funcion guardarcategorias
//el formato de linea es : 0001-tv video home cinema

void guardarcategorias(categorias *categorias, int numcategorias){
    FILE *fichero;
    fichero = fopen("Categorias.txt", "w");
    if (!fichero)
    {
        printf("Error al abrir el fichero de categorias\n");
        exit(1);
    }
    for (int i = 0; i < numcategorias; i++)
    {
        fprintf(fichero, "%s-%s", categorias[i].id_categ, categorias[i].descrip);
    }
    fclose(fichero);
}

//funcion cargardescuentos
//el formato de linea es : black001-Black Friday-codpro-activo-10-esizon

void cargardescuentos(descuentos *descuentos, int *numdescuentos)
{
    
    FILE *fichero; 
    fichero = fopen("Descuentos.txt", "r");
    if (!fichero)
    {
        printf("Error al abrir el fichero de descuentos\n");
        exit(1);
    }
    char linea[300];
    while (fgets(linea, 200, fichero))
    {    //formato a leer
        sscanf(linea, "%[^-]-%[^-]-%[^-]-%[^-]-%i-%s", descuentos[*numdescuentos].id_cod, descuentos[*numdescuentos].descrip, descuentos[*numdescuentos].tipo, descuentos[*numdescuentos].estado, &descuentos[*numdescuentos].importe, descuentos[*numdescuentos].aplicable);
        (*numdescuentos)++;
        //imprimir el contenido de la línea, esto es solo para pruebas
        printf("%s", linea);
    }
    fclose(fichero);
}

//funcion guardardescuentos
//el formato de linea es : black001-Black Friday-codpro-activo-10-esizon

void guardardescuentos(descuentos *descuentos, int numdescuentos){
    FILE *fichero;
    fichero = fopen("Descuentos.txt", "w");
    if (!fichero)
    {
        printf("Error al abrir el fichero de descuentos\n");
        exit(1);
    }
    for (int i = 0; i < numdescuentos; i++)
    {
        fprintf(fichero, "%s-%s-%s-%s-%i-%s\n", descuentos[i].id_cod, descuentos[i].descrip, descuentos[i].tipo, descuentos[i].estado, descuentos[i].importe, descuentos[i].aplicable);
    }
    fclose(fichero);
}

//funcion cargardescuentosclientes
//el formato de linea es : 0000001-black001-25/01/2024-27/03/2024-0

void cargardescuentosclientes(descuentos_clientes *descuentosclientes, int *numdescuentosclientes)
{
    
    FILE *fichero; 
    fichero = fopen("DescuentosClientes.txt", "r");
    if (!fichero)
    {
        printf("Error al abrir el fichero de descuentosclientes\n");
        exit(1);
    }
    char linea[300];
    while (fgets(linea, 200, fichero))
    {    //formato a leer
        sscanf(linea, "%[^-]-%[^-]-%[^-]-%[^-]-%i", descuentosclientes[*numdescuentosclientes].id_cliente, descuentosclientes[*numdescuentosclientes].id_cod, descuentosclientes[*numdescuentosclientes].fecha_asignacion, descuentosclientes[*numdescuentosclientes].fecha_caducidad, &descuentosclientes[*numdescuentosclientes].estado);
        (*numdescuentosclientes)++;
        //imprimir el contenido de la línea, esto es solo para pruebas
        printf("%s", linea);
    }
    fclose(fichero);
}

//funcion guardardescuentosclientes
//el formato de linea es : 0000001-black001-25/01/2024-27/03/2024-0

void guardardescuentosclientes(descuentos_clientes *descuentosclientes, int numdescuentosclientes){
    FILE *fichero;
    fichero = fopen("DescuentosClientes.txt", "w");
    if (!fichero)
    {
        printf("Error al abrir el fichero de descuentosclientes\n");
        exit(1);
    }
    for (int i = 0; i < numdescuentosclientes; i++)
    {
        fprintf(fichero, "%s-%s-%s-%s-%i\n", descuentosclientes[i].id_cliente, descuentosclientes[i].id_cod, descuentosclientes[i].fecha_asignacion, descuentosclientes[i].fecha_caducidad, descuentosclientes[i].estado);
    }
    fclose(fichero);
}

//funcion cargarlockers
//el formato de linea es: Lock001-Puerto Real-Cádiz-local 12-15-0

void cargarlockers(lockers *lockers, int *numlockers)
{
    
    FILE *fichero; 
    fichero = fopen("Lockers.txt", "r");
    if (!fichero)
    {
        printf("Error al abrir el fichero de lockers\n");
        exit(1);
    }
    char linea[300];
    while (fgets(linea, 200, fichero))
    {    //formato a leer
        sscanf(linea, "%[^-]-%[^-]-%[^-]-%[^-]-%i-%i", lockers[*numlockers].id_locker, lockers[*numlockers].localidad, lockers[*numlockers].provincia, lockers[*numlockers].ubicacion, &lockers[*numlockers].num_compT, &lockers[*numlockers].num_compOcup);
        (*numlockers)++;
        //imprimir el contenido de la línea, esto es solo para pruebas
        printf("%s", linea);
    }
    fclose(fichero);
}

//funcion guardarlockers
//el formato de linea es: Lock001-Puerto Real-Cádiz-local 12-15-0

void guardarlockers(lockers *lockers, int numlockers){
    FILE *fichero;
    fichero = fopen("Lockers.txt", "w");
    if (!fichero)
    {
        printf("Error al abrir el fichero de lockers\n");
        exit(1);
    }
    for (int i = 0; i < numlockers; i++)
    {
        fprintf(fichero, "%s-%s-%s-%s-%i-%i\n", lockers[i].id_locker, lockers[i].localidad, lockers[i].provincia, lockers[i].ubicacion, lockers[i].num_compT, lockers[i].num_compOcup);
    }
    fclose(fichero);
}

//funcion cargarcompartimentoslockers
//el formato de linea es: Lock001-01-134697-ocupado-08/01/2024-13/03/2024

void cargarcompartimentoslockers(compartimentos_lockers *compartimentoslockers, int *numcompartimentoslockers)
{
    
    FILE *fichero; 
    fichero = fopen("CompartimentosLockers.txt", "r");
    if (!fichero)
    {
        printf("Error al abrir el fichero de compartimentoslockers\n");
        exit(1);
    }
    char linea[300];
    while (fgets(linea, 200, fichero))
    {    //formato a leer
        sscanf(linea, "%[^-]-%i-%[^-]-%[^-]-%[^-]-%[^-]", compartimentoslockers[*numcompartimentoslockers].id_locker, &compartimentoslockers[*numcompartimentoslockers].num_comp, &compartimentoslockers[*numcompartimentoslockers].cod_locker, compartimentoslockers[*numcompartimentoslockers].estado, compartimentoslockers[*numcompartimentoslockers].fecha_ocupacion, compartimentoslockers[*numcompartimentoslockers].fecha_caducidad);
        (*numcompartimentoslockers)++;
        //imprimir el contenido de la línea, esto es solo para pruebas
        printf("%s", linea);
    }
    fclose(fichero);
}

//funcion guardarcompartimentoslockers
//el formato de linea es: Lock001-01-134697-ocupado-08/01/2024-13/03/2024

void guardarcompartimentoslockers(compartimentos_lockers *compartimentoslockers, int numcompartimentoslockers){
    FILE *fichero;
    fichero = fopen("CompartimentosLockers.txt", "w");
    if (!fichero)
    {
        printf("Error al abrir el fichero de compartimentoslockers\n");
        exit(1);
    }
    for (int i = 0; i < numcompartimentoslockers; i++)
    {
        fprintf(fichero, "%s-%02i-%s-%s-%s-%s", compartimentoslockers[i].id_locker, compartimentoslockers[i].num_comp, compartimentoslockers[i].cod_locker, compartimentoslockers[i].estado, compartimentoslockers[i].fecha_ocupacion, compartimentoslockers[i].fecha_caducidad);
    }
    fclose(fichero);
}

//funcion cargaradmin_prov
//el formato de linea es: 0001-ESIZON-antonio.martin@esizon.com-antmar01-administrador

void cargaradmin_prov(admin_prov *admin_prov, int *numadmin_prov)
{
    
    FILE *fichero; 
    fichero = fopen("AdminProv.txt", "r");
    if (!fichero)
    {
        printf("Error al abrir el fichero de admin_prov\n");
        exit(1);
    }
    char linea[300];
    while (fgets(linea, 200, fichero))
    {    //formato a leer
        sscanf(linea, "%[^-]-%[^-]-%[^-]-%[^-]-%s", admin_prov[*numadmin_prov].id_empresa, admin_prov[*numadmin_prov].nombre, admin_prov[*numadmin_prov].email, admin_prov[*numadmin_prov].password, admin_prov[*numadmin_prov].perfil_usuario);
        (*numadmin_prov)++;
        //imprimir el contenido de la línea, esto es solo para pruebas
        printf("%s", linea);
    }
    fclose(fichero);
}

//funcion guardaradmin_prov
//el formato de linea es: 0001-ESIZON-antonio.martin@esizon.com-antmar01-administrador

void guardaradmin_prov(admin_prov *admin_prov, int numadmin_prov){
    FILE *fichero;
    fichero = fopen("AdminProv.txt", "w");
    if (!fichero)
    {
        printf("Error al abrir el fichero de admin_prov\n");
        exit(1);
    }
    for (int i = 0; i < numadmin_prov; i++)
    {
        fprintf(fichero, "%s-%s-%s-%s-%s\n", admin_prov[i].id_empresa, admin_prov[i].nombre, admin_prov[i].email, admin_prov[i].password, admin_prov[i].perfil_usuario);
    }
    fclose(fichero);
}

//funcion cargarpedidos
//el formato de linea es si pone domicilio: 0000001-02/02/2024-0000001-domicilio-che001
//el formatoque pone locker:0000002-03/02/2024-0000002-locker-Lock001

void cargarpedidos(pedidos *pedidos, int *numpedidos)
{
    
    FILE *fichero; 
    fichero = fopen("Pedidos.txt", "r");
    if (!fichero)
    {
        printf("Error al abrir el fichero de pedidos\n");
        exit(1);
    }
    char linea[300];
    while (fgets(linea, 200, fichero))
    {    //formato a leer
        if (strstr(linea, "domicilio"))
        {
            sscanf(linea, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]", pedidos[*numpedidos].id_pedido, pedidos[*numpedidos].fecha_pedido, pedidos[*numpedidos].id_cliente, pedidos[*numpedidos].lugar, pedidos[*numpedidos].id_cod);
        }
        else if (strstr(linea, "locker"))
        {
            sscanf(linea, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]", pedidos[*numpedidos].id_pedido, pedidos[*numpedidos].fecha_pedido, pedidos[*numpedidos].id_cliente, pedidos[*numpedidos].lugar, pedidos[*numpedidos].id_locker);
        }
        (*numpedidos)++;
        //imprimir el contenido de la línea, esto es solo para pruebas
        printf("%s", linea);
    }
    fclose(fichero);
}

//funcion guardarpedidos
//el formato de linea es si pone domicilio: 0000001-02/02/2024-0000001-domicilio-che001
//el formatoque pone locker:0000002-03/02/2024-0000002-locker-Lock001

void guardarpedidos(pedidos *pedidos, int numpedidos){
    FILE *fichero;
    fichero = fopen("Pedidos.txt", "w");
    if (!fichero)
    {
        printf("Error al abrir el fichero de pedidos\n");
        exit(1);
    }
    for (int i = 0; i < numpedidos; i++)
    {
        if (strstr(pedidos[i].lugar, "domicilio"))
        {
            fprintf(fichero, "%s-%s-%s-%s-%s", pedidos[i].id_pedido, pedidos[i].fecha_pedido, pedidos[i].id_cliente, pedidos[i].lugar, pedidos[i].id_cod);
        }
        else if (strstr(pedidos[i].lugar, "locker"))
        {
            fprintf(fichero, "%s-%s-%s-%s-%s", pedidos[i].id_pedido, pedidos[i].fecha_pedido, pedidos[i].id_cliente, pedidos[i].lugar, pedidos[i].id_locker);
        }
    }
    fclose(fichero);
}

//funcion cargardevoluciones
//en el caso de que este aceptado el formato de linea es: 0000001-0000001-25/02/2024-desperfecto-aceptado-25/02/2024-25/03/2024
//en el resto de casos el formato de linea es: 0000002-0000001-25/02/2024-desperfecto-pendiente

void cargardevoluciones(devoluciones *devoluciones, int *numdevoluciones)
{
    
    FILE *fichero; 
    fichero = fopen("Devoluciones.txt", "r");
    if (!fichero)
    {
        printf("Error al abrir el fichero de devoluciones\n");
        exit(1);
    }
    char linea[300];
    while (fgets(linea, 200, fichero))
    {    //formato a leer
        if (strstr(linea, "aceptado"))
        {
            sscanf(linea, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]", devoluciones[*numdevoluciones].id_pedido, devoluciones[*numdevoluciones].id_prod, devoluciones[*numdevoluciones].fecha_devolucion, devoluciones[*numdevoluciones].motivo, devoluciones[*numdevoluciones].estado, devoluciones[*numdevoluciones].fecha_aceptacion, devoluciones[*numdevoluciones].fecha_caducidad);
        }
        else
        {
            sscanf(linea, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]", devoluciones[*numdevoluciones].id_pedido, devoluciones[*numdevoluciones].id_prod, devoluciones[*numdevoluciones].fecha_devolucion, devoluciones[*numdevoluciones].motivo, devoluciones[*numdevoluciones].estado);
        }
        (*numdevoluciones)++;
        //imprimir el contenido de la línea, esto es solo para pruebas
        printf("%s", linea);
    }
    fclose(fichero);
}

//funcion guardardevoluciones
//en el caso de que este aceptado el formato de linea es: 0000001-0000001-25/02/2024-desperfecto-aceptado-25/02/2024-25/03/2024
//en el resto de casos el formato de linea es: 0000002-0000001-25/02/2024-desperfecto-pendiente

void guardardevoluciones(devoluciones *devoluciones, int numdevoluciones){
    FILE *fichero;
    fichero = fopen("Devoluciones.txt", "w");
    if (!fichero)
    {
        printf("Error al abrir el fichero de devoluciones\n");
        exit(1);
    }
    for (int i = 0; i < numdevoluciones; i++)
    {
        if (strstr(devoluciones[i].estado, "aceptado"))
        {
            fprintf(fichero, "%s-%s-%s-%s-%s-%s-%s", devoluciones[i].id_pedido, devoluciones[i].id_prod, devoluciones[i].fecha_devolucion, devoluciones[i].motivo, devoluciones[i].estado, devoluciones[i].fecha_aceptacion, devoluciones[i].fecha_caducidad);
        }
        else
        {
            fprintf(fichero, "%s-%s-%s-%s-%s", devoluciones[i].id_pedido, devoluciones[i].id_prod, devoluciones[i].fecha_devolucion, devoluciones[i].motivo, devoluciones[i].estado);
        }
    }
    fclose(fichero);
}

void cargarTodo(clientes *clientes, int *numclientes, transportistas *transportistas, int *numtransportistas, productos_pedidos *productos_pedidos, int *numproductos_pedido, productos *productos, int *numproductos, categorias *categorias, int *numcategorias, descuentos *descuentos, int *numdescuentos, descuentos_clientes *descuentosclientes, int *numdescuentosclientes, lockers *lockers, int *numlockers, compartimentos_lockers *compartimentoslockers, int *numcompartimentoslockers, admin_prov *admin_prov, int *numadmin_prov, pedidos *pedidos, int *numpedidos, devoluciones *devoluciones, int *numdevoluciones)
{
    cargarclientes(clientes, numclientes);
    cargartransportistas(transportistas, numtransportistas);
    cargarproductos_pedidos(productos_pedidos, numproductos_pedido);
    cargarproductos(productos, numproductos);
    cargarcategorias(categorias, numcategorias);
    cargardescuentos(descuentos, numdescuentos);
    cargardescuentosclientes(descuentosclientes, numdescuentosclientes);
    cargarlockers(lockers, numlockers);
    cargarcompartimentoslockers(compartimentoslockers, numcompartimentoslockers);
    cargaradmin_prov(admin_prov, numadmin_prov);
    cargarpedidos(pedidos, numpedidos);
    cargardevoluciones(devoluciones, numdevoluciones);

}
void guardarTodo(clientes *clientes, int numclientes, transportistas *transportistas, int numtransportistas, productos_pedidos *productos_pedidos, int numproductos_pedido, productos *productos, int numproductos, categorias *categorias, int numcategorias, descuentos *descuentos, int numdescuentos, descuentos_clientes *descuentosclientes, int numdescuentosclientes, lockers *lockers, int numlockers, compartimentos_lockers *compartimentoslockers, int numcompartimentoslockers, admin_prov *admin_prov, int numadmin_prov, pedidos *pedidos, int numpedidos, devoluciones *devoluciones, int numdevoluciones){
    guardarclientes(clientes, numclientes);
    guardartransportistas(transportistas, numtransportistas);
    guardarproductos_pedidos(productos_pedidos, numproductos_pedido);
    guardarproductos(productos, numproductos);
    guardarcategorias(categorias, numcategorias);
    guardardescuentos(descuentos, numdescuentos);
    guardardescuentosclientes(descuentosclientes, numdescuentosclientes);
    guardarlockers(lockers, numlockers);
    guardarcompartimentoslockers(compartimentoslockers, numcompartimentoslockers);
    guardaradmin_prov(admin_prov, numadmin_prov);
    guardarpedidos(pedidos, numpedidos);
    guardardevoluciones(devoluciones, numdevoluciones);
}