#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main()
{
    int matrix[3][3][3];
    float avg,avg1,avg2,avg3;
    
	srand((unsigned)time(NULL));
	
    printf("The matrix:\n");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {   
        	for( int z =0; z<3;z++ ){
            matrix[i][j][z] = rand() % 100;
            avg += matrix[i][j][z];
            printf("matrix[%d][%d][%d] = %2d, ", i+1, j+1,z+1, matrix[i][j][z]);
            avg1 =avg-matrix[0][j][z];
            avg2 =avg-matrix[1][j][z];
            avg3 =avg-matrix[2][j][z];
        }
        printf("\n");
    	}
	}


    avg = avg / 27.0;
    avg1 = avg1 /18.0;
    avg2 = avg2 /18.0;
    avg3 = avg3 /18.0;
    printf("Average:%f\n", avg);
	printf("Average:%f\n", avg1);
	printf("Average:%f\n", avg2);
	printf("Average:%f\n", avg3);
    return 0;
}

