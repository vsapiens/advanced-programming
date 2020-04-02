//
// Autor: Erick González
// Matrícula: A01039859
// Fecha: 13/03/2020
//
// Obtiene el valor de diferentes valores de diferentes basesydemás
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estructura de nodo
struct Node
{
    char cLetter;
    struct Node *next;
};
//Estructura de LinkedList
struct LinkedList
{
    struct Node *head, *tail;
};

void addChar(char c, struct LinkedList *keylogger)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->cLetter = c;
    n->next = NULL;

    if (keylogger->head == NULL)
    {
        keylogger->head = n;
        keylogger->tail = n;
    }
    else
    {
        keylogger->tail->next = n;
        keylogger->tail = keylogger->tail->next;
    }
}
union Data {
    char c;

} data;
int main(void)
{
    struct LinkedList *keylogger;
    printf("Por favor, teclea un string largo seguido:\n");
    while (strncmp("\n", &data.c, 1) != 0)
    {
        scanf("%c", &data.c);
        addChar(data.c, keylogger);
    }

    struct Node *n;
    n = keylogger->head;

    printf("El string es ");
    while (n != NULL)
    {
        printf("%c", n->cLetter);
        n = n->next;
    }
    printf("\n");

    return 0;
}