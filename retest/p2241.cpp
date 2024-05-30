#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N], m, n;
int main(void)
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int q;
        cin >> q;
        int ans = int(lower_bound(a + 1, a + n + 1, q) - a);
        if (a[ans] == q)
        {
            cout << ans << " ";
        }
        else
        {
            cout << -1 << " ";
        }
    }
    return 0;
}