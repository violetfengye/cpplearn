//Parking02�������������ƺš�ͣ��ʱ��������ͣ���Ѳ����
#include <stdio.h>
#include <math.h>
int main(void)
{
    char licenseNum[10];
    float parkTime;
    int parkCost;
    int hours;
    int days;
    printf("�����복�ƺţ�");
    scanf("%s", licenseNum[10]);
    printf("������ͣ��ʱ��(Сʱ)��");
    scanf("%f", parkTime);
    hours = ceil(parkTime); //����ȡ����ͣ��ʱ������1Сʱ��1Сʱ��
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
    printf("���ƺ�%s���շѣ�%dԪ\n", licenseNum, parkCost);
    return 0;
}
