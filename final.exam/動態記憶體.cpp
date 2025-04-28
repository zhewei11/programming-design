#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main() {
    int num, i;
    struct student {
        char name[10];
        int score;
    } *ptr;

    printf("Number of students: ");
    scanf("%d", &num);

    ptr = (struct student*) malloc(num * sizeof(struct student));

    for (i = 0; i < num; i++) {
        //flush(stdin);
        printf("Name for student %d: ", i + 1);
        scanf("%s", (ptr + i)->name);
        printf("Score for student %d: ", i + 1);
        scanf("%d", &(ptr + i)->score);
    }

    for (i = 0; i < num; i++)
        printf("%s: score = %d\n", (ptr + i)->name, (ptr + i)->score);

    free(ptr);
    return 0;
}

