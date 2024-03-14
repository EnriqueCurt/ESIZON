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