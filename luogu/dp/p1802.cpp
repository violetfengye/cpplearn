#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1005;

ll n, X, v1[N], v2[N], x[N];
ll dp[N];

int main(){
    cin >> n >> X;
    for (int i = 1; i <= n;i++){
        cin >> v1[i] >> v2[i] >> x[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = X; j >= 0; j--)
        {
            if (j >= x[i])
                dp[j] = max(dp[j] + v1[i], dp[j - x[i]] + v2[i]);
            else
                dp[j] += v1[i];
        }
    }
    cout << 5*dp[X] << endl;
    return 0;
}