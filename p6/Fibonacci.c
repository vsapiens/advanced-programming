//
// Autor: Erick González
// Matrícula: A01039859
// Fecha: 21/02/2020
//
// Obtiene la serie de fibonacci hasta N

#include <stdio.h>
//Función de fibonacci recursiva
int fibonacci(int fib)
{

    if (fib == 0)
        return 0;

    if (fib == 1)
        return 1;

    return fibonacci(fib - 1) + fibonacci(fib - 2);
}
//Función principal
int main(void)
{
    //Declaración de variables
    int numFib;
    //Pedir el numero al usuario
    printf("Enter the nth term of Fibonacci: ");
    scanf("%d", &numFib);
    //Impresión de los números de fibonacci
    for (int i = 0; i < numFib; ++i)
    {
        printf(" %d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}