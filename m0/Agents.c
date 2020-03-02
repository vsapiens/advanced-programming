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
struct Identifiers
{
    char cIdentifier[14];
    struct Identifiers *next;
};
struct IdentifiersList
{
    struct Identifiers *head, *last;
};
//Estructura de AGENTE
struct Agent
{
    char sName[50];
    char sLastName[50];
    int iAge;
    struct IdentifiersList assets;
    struct IdentifiersList missions;
};
//Estructura de Entry
struct Entry
{
    struct Agent agent;
    struct Entry *next;
};
//Estructura de lista de entries
struct EntryList
{
    struct Entry *head, *last;
};
//Creación de la agencia
struct EntryList agency;

//Añadir una entrada
void addEntry(struct Agent a)
{

    struct Entry *entry = (struct Entry *)malloc(sizeof(struct Entry));

    entry->agent = a;
    entry->next = NULL;
    if (agency.head == NULL)
    {
        agency.head = entry;
        agency.last = entry;
    }
    else
    {
        agency.last->next = entry;
        agency.last = agency.last->next;
    }
    printf("\nNew AGENT Added\n");
}
//Añadir una Misión
void addMission(struct Agent *a, char mission[14])
{
    struct Identifiers *identifierM = (struct Identifiers *)malloc(sizeof(struct Identifiers));

    strcpy(identifierM->cIdentifier, mission);
    strcat(identifierM->cIdentifier, "\0");
    identifierM->next = NULL;

    if (a->missions.head == NULL)
    {
        a->missions.head = a->missions.last = identifierM;
    }
    else
    {
        a->missions.last->next = identifierM;
        a->missions.last = a->missions.last->next;
    }
}
//Añadir un asset
void addAsset(struct Agent *a, char asset[14])
{
    struct Identifiers *identifierM = (struct Identifiers *)malloc(sizeof(struct Identifiers));

    strncpy(identifierM->cIdentifier, asset,14);
    strcat(identifierM->cIdentifier, "\0");
    identifierM->next = NULL;

    if (a->assets.head == NULL)
    {
        a->assets.head = a->assets.last = identifierM;
    }
    else
    {
        a->assets.last->next = identifierM;
        a->assets.last = a->assets.last->next;
    }
}
//Imprimir todos los agentes
void printAgents()
{
  struct Identifiers *m1, *a1;
    struct Entry *e = agency.head;
    int i = 1;
    while (e != NULL)
    {
        printf("%d) Agent: %s %s \n", i, e->agent.sName, e->agent.sLastName);
        printf("\tAge: %d\n", e->agent.iAge);
        
        printf("\tMissions:\n");
        m1 = e->agent.missions.head;
        a1 = e->agent.assets.head;
        while (m1 != NULL)
        {
            printf("\t\t %s\n", m1->cIdentifier);
            m1 = m1->next;
        }
        printf("\tAssets:\n");
        while (a1 != NULL)
        {
            printf("\t\t %s\n", a1->cIdentifier);
            a1 = a1->next;
        }
        e = e->next;
        i++;
    }
}
//Borrar agentes
bool deleteAgente(int iNum)
{
  printf("Borrar 1\n");
    struct Entry *e = agency.head, *past;
    if (iNum == 1)
    {
        e = agency.head;
        agency.head = agency.head->next;
        free(e);
        return true;
    }
  printf("Borrar 2\n");
    while (iNum != 0 && e != NULL)
    {
        --iNum;
        e = e->next;
    }
  printf("Borrar 3\n");
    if (e->next != NULL)
    {
        past = e->next;
        e->next = e->next->next;
        free(past);
        return true;
    }
      printf("Borrar 4\n");
    return false;
}
//Función principal
int main(void)
{
    char option;
    struct Agent *a = (struct Agent *)malloc(sizeof(struct Agent));
    int iM, iA, iNum;
    char sM[14], sA[14];
    //printf("Opening secure connection to Agent Database...\n");
    do
    {
        printf(" Introduzca la letra de su opción:\n");
        printf("\ta) Crear Nueva Entrada\n");
        printf("\tb) Eliminar una Entrada\n");
        printf("\tc) Desplegar Agentes\n");
        printf("\td) Salir\n");
        scanf(" %c", &option);
        switch (option)
        {
        case 'a':
            printf("Insert Name:\n");
            scanf("%s", &a->sName);
            printf("Insert Last Name:\n");
            scanf("%s", &a->sLastName);
            printf("Insert Age:\n");
            scanf("%d", &a->iAge);
            printf("Insert Number of missions:\n");
            scanf("%d", &iM);
            for (int i = 0; i < iM; ++i)
            {
                printf("Insert Mission Name:\t");
                scanf("%s", &sM);
                addMission(a, sM);
            }
            printf("Insert Number of assets:\n");
            scanf("%d", &iA);
            for (int i = 0; i < iA; ++i)
            {
                printf("Insert Asset Name:\t");
                scanf("%s", &sA);
                addAsset(a, sA);
            }
            addEntry(*a);
            break;
        case 'b':
            printAgents();
            printf("¿Cuál agente desea borrar?\n");
            scanf("%d", &iNum);
            if (deleteAgente(iNum))
            {
                printf("Agente borrado con éxito.\n");
            }
            else
            {
                printf("Agente no encontrado.\n");
            }
            break;
        case 'c':
            printAgents();
            break;
        case 'd':
            printf("Closing Connection...\n");
            break;
        default:
            break;
        }
    } while (strncmp(&option, "d", 2));

    return 0;
}