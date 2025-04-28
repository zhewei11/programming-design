#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int answer[4]; // 存放正確答案的陣列
    int guess[4]; // 存放電腦猜測的數字的陣列
    int i, j; // 迴圈計數器
    int A, B; // 存放 A, B 的數量
    int round = 0; // 記錄回合數
    int isWin = 0; // 是否猜中答案
    srand(time(NULL)); 
    
    // 提示使用者輸入正確答案
    printf("請輸入 4 個不重複的數字（0~9）：");
    scanf("%1d%1d%1d%1d", &answer[0], &answer[1], &answer[2], &answer[3]);
    
    printf("電腦已經準備好猜測答案了\n");

    while (!isWin) {
        // 電腦隨機產生一個數字作為猜測
        for (i = 0; i < 4; i++) {
            guess[i] = rand() % 10; // 取 0~9 之間的數字
            for (j = 0; j < i; j++) {
                if (guess[i] == guess[j]) {
                    i--; // 若重複則重新產生
                    break;
                }
            }
        }

        // 計算 A, B 的數量
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

        // 輸出結果
        printf("電腦猜測的數字為：%d %d %d %d，結果為 %dA%dB\n", guess[0], guess[1], guess[2], guess[3],A, B);
        round++;

        // 判斷是否猜中答案
        if (A == 4) {
            isWin = 1;
            printf("電腦猜中了！\n");
            printf("共猜了 %d 回合\n", round);
        }
    }

    return 0;
}

