//
// Autor: Erick González
// Matrícula: A01039859
// Fecha: 18/02/2020
//
// Cambia el valor de los apuntadores
#include <stdio.h>
#include <string.h>

#define MAX 50
//funcion principal
int main(void)
{
    //declaración de variables

    char string[MAX];
    //Lee el input
    fgets(string, MAX, stdin);
    int c = 0;
    //Recorre el string
    while (string[c] != '\0')
    {
        switch (string[c])
        {
        case 'A':
        case 'a':
            string[c] = '4';
            break;
        case 'E':
        case 'e':
            string[c] = '3';
            break;
        case 'I':
        case 'i':
            string[c] = '1';
            break;
        case 'O':
        case 'o':
            string[c] = '0';
            break;
        case 'U':
        case 'u':
            string[c] = '2';
            break;
        default:
            break;
        }
        printf("%c", string[c]);
        c++;
    }
    return 0;
}