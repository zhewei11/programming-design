#include <stdio.h>

int i,j;
int main()
{
	printf("input:"); 
	int input[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	for(i=0;i<4;i++){
		printf("\n");
		for(j=0;j<4;j++)
			printf("%d ",input[i][j]);
	}
	printf("\n");
	printf("\n");
	printf("output:\n");

	for(i = 0;i<4;i++){
		if (i%2==0){
			for(j = 4-1;j>=0;j--){
				printf("%d ",input[i][j]);
			}
		}
		if (i%2){
			for(j = 0;j<4;j++){
				printf("%d ",input[i][j]);
			}
		}
	}
}
