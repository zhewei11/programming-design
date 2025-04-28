#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// ��ƭ쫬
void selectionSort(int arr[], int n);
void printArray(int arr[], int n);

int main() {
	srand(time(NULL));
    int n = rand()%20;
	int arr[n] ; 
    
    for(int i=0;i<n;i++) arr[i]=rand()%100;

    printf("��l�}�C�G\n");
    printArray(arr, n);

    selectionSort(arr, n);
  
    printf("\n�Ƨǫ�}�C�G\n");
    printArray(arr, n);

    return 0;
}

// ��ܴ��J�k
void selectionSort(int arr[], int n) {
    int i, j, max, temp;
    for (i = 0; i < n - 1; i++) {
        max = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[max]) {
                max = j;
            }
        }
        // �N�̤p�����洫�쥼�Ƨǳ������_�l��m
        temp = arr[max];
        arr[max] = arr[i];
        arr[i] = temp;
        printArray(arr,n);
    }
}

// ��X�}�C
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

