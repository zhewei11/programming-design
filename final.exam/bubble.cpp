#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* Print an array */
void print_arr(int arr[], int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

/* Bubble sort */
void bubble_sort(int arr[], int n) {
	int i;
	int num=0;
	for (i = n-1; i > 0; i--) {
		int j;
		for (j = 0; j < i; j++) {
			if (arr[j] > arr[j+1]) {
				// Swap
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			
			}
		}
		num++;
		printf("%d : ",num );
		print_arr(arr, n);
	}
}

int main(void){
	srand(time(NULL));
	int n = rand()%20; // Array size 
	int arr[n];  // Array
	for(int z =0;z<n;z++){
		arr[z]=rand()%100;
	}
	
	printf("Origin: "); 
	print_arr (arr, n);
	
	bubble_sort(arr, n); // Call the function of bubble sort
	
	return 0;
}


