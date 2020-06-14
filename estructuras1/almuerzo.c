#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "almuerzo.h"


void inicializarAlmuerzos(eAlmuerzo vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

//---------------------------------------------------------------------------------------------------

int buscarLibreAlmuerzo (eAlmuerzo vec[], int tam)
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

//---------------------------------------------------------------------------------------------------

void listarAlmuerzos(eAlmuerzo almuerzos[], int tamal, eComida comidas[], int tamcom, eEmpleado empleados[], int tamEmp)
{
    int flag = 0;

    system("cls");
    printf("*** Listado almuerzos ***\n");
    printf("   Id      Id Empleado     Nombre      Comida       Fecha\n");

    for(int i=0; i<tamal; i++)
    {
        if(almuerzos[i].isEmpty == 0)
        {
            listarAlmuerzo(almuerzos[i], comidas, tamcom, empleados, tamEmp);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("No hay almuerzos que mostrar\n");
    }
    printf("\n");
}

//---------------------------------------------------------------------------------------------------

int altaAlmuerzo(int idAlmuerzo, eAlmuerzo almuerzos[], int tamAl, eEmpleado empleados[], int tamEmp, eSector sectores[], int tamSec, eComida comidas[], int tamCom)
{
    int todoOk = 0;
    eAlmuerzo nuevoAlmuerzo;
    int indice;

    system("cls");
    printf("***** Alta almuerzo *****\n\n");

    indice = buscarLibreAlmuerzo(almuerzos, tamAl);

    if(indice == -1)
    {
        printf("Sistema completo no se pueden dar almuerzos de alta\n");
    }
    else
    {
        mostrarEmpleados(empleados, tamEmp, sectores, tamSec);
        printf("Ingrese id empleado: ");
        scanf("%d", &nuevoAlmuerzo.idEmpleado);

        listarComidas(comidas, tamCom);
        printf("Ingrese id comida: ");
        scanf("%d", &nuevoAlmuerzo.idComida);

        printf("Ingrese fecha dd/mm/aaaa: ");
        scanf("%d/%d/%d", &nuevoAlmuerzo.fecha.dia, &nuevoAlmuerzo.fecha.mes, &nuevoAlmuerzo.fecha.anio);

        nuevoAlmuerzo.id = idAlmuerzo;
        nuevoAlmuerzo.isEmpty = 0;

        almuerzos[indice] = nuevoAlmuerzo;

        todoOk = 1;

        printf("\nAlta almuerzo exitosa!!!");

    }

    return todoOk;
}

//---------------------------------------------------------------------------------------------------

int cargarDescripcionComida(char descripcion[], int id, eComida comidas[], int tam)
{
    int todoOk = 0;

    for(int i=0; i<tam; i++)
    {
        if(comidas[i].id == id)
        {
            strcpy(descripcion, comidas[i].descripcion);
            todoOk = 1;
        }
    }
    return todoOk;
}

//---------------------------------------------------------------------------------------------------

int cargarNombreEmpleado(char nombre[], int id, eEmpleado empleados[], int tam)
{
    int todoOk = 0;

    for(int i=0; i<tam; i++)
    {
        if(empleados[i].id == id && empleados[i].isEmpty == 0)
        {
            strcpy(nombre, empleados[i].nombre);
            todoOk = 1;
        }
    }
    return todoOk;
}

//---------------------------------------------------------------------------------------------------

void listarAlmuerzo(eAlmuerzo almuerzo, eComida comidas[], int tamcom, eEmpleado empleados[], int tamEmp)
{
    char descComida[20];
    char nombreEmpleado[20];

    cargarDescripcionComida(descComida, almuerzo.idComida, comidas, tamcom);
    cargarNombreEmpleado(nombreEmpleado, almuerzo.idEmpleado, empleados, tamEmp);
    printf("   %d    %d   %10s   %10s     %d/%d/%d\n", almuerzo.id, almuerzo.idEmpleado, nombreEmpleado, descComida, almuerzo.fecha.dia, almuerzo.fecha.mes, almuerzo.fecha.anio);
}
