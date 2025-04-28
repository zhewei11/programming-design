#include <stdio.h>

void hanoi(int n, char source, char auxiliary, char target, int *moves) {
    if (n > 0) {
        hanoi(n-1, source, target, auxiliary, moves);
        printf("%d:Move disk %d from %c to %c\n",*moves, n, source, target);
        (*moves)++;
        hanoi(n-1, auxiliary, source, target, moves);
    }
}

int main() {
    int n, moves = 0;
    printf("Enter the height of the tower: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C', &moves);
    printf("Total moves: %d\n", moves);
    return 0;
    } 
