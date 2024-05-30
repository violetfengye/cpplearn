#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
struct KS
{
    int w, v;
}a[N];
ll sum1[N]{}, sum2[N]{}, n, m, l[N], r[N], s;
ll gety(int x)
{
    ll  y{};
    for (int i = 0; i < n; i++)
    {
        sum1[i + 1] = sum1[i] + (a[i].w >= x);
        sum2[i + 1] = sum2[i] + a[i].v * (a[i].w >= x);
    }
    for (int i = 0; i < m; i++)
    {
        y += (sum1[r[i]] - sum1[l[i] - 1]) * (sum2[r[i]] - sum2[l[i] - 1]);
    }
    return y;
}
int main(void)
{
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].w >> a[i].v;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> l[i] >> r[i];
    }
    int _min{0}, _max{1000000}, mid;
    ll ans{10000000000000000};
    while (_max >= _min)
    {
        mid = _min + _max >> 1;
        ll temp = gety(mid);
        if(temp<s){
            _max = mid - 1;
        }
        else{
            _min = mid + 1;
        }
        ans = min(ans, abs(s - temp));
    }
    cout << ans;
    return 0;
}