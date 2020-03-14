//
// Autor: Erick González
// Matrícula: A01039859
// Fecha: 21/02/2020
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <stdbool.h>
//Estructura de misión
const int CONST_MAX = 50;
struct Mission
{
    int iDigits;
    char cIdentifier[3];
};
//Estructura de ASSET
struct Asset
{
    int iDigits;
    char cIdentifier[4];
};
struct Agent
{
    char sName[50];
    char sLastName[50];
    int iAge;
    struct Mission mMission;
};

int main(void)
{
    char option;
    //printf("Opening secure connection to Agent Database...\n");
    do
    {
        printf(" Introduzca la letra de su opción:\n");
        printf("\ta) Crear Nueva Entrada\n");
        printf("\tb) Eliminar una Entrada\n");
        printf("\tc) Salir\n");
        scanf(" %c", &option);
        switch (option)
        {
        case 'a':
            /* code */
            break;
        case 'b':
            /* code */
            break;
        case 'c':
            /* code */
            break;
        case 'd':
            //printf("Closing Connection...\n");
            break;
        default:
            break;
        }
    } while (strncmp(&option, "d", 2));

    return 0;
}