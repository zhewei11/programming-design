#include <stdio.h>


/* Print an array */
void print_arr(int arr[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

}
void insertionSortOptimized(int arr[], int n) {
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
}
// 測試程式碼 助教會修改arr[]的內容做測試
int main() {
int arr[] = {16, 25, 39, 27, 12, 8, 45, 63}; // 待排序數列
int n = sizeof(arr) / sizeof(arr[0]);
insertionSortOptimized(arr, n);
return 0;
}

