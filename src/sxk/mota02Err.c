//mota02，输入勇士和怪物的生命值、攻击力、防御力，输出战斗各回合详细情况。
#include <stdio.h>
int main(void)
{ //主函数
    int aHp, aAtk, aDef;    //勇士的生命值、攻击力、防御力
    int bHp, bAtk, bDef;    //怪物的生命值、攻击力、防御力
    int abHurt; baHurt;     //勇士每回合攻击怪物的伤害、怪物反击的伤害
    int turn;
    printf("输入勇士的生命值、攻击力和防御力：");    //提示1
    scanf("%d%d%d", &aHp, &aAtk, &aDef);       //输入勇士的属性
    printf("输入怪物的生命值、攻击力和防御力：");    //提示2
    scanf("%d%d%d", &bHp, &bAtk, &bDef);       //输入怪物的属性
    abHurt = (aAtk>bDef)?(aAtk-bDef):0; //勇士攻击，每回对怪物造成的伤害
    baHurt = (bAtk>aDef)?(bAtk-aDef):0; //怪物反击，每回对勇士造成的伤害
    printf("勇士攻击怪物，每回造成的伤害=勇士攻击力%d-怪物防御力%d=%d点\n",
            aAtk, bDef, abHurt);
    printf("怪物反击勇士，每回造成的伤害=怪物攻击力%d-勇士防御力%d=%d点\n",
            bAtk, aDef, baHurt);
    if (abHurt=0 && baHurt=0)
    {
        printf("勇士与怪物都不能伤害到对方，双方平局。\n");
        return 0;
    }
    for (turn=1; aHp>0 && bHp>0; turn++)
    {
        printf("回合%f:", turn);
        printf("攻击怪物，怪物生命%d-%d=%d点；", bHp, abHurt, bHp-abHurt);
        bHp -= abHurt;
        if (bHp<=0)
            break;
        printf("怪物反击，勇士生命%d-%d=%d点\n", aHp, baHurt, aHp-baHurt);
        aHp -= baHurt;
    }
    if (aHp>0)
        printf("\n勇士战胜怪物，%d个回合，生命损失%d点\n",
                turn, turn*baHurt);
    else
        printf("勇士战斗失败\n");
    return 0;
}
//运行示例1（绿头怪）：  1000 10 10   50 20 1
//运行示例2（红头怪）：   950 10 10   70 15 2
//运行示例3（骷髅士兵）： 910 10 10  150 40 20
//运行示例4（平局）：     910 10 10  100 9 11
