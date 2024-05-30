#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(void)
{
    int n, a;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        v.insert(upper_bound(v.begin(), v.end(), a), a); // 无敌
        if (v.size() % 2)
        {
            cout << v[i / 2] << endl;
        }
    }
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
inline int read(){
    register int x=0,f=1;
    register char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    return x*f;
}
inline void write(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
priority_queue<int>q1;//大根堆
priority_queue<int,vector<int>,greater<int> >q2;//小根堆
int mid=0,num[N];
int main()
{
    int n,a,b; n=read();
    for(int i=1;i<=n;++i)
        num[i]=read();
    mid=num[1]; printf("%d\n",mid);
    for(int i=2;i<=n;++i){
        if(num[i]>mid)q2.push(num[i]);//丢到小根堆
        else q1.push(num[i]);//丢到大根堆
        //始终保证q1中的所有数<=mid<q2中的所有数
        if(i&1){//个数为奇数时
            while(q1.size()>q2.size()){
                q2.push(mid);
                mid=q1.top();
                q1.pop();
            }
            while(q1.size()<q2.size()){
                q1.push(mid);
                mid=q2.top();
                q2.pop();
            }
            printf("%d\n",mid);
        }
    }
    return 0;
}
*/