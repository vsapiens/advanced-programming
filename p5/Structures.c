#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mission
{
    int iDigits[9];
    char cIdentifier[3];
};
typedef struct mission Mission;
struct agent
{
    char sName[50];
    char sLastName[50];
    int iAge;
    char cGender[6];
    Mission mMission;
};

typedef struct agent Agent;

Mission *newMission(int iDigits[9], char cIdentifier[3])
{
    Mission *m = (Mission *)malloc(sizeof(Mission));
    strcpy(m->cIdentifier, cIdentifier);
    *(m)->iDigits = *iDigits;
    return m;
}

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

int main(void)
{
    int iIdent1[] = {1, 2, 6, 8, 9, 0, 0, 2, 1};
    int iIdent2[] = {1, 2, 6, 7, 9, 0, 0, 3, 2};
    char code1[] = "MEX";
    char code2[] = "LON";
    char name1[] = "Vsapiens";
    char name2[] = "Loptt";

    Agent *list[3];
    Mission *m1 = newMission(iIdent1, code1);
    Mission *m2 = newMission(iIdent2, code2);

    Agent *agent1 = newAgent("Vocem", "Sapiens", 21, "Male", *m1);
    Agent *agent2 = newAgent("James", "Bond", 45, "Male", *m2);
    Agent *agent3 = newAgent("Eames", "Westbound", 34, "Female", *m2);

    list[0] = agent1;
    list[1] = agent2;
    list[2] = agent3;

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
        for (int i = 0; i < 9; ++i)
        {
            printf("%d", list[iCounter]->mMission.iDigits[i]);
        }
        printf("\n");
    }

    printf("\n");
    return 0;
}