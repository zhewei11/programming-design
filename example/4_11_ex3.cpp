#include <stdio.h>
#include <stdlib.h> 

int count = 0;
void hanoi(int n, char A, char B, char C)
{
	if (n==1){
	
		printf("%c==>%c\n",A,C);
}
	else{
		hanoi(n-1,A,C,B);
		printf("%c==>%c\n",A,C);
		hanoi(n-1,B,A,C);
}
	count++;
}

int main()
{
    int n;
    printf("Hanoi tower height:");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    printf("Total moved %d steps\n", count);
		system("pause");
    return 0;
}
