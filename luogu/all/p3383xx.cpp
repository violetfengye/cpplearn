#include <bits/stdc++.h>
using namespace std;
int z[6000005];
bool vis[100000002];
int ans;
void siev(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
            z[++ans] = i;
        for (int j = 1; j <= ans && i * z[j] <= n; j++)
        {
            vis[i * z[j]] = 1;
            if (i % z[j] == 0)
                break;
        }
    }
}
int main()
{
    // freopen("P3383_1.in","r",stdin);
    // freopen("1.out","w",stdout);
    int n, x;
    cin >> n >> x;
    siev(n);
    int a;
    for (int i = 1; i <= x; i++)
    {
        // printf("%d)",i);
        cin >> a;
        cout << z[a] << endl;
    }
    return 0;
}
