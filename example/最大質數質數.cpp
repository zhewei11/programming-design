#include <stdio.h>

int main() {
    int n;

    printf("�п�J�@�ӥ���ơG");
    scanf("%d", &n);

    // �qn-1�}�l�V�U�M���C�ӼƦr�A���̤j�����
    for (int i = n - 1; i >= 2; i--) {
        int is_prime = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            printf("�p��%d���̤j��ƬO%d\n", n, i);
            return 0;
        }
    }

    printf("���s�b�p��%d�����\n", n);
    return 0;
}
