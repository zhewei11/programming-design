#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int answer[5]; 		// answer list
    int guess[5]; 		// guess list
    int i, j; 			// circle times
    int A, B; 			// A & B times
    int round = 0; 		// roumd times
    int isWin = 0; 		// distinguish whether to guess the answer
    int isRepeat;		//distinguish whether the numbers are recurring
    srand(time(NULL)); 
    
    // randomly generate 5 digits number
    for (i = 0; i < 5; i++) {
        answer[i] = rand() % 10; // // number in 0~9
        for (j = 0; j < i; j++) {
            if (answer[i] == answer[j]) {
                i--; //if the number recur delete it  
                break;
            }
        }
    }

    printf("===== �q�Ʀr�C���}�l =====\n");

    while (!isWin) {
        
        printf("�п�J 5 �Ӥ����ƪ��Ʀr�]0~9�^�G");
        scanf("%1d%1d%1d%1d%1d", &guess[0], &guess[1], &guess[2], &guess[3], &guess[4]);
        
        // examine whether the numbers are recurring
        for (i = 0; i < 5; i++) {
            for (j = i + 1; j < 5; j++) {
                if (guess[i] == guess[j]) {
                    printf("��J���Ʀr�����ơA�Э��s��J\n");
                    isRepeat = 1;
                    break;
                }
            }
            if (isRepeat) {
                isRepeat = 0;
                break;
            }
        }
        
// examine the guess numbers are correct
       
        // count the a&b quantity
        A = B = 0;
        for (i = 0; i < 5; i++) {
            if (guess[i] == answer[i]) {
                A++;
            } else {
                for (j = 0; j < 5; j++) {
                    if (guess[i] == answer[j]) {
                        B++;
                        break;
                    }
                }
            }
        }

        printf("%dA%dB\n", A, B);
        round++;

        // determine whether all of the number are correct 
        if (A == 5) {
            isWin = 1;
            printf("���ߧA�q���F�I\n");
            printf("�@�q�F %d �^�X\n", round);
        }
    }

    return 0;
}
