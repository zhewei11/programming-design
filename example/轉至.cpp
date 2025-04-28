#include <stdio.h>

void swap_third_row(int matrix[5][5],int a,int b) {
    int temp;
    for (int i = 0; i < 5; i++) {
        temp = matrix[a][i];
        matrix[a][i] = matrix[b][i];
        matrix[b][i] = temp;
    }
}

void print_matrix(int matrix[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    printf("Original Matrix:\n");
    print_matrix(matrix);

    swap_third_row(matrix,0,4);
    swap_third_row(matrix,1,3);

    printf("\nMatrix after swapping third row:\n");
    print_matrix(matrix);

    return 0;
}

