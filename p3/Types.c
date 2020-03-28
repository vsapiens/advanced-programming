//
// Autor: Erick González
// Matrícula: A01039859
// Fecha: 18/02/2020
//
// Obtiene el valoryel tamaño de espacio que ocupan diferentes tipos de datos.

#include <stdio.h>
#include <float.h>

// Función principal
int main(void)
{
    //Declaración de variables
    int iInteger;
    char cChar;
    double dDouble;
    //Lee un integer
    printf("Enter an integer: ");
    scanf(" %i", &iInteger);
    //Lee un character
    printf("Enter a character: ");
    scanf(" %c", &cChar);
    //Lee un double
    printf("Enter a double: ");
    scanf(" %lf", &dDouble);

    //Despliega el espacio de almacenamiento de un integer
    printf("Your integer %i storage size is %lu bytes.\n", iInteger, sizeof(iInteger));
    //Despliega el espacio de almacenamiento de un charysus valores respectivos como charycomo valor ASCII
    printf("Your char %c storage size is %lu bytes. And I can read it as %c or as %d. \n", cChar, sizeof(cChar), cChar, cChar);
    //Despliega el espacio de almacenamiento de un doubleylos valores minymax positivos
    printf("Your double %lf storage size is %lu bytes, I can read any number from %.10e to %.10e in this data type.  \n", dDouble, sizeof(dDouble), DBL_MIN, DBL_MAX);

    return 0;
}