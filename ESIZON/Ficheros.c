//realizar las funciones de Ficheros.h

#include "Ficheros.h"
#include "Structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargarclientes(clientes *clientes, int *numclientes)
{
    //el formato del fichero es: 0000001-Juan Pérez-Plaza San Francisco 1 11100-San FernandoCádiz-juanperez@gmail.com-psw1234-1000
    //cada campo está separado por un guión
    //typedef struct{
    //char id_cliente[8];
    //char nombre[21];
    //char direccion[51];
    //char localidad[21];
    //char provincia[21];
    //char email[31];
    //char password[16];
    //int cartera;
    //} clientes;
    FILE *fichero; 
    //poner ruta del fichero completa
    fichero = fopen("clientes.txt", "r");
    if (!fichero)
    {
        printf("Error al abrir el fichero de clientes\n");
        exit(1);
    }
    char linea[300];
    while (fgets(linea, 200, fichero))
    {
        sscanf(linea, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%i\n", clientes[*numclientes].id_cliente, clientes[*numclientes].nombre, clientes[*numclientes].direccion, clientes[*numclientes].localidad, clientes[*numclientes].provincia, clientes[*numclientes].email, clientes[*numclientes].password, &clientes[*numclientes].cartera);
        (*numclientes)++;
        //imprimir el contenido de la línea
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