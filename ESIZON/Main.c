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
    //hacer una prueba de cargar y guardar clientes
    clientes clientes[100];
    int numclientes = 0;
    cargarclientes(clientes, &numclientes);
    printf("\nEl numero de clientes es: %d\n", numclientes);
    guardarclientes(clientes, numclientes);
    return 0;
 }