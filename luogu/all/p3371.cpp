#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4;
const ll MAX_ = pow(2, 31) - 1;
ll d[N], n, m, s, dx[N][N];
bool vis[N];
void dijkstra(int x){
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.push({0, x});
    d[x] = 0;
    while(!q.empty()){
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(int i = 1; i <= n; i++){
            if(d[u] + dx[u][i] < d[i]){
                d[i] = d[u] + dx[u][i];
                if(!vis[i])
                    q.push({d[i], i});
            }
        }
    }
}
int main(void){
    cin >> n >> m >> s;
    for (int i = 1;i <= n;i++){
        for (int j = 1; j <= n;j++){
            dx[i][j] = MAX_, d[i] = MAX_;
            if(i == j){
                dx[i][j] = 0;
            }
        }
    }
    for (int i = 0;i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(dx[a][b] >c){
            dx[a][b] = c;
        }
    }
    dijkstra(s);
    for (int i = 1;i <= n;i++){
        cout << d[i] << " ";
    }
    return 0;
}