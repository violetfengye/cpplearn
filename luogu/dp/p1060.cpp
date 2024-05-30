#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, ans=-1;
ll v[30],p[30];

void dfs(ll mn,ll pv,ll top){
    if(mn>n)
        return;
    if(top>m){
        ans=max(ans,pv);
        return;
    }
    dfs(mn+v[top], pv + p[top] * v[top], top + 1);
    dfs(mn, pv, top + 1);
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> v[i] >> p[i];
    }
    dfs(0, 0, 1);
    cout << ans << endl;
    return 0;
}