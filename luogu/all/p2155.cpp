#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll M, N, T, R;
ll gcd(ll a,ll b){
    return !b ? a : gcd(b, a % b);
}
ll jc_mol(ll n){
    if(n==0){
        return 1;
    }
    else{
        return (n%R * jc_mol(n - 1)%R)%R;
    }
}
int main(void){
    cin >> T >> R;
    for (ll i = 0; i < T;i++){
        cin >> N >> M;
        ll ans{};
        for (ll j = 1; j <= N;j++){
            if(gcd(M,jc_mol(j))==1){
                ans++;
            }
        }
        cout << ans%R << endl;
    }
    return 0;
}