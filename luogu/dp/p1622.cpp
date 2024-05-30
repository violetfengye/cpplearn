#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll p, q, r[105];
ll ans=1005;
bool vis[105];

void dfs(ll pn,ll cn,ll top){
    if(pn>=ans)return;
    if(cn==q){
        ans=min(ans,pn);
        return;
    }
    for (int i = 0; i < q;i++){
        if(!vis[i]){
            vis[i] = true;
            
        }
    }
}

int main(){
    cin >> p >> q;
    for(int i = 0; i < q; i++){
        cin >> r[i];
    }
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}