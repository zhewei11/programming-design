#include <stdio.h>

int main() {
    int n;

    printf("請輸入一個正整數：");
    scanf("%d", &n);

    printf("小於%d的所有質數是：\n", n);

    // 從2開始遍歷每個數字，找到所有的質數
    for (int i = 2; i < n; i++) {
        int is_prime = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}






