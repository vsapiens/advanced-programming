//
// Autor: Erick González
// Matrícula: A01039859
// Fecha: 21/02/2020
//
// Obtiene el factorial de un número hasta N

#include <stdio.h>
//Función de fibonacci recursiva
int factorial(int fac)
{
    if (fac <= 1)
        return 1;

    return fac * factorial(fac - 1);
}
//Función principal
int main(void)
{
    //Declaración de variables
    int numFac;
    //Pedir el numero al usuario
    printf("Enter the nth term of Factorial: ");
    scanf("%d", &numFac);
    //Impresión de los números de factorial
    printf("Factorial of %d = %d ", numFac, factorial(numFac));
    printf("\n");

    return 0;
}