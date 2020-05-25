//
// Autor: Erick González
// Matrícula: A01039859
// Fecha: 24/05/2020
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <ctype.h>
#include <string.h>
//Definición de estructura para manejar los trabajos del sistema
typedef struct osTask
{
    int id;
    int time;
    int *dependencies;
    int size;
} osTask;
//Creación de una nueva task del sistema
osTask *NewTask(int id, int time, int dependencies[50], int size)
{
    osTask *task = malloc(sizeof(osTask));
    task->id = id;
    task->time = time;
    task->dependencies = dependencies;
    task->size = size;
    return task;
}

int getId(char *id)
{
    int ID = 0, count = 1;
    while (*id != '\0')
    {
        if (isdigit(*id))
        {
            ID += atoi(id) * count;
            count *= 10;
        }
        count++;
    }
    return ID;
}
int *parseFile(char *id, int size)
{
    int *dependencies = malloc(size * sizeof(int)), count = 0;
    char *token = strtok(id, ",");
    while (token != NULL)
    {
        int ID = getId(token);
        dependencies[count++] = ID;
        token = strtok(NULL, ",");
    }
    return dependencies;
}
osTask **initialize(char *file, int lines)
{
    FILE *in;
    char task[5], dependency[50];
    int time, count = 0;
    in = fopen(file, "r");
    osTask **tasks = malloc(lines * sizeof(osTask));
    //Initializers
    int elems = 0;
    while (fscanf(in, "%s %d %s", task, &time, dependency) != EOF)
    {
        elems = 0;
        if (*dependency != '-')
        {
            char *parser = malloc(sizeof(dependency));
            strcpy(parser, dependency);
            char *token;
            token = strtok(parser, ",");
            while (token != NULL)
            {
                elems++;
                token = strtok(NULL, ",");
            }
            free(parser);
        }
        int ID = getId(task), *dependentsID = parseFile(dependency, elems);
        tasks[count] = NewTask(ID, time, dependentsID, elems);
        count++;
    }
    fclose(in);
    return tasks;
};
//Lista de los threads
pthread_t threadList[50];
void *operatingSystem(void *id)
{
    osTask *task = (struct osTask *)id;

    printf("Opening Thread No.%d\n", task->id);

    for (int iCounter = 0; iCounter < task->size; iCounter++)
    {
        printf("Current Thread No.%d\t=> Dependent: %d\t Time:%d\n", task->id, task->dependencies[iCounter], task->time);
        pthread_join(threadList[task->dependencies[iCounter] - 1], NULL);
    }

    printf("Closing Thread No.%d\n", task->id);
    pthread_exit(NULL);
}
int main()
{
    //Count lines of the file
    FILE *in;
    int lines = 0, noThred = 0;
    char data[20];
    char *file = "test1.txt";
    in = fopen(file, "r");
    while (fscanf(in, "%s %s %s", data, data, data) == 3)
    {
        lines++;
    }
    fclose(in);
    osTask **tasks = initialize(file, lines);
    for (int currT = 0; currT < lines; ++currT)
    {
        noThred = pthread_create(threadList + currT, NULL, operatingSystem, (void *)tasks[currT]);
        if (noThred)
        {
            printf("Error to create a thread.\n");
            exit(-1);
        }
        /*         
        printf("%d\t%d\t", tasks[i]->id, tasks[i]->time);
        printf("Dependencies: ");
        for (int j = 0; j < tasks[i]->size; ++j)
        {
            printf(" %d", tasks[i]->dependencies[j]);
        };
        printf("\n"); 
        */
    }
    return 0;
}