//
// Autor: Erick González
// Matrícula: A01039859
// Fecha: 21/02/2020
//
// Crea 2 estructuras nuevas para las misiones de los agentes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Estructura de misión
struct mission
{
    int iDigits;
    char cIdentifier[3];
};
typedef struct mission Mission;
//Estructura de AGENTE
struct agent
{
    char sName[50];
    char sLastName[50];
    int iAge;
    char cGender[6];
    Mission mMission;
};

typedef struct agent Agent;
//Constructor de una nueva misión
Mission *newMission(int iDigits, char cIdentifier[3])
{
    Mission *m = (Mission *)malloc(sizeof(Mission));
    strcpy(m->cIdentifier, cIdentifier);
    m->iDigits = iDigits;
    return m;
}
//Constructor de un nuevo agente
Agent *newAgent(char sName[50], char sLastName[50], int iAge, char cGender[6], Mission mMission)
{
    Agent *a = (Agent *)malloc(sizeof(Agent));
    a->iAge = iAge;
    a->mMission = mMission;
    strcpy(a->sName, sName);
    strcpy(a->sLastName, sLastName);
    strcpy(a->cGender, cGender);
    return a;
}
//Función principal
int main(void)
{
    //Declaración de variables
    Agent *list[3];
    Mission *m1 = newMission(216890021, "MX-");
    Mission *m2 = newMission(216890022, "USA");
    Mission *m3 = newMission(216890023, "GER");
    Agent *agent1 = newAgent("Vocem", "Sapiens", 21, "Male", *m1);
    Agent *agent2 = newAgent("James", "Bond", 45, "Male", *m2);
    Agent *agent3 = newAgent("Eames", "Westbound", 34, "Female", *m3);

    list[0] = agent1;
    list[1] = agent2;
    list[2] = agent3;

    //Inicialización de variables
    for (int iCounter = 0; iCounter < 3; ++iCounter)
    {
        printf("Agent %i: %s %s\n", iCounter + 1, list[iCounter]->sName, list[iCounter]->sLastName);
        printf("\tAge: %i\n", list[iCounter]->iAge);
        printf("\tGender: %s\n", list[iCounter]->cGender);
        printf("\tMission: ");
        for (int i = 0; i < 3; ++i)
        {
            printf("%c", list[iCounter]->mMission.cIdentifier[i]);
        }
        printf("%d", list[iCounter]->mMission.iDigits);
        printf("\n");
    }

    printf("\n");
    //Liberación de Memoria
    free(m1);
    free(m2);
    free(m3);
    free(agent1);
    free(agent2);
    free(agent3);
    return 0;
}