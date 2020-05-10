//
// Autor: Erick González
// Matrícula: A01039859
// Fecha: 27/03/2020
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DecimalDegrees
{
    double lat, longit;
    char clat[16], clongit[16];
};
void swap(struct DecimalDegrees *xp, struct DecimalDegrees *yp)
{
    struct DecimalDegrees temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(struct DecimalDegrees arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {

        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j].lat < arr[min_idx].lat)
                min_idx = j;

        // Swap the found minimum element
        // with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

void changeF(char *s)
{
    size_t i = strlen(s);
    char c = s[i - 1];
    s[i - 1] = ' ';
    switch (c)
    {
    case 'N':
        strcat(s, "North");
        break;
    case 'W':
        strcat(s, "West");
        break;
    case 'S':
        strcat(s, "South");
        break;
    case 'E':
        strcat(s, "East");
        break;
    default:
        break;
    }
}
int main(void)
{
    FILE *coord, *degrees, *decimal, *start;
    struct DecimalDegrees dd[100];

    int count = 0;
    coord = fopen("coordinates_utf8.txt", "r");
    degrees = fopen("degrees.txt", "w+");
    decimal = fopen("decimal.txt", "w+");

    start = coord;

    if (coord == NULL || degrees == NULL || decimal == NULL)
    {
        printf("Error!");
        exit(1);
    }
    char dec1[16], degree1[15], dec2[16], degree2[15];

    while (fscanf(coord, "%*s %s %s\n", dec1, degree1) == 2)
    {
        if (fscanf(coord, "%*s %s %s\n", dec2, degree2) == 2)
        {
            dd[count].lat = atof(degree1);
            dd[count].longit = atof(degree2);
            changeF(&dec1);
            changeF(&dec2);
            fprintf(degrees, "%s %s\n", dec1, dec2);
            count++;
        }
    }
    int n = sizeof(dd) / sizeof(dd[0]);
    selectionSort(dd, n);
    for (int i = 0; i < 100; i++)
    {
        fprintf(decimal, "%lf  %lf\n", dd[i].lat, dd[i].longit);
        //fprintf(degrees, "%s %s\n", dd[i].clat, dd[i].clongit);
    }

    fclose(coord);
    fclose(degrees);
    fclose(decimal);
    return 0;
}