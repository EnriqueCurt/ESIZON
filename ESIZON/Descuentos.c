#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "Descuentos.h"

void listarDescuentosCliente(descuentos_clientes *descuentosclientes, int numdescuentosclientes,int id)
{
    system("cls");
    char cadena[8];
    sprintf(cadena, "%08d", id+1);
    int i;
    for(i=0; i<numdescuentosclientes; i++)
    {
        if(strcmp(descuentosclientes[i].id_cliente, cadena)==0)
        {
            printf("\nID del cliente: %s", descuentosclientes[i].id_cliente);
            printf("\nID del codigo de descuento: %s", descuentosclientes[i].id_cod);
            printf("\nFecha de asignacion: %s", descuentosclientes[i].fecha_asignacion);
            printf("\nFecha de caducidad: %s", descuentosclientes[i].fecha_caducidad);
            printf("\nEstado: %d", descuentosclientes[i].estado);
        }
    }

}

void GestionarDescuentosAdmin(descuentos *descuentos, int *numdescuentos, descuentos_clientes *descuentosclientes, int *numdescuentosclientes, int numclientes)
{
    /* Mediante el menú correspondiente podrá realizar altas, bajas, búsquedas, listados y
    modificaciones de estos descuentos.
    • Además también podrá generar los listados de clientes que tienen asignado algún cheque
        regalo/código promocional, así como los listados de clientes que han hecho uso de algún
        cheque regalo/código promocional.
    • Por supuesto podrá asignar a un cliente determinado un cheque regalo.
    • En el caso de la creación de un nuevo código promocional, éste deberá ser asignado a todos
        los clientes.*/

    system("cls");
    int opcion;
    do
    {
        system("cls");
        printf("\n1. Realizar alta de descuento");
        printf("\n2. Realizar baja de descuento");
        printf("\n3. Realizar busqueda de descuento");
        printf("\n4. Listar descuentos");
        printf("\n5. Listar descuentos de un cliente");
        printf("\n6. Listar clientes con descuentos");
        printf("\n7. Listar clientes que han hecho uso de un descuento");
        printf("\n8. Asignar descuento a un cliente");
        printf("\n10. Salir");
        printf("\n\nIntroduzca una opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                altaDescuento(descuentos, numdescuentos, descuentosclientes, numdescuentosclientes, numclientes);
                break;
            case 2:
                bajaDescuento(descuentos, numdescuentos);
                break;
            case 3:
                busquedaDescuento(descuentos, *numdescuentos);
                break;
            case 4:
                listarDescuentos(descuentos, *numdescuentos);
                break;
            case 5:
                printf("\nIntroduzca el id del cliente: ");
                int id;
                scanf("%d", &id);
                listarDescuentosCliente(descuentosclientes, *numdescuentosclientes, id);
                break;
            case 6:
                listarClientesConDescuentos(descuentosclientes, *numdescuentosclientes);
                break;
            case 7:
                listarClientesConDescuentosUsados(descuentosclientes, *numdescuentosclientes);
                break;
            case 8:
                asignarDescuentoCliente(descuentosclientes, numdescuentosclientes);
                break;
            case 9:
            system("cls");
                break;
            default:
                system("cls");
                printf("\nOpcion no valida");
                system("pause");
                break;
        }
    }while(opcion!=9);
}

void altaDescuento(descuentos *descuentos, int *numdescuentos,descuentos_clientes *descuentosclientes, int *numdescuentosclientes, int numclientes)
{
    system("cls");
    char cadena[11];
    int tipo_descuento;
    sprintf(cadena, "%05d", (*numdescuentos)+1);
    strcpy(descuentos[*numdescuentos].id_cod,cadena);
    gets(descuentos[*numdescuentos].id_cod);
    printf("\nIntroduzca la descripcion del descuento: ");
    fflush(stdin);
    gets(descuentos[*numdescuentos].descrip);
    printf("\nPulse uno si desea un codigo promocional o dos si desea un cheque regalo:");
    fflush(stdin);
    scanf("%d", &tipo_descuento);
    if(tipo_descuento==1)
    {
        strcpy(descuentos[*numdescuentos].tipo, "cod pro");
        int id_descuento= (*numdescuentos)+1;
        void asignarTodosClientes(descuentos_clientes *descuentosclientes, int *numdescuentosclientes, int numclientes, int id_descuento);
    }
    else
    {
        strcpy(descuentos[*numdescuentos].tipo, "cheq reg");
    }
    printf("\nIntroduzca el estado del descuento: ");
    fflush(stdin);
    gets(descuentos[*numdescuentos].estado);
    printf("\nIntroduzca el importe del descuento: ");
    fflush(stdin);
    scanf("%d", &descuentos[*numdescuentos].importe);
    printf("\nIntroduzca el tipo de aplicacion del descuento: ");
    fflush(stdin);
    gets(descuentos[*numdescuentos].aplicable);
    (*numdescuentos)++;
}

void bajaDescuento(descuentos *descuentos, int *numdescuentos)
{
    system("cls");
    char cadena[11];
    printf("\nIntroduzca el id del descuento a dar de baja: ");
    fflush(stdin);
    gets(cadena);
    int i;  
    //cambiar el estado a baja
    for(i=0; i<*numdescuentos; i++)
    {
        if(strcmp(descuentos[i].id_cod, cadena)==0)
        {
            strcpy(descuentos[i].estado, "inactivo");
        }
    }
}

