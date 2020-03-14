//
// Autor: Erick González
// Matrícula: A01039859
// Fecha: 01/03/2020
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <stdbool.h>
#include <ctype.h>
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
//Password válido
bool isPassword;
//Función de encriptación tipo César
const char *encrypt(const char *s)
{
    if (isPassword != 0)
    {
        int i = 0;
        char result[50] = "";
        char letter;
        while (s[i] != '\0')
        {
            letter = (char)(((int)(s[i] + strlen(s) - 65)) % 26 + 65);
            if (s[i] != ' ')
            {
                strncat(result, &letter, 1);
            }
            else
            {
                strncat(result, " ", 1);
            }
            i++;
        }
        return result;
    }
    else
    {
        return s;
    }
}
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
    printf("\n");
    printf("%s", encrypt("New AGENT Added"));
    printf("\n");
}
//Añadir una Misión
void addMission(struct Agent *a, char mission[14])
{
    printf("\n");
    printf("%s", encrypt("Adding Mission..."));
    printf("\n");
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

    strncpy(identifierM->cIdentifier, asset, 14);
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
    if (isPassword != 0)
    {
        while (e != NULL)
        {
            char *eSName = encrypt(&e->agent.sName);
            char *sLastName = encrypt(&e->agent.sLastName);
            printf("X) XXXXX: %s %s \n", eSName, sLastName);
            printf("\tXXX: %d\n", encrypt(&e->agent.iAge));
            printf("\t XXXXXXXX:\n");
            m1 = e->agent.missions.head;
            a1 = e->agent.assets.head;
            while (m1 != NULL)
            {
                printf("\t\t %s\n", encrypt(&m1->cIdentifier));
                m1 = m1->next;
            }
            printf("\tXXXXXX:\n");
            while (a1 != NULL)
            {
                printf("\t\t %s\n", encrypt(&a1->cIdentifier));
                a1 = a1->next;
            }
            e = e->next;
            i++;
        }
    }
    else
    {
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
}
//Borrar agentes
bool deleteAgente(int iNum)
{
    struct Entry *e = agency.head;
    struct Entry *past;
    --iNum;
    if (iNum == 0)
    {
        e = agency.head;
        agency.head = agency.head->next;
        free(e);
        return true;
    }

    while (iNum != 0 && e != NULL)
    {
        --iNum;
        e = e->next;
    }

    if (e->next != NULL)
    {
        past = e->next;
        e->next = e->next->next;
        free(past);
        return true;
    }
    return false;
}
void editarAgente(int num)
{
    struct Agent *a;
    struct Entry *e = agency.head;
    int iM, iA;
    char sM[14], sA[14];
    char cOpt;
    --num;
    printf("%d\n", num);
    while (num != 0 && e != NULL)
    {
        --num;
        e = e->next;
    }
    printf(encrypt("a) Add Missions\nb) Add Assets\n"));
    scanf(" %c", &cOpt);
    if (strncmp(&cOpt, "a", 1) == 0)
    {
        printf(encrypt("Insert Number of missions:"));
        printf("\n");
        scanf("%d", &iM);
        for (int i = 0; i < iM; ++i)
        {
            printf(encrypt("Insert Mission Name:"));
            printf("\n");
            scanf(" %s", &sM);
            addMission(&e->agent, sM);
        }
    }
    else
    {
        printf(encrypt("Insert Number of assets:"));
        printf("\n");
        scanf("%d", &iA);
        for (int i = 0; i < iA; ++i)
        {
            printf(encrypt("Insert Asset Name:"));
            printf("\n");
            scanf(" %s", &sA);
            addAsset(&e->agent, sA);
        }
    }
}
void searchApellido()
{
    struct Identifiers *m1, *a1;
    char *insertar = "Insert last name\n";
    char *buscar = "Searching agents by last name\n";
    char apellido[50];
    struct Entry *e = agency.head;
    int i = 0, m = 0;
    char opc;
    if (isPassword != 0)
    {
        printf(encrypt(&insertar));
        scanf("%s", &apellido);
        printf(encrypt(&buscar));
        while (e != NULL)
        {
            if (strcmp(e->agent.sLastName, apellido) == 0)
            {
                char *eSName = encrypt(&e->agent.sName);
                char *sLastName = encrypt(&e->agent.sLastName);
                printf("X) XXXXX: %s %s \n", eSName, sLastName);
                printf("\tXXX: %d\n", encrypt(&e->agent.iAge));
                printf("\t XXXXXXXX:\n");
                m1 = e->agent.missions.head;
                a1 = e->agent.assets.head;
                while (m1 != NULL)
                {
                    printf("\t\t %s\n", encrypt(&m1->cIdentifier));
                    m1 = m1->next;
                }
                printf("\tXXXXXX:\n");
                while (a1 != NULL)
                {
                    printf("\t\t %s\n", encrypt(&a1->cIdentifier));
                    a1 = a1->next;
                }
                m++;
            }
            e = e->next;
            i++;
        }
    }
    else
    {
        printf(insertar);
        scanf("%s", &apellido);
        printf(buscar);
        while (e != NULL)
        {
            if (strcmp(e->agent.sLastName, apellido) == 0)
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
                m++;
            }
            e = e->next;
            i++;
        }
    }
    if (m != 0)
    {
        printf(encrypt("a)Edit\n"));
        printf(encrypt("b)Delete\n"));
        scanf(" %c", &opc);
        if (strncmp(&opc, "a", 1) == 0)
        {
            editarAgente(i);
        }
        else
        {
            deleteAgente(i);
        }
    }
}
void searchAsset()
{
    struct Identifiers *m1, *a1;
    char *insertar = "Insert asset\n";
    char *buscar = "Searching agent by asset\n";
    char cOpcion;
    char asset[14];
    int m = 0;
    struct Entry *e = agency.head;
    int i = 0;
    if (isPassword != 0)
    {
        printf(encrypt(&insertar));
        scanf("%s", &asset);
        printf(encrypt(&buscar));
        while (e != NULL)
        {
            struct Identifiers *iAsset = e->agent.assets.head;
            while (iAsset != NULL)
            {
                if (strcmp(iAsset->cIdentifier, asset) == 0)
                {
                    char *eSName = encrypt(&e->agent.sName);
                    char *sLastName = encrypt(&e->agent.sLastName);
                    printf("X) XXXXX: %s %s \n", eSName, sLastName);
                    printf("\tXXX: %d\n", encrypt(&e->agent.iAge));
                    printf("\t XXXXXXXX:\n");
                    m1 = e->agent.missions.head;
                    a1 = e->agent.assets.head;
                    while (m1 != NULL)
                    {
                        printf("\t\t %s\n", encrypt(&m1->cIdentifier));
                        m1 = m1->next;
                    }
                    printf("\tXXXXXX:\n");
                    while (a1 != NULL)
                    {
                        printf("\t\t %s\n", encrypt(&a1->cIdentifier));
                        a1 = a1->next;
                    }
                    m++;
                    break;
                }
                iAsset = iAsset->next;
            }
            e = e->next;
            i++;
        }
    }
    else
    {
        printf(insertar);
        scanf("%s", &asset);
        printf(buscar);
        while (e != NULL)
        {
            struct Identifiers *iAsset = e->agent.assets.head;
            while (iAsset != NULL)
            {
                if (strcmp(iAsset->cIdentifier, asset) == 0)
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
                    m++;
                    break;
                }
                iAsset = iAsset->next;
            }
            e = e->next;
            i++;
        }
    }

    if (m != 0)
    {
        printf(encrypt("a)Edit\nb)Delete\n"));
        scanf(" %c", &cOpcion);
        if (strncmp(&cOpcion, "a", 1) == 0)
        {
            editarAgente(i);
        }
        else
        {
            deleteAgente(i);
        }
    }
}
void search()
{
    char opcion;
    char *opcionA = "a) Buscar por apellido\n";
    char *opcionB = "b) Buscar por asset\n";
    char *ingresar = "Ingresar letra de opción\n";

    if (isPassword != 0)
    {
        printf(encrypt(&opcionA));
        printf(encrypt(&opcionB));
        printf(encrypt(&ingresar));
    }
    else
    {
        printf(opcionA);
        printf(opcionB);
        printf(ingresar);
    }

    scanf(" %c", &opcion);
    if (opcion == 'a')
    {
        searchApellido();
    }
    else
    {
        searchAsset();
    }
}
//Función principal
int main(void)
{
    char option;
    char password[8] = "password";
    char input[50];
    struct Agent *a = (struct Agent *)malloc(sizeof(struct Agent));
    int iM, iA, iNum;
    char sM[14], sA[14];
    printf("Opening secure connection to Agent Database...\n");
    printf("Insert password...\n");
    scanf("%s", &input);
    isPassword = strncmp(password, input, 8);
    do
    {
        printf("%s", encrypt("Insert option"));
        printf("\n");
        printf("\t");
        printf("%s", encrypt("a. Create"));
        printf("\n");
        printf("\t");
        printf("%s", encrypt("b. Delete"));
        printf("\n");
        printf("\t");
        printf("%s", encrypt("c. Display"));
        printf("\n");
        printf("\t");
        printf("%s", encrypt("d. Search"));
        printf("\n");
        printf("\t");
        printf("%s", encrypt("e. Exit"));
        printf("\n");
        printf("\t");
        scanf(" %c", &option);
        switch (option)
        {
        case 'a':
        case 'A':
            printf("%s", encrypt("Insert Name"));
            printf("\n");
            scanf("%s", &a->sName);
            printf(encrypt("Insert Last Name"));
            printf("\n");
            scanf("%s", &a->sLastName);
            printf(encrypt("Insert Age:"));
            printf("\n");
            scanf("%d", &a->iAge);
            printf(encrypt("Insert Number of missions"));
            printf("\n");
            scanf("%d", &iM);
            for (int i = 0; i < iM; ++i)
            {
                printf(encrypt("Insert Mission Name"));
                printf("\n");
                scanf("%s", &sM);
                addMission(a, sM);
            }
            printf("%s", encrypt("Insert Number of assets:"));
            printf("\n");
            scanf("%d", &iA);
            for (int i = 0; i < iA; ++i)
            {
                printf("%s", encrypt("Insert Asset Name:"));
                printf("\n");
                scanf("%s", &sA);
                addAsset(a, sA);
            }
            addEntry(*a);
            break;
        case 'b':
        case 'B':
            printAgents();
            printf("%s", encrypt("¿Cuál agente desea borrar?"));
            printf("\n");
            scanf("%d", &iNum);
            if (deleteAgente(iNum))
            {
                printf("%s", encrypt("Agente borrado con éxito."));
                printf("\n");
            }
            else
            {
                printf("%s", encrypt("Agente no encontrado."));
                printf("\n");
            }
            break;
        case 'c':
        case 'C':
            printAgents();
            break;
        case 'd':
        case 'D':
            search();
            break;
        case 'e':
        case 'E':
            printf("%s", encrypt("Closing Connection"));
            printf("\n");
            break;
        default:
            break;
        }
    } while (strncmp(&option, "e", 2) || strncmp(&option, "E", 2));

    return 0;
}
