#include <stdio.h>

int main() {
    int n;

    printf("�п�J�@�ӥ���ơG");
    scanf("%d", &n);

    printf("�p��%d���Ҧ���ƬO�G\n", n);

    // �q2�}�l�M���C�ӼƦr�A���Ҧ������
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






