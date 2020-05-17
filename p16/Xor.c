//
// Autor: Erick González
// Matrícula: A01039859
// Fecha: 15/05/2020
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *in, *out;

    int curr;
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w+");
    fscanf(in, "%d", &curr);
    while (curr--)
    {
        int num, a, v;
        int s = 0;

        fscanf(in, "%d", &num);
        while (num--)
        {
            fscanf(in, "%d %d", &a, &v);
            s += a - v;
        }
        fprintf(out, "%d\n", s);
    }
    fclose(in);
    fclose(out);
    return 0;
}