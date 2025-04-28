#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main() {
    srand((unsigned)time(NULL));  // 設置隨機數種子

    int count = 0;  // 抽卡次數
    int five_star_count = 0;  // 抽到五星角色的次數
    int four_star_count = 0;  // 抽到四星角色的次數
    double five_star_prob = 0.006;  // 五星角色的機率
    double four_star_prob = 0.051;  // 四星角色的機率

    while (1) {  // 無限循環
        count++;  // 抽卡次數加一
        double r = (double)rand() / RAND_MAX;  // 生成0到1之間的隨機小數

        if (r < five_star_prob) {  // 抽到五星角色
            five_star_count++;  // 抽到五星角色的次數加一
            printf("第%d抽，抽到五星角色！\n", count);
            if (count >= 90) {  // 抽到90抽
                printf("恭喜你，在第%d抽抽到了五星角色！\n", count);
                break;  // 跳出循環
            }
        } else if (r < five_star_prob + four_star_prob) {  // 抽到四星角色
            four_star_count++;  // 抽到四星角色的次數加一
            printf("第%d抽，抽到四星角色！\n", count);
            if (count == 9) {  // 抽到第9抽
                double p = 1 - pow(1 - four_star_prob, count);  // 計算抽到四星角色的概率
                printf("第9抽時，抽到四星角色的機率為%.1f%%\n", p * 100);
            }
            if (count == 10) {  // 抽到第10抽
                double p = 1 - pow(1 - four_star_prob, count);  // 計算抽到四星角色的概率
                printf("第10抽時，抽到四星角色的機率為%.1f%%\n", p * 100);
            }
        } else {  // 抽到三星或以下角色
            printf("第%d抽，抽到三星或以下角色。\n", count);
        }

        // 如果抽到90抽還沒有五星角色，顯示沒有抽到
        if (count >= 90 && five_star_count == 0) {
            printf("很遺憾，在%d抽時沒有抽到五星角色。\n", count);
			break; // 跳出循環
}


    // 如果抽到了四星或五星角色，重置計數器
    if (four_star_count > 0 || five_star_count > 0) {
        count = 0;
        four_star_count = 0;
        five_star_count = 0;
        five_star_prob = 0.006;  // 重置五星角色的機率
        four_star_prob = 0.051;  // 重置四星角色的機率
    }

    // 在第74抽之後，增加五星角色的機率
    if (count >= 74) {
        five_star_prob += 0.0006;
    }

    // 在第9抽時，修改四星角色的機率
    if (count == 9) {
        four_star_prob = 0.562 / count;
    }

    // 在第10抽時，修改四星角色的機率
    if (count == 10) {
        four_star_prob = 0.994 / count;
    }
}

return 0;
}
