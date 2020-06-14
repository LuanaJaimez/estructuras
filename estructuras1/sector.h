#ifndef SECTOR_H_INCLUDED
#define SECTOR_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

}eSector;

/*Tambien se pueden definir como
struct eEmpleado{

int id;
char nombre[20];
int edad;
char sexo;
float sueldo;

};

En el main se declararia como
struct eEmpleado unEmpleado;
*/

#endif // SECTOR_H_INCLUDED

void mostrarSectores(eSector sectores[], int tam);
