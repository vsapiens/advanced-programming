
//
// Autor: Erick González
// Matrícula: A01039859
// Fecha: 13/03/2020
//
// Obtiene el valor de diferentes valores de diferentes bases y demás
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//Funcion para convertir de binario a int
int asciiBinaryToInt(char *s)
{
    for (size_t i = strlen(s); i < strlen(s) ;i++){
        if(s[i] - '0' != 1 || s[i] - '0' != 0){
            return -1;
        }
    }
    return (int)strtol(s, NULL, 2);
}
//Funcion para convertir de HEX a int
int asciiHEXToInt(char *s){

    for (size_t i = strlen(s); i < strlen(s); i++)
    {
        if (!(s[i] >= 65 || s[i] <= 90) || !(s[i] >= 96 || s[i] <= 122) || s[i] - '0' != 1 || s[i] - '0' != 0)
        {
            return -1;
        }
    }
    return (int)strtol(s, NULL, 16);
}
//Funcion para convertir de un número a double
void asciiToDouble(char *s)
{
    size_t i = 0;
    size_t dot = 0;
    char sign = ' ';
    char withSign[strlen(s) + 1];

    if (s[0] == '+' || s[0] == '-')
    {
        i = strlen(s) + 1;
        sign = s[0];
    }
    else
    {
        i = strlen(s);
    }
    for (; i < strlen(s); i++)
    {
        if ( s[i] < 48 || s[i] > 57)
        {
            printf("Verify the input\n");
            return;
        }
    }
    if (sign == ' ' ||  sign == '-')
    {
        printf("\nResult => Number: %s\n \tDouble Precision Number: %f\n\n", s, (double)strtod(s, NULL));
    }
    else{
        strncpy(withSign, s,(int) strlen(s));
        printf("\nResult => Number: %s\n \tDouble Precision Number: %c%f\n\n", s, sign,(double)strtod(withSign, NULL));
    }
}
//Union de INput para majear la entrada de datos
union Input {
    char data[256];
} input;
//Funcion principal
int main(void)
{
    long long n;
    printf("Select an option\n");
    char option;
    //Manejo de diferentes tipos de formatos
    while (strncmp("d", &option, 1) != 0)
    {
        //Menu
        printf("a) Binary to Int\n");
        printf("b) HEX to Int\n");
        printf("c) Number to Double\n");
        scanf(" %c", &option);
        //Cambiar de opcion
        switch (option)
        {
        case 'a':
            printf("Enter a Binary Number\n");
            scanf("%s",&input.data);
            if (asciiBinaryToInt(input.data) != -1)
            {
                printf("\nResult => Binary Number: %s\n \tInt Number: %d\n\n", input.data, asciiBinaryToInt(input.data));
            } else {
                printf("Verify the input\n");
            }
            break;
        case 'b':
            printf("Enter a Hex Number\n");
            scanf("%s", &input.data);
            if (asciiBinaryToInt(input.data) != -1)
            {
                printf("\nResult => Hex Number: %s\n \tInt Number: %d\n\n", input.data, asciiHEXToInt(input.data));
            }
            else
            {
                printf("Verify the input\n");
            }
            break;
        case 'c':
            printf("Enter a Number\n");
            scanf("%s", &input.data);
            asciiToDouble(input.data);
            break;

        default:
            break;
        }
    }
    return 0;
}