#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll const N = 1e5 + 5;
ll n, m, t, sum[N], ans;
vector<ll>sv[N];
set<ll> sn, tmp;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m >> t;
    for (int i = 1;i<=m;i++){
        ll a, b;
        cin >> a >> b;
        sv[a].push_back(b);
    }
    for(int i = 1; i <= t;i++) {
        for (auto it = sv[i].begin(); it != sv[i].end(); it++)
        {
            unsigned long long temp = tmp.size();
            tmp.insert(*it);
            if(temp<tmp.size()){
                sum[*it] += 3;
            }
            else{
                sum[*it] += 2;
            }
        }
        tmp.clear();
        for (int j = 1; j <= n;j++) {
            sum[j] -= 1;
            if(sum[j]<0){
                sum[j] = 0;
            }
            if(sum[j]>5&&sn.count(j)==0){
                sn.insert(j);
            }
            if(sum[j]<=3&&sn.count(j)==1){
                sn.erase(j);
            }
        }
    }
    cout<<sn.size()<<endl;
    return 0;
}