#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main() {
    srand((unsigned)time(NULL));  // �]�m�H���ƺؤl

    int count = 0;  // ��d����
    int five_star_count = 0;  // ��줭�P���⪺����
    int four_star_count = 0;  // ���|�P���⪺����
    double five_star_prob = 0.006;  // ���P���⪺���v
    double four_star_prob = 0.051;  // �|�P���⪺���v

    while (1) {  // �L���`��
        count++;  // ��d���ƥ[�@
        double r = (double)rand() / RAND_MAX;  // �ͦ�0��1�������H���p��

        if (r < five_star_prob) {  // ��줭�P����
            five_star_count++;  // ��줭�P���⪺���ƥ[�@
            printf("��%d��A��줭�P����I\n", count);
            if (count >= 90) {  // ���90��
                printf("���ߧA�A�b��%d����F���P����I\n", count);
                break;  // ���X�`��
            }
        } else if (r < five_star_prob + four_star_prob) {  // ���|�P����
            four_star_count++;  // ���|�P���⪺���ƥ[�@
            printf("��%d��A���|�P����I\n", count);
            if (count == 9) {  // ����9��
                double p = 1 - pow(1 - four_star_prob, count);  // �p����|�P���⪺���v
                printf("��9��ɡA���|�P���⪺���v��%.1f%%\n", p * 100);
            }
            if (count == 10) {  // ����10��
                double p = 1 - pow(1 - four_star_prob, count);  // �p����|�P���⪺���v
                printf("��10��ɡA���|�P���⪺���v��%.1f%%\n", p * 100);
            }
        } else {  // ���T�P�ΥH�U����
            printf("��%d��A���T�P�ΥH�U����C\n", count);
        }

        // �p�G���90���٨S�����P����A��ܨS�����
        if (count >= 90 && five_star_count == 0) {
            printf("�ܿ�ѡA�b%d��ɨS����줭�P����C\n", count);
			break; // ���X�`��
}


    // �p�G���F�|�P�Τ��P����A���m�p�ƾ�
    if (four_star_count > 0 || five_star_count > 0) {
        count = 0;
        four_star_count = 0;
        five_star_count = 0;
        five_star_prob = 0.006;  // ���m���P���⪺���v
        four_star_prob = 0.051;  // ���m�|�P���⪺���v
    }

    // �b��74�⤧��A�W�[���P���⪺���v
    if (count >= 74) {
        five_star_prob += 0.0006;
    }

    // �b��9��ɡA�ק�|�P���⪺���v
    if (count == 9) {
        four_star_prob = 0.562 / count;
    }

    // �b��10��ɡA�ק�|�P���⪺���v
    if (count == 10) {
        four_star_prob = 0.994 / count;
    }
}

return 0;
}
