#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

/* Print an array */
void print_arr(int arr[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

}

/* Insertion sort */
void insertion_sort(int arr[], int n) {
	int i,num=0;
	for (i = 0; i < n; i++) { 
		int j = i;
		while (j > 0 && arr[j - 1] < arr[j]) { // Compare to the previous one
			// Swap
			int temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}
		print_arr(arr, n); 
	}
	
	printf("Result: "); 
	print_arr (arr, n); 
}

int main(void){
	srand(time(NULL));
	int n = rand()%20; // Array size 
	int arr[n];  // Array
	for(int i=0;i<n;i++){
		arr[i]=rand()%100;
	}
	
	printf("Origin: "); 
	print_arr (arr, n);
	
	insertion_sort(arr, n); // Call the function of insertion sort
	
	return 0;
}

/* OUTPUT----
Origin: 16 25 39 27 12 8 45 63
Result: 8 12 16 25 27 39 45 63
--------------------*/
