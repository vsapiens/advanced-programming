//
// Autor: Erick González
// Matrícula: A01039859
// Fecha: 20/02/2020
//
// Includes multiplication, display, substraction and addition

#include <stdio.h>
//Defined constants
const static int ROWS = 2;
const static int COLS = 2;

//Displays a matrix
void display(int m1[ROWS][COLS])
{
    printf("Display \n");
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < ROWS; ++j)
        {
            printf(" %d ", m1[i][j]);
        }
        printf("\n");
    }
}
//Adds a matrix
void addition(int m1[ROWS][COLS], int m2[ROWS][COLS])
{
    int m3[ROWS][COLS];
    printf("Addition\n");
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            m3[i][j] = 0;
            m3[i][j] = m1[i][j] + m2[i][j];
            printf(" %d ", m3[i][j]);
        }
        printf("\n");
    }
}
//Substracts a matrix
void substraction(int m1[ROWS][COLS], int m2[ROWS][COLS])
{
    int m3[ROWS][COLS];
    printf("Substraction\n");
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            m3[i][j] = 0;
            m3[i][j] = m1[i][j] - m2[i][j];
            printf(" %d ", m3[i][j]);
        }
        printf("\n");
    }
}
//Multiplies 2 matrices
void multiplication(int m1[ROWS][COLS], int m2[ROWS][COLS])
{
    int m3[ROWS][COLS];
    printf("Multiplication\n");
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            m3[i][j] = 0;
            for (int k = 0; k < COLS; ++k)
            {
                m3[i][j] += m1[i][k] * m2[k][j];
            }
            printf(" %d ", m3[i][j]);
        }
        printf("\n");
    }
}
// Función principal
int main(void)
{
    //Declaración de variables
    int m3[2][2] = {{1, 1}, {1, 1}};
    int m1[2][2];
    int m2[2][2];
    int num = 0;
    //Lee matriz 1
    printf("Insert the numbers of the matrix 1\n");
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            m1[i][j] = 0;
            scanf(" %d", &num);
            m1[i][j] = num;
        }
        printf("\n");
    }
    //Lee matriz 2
    printf("Insert the numbers of the matrix 2\n");
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            m2[i][j] = 0;
            scanf(" %d", &num);
            m2[i][j] = num;
        }
        printf("\n");
    }
    //Despliega matrices
    display(m1);
    display(m2);
    display(m3);
    //Añade matrices
    addition(m1, m2);
    addition(m2, m3);
    //Substracción de matrices
    substraction(m1, m2);
    substraction(m2, m3);
    //Multiplicación de  matrices
    multiplication(m1, m2);
    multiplication(m2, m3);

    return 0;
}