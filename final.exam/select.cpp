#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 函數原型
void selectionSort(int arr[], int n);
void printArray(int arr[], int n);

int main() {
	srand(time(NULL));
    int n = rand()%20;
	int arr[n] ; 
    
    for(int i=0;i<n;i++) arr[i]=rand()%100;

    printf("原始陣列：\n");
    printArray(arr, n);

    selectionSort(arr, n);
  
    printf("\n排序後陣列：\n");
    printArray(arr, n);

    return 0;
}

// 選擇插入法
void selectionSort(int arr[], int n) {
    int i, j, max, temp;
    for (i = 0; i < n - 1; i++) {
        max = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[max]) {
                max = j;
            }
        }
        // 將最小元素交換到未排序部分的起始位置
        temp = arr[max];
        arr[max] = arr[i];
        arr[i] = temp;
        printArray(arr,n);
    }
}

// 輸出陣列
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

