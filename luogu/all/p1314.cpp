#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
struct Ks
{
    int w, v;
} ks[N];
int n, m, l[N], r[N], W, _max{}, _min{};
ll s, y, sum[N], ans{100000000000};
static bool cmp(Ks a, Ks b)
{
    return a.w < b.w;
}
ll ysum(int w)
{
    y = 0;
    int p, x{1};
    for (int i = 1; i <= n; i++)
    {
        if (ks[i].w >= W)
        {
            p = i;
            break;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (r[i] < p)
        {
            y += 0;
        }
        else
        {
            if (l[i] > p)
            {
                y += (sum[r[i]] - sum[l[i] - 1]) * (r[i] - l[i] + 1);
            }
            else
            {
                y += (sum[r[i]] - sum[p - 1]) * (r[i] - p + 1);
            }
        }
    }
    return y;
}
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> ks[i].w >> ks[i].v;
        sum[i] = sum[i - 1] + ks[i].v;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> l[i] >> r[i];
    }
    sort(ks + 1, ks + n + 1, cmp);
    _max = ks[n].v;
    while (_max >= _min)
    {
        W = _max + _min >> 1;
        ll tmp = ysum(W);
        if (tmp < s)
        {
            _max = W - 1;
        }
        else
        {
            _min = W + 1;
        }
        ans = min(ans, abs(s - tmp));
    }
    cout << ans;
    return 0;
}
