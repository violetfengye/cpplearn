#include <stdio.h>
#include <stdlib.h>

void select(FILE *fp1, int x)
{
    int num, score1, score2;
    char name[20];
    
    // 使用循环来读取文件数据
    while (fscanf(fp1, "%d%s%d%d", &num, name, &score1, &score2) == 4) {
        // 如果学生编号是0，跳过
        if (num == 0)
            continue;
        
        // 判断条件
        if (x < score2) {
            // 打印符合条件的记录
            printf("%3d  %-7s  %3d  %3d\n", num, name, score1, score2);
        }
    }
}

int main(void)
{
    FILE *fp1;  // 修正为文件指针
    int x;
    
    // 打开文件
    fp1 = fopen("studentA_3_3.txt", "r");
    if (fp1 == NULL) {
        printf("File Open Error!\n");
        exit(1);  // 使用非0的退出码来表示错误
    }
    
    // 输入阈值
    printf("Enter a threshold for score2: ");
    scanf("%d", &x);
    
    // 调用函数进行选择
    select(fp1, x);
    
    // 关闭文件
    fclose(fp1);
    
    return 0;
}
