//
// Autor: Erick González
// Matrícula: A01039859
// Fecha: 27/03/2020
//
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
//Shift del string
char *shiftString(char *str, int shiftBy)
{
    char *buff = malloc((sizeof(char) * shiftBy) + 1);
    int i = 0;
    strncpy(buff, str, shiftBy);
    buff[shiftBy] = '\0';
    while (str[i + shiftBy] != '\0')
    {
        str[i] = str[i + shiftBy];
        str[i + shiftBy] = '\0';
        i++;
    }
    strcat(str, buff);
    return str;
}
//Borrar espacios en blanco
void deleteblankspaces(char *s)
{
    int i, k = 0;

    for (i = 0; s[i]; i++)
    {
        s[i] = s[i + k];

        if (s[i] == ' ' || s[i] == '\t')
        {
            k++;
            i--;
        }
    }
}
//estructura de agente
struct Agent
{
    char identifier[4];
    char data[1000];
};
//Funcion principal
int main(void)
{
    char *found;
    char data[1000];
    struct Agent *a = (struct Agent *)malloc(sizeof(struct Agent));
    printf("Inserte los números de identificador\n");
    gets(data);
    deleteblankspaces(data);
    found = strtok(data, ",");

    printf("Inserte los identificadores\n");
    gets(a->identifier);
    while (found)
    {
        if (!strcmp(found, "uno"))
        {
            strcat(a->data, "1");
        }
        else if (!strcmp(found, "dos"))
        {
            strcat(a->data, "2");
        }
        else if (!strcmp(found, "tres"))
        {
            strcat(a->data, "3");
        }
        else if (!strcmp(found, "cuatro"))
        {
            strcat(a->data, "4");
        }
        else if (!strcmp(found, "cinco"))
        {
            strcat(a->data, "5");
        }
        else if (!strcmp(found, "seis"))
        {
            strcat(a->data, "6");
        }
        else if (!strcmp(found, "siete"))
        {
            strcat(a->data, "7");
        }
        else if (!strcmp(found, "ocho"))
        {
            strcat(a->data, "8");
        }
        else if (!strcmp(found, "nueve"))
        {
            strcat(a->data, "9");
        }
        else if (!strcmp(found, "diez"))
        {
            strcat(a->data, "10");
        }
        else if (!strcmp(found, "once"))
        {
            strcat(a->data, "11");
        }
        else if (!strcmp(found, "doce"))
        {
            strcat(a->data, "12");
        }
        else if (!strcmp(found, "trece"))
        {
            strcat(a->data, "13");
        }
        else if (!strcmp(found, "catorce"))
        {
            strcat(a->data, "14");
        }
        else if (!strcmp(found, "quince"))
        {
            strcat(a->data, "15");
        }
        else if (!strcmp(found, "dieciseis"))
        {
            strcat(a->data, "16");
        }
        else if (!strcmp(found, "diecisiete"))
        {
            strcat(a->data, "17");
        }
        else if (!strcmp(found, "dieciocho"))
        {
            strcat(a->data, "18");
        }
        else if (!strcmp(found, "diecinueve"))
        {
            strcat(a->data, "19");
        }
        else if (!strcmp(found, "veinte"))
        {
            strcat(a->data, "20");
        }
        else if (!strcmp(found, "veintiuno"))
        {
            strcat(a->data, "21");
        }
        else if (!strcmp(found, "veintidos"))
        {
            strcat(a->data, "22");
        }
        else if (!strcmp(found, "veintitres"))
        {
            strcat(a->data, "23");
        }
        else if (!strcmp(found, "veinticuatro"))
        {
            strcat(a->data, "24");
        }
        else if (!strcmp(found, "veinticinco"))
        {
            strcat(a->data, "25");
        }
        else if (!strcmp(found, "veintiseis"))
        {
            strcat(a->data, "26");
        }
        else if (!strcmp(found, "veintisiete"))
        {
            strcat(a->data, "27");
        }
        else if (!strcmp(found, "veintiocho"))
        {
            strcat(a->data, "28");
        }
        else if (!strcmp(found, "veintinueve"))
        {
            strcat(a->data, "29");
        }
        else if (!strcmp(found, "treinta"))
        {
            strcat(a->data, "30");
        }
        else if (!strcmp(found, "treintayuno"))
        {
            strcat(a->data, "31");
        }
        else if (!strcmp(found, "treintaydos"))
        {
            strcat(a->data, "32");
        }
        else if (!strcmp(found, "treintaytres"))
        {
            strcat(a->data, "33");
        }
        else if (!strcmp(found, "treintaycuatro"))
        {
            strcat(a->data, "34");
        }
        else if (!strcmp(found, "treintaycinco"))
        {
            strcat(a->data, "35");
        }
        else if (!strcmp(found, "treintayseis"))
        {
            strcat(a->data, "36");
        }
        else if (!strcmp(found, "treintaysiete"))
        {
            strcat(a->data, "37");
        }
        else if (!strcmp(found, "treintayocho"))
        {
            strcat(a->data, "38");
        }
        else if (!strcmp(found, "treintaynueve"))
        {
            strcat(a->data, "39");
        }
        else if (!strcmp(found, "cuarenta"))
        {
            strcat(a->data, "40");
        }
        else if (!strcmp(found, "cuarentayuno"))
        {
            strcat(a->data, "41");
        }
        else if (!strcmp(found, "cuarentaydos"))
        {
            strcat(a->data, "42");
        }
        else if (!strcmp(found, "cuarentaytres"))
        {
            strcat(a->data, "43");
        }
        else if (!strcmp(found, "cuarentaycuatro"))
        {
            strcat(a->data, "44");
        }
        else if (!strcmp(found, "cuarentaycinco"))
        {
            strcat(a->data, "45");
        }
        else if (!strcmp(found, "cuarentayseis"))
        {
            strcat(a->data, "46");
        }
        else if (!strcmp(found, "cuarentaysiete"))
        {
            strcat(a->data, "47");
        }
        else if (!strcmp(found, "cuarentayocho"))
        {
            strcat(a->data, "48");
        }
        else if (!strcmp(found, "cuarentaynueve"))
        {
            strcat(a->data, "49");
        }
        else if (!strcmp(found, "cincuenta"))
        {
            strcat(a->data, "50");
        }
        else if (!strcmp(found, "cincuentayuno"))
        {
            strcat(a->data, "51");
        }
        else if (!strcmp(found, "cincuentaydos"))
        {
            strcat(a->data, "52");
        }
        else if (!strcmp(found, "cincuentaytres"))
        {
            strcat(a->data, "53");
        }
        else if (!strcmp(found, "cincuentaycuatro"))
        {
            strcat(a->data, "54");
        }
        else if (!strcmp(found, "cincuentaycinco"))
        {
            strcat(a->data, "55");
        }
        else if (!strcmp(found, "cincuentayseis"))
        {
            strcat(a->data, "56");
        }
        else if (!strcmp(found, "cincuentaysiete"))
        {
            strcat(a->data, "57");
        }
        else if (!strcmp(found, "cincuentayocho"))
        {
            strcat(a->data, "58");
        }
        else if (!strcmp(found, "cincuentaynueve"))
        {
            strcat(a->data, "59");
        }
        else if (!strcmp(found, "sesenta"))
        {
            strcat(a->data, "60");
        }
        else if (!strcmp(found, "sesentayuno"))
        {
            strcat(a->data, "61");
        }
        else if (!strcmp(found, "sesentaydos"))
        {
            strcat(a->data, "62");
        }
        else if (!strcmp(found, "sesentaytres"))
        {
            strcat(a->data, "63");
        }
        else if (!strcmp(found, "sesentaycuatro"))
        {
            strcat(a->data, "64");
        }
        else if (!strcmp(found, "sesentaycinco"))
        {
            strcat(a->data, "65");
        }
        else if (!strcmp(found, "sesentayseis"))
        {
            strcat(a->data, "66");
        }
        else if (!strcmp(found, "sesentaysiete"))
        {
            strcat(a->data, "67");
        }
        else if (!strcmp(found, "sesentayocho"))
        {
            strcat(a->data, "68");
        }
        else if (!strcmp(found, "sesentaynueve"))
        {
            strcat(a->data, "69");
        }
        else if (!strcmp(found, "setenta"))
        {
            strcat(a->data, "70");
        }
        else if (!strcmp(found, "setentayuno"))
        {
            strcat(a->data, "71");
        }
        else if (!strcmp(found, "setentaydos"))
        {
            strcat(a->data, "72");
        }
        else if (!strcmp(found, "setentaytres"))
        {
            strcat(a->data, "73");
        }
        else if (!strcmp(found, "setentaycuatro"))
        {
            strcat(a->data, "74");
        }
        else if (!strcmp(found, "setentaycinco"))
        {
            strcat(a->data, "75");
        }
        else if (!strcmp(found, "setentayseis"))
        {
            strcat(a->data, "76");
        }
        else if (!strcmp(found, "setentaysiete"))
        {
            strcat(a->data, "77");
        }
        else if (!strcmp(found, "setentayocho"))
        {
            strcat(a->data, "78");
        }
        else if (!strcmp(found, "setentaynueve"))
        {
            strcat(a->data, "79");
        }
        else if (!strcmp(found, "ochenta"))
        {
            strcat(a->data, "80");
        }
        else if (!strcmp(found, "ochentayuno"))
        {
            strcat(a->data, "81");
        }
        else if (!strcmp(found, "ochentaydos"))
        {
            strcat(a->data, "82");
        }
        else if (!strcmp(found, "ochentaytres"))
        {
            strcat(a->data, "83");
        }
        else if (!strcmp(found, "ochentaycuatro"))
        {
            strcat(a->data, "84");
        }
        else if (!strcmp(found, "ochentaycinco"))
        {
            strcat(a->data, "85");
        }
        else if (!strcmp(found, "ochentayseis"))
        {
            strcat(a->data, "86");
        }
        else if (!strcmp(found, "ochentaysiete"))
        {
            strcat(a->data, "87");
        }
        else if (!strcmp(found, "ochentayocho"))
        {
            strcat(a->data, "88");
        }
        else if (!strcmp(found, "ochentaynueve"))
        {
            strcat(a->data, "89");
        }
        else if (!strcmp(found, "noventa"))
        {
            strcat(a->data, "90");
        }
        else if (!strcmp(found, "noventayuno"))
        {
            strcat(a->data, "91");
        }
        else if (!strcmp(found, "noventaydos"))
        {
            strcat(a->data, "92");
        }
        else if (!strcmp(found, "noventaytres"))
        {
            strcat(a->data, "93");
        }
        else if (!strcmp(found, "noventaycuatro"))
        {
            strcat(a->data, "94");
        }
        else if (!strcmp(found, "noventaycinco"))
        {
            strcat(a->data, "95");
        }
        else if (!strcmp(found, "noventayseis"))
        {
            strcat(a->data, "96");
        }
        else if (!strcmp(found, "noventaysiete"))
        {
            strcat(a->data, "97");
        }
        else if (!strcmp(found, "noventayocho"))
        {
            strcat(a->data, "98");
        }
        else if (!strcmp(found, "noventaynueve"))
        {
            strcat(a->data, "99");
        }
        else if (!strcmp(found, "cien"))
        {
            strcat(a->data, "100");
        }
        found = strtok(NULL, ",");
    }
     if (strlen(a->data) < 9)
    {
        printf("Faltan digitos de identicador vuelva a intentar\n");
    }
    else
    {
        printf("Tu identificador correcto es: %s\n", a->identifier);
        shiftString(a->data, 3);
        printf("Tu identificador modificado es: ");
        for (int i = 0; i < strlen(a->identifier);++i){
            printf("%c", a->identifier[i]);
        }
        printf("\n");
    }
    return 0;
}