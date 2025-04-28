#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int answer[4];   // answer list
    int guess[4];   // guess list
    int i, j; 	    // circle times
    int A, B; 	   	// A & B times
    int round = 0; 	// roumd times
    int isWin = 0; 	// distinguish whether to guess the answer
	int isRepeat;	// distinguish whether the numbers are recurring
    srand(time(NULL)); 
    
    //randomly generate 4 digits number
    for (i = 0; i < 4; i++) {
        answer[i] = rand() % 10; // number in 0~9
        for (j = 0; j < i; j++) {
            if (answer[i] == answer[j]) {
                i--; // if the number recur delete it  
                break;
            }
        }
    }

    printf("===== 1A2B 遊戲開始 =====\n");

    while (!isWin) {
     
        printf("請輸入 4 個不重複的數字（0~9）：");
        scanf("%1d%1d%1d%1d", &guess[0], &guess[1], &guess[2], &guess[3]);
		
		// examine whether the numbers are recurring 
		for (i = 0; i < 4; i++) {
		    for (j = i + 1; j < 4; j++) {
		        if (guess[i] == guess[j]) {
		            printf("輸入的數字有重複，請重新輸入\n");
		            isRepeat = 1;
		            break;
		        }
		    }
		    if (isRepeat) {
		        isRepeat = 0;
		        continue;
		    }
	}
// examine the guess numbers are correct
		
        // count the a&b quantity
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

        printf("%dA%dB\n", A, B);
        round++;

// determine whether all of the number are correct 
        if (A == 4) {
            isWin = 1;
            printf("恭喜你猜中了！\n");
            printf("共猜了 %d 回合\n", round);
        }
    }

    return 0;
}
