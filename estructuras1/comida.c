#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comida.h"

void listarComidas(eComida comidas[], int tam)
{
    printf("*** Listado comidas ***\n");
    printf("   Id  Descripcion   Precio\n");

    for(int i=0; i<tam; i++)
    {
        printf("   %d  %10s  %5.2f\n", comidas[i].id, comidas[i].descripcion, comidas[i].precio);
    }
    printf("\n");
}




