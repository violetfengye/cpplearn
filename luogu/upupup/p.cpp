#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PII pair<ll,ll>
PII horse, ed;
bool vis[25][25];
ll dx[8]{-2, -2, -1, -1, 1, 1, 2, 2};
ll dy[8]{-1, 1, -2, 2, -2, 2, -1, 1};
ll ans;
void dfs(PII now){
    if(now==ed){
        ans++;
        return;
    }
    if(vis[now.first+1][now.second]==false&&now.first+1<=ed.first){
        dfs(make_pair(now.first+1,now.second));
    }
    if(vis[now.first][now.second+1]==false&&now.second+1<=ed.second){
        dfs(make_pair(now.first,now.second+1));
    }

}
int main(){
    cin >> ed.first >> ed.second >> horse.first >> horse.second;
    vis[horse.first][horse.second] = true;
    for (int i = 0; i < 8;i++){
        ll x=horse.first+dx[i],y=horse.second+dy[i];
        if(x>0&&y>0&&x<=20&&y<=20){
            vis[x][y] = true;
        }
    }
    dfs({0, 0});
    cout << ans << endl;
    return 0;
}