#include <stdio.h>

void fibonacci(int fib)
{

    int fibSequence[2];
    fibSequence[0] = 0;
    fibSequence[1] = 1;
    int i = 0;
    while (i <= fib - 1)
    {
        fibSequence[i % 2] = fibSequence[1] + fibSequence[0];
        ++i;
        printf(" %d ", fibSequence[i % 2]);
    }
    printf("\n");
}

int main(void)
{
    int numFib;
    printf("Enter the nth term of Fibonacci: ");
    scanf("%d", &numFib);

    fibonacci(numFib);

    return 0;
}