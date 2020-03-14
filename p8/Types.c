//
// Autor: Erick González
// Matrícula: A01039859
// Fecha: 13/03/2020
//
// Obtiene el valor y el tamaño de espacio que ocupan diferentes tipos de datos.

#include <stdio.h>
#include <float.h>
#include <string.h>

union Input {
    int Integer;
    char Char[100];
    double Double;
};
// Función principal
int main(void)
{
    union Input I;
    //Lee un integer
    printf("Enter an integer:\n");
    scanf("%d", &I.Integer);
    //Despliega el espacio de almacenamiento de un integer
    printf("Your integer %i storage size is %lu bytes.\n", I.Integer, sizeof(I.Integer));
    //Lee un character
    printf("Enter a string:\n");
    scanf(" %s", &I.Char);
    //Despliega el espacio de almacenamiento de un char y sus valores respectivos como char y como valor ASCII
    printf("Your array of chars %s storage size is %lu bytes. And I can read it as %s or as %d. \n", I.Char, sizeof(I.Char), I.Char, I.Char);
    //Lee un double
    printf("Enter a double:\n");
    scanf(" %lf", &I.Double);
    //Despliega el espacio de almacenamiento de un double y los valores min y max positivos
    printf("Your double %lf storage size is %lu bytes, I can read any number from %.10e to %.10e in this data type.  \n", I.Double, sizeof(I.Double), DBL_MIN, DBL_MAX);

    return 0;
}