#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum{};
ll a, n, m;
vector<ll> v1;
vector<ll> v2;
int main(void)
{
    cin >> n >> m;
    for (int i = 0; i <= n + m; i++)
    {
        cin >> a;
        if (a >= 0)
        {
            v1.push_back(a);
        }
        else
        {
            v2.push_back(a);
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    if (m == 0)
    {
        for (int i = 0; i < v1.size(); i++)
        {
            sum += v1[i];
        }
        for (int i = 0; i < v2.size(); i++)
        {
            sum += v2[i];
        }
    }
    else
    {
        if (v2.size() == 0)
        {
            sum += -v1[0];
            for (int i = 1; i <= n + m; i++)
            {
                sum += v1[i];
            }
        }
        if (v1.size() == 0)
        {
            for (int i = 0; i < m + n; i++)
            {
                sum += -v2[i];
            }
            sum += v2[n + m];
        }
        if (v1.size() > 0 && v2.size() > 0)
        {
            for (int i = 0; i < v1.size(); i++)
            {
                sum += v1[i];
            }
            for (int i = 0; i < v2.size(); i++)
            {
                sum += -v2[i];
            }
        }
    }
    cout << sum;
    return 0;
}
/*
// P8683
#include <bits/stdc++.h>
using namespace std;
inline int read(){
    register int x=0,f=1;
    register char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    return x*f;
}

const int N=2e5+4;
const int INF=0x3f3f3f3f;
int main()
{
    int n,m; n=read(); m=read();
    int minn=INF,maxn=-INF;
    long long sum=0;
    if(m){
        for(int i=1,temp;i<=n+m+1;++i){
            temp=read();
            minn=min(minn,temp); maxn=max(maxn,temp);
            sum+=abs(temp);
        }
        if(minn>0) sum-=minn<<1;
        if(maxn<0) sum+=maxn<<1;
    }
    else for(int i=1;i<=1+n+m;++i) sum+=read();
    cout<<sum<<endl;
    return 0;
}
*/