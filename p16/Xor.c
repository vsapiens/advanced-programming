//
// Autor: Erick González
// Matrícula: A01039859
// Fecha: 27/03/2020
//
#include <stdio.h>

int main()
{
    int curr;
    scanf("%d", &curr);
    while (curr--)
    {
        int num, a, v;
        int s = 0;

        scanf("%d", &num);
        while (num--)
        {
            scanf("%d %d", &a, &v);
            s += a - v;
        }
        printf("%d\n", s);
    }
    return 0;
}