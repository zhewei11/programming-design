#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int answer[4]; // �s�񥿽T���ת��}�C
    int guess[4]; // �s��q���q�����Ʀr���}�C
    int i, j; // �j��p�ƾ�
    int A, B; // �s�� A, B ���ƶq
    int round = 0; // �O���^�X��
    int isWin = 0; // �O�_�q������
    srand(time(NULL)); 
    
    // ���ܨϥΪ̿�J���T����
    printf("�п�J 4 �Ӥ����ƪ��Ʀr�]0~9�^�G");
    scanf("%1d%1d%1d%1d", &answer[0], &answer[1], &answer[2], &answer[3]);
    
    printf("�q���w�g�ǳƦn�q�����פF\n");

    while (!isWin) {
        // �q���H�����ͤ@�ӼƦr�@���q��
        for (i = 0; i < 4; i++) {
            guess[i] = rand() % 10; // �� 0~9 �������Ʀr
            for (j = 0; j < i; j++) {
                if (guess[i] == guess[j]) {
                    i--; // �Y���ƫh���s����
                    break;
                }
            }
        }

        // �p�� A, B ���ƶq
        A = B = 0;
        for (i = 0; i < 4; i++) {
            if (guess[i] == answer[i]) {
                A++;
            } else {
                for (j = 0; j < 4; j++) {
                    if (guess[i] == answer[j]) {
                        B++;
                        break;
                    }
                }
            }
        }

        // ��X���G
        printf("�q���q�����Ʀr���G%d %d %d %d�A���G�� %dA%dB\n", guess[0], guess[1], guess[2], guess[3],A, B);
        round++;

        // �P�_�O�_�q������
        if (A == 4) {
            isWin = 1;
            printf("�q���q���F�I\n");
            printf("�@�q�F %d �^�X\n", round);
        }
    }

    return 0;
}

