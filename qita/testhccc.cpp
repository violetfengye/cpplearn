#include <stdio.h>
#include <stdlib.h>

int tmp[18],mult[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2} ;

int *sw(char *a){
	for(int i=0;i<18;i++)
    {
    	if(a[i]=='x')
            tmp[i]=10;
        else
            tmp[i]=a[i]-48;
    }
    return tmp;
}

int correct(int *id)
{
    int cor[18],sum=0;
    for(int i=0;i<17;i++){
    	cor[i]=id[i]*mult[i];
    	sum+=cor[i];
	}
    int a=sum%11;
    if((a+id[17])==12 || (id[17]==1 && a==0) || (id[17]==0 && a==1))
        return 1;
    else
        return 0;
}

int main()
{
    char a[18];
    int *id;
    while(1)
    {
        printf("请输入身份证号：\n");
        gets(a);
        id = sw(a);
        if(correct(id))
        {
            printf("correct,");
            printf("出生年月为:%d%d%d%d年%d%d月%d%d日\n",id[6],id[7],id[8],id[9],
                   id[10],id[11],id[12],id[13]);
        }
        else
        {
            printf("wrong\n");
        }
        printf("\n");
    }
    return 0;
}