void busquedaDescuento(descuentos *descuentos, int numdescuentos)
{
    system("cls");
    char cadena[11];
    int id;
    printf("\nIntroduzca el id del descuento a buscar: ");
    fflush(stdin);
    scanf("%d", &id);
    sprintf(cadena, "%011d", id);
    int i;
    for(i=0; i<numdescuentos; i++)
    {
        if(strcmp(descuentos[i].id_cod, cadena)==0)
        {
            printf("\nID del descuento: %s", descuentos[i].id_cod);
            printf("\nDescripcion del descuento: %s", descuentos[i].descrip);
            printf("\nTipo del descuento: %s", descuentos[i].tipo);
            printf("\nEstado del descuento: %s", descuentos[i].estado);
            printf("\nImporte del descuento: %d", descuentos[i].importe);
            printf("\nTipo de aplicacion del descuento: %s", descuentos[i].aplicable);
        }
    }
}

void listarDescuentos(descuentos *descuentos, int numdescuentos)
{
    system("cls");
    int i;
    for(i=0; i<numdescuentos; i++)
    {
        printf("\nID del descuento: %s", descuentos[i].id_cod);
        printf("\nDescripcion del descuento: %s", descuentos[i].descrip);
        printf("\nTipo del descuento: %s", descuentos[i].tipo);
        printf("\nEstado del descuento: %s", descuentos[i].estado);
        printf("\nImporte del descuento: %d", descuentos[i].importe);
        printf("\nTipo de aplicacion del descuento: %s", descuentos[i].aplicable);
    }
}

void listarClientesConDescuentos(descuentos_clientes *descuentosclientes, int numdescuentosclientes)
{
    system("cls");
    int i;
    for(i=0; i<numdescuentosclientes; i++)
    {
        printf("\nID del cliente: %s", descuentosclientes[i].id_cliente);
        printf("\nID del codigo de descuento: %s", descuentosclientes[i].id_cod);
        printf("\nFecha de asignacion: %s", descuentosclientes[i].fecha_asignacion);
        printf("\nFecha de caducidad: %s", descuentosclientes[i].fecha_caducidad);
        printf("\nEstado: %d", descuentosclientes[i].estado);
    }
}

void listarClientesConDescuentosUsados(descuentos_clientes *descuentosclientes, int numdescuentosclientes)
{
    system("cls");
    int i;
    for(i=0; i<numdescuentosclientes; i++)
    {
        if(descuentosclientes[i].estado==1)
        {
            printf("\nID del cliente: %s", descuentosclientes[i].id_cliente);
            printf("\nID del codigo de descuento: %s", descuentosclientes[i].id_cod);
            printf("\nFecha de asignacion: %s", descuentosclientes[i].fecha_asignacion);
            printf("\nFecha de caducidad: %s", descuentosclientes[i].fecha_caducidad);
            printf("\nEstado: %d", descuentosclientes[i].estado);
        }
    }
}
void asignarDescuentoCliente(descuentos_clientes *descuentosclientes, int *numdescuentosclientes)
{
    system("cls");
    char cadena[8];
    int id_cliente;
    int id_descuento;
    printf("\nIntroduzca el id del cliente al que asignar el descuento: ");
    fflush(stdin);
    scanf("%d", &id_cliente);
    sprintf(cadena, "%08d", id_cliente);
    printf("\nIntroduzca el id del descuento a asignar: ");
    fflush(stdin);
    scanf("%d", &id_descuento);
    char cadena2[11];
    sprintf(cadena2, "%011d", id_descuento);
    strcpy(descuentosclientes[*numdescuentosclientes].id_cliente, cadena);
    strcpy(descuentosclientes[*numdescuentosclientes].id_cod, cadena2);
    printf("\nIntroduzca la fecha de asignacion: ");
    fflush(stdin);
    gets(descuentosclientes[*numdescuentosclientes].fecha_asignacion);
    printf("\nIntroduzca la fecha de caducidad: ");
    fflush(stdin);
    gets(descuentosclientes[*numdescuentosclientes].fecha_caducidad);
    descuentosclientes[*numdescuentosclientes].estado = 0;
    (*numdescuentosclientes)++;
}

void asignarTodosClientes(descuentos_clientes *descuentosclientes, int *numdescuentosclientes, int numclientes, int id_descuento)
{
    system("cls");
    char cadena_cod[11];
    char cadena_cliente[8];
    sprintf(cadena_cod, "%011d", id_descuento);

    int i;
    for(i=0; i<numclientes; i++)
    {
        sprintf(cadena_cliente, "%08d", i+1);
        strcpy(descuentosclientes[*numdescuentosclientes].id_cliente, cadena_cliente);
        strcpy(descuentosclientes[*numdescuentosclientes].id_cod, cadena_cod);
        printf("\nIntroduzca la fecha de asignacion: ");
        fflush(stdin);
        gets(descuentosclientes[*numdescuentosclientes].fecha_asignacion);
        printf("\nIntroduzca la fecha de caducidad: ");
        fflush(stdin);
        gets(descuentosclientes[*numdescuentosclientes].fecha_caducidad);
        descuentosclientes[*numdescuentosclientes].estado = 0;
        (*numdescuentosclientes)++;
    }
}

