#include<bits/stdc++.h>
#include"bcj.h"
using namespace std;
typedef long long ll;
/*
ll n, m, sum,cnt;
struct edge{
    ll n1, n2, q;
}ed[200005];


int main(void){
    cin >> n >> m;
    for (int i = 0; i < m;i++){
        cin >> ed[i].n1 >> ed[i].n2 >> ed[i].q;
    }
    sort(ed, ed + m, [](edge a, edge b)
         { return a.q < b.q; });
    unionfind uf(n);
    for(int i = 0; i < m; i++){
        if(cnt==n-1)break;
        if(uf.find(ed[i].n1) == uf.find(ed[i].n2)){
            continue;
        }
        uf.unite(ed[i].n1, ed[i].n2);
        sum += ed[i].q;
        cnt++;
    }
    if(cnt==n-1){
        cout<<sum<<endl;
    }
    else{
        cout << "orz" << endl;
    }
    return 0;
}
*/
#define INF 0x3f3f3f
class node
{
public:
    int to, next, w;
} edge[400010];
int n, m, head[200010], dis[200010], cnt = 0, ans = 0, sum = 0, vis[200010], now = 1;
void add(int u, int v, int w)
{
    edge[++cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
}
int prim()
{
    memset(dis, INF, sizeof(dis));
    for (int i = head[1]; i; i = edge[i].next)
        dis[edge[i].to] = min(dis[edge[i].to], edge[i].w); 
    while (++sum < n)                                      
    {
        int minn = INF;
        vis[now] = 1;
        for (int i = 1; i <= n; i++)
            if (!vis[i] && minn > dis[i])
            {
                minn = dis[i];
                now = i;
            }
        ans += minn;
        for (int i = head[now]; i; i = edge[i].next)
            if (dis[edge[i].to] > edge[i].w && !vis[edge[i].to]) 
                dis[edge[i].to] = edge[i].w;
    }
    return ans;
}
int main()
{
    memset(head, 0, sizeof(head));
    int u, v, w;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    cout << prim();
    return 0;
}