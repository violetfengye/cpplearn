#include <stdio.h>
#include <math.h>
int main(void)
{
    float x,y;
    printf("input x:");
    scanf("%f", &x);//float类型需要使用 %f
    if (x<0)
        y = sqrt(1-3*x);
    else if (fabs(x)<1e-6)//==是判断是否相等的运算符，=是赋值运算符，但是建议浮点数判0使用fabs函数  
        y = 2*x*x+2;
    else if(x>0 && x<3)
        y = 4*x-10;
    else
        y = (x+2)/(1-5*x);//5和x之间需要加上*
    printf("x=%f, y=%.2f\n",x,y);
    return 0;
}
