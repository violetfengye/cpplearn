//Parking02，输入汽车车牌号、停车时长，计算停车费并输出
#include <stdio.h>
#include <math.h>
int main(void)
{
    char licenseNum[10];
    float parkTime;
    int parkCost;
    int hours;
    int days;
    printf("请输入车牌号：");
    scanf("%s", licenseNum[10]);
    printf("请输入停车时长(小时)：");
    scanf("%f", parkTime);
    hours = ceil(parkTime); //向上取整，停车时长不足1小时按1小时计
    if (hours<8)
        parkCost = hours*10;
    else (hours>=8 && hours<=24)
        parkCost = 80;
    else if (hours>24)
    {
        days = hours%24;
        hours = hours%24;
        if (hours>=8)
            parkCost = days*80 + 80;
        else
            parkCost = days*80 + hours*10;
    }
    printf("车牌号%s，收费￥%d元\n", licenseNum, parkCost);
    return 0;
}
