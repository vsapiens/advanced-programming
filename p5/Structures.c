#include <stdio.h>

typedef struct mission
{
    int iDigits[9];
    char cIdentifier[3];
} Mission;

Mission *newMission(int iDigits[9], char cIdentifier[3])
{
    Mission *m = malloc(sizeof(Mission));
    m->cIdentifier = cIdentifier;
    m->iDigits = iDigits;
    return m;
}

typedef struct agent
{
    char sName[50];
    char sLastName[50];
    int iAge;
    char cGender[6];
    Mission mMission;
} Agent;

Agent *newAgent(char sName[50],char sLastName[50],int iAge, )

int main(void)
{
    Agent agent1;
    Agent agent2;

    return 0;
}