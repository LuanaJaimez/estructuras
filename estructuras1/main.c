#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "sector.h"
#include "informes.h"
#include "comida.h"
#include "almuerzo.h"

#define TAM 10
#define TAMSEC 5
#define TAMCOM 5
#define TAMAL 50
#define CANTHARDCODE 5

int menu();

int main()
{
    char seguir = 's';
    char confirma;
    int proximoId = 1000;
    int proximoIdAlmuerzo = 20000;
    eEmpleado lista[TAM];
    eSector sectores[TAMSEC] =
    {
        {1, "Sistemas"},
        {2, "RRHH"},
        {3, "Ventas"},
        {4, "Compras"},
        {5, "Contable"}
    };
    eComida comidas[TAMCOM] =
    {
        {100, "Milanesa", 150},
        {102, "Fideos", 120},
        {103, "Pizza", 140},
        {104, "Ensalada", 200},
        {105, "Arroz", 135}
    };
    eAlmuerzo almuerzos[TAMAL];

    inicializarEmpleados(lista, TAM);
    inicializarAlmuerzos(almuerzos, TAMAL);

    hardcodearEmpleados(lista, CANTHARDCODE);
    proximoId += CANTHARDCODE;
    //-----------------------------

    do{
        switch(menu())
        {
        case 1:
            if(altaEmpleado(proximoId, lista, TAM, sectores, TAMSEC) == 1)
            {
                proximoId++;
            }
            break;
        case 2:
            modificarEmpleado(lista, TAM, sectores, TAMSEC);
            break;
        case 3:
            bajaEmpleado(lista, TAM, sectores, TAMSEC);
            break;
        case 4:
            printf("Ordenar\n");
            break;
        case 5:
            system("cls");
            mostrarEmpleados(lista, TAM, sectores, TAMSEC);
            break;
        case 6:
            informar(lista, TAM, sectores, TAMSEC);
            break;
        case 7:
            if(altaAlmuerzo(proximoIdAlmuerzo, almuerzos, TAMAL, lista, TAM, sectores, TAMSEC, comidas, TAMCOM) == 1)
            {
                proximoIdAlmuerzo++;
            }
            break;
        case 8:
            listarAlmuerzos(almuerzos, TAMAL, comidas, TAMCOM, lista, TAM);
            break;
        case 10:
            printf("Confirme salida: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;
        }

        system("pause");

    }while(seguir == 's');

    return 0;
}

//---------------------------------------------------------------------------------------------------

int menu()
{
    int opcion;

    system("cls");
    printf("***** Gestion de Empleados *****\n\n");
    printf("1. Alta Empleados\n");
    printf("2. Modificar Empleados\n");
    printf("3. Baja Empleados\n");
    printf("4. Ordenar Empleados\n");
    printf("5. Listar Empleados\n");
    printf("6. Informes\n");
    printf("7. Alta almuerzo\n");
    printf("8. Listar almuerzos\n");
    printf("10. Salir\n");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}


