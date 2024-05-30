#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 100000007,N=1005;
ll n, s, a, b;
ll dp[N][N];
int main(){
    cin >> n >> s >> a >> b;
    memset(dp,0,sizeof dp);
    dp[1][0] = 0;
    for (int i = 2; i <= n; ++i)
    {
        int last = n - i + 1; // 改变会影响后面last个数
        for (int j = 0; j < n; ++j)
        {
            // dp[i][j]=(dp[i][j]+dp[i-1][((j-a*last)%n+n)%n]+dp[i-1][(j+b*last)%n])%MOD;
            dp[i][j] = (dp[i][j] + dp[i - 1][((j - a * last) % n + n) % n]) % MOD;
            dp[i][j] = (dp[i][j] + dp[i - 1][(j + b * last) % n]) % MOD;
            /* dp[i][(j-a*last+n)%n]=(dp[i][(j-a*last)%n]+dp[i-1][j])%MOD;
            dp[i][(j+b*last)%n]=(dp[i][(j+b*last)%n]+dp[i-1][j])%MOD; */
        }
    }
    cout << dp[n][(s % n + n) % n] << endl;
    return 0;
}