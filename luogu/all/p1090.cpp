#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<ll, vector<ll>, greater<ll>> Q;
int main(void)
{
    ll n, sum{}, a, ans{};
    //freopen("D:\\c++inandout\\P1090_2.in", "r", stdin);
    //freopen("D:\\c++inandout\\out.txt", "w", stdout);
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> a;
        Q.push(a);
    }
    int t = Q.size();
    if (t == 1)
    {
        cout << Q.top();
    }
    else
    {
        while (!Q.empty())
        {
            ans += Q.top();
            Q.pop();
            ans += Q.top();
            Q.pop();
            sum += ans;
            Q.push(ans);
            ans = 0;
            if (Q.size() == 1)
                break;
        }
    }
    cout << sum;
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
inline int read(){
    register int x=0,f=1;
    register char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    return x*f;
}
priority_queue<int,vector<int>,greater<int> >pq;//小根堆
int main()
{
    int n=read();
    while(n--) pq.push(read());
    long long res=0;
    while(pq.size()>1){
        int temp=pq.top(); pq.pop();
        temp+=pq.top(); pq.pop();//取出两个果子并合并
        res+=temp;//体力消耗
        pq.push(temp);
    }
    cout<<res<<endl;
    return 0;
}
*/