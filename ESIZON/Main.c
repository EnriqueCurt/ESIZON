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
    clientes clientes[100];
    int numclientes = 0;
    cargarclientes(clientes, &numclientes);
    printf("\nEl numero de clientes es: %d\n", numclientes); //esto es solo para pruebas
    guardarclientes(clientes, numclientes);
    return 0;
 }