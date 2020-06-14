#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

int menuInformes();
void informar(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void informarEmpleadosXAnio(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void informarEmpleadosVarones(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void informarTotalSueldos(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void informarEmpleadoSector(eEmpleado empleados[], int tam, eSector sectores[], int tamsec);
void informarEmpleadoXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamsec);
void informarTotalSueldosSetor(eEmpleado empleados[], int tam, eSector sectores[], int tamsec);
void informarMayorSueldoSector(eEmpleado empleados[], int tam, eSector sectores[], int tamsec);
void informarMayorSueldoEmpleadoSector(eEmpleado empleados[], int tam, eSector sectores[], int tamsec);
void aumentarSueldosSectorPorcentaje(eEmpleado empleados[], int tam, eSector sectores[], int tamsec);

void sectorQueMasCobra(eEmpleado empleados[], int tam, eSector sectores[], int tamsec);
//float obtenerTotalSueldosSector(int idSector, eEmpleado empleados[], int tam);
float obtenerTotalSueldosSector(eEmpleado empleados[], int tam, int idSector);
