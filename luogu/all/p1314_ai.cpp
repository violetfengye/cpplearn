#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10, M = 2e5 + 10;
int n, m;
int w[N], v[N];
ll S, s[N], g[N];
int x[M], y[M];
ll get(int W)
{
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + v[i] * (w[i] >= W),
        g[i] = g[i - 1] + 1 * (w[i] >= W);
    ll tmp = 0;
    for (int i = 1; i <= m; i++)
        tmp += (s[y[i]] - s[x[i] - 1]) * (g[y[i]] - g[x[i] - 1]);
    return tmp;
}
int main()
{
    scanf("%d%d%lld", &n, &m, &S);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &w[i], &v[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d%d", &x[i], &y[i]);
    int l = 0, r = 1e6, mid;
    ll ans = 1e18;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        ll tmp = get(mid);
        if (tmp < S)
            r = mid - 1;
        else
            l = mid + 1;
        ans = min(ans, abs(S - tmp));
    }
    printf("%lld", ans);
}
