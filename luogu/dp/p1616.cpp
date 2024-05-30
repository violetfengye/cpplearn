#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e7+5;
ll T, m;
ll v[10005],t[10005],dp[N];

int main(){
    cin >> T >> m;
    for (int i = 1;i<=m;i++){
        cin >> t[i] >> v[i];
    }
    for (int i = 1;i<=m;i++){
        for (int j = 1;j<=T;j++){
            if (j>=t[i]){
                dp[j] = max(dp[j],dp[j-t[i]]+v[i]);
            }
            else{
                dp[j] = max(dp[j],dp[j-1]);
            }
        }
    }
    cout << dp[T] << endl;
    return 0;
}
