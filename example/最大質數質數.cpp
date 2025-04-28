#include <stdio.h>

int main() {
    int n;

    printf("叫块タ俱计");
    scanf("%d", &n);

    // 眖n-1秨﹍筂菌–计т程借计
    for (int i = n - 1; i >= 2; i--) {
        int is_prime = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            printf("%d程借计琌%d\n", n, i);
            return 0;
        }
    }

    printf("ぃ%d借计\n", n);
    return 0;
}
