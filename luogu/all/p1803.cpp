#include <bits/stdc++.h>
using namespace std;
struct game
{
    int start, end;
} a[1000007], t;

int main()
{
    int n, count = 1, flag = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].start >> a[i].end;
    // 按照结束时间排序
    sort(a, a + n, [](game x, game y)
         { return x.end < y.end; });
    int earliest = 0; // 当前最早结束时间
    while (earliest != n && flag)
    { // 当是最后一个或者没有符合条件的时候退出
        flag = 0;
        for (int i = earliest; i < n; i++)
            if (a[i].start >= a[earliest].end)
            {
                earliest = i; // 更新earliest
                count++;      // 计数加1
                flag = 1;     // 说明有符合条件的
            }
    }
    cout << count;
    return 0;
}
/*
// P1803
#include <bits/stdc++.h>
using namespace std;
inline int read(){
    register int x=0,f=1;
    register char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    return x*f;
}
//const int N=10;
const int N=1e6+3;
struct node{
    int a,b;
}con[N];
bool cmp(node x,node y){
    if(x.b==y.b) return x.a>y.a;
    return x.b<y.b;
}
int main()
{
    int n=read(), res=0, last=0;
    for(int i=1;i<=n;++i){
        con[i].a=read(); con[i].b=read();
    }
    sort(con+1,con+1+n,cmp);
    for(int i=1;i<=n;++i){
        if(con[i].a>=last){
            ++res; last=con[i].b;
        }
    }
    cout<<res<<endl;
    return 0;
}
*/
