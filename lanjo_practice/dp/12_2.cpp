#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PII;
ll n, c, ans, dp[3005][3005];
PII wp[105];
ll solve(ll i,ll j){
    if(dp[i][j]!=0)
        return dp[i][j];
    if(i == 0)
        return 0;
    if(wp[i].first>j){
        dp[i][j] = solve(i - 1, j);
    }
    else{
        dp[i][j] =max(dp[i-1][j], solve(i-1,j-wp[i].first)+wp[i].second);
    }
    return dp[i][j];
}
int main(void)
{
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> wp[i].first >> wp[i].second;
    }
    ans=solve(n,c);
    cout << ans << endl;
    return 0;
}
