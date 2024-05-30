#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;
int m, n, l, a[N], t[N];
bool check(int x)
{
    int num{}, p{};
    for (int i = 1; i <= n + 1; i++)//复制a数组给t，因为t每check一次都会改变
    {
        t[i] = a[i];
    }
    for (int i = 1; i <= n + 1; i++)
    {
        if (t[i] - t[i - 1] < x)
        {
            t[i] = t[i - 1];
            num++;
        }
    }
    return num <= m;
}
int main(void)
{
    cin >> l >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    a[n + 1] = l;
    int max{l / (n - m + 1)}, min{1}, mid{}, ans;
    while (max >= min)//二分寻找最优答案
    {
        mid = max + min >> 1;
        if (check(mid))
        {
            ans = mid;
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }
    cout << ans;
    return 0;
}