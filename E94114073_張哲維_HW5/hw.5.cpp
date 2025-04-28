#include <stdio.h>

/* Print an array */
void print_arr(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Swap two elements */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Selection sort */
void selection_sort(int arr[], int n) {
    int i, j, max_index;

    for (i = 0; i < n - 1; i++) {
        max_index = i; // Assume the current element is the maximum

        // Find the index of the maximum element in the remaining unsorted array
        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[max_index])
                max_index = j;
        }

        // Print the current step
//        printf("Step %d: ", i+1);
//        print_arr(arr, n);
        // Swap the maximum element with the current element
        swap(&arr[i], &arr[max_index]);
    }
}

int main(void) {
    int n = 9; // Array size
    int arr[] = {16, 25, 39, 27, 35 , 12, 8, 45, 63}; // Array

    printf("Origin: ");
    print_arr(arr, n);
    selection_sort(arr, n); // Call the function of selection sort
    printf("Result: ");
	print_arr(arr, n);

    return 0;
}

