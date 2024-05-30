#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
int main()
{
    stack<int> s; // 定义一个栈
    string str;
    cin >> str;                    // 输入字符串
    int ans = 0;                   // 最终计算结果
    for (int i = 0; i != '@'; i++) // 遍历字符串，遇到'@'跳出
    {
        int num = 0; // 记录每个数
        int t = 1;
        if (str[i] == '.')
        { // 遇到了该符号，把其前面的字符型数字转换为整型数字
            for (int j = i - 1; str[j] >= '0' && str[j] <= '9'; j--)
            {
                num += (str[j] - '0') * t;
                t *= 10;
            }
            s.push(num); // 转换后的数压入栈
        }
        else if (str[i] >= '0' && str[i] <= '9') // 如果是数字，跳过此次循环
            continue;
        else
        {                    // 遇到其他符号
            int k = s.top(); // 因为运算是两个数，所以先把栈顶的数暂存入k
            s.pop();         // 栈顶出栈
            if (str[i] == '+')
            {
                ans = s.top() + k; //'+'前两个数相加
                s.pop();           // 第一个加数不存在了，出栈
            }
            else if (str[i] == '-')
            {                      //'-'前两个数相减
                ans = s.top() - k; //'-'号前第二个数减第一个数
                s.pop();           // 被减数不存在了，出栈
            }
            else if (str[i] == '*')
            {                      //'*'前两个数相乘
                ans = s.top() * k; // 相乘
                s.pop();           // 第一个数不存在了，出栈
            }
            else if (str[i] == '/')
            {                      //'/'前两个数相除
                ans = s.top() / k; // '/'号前第二个数除第一个数
                s.top();           // 被除数不存在了，出栈
            }
            s.push(ans); // 把此次运算后的数压入栈
        }
    }
    cout << s.top() << endl; // 最后只剩一个数，输出栈顶
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
//P1449
string s;
stack<int>st;
int main()
{
    int last=0,res=0,temp1,temp2;
    cin>>s;
    for(int i=0;s[i]!='@';++i){
        switch(s[i]){
            case '.':
                st.push(last); last=0; break;
            case '+':
                temp1=st.top(); st.pop();
                temp2=st.top(); st.pop();
                st.push(temp1+temp2);
                break;
            case '-':
                temp1=st.top(); st.pop();
                temp2=st.top(); st.pop();
                st.push(temp2-temp1);
                break;
            case '*':
                temp1=st.top(); st.pop();
                temp2=st.top(); st.pop();
                st.push(temp1*temp2);
                break;
            case '/':
                temp1=st.top(); st.pop();
                temp2=st.top(); st.pop();
                st.push(temp2/temp1);
                break;
            default:
                //last=(last<<1)+(last<<3)+(s[i]^48);
                last=last*10+s[i]-'0';
                break;
        }
    }
    cout<<st.top()<<endl;
    return 0;
}
*/