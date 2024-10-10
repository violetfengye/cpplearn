//AI优化
#include <stdio.h>
#include <math.h>

#define BASE_TIME_WITHOUT_CARD 120    // 无月卡免费时间
#define BASE_COST_WITHOUT_CARD 0.5    // 无月卡骑行每15分钟的费用
#define BASE_TIME_WITH_CARD 15        // 月卡持有者免费时间
#define BASE_COST_WITH_CARD 1.5       // 月卡持有者前15分钟的费用
#define TIME_BLOCK 15                 // 每15分钟一个计费周期

double calculateCost(int hasMonthCard, int rideDuration) {
    if (hasMonthCard == 2) {  // 无月卡
        if (rideDuration <= BASE_TIME_WITH_CARD) {
            return BASE_COST_WITH_CARD;  // 15分钟内费用
        } else {
            int extraTime = rideDuration - BASE_TIME_WITH_CARD;
            return BASE_COST_WITH_CARD + BASE_COST_WITHOUT_CARD * ceil(extraTime * 1.0 / TIME_BLOCK);
        }
    } else {  // 有月卡
        if (rideDuration <= BASE_TIME_WITHOUT_CARD) {
            return 0;  // 120分钟内免费
        } else {
            int extraTime = rideDuration - BASE_TIME_WITHOUT_CARD;
            return BASE_COST_WITHOUT_CARD * ceil(extraTime * 1.0 / TIME_BLOCK);
        }
    }
}

int main() {
    int hasMonthCard, rideDuration;
    
    printf("是否有骑行卡（输入1表示有，2表示没有）：");
    scanf("%d", &hasMonthCard);
    printf("请输入骑行的时间长度（分钟）：");
    scanf("%d", &rideDuration);
    
    double cost = calculateCost(hasMonthCard, rideDuration);
    printf("您的骑行费用为：%.2lf\n", cost);
    
    return 0;
}
