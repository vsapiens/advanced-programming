//
// Autor: Erick González
// Matrícula: A01039859
// Fecha: 29/05/2020
//
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include <time.h>
//Single threaded 
void singleThreaded()
{
    printf("Single Threaded Calculation of Pi\n");
    time_t init = clock();

    long double dx = 0.0001, A = 0, x = -1;
    while (x < 1)
    {
        A = A + sqrt(1 - pow(x, 2)) * dx;
        x += dx;
    }
    time_t limit = clock();

    printf("The approximation of pi is: %.15Lf\n", A * 2);
    printf("Time elapsed: %.5f\n", (double)(limit - init) / CLOCKS_PER_SEC);
}
//Multi threaded
void multiThreaded()
{
    printf("Multi Threaded Calculation of Pi\n");
    time_t init = clock();

    long double dx = 0.001, A = 0,x,dy,diff;
    int count;

#pragma omp parallel
    {
#pragma omp for private(x, count, dy,diff) reduction(+:A)
        for (count = 0; count < 1000; count++)
        {
            x = count * dx;
            dy = sqrt(1.0 - x * x);
            diff = dx * dy;
            A += diff;
        }
    }
    time_t limit = clock();
    printf("The approximation of pi is: %.15Lg\n", A*4);
    printf("Time elapsed: %.5f\n", (double)(limit - init) / CLOCKS_PER_SEC);
}
int main()
{

    singleThreaded();
    multiThreaded();
    return 0;
}