//mota02��������ʿ�͹��������ֵ���������������������ս�����غ���ϸ�����
#include <stdio.h>
int main(void)
{ //������
    int aHp, aAtk, aDef;    //��ʿ������ֵ����������������
    int bHp, bAtk, bDef;    //���������ֵ����������������
    int abHurt; baHurt;     //��ʿÿ�غϹ���������˺������ﷴ�����˺�
    int turn;
    printf("������ʿ������ֵ���������ͷ�������");    //��ʾ1
    scanf("%d%d%d", &aHp, &aAtk, &aDef);       //������ʿ������
    printf("������������ֵ���������ͷ�������");    //��ʾ2
    scanf("%d%d%d", &bHp, &bAtk, &bDef);       //������������
    abHurt = (aAtk>bDef)?(aAtk-bDef):0; //��ʿ������ÿ�ضԹ�����ɵ��˺�
    baHurt = (bAtk>aDef)?(bAtk-aDef):0; //���ﷴ����ÿ�ض���ʿ��ɵ��˺�
    printf("��ʿ�������ÿ����ɵ��˺�=��ʿ������%d-���������%d=%d��\n",
            aAtk, bDef, abHurt);
    printf("���ﷴ����ʿ��ÿ����ɵ��˺�=���﹥����%d-��ʿ������%d=%d��\n",
            bAtk, aDef, baHurt);
    if (abHurt=0 && baHurt=0)
    {
        printf("��ʿ����ﶼ�����˺����Է���˫��ƽ�֡�\n");
        return 0;
    }
    for (turn=1; aHp>0 && bHp>0; turn++)
    {
        printf("�غ�%f:", turn);
        printf("���������������%d-%d=%d�㣻", bHp, abHurt, bHp-abHurt);
        bHp -= abHurt;
        if (bHp<=0)
            break;
        printf("���ﷴ������ʿ����%d-%d=%d��\n", aHp, baHurt, aHp-baHurt);
        aHp -= baHurt;
    }
    if (aHp>0)
        printf("\n��ʿսʤ���%d���غϣ�������ʧ%d��\n",
                turn, turn*baHurt);
    else
        printf("��ʿս��ʧ��\n");
    return 0;
}
//����ʾ��1����ͷ�֣���  1000 10 10   50 20 1
//����ʾ��2����ͷ�֣���   950 10 10   70 15 2
//����ʾ��3������ʿ������ 910 10 10  150 40 20
//����ʾ��4��ƽ�֣���     910 10 10  100 9 11
