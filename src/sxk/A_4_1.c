#include<stdio.h>
#include<math.h>

double cost(int MonthCard,int RideTime){
    if(MonthCard==2){
        if(RideTime<=15){
            return 1.5;
        }
        else{
            return 0.5*ceil((RideTime-15)*1.0/15)+1.5;
        }
    }
    else{
        if(RideTime<=120){
            return 0;
        }
        else {
            return 0.5*ceil((RideTime-120)*1.0/15);
        }
    }
}

int main(){
    int MonthCard,RideTime;
    printf("是否有骑行卡（输入1表示有，2表示没有）：");
    scanf("%d",&MonthCard);
    printf("请输入骑行的时间长度（分钟）：");
    scanf("%d",&RideTime);
    printf("您的骑行费用为：%.2lf\n",cost(MonthCard,RideTime));
    return 0;
}