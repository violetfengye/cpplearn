#include <stdio.h>
#include <string.h>

int getSubString(char s[], char t[], int start, int count)
{
    int k;
    int len = strlen(s);
    if (start >= 0 && start + count <= len) // 边界检查修正
    {
        for (k = 0; k < count; k++)
            t[k] = s[start + k];
        t[k] = '\0';
        return 1;
    }
    return 0;
}

int main(void)
{
    int n, m;
    char str[80], sub[80];
    
    printf("Please enter a string: ");
    fgets(str, sizeof(str), stdin); // 用 fgets 替代 scanf 来接受字符串输入
    str[strcspn(str, "\n")] = '\0'; // 去除换行符
    
    printf("Enter start position and count: ");
    scanf("%d%d", &n, &m);
    
    n--;  // 将 start 从 1-based 转换为 0-based
    if (getSubString(str, sub, n, m))
        printf("Substring: %s\n", sub);
    else
        printf("Invalid input\n");
    
    return 0;
}
