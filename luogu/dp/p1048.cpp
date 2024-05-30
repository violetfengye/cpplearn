#include<bits/stdc++.h>
using namespace std;

int T, m, ans=-1;
int t[105],v[105],dp[105][1005];

int main(){
    cin >> T >> m;
    for (int i = 1;i<=m;i++){
        cin >> t[i]>>v[i];
    }
    for (int i = 1;i<=m;i++){
        for (int j = 1; j <= T;j++){
            if(j>=t[i]){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-t[i]]+v[i]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout << dp[m][T] << endl;
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
ll T, m;
ll v[105],t[105],dp[N];

int main(){
    cin >> T >> m;
    for (int i = 1;i<=m;i++){
        cin >> t[i] >> v[i];
    }
    for (int i = 1;i<=m;i++){
        for (int j = T;j>=t[i];j--){
            dp[j] = max(dp[j],dp[j-t[i]]+v[i]);
        }
    }
    cout << dp[T] << endl;
    return 0;
}

*/