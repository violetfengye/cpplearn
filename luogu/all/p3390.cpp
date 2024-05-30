#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
struct sq
{
    ll zj[105][105];
    sq(){
        memset(zj, 0, sizeof zj);
    }
};
sq operator*(sq a,sq b)
{
    sq c;
    for (int i = 0; i < 105;i++)
        for (int j = 0; j < 105;j++)
            for (int k = 0; k < 105;k++)
                c.zj[i][j] = (c.zj[i][j] + a.zj[i][k] * b.zj[k][j] % mod) % mod;
    return c;
    
}
sq quick_mol(sq c,ll k){
    sq ans;
    for (int i = 1; i < 105;i++){
        ans.zj[i][i] = 1;
    }
        while (k)
        {
            if (k & 1)
                ans = ans * c;
            c = c * c;
            k >>= 1;
        }
    return ans;
}
int main(void){
    sq a, ans;
    ll n, k;
    cin >> n >> k;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            cin >> a.zj[i][j];
        }
    }
    ans=quick_mol(a, k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << ans.zj[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
}

