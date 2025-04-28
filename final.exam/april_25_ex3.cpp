#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void prtMatrix(int m[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("[%d][%d] = %3d, ", i, j, m[i][j]);
        }
        printf("\n");
    }

}

int main()
{
    int matrix1[3][3];
    int matrix2[3][3];
    int result[3][3];

    srand((unsigned) time(NULL));

    // Matrices initialization
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            matrix1[i][j] = rand() % 10;
            matrix2[i][j] = rand() % 10;
            result[i][j] = 0;
        }
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
        	for(int k=0;k<3;k++){
			
            result[i][j] += matrix1[i][k]*matrix2[k][j];
        	}
        }
    }

    printf("matrix1:\n");
    prtMatrix(matrix1);

    printf("\n");

    printf("matrix2:\n");
    prtMatrix(matrix2);

    printf("\n");

    printf("The matrix1 dot matrix2:\n");
    prtMatrix(result);   

    return 0;
}

