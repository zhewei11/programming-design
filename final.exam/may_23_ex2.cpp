#include<stdio.h>
#include<stdlib.h>

int main(void){
	double *ptr = (double *)malloc(3 * sizeof(double));
	
	for(int i = 0; i < 3; i++){
		printf("input:");
		scanf("%lf", (ptr + i));
	}
	
	double sum = 0.0;
	for(int i = 0; i < 3; i++){
		sum += *(ptr + i);
	}
	
	double average = sum / 3;
	printf("Á`©M: %.2lf\n", sum);
	printf("¥­§¡­È: %.2lf\n", average);
	
	free(ptr);
	
	return 0;
}

