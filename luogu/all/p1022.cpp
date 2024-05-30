#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int s = 0, deng = 1, jiaj = 1;
    char c, x; // x用于记录未知数
    int kx = 0, k0 = 0;
    // 6a-5+a = 2-2a;
    while (cin >> c)
    {
        if (c >= 'a' && c <= 'z')
        {
            x = c; // 用x记录下未知数
            if (s == 0)
                s = 1;
            kx += s * deng * jiaj;
            s = 0;
        }
        if (c >= '0' && c <= '9')
        {
            s = s * 10 + c - '0'; // c - '0'可以将其转为数字
            // 此语句用于记录数字
        }
        if (c == '=') // 当遇到等号的时候
        {
            // 首先先把记录的数字先加上
            k0 += s * deng * jiaj;
            s = 0;
            deng = -1;
            jiaj = 1;
        }
        if (c == '-')
        {
            k0 += s * deng * jiaj;
            s = 0;
            jiaj = -1;
        }
        if (c == '+')
        {
            k0 += s * deng * jiaj;
            s = 0;
            jiaj = 1;
        }
    }
    k0 += s * deng * jiaj;
    cout << fixed << setprecision(3) << x << "=" << -1.0 * k0 / kx << endl;
    return 0;
}
/*
// P1022
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s; cin>>s;
    bool flag=true;//true等号左边 false等号右边
    char ver;//记录变量类型
    int k=0,b=0;//最终化成kx=b
    for(int i=0,f=1,last;;++i){
        if(flag){
            if(s[i]>='0'&&s[i]<='9'){
                last=last*10+s[i]-'0';
            }
            else if(s[i]>='a'&&s[i]<='z'){
                ver=s[i];
                k+=last*f?last*f:1; f=1; last=0;
            }
            else{
                b-=last*f; f=1; last=0;
                if(s[i]=='-') f=-1;
                if(s[i]=='=') flag=false;
            }
        }
        else{
            if(s[i]>='0'&&s[i]<='9'){
                last=last*10+s[i]-'0';
            }
            else if(s[i]>='a'&&s[i]<='z'){
                ver=s[i];
                k-=last*f?last*f:1; f=1; last=0;
            }
            else{
                b+=last*f; f=1; last=0;
                if(s[i]=='-') f=-1;
                if(s[i]=='\0') break;
            }
        }
    }
    cout<<ver<<"="<<fixed<<setprecision(3)<<(double)b/k<<endl;
    return 0;
}
*